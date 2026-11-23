#!/bin/bash
# Stops the gopls of a Claude Code session after the session transcript has not
# changed for GOPLS_IDLE_SECONDS (default 900). Claude Code starts gopls again
# lazily on the next Go edit or LSP request.
#
#   arm    (Stop hook, reads the hook JSON on stdin) replaces the watcher of the session
#   watch  <session_id> <claude_pid> <transcript>   the detached watcher loop
set -u

idle_seconds="${GOPLS_IDLE_SECONDS:-900}"
state_dir="${XDG_STATE_HOME:-$HOME/.local/state}/gopls-idle"
log="$state_dir/log"

claude_pid_of() {
  local pid=$1
  while [ "$pid" -gt 1 ]; do
    case "$(ps -o comm= -p "$pid")" in
      *claude*) echo "$pid"; return 0 ;;
    esac
    pid=$(ps -o ppid= -p "$pid" | tr -d ' ')
  done
  return 1
}

is_claude() {
  case "$(ps -o comm= -p "$1" 2>/dev/null)" in
    *claude*) return 0 ;;
  esac
  return 1
}

arm() {
  local input session_id transcript claude_pid pidfile
  input=$(cat)
  session_id=$(jq -r '.session_id // empty' <<<"$input")
  transcript=$(jq -r '.transcript_path // empty' <<<"$input")
  [ -n "$session_id" ] && [ -f "$transcript" ] || exit 0
  claude_pid=$(claude_pid_of "$PPID") || exit 0

  mkdir -p "$state_dir"
  pidfile="$state_dir/$session_id.pid"
  if [ -f "$pidfile" ]; then
    kill "$(cat "$pidfile")" 2>/dev/null
  fi
  nohup bash "$0" watch "$session_id" "$claude_pid" "$transcript" </dev/null >/dev/null 2>&1 &
  echo $! >"$pidfile"
}

watch() {
  local session_id=$1 claude_pid=$2 transcript=$3 age pids
  while true; do
    is_claude "$claude_pid" || break
    age=$(( $(date +%s) - $(/usr/bin/stat -f %m "$transcript") ))
    if [ "$age" -lt "$idle_seconds" ]; then
      sleep $(( idle_seconds - age + 5 ))
      continue
    fi
    pids=$(pgrep -P "$claude_pid" -x gopls | paste -sd ' ' -)
    if [ -n "$pids" ]; then
      # shellcheck disable=SC2086
      kill $pids
      echo "$(date '+%F %T') stopped gopls $pids of claude $claude_pid (session $session_id, idle ${age}s)" >>"$log"
    fi
    break
  done
  rm -f "$state_dir/$session_id.pid"
}

case "${1:-}" in
  arm) arm ;;
  watch) shift; watch "$@" ;;
esac
exit 0
