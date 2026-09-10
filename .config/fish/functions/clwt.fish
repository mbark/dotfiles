function clwt --description 'Create a Git worktree and start Claude'
    argparse h/help n/no-start -- $argv
    or return 2

    if set -q _flag_help
        printf 'Usage: clwt [--no-start] <worktree-name> [branch]\n'
        printf 'Creates a sibling Git worktree and starts Claude there.\n'
        return 0
    end

    if test (count $argv) -lt 1
        printf 'Usage: clwt [--no-start] <worktree-name> [branch]\n' >&2
        return 2
    end

    if not set -q _flag_no_start
        if not command -sq claude
            printf 'clwt: claude command not found\n' >&2
            return 127
        end
    end

    set -l worktree_name $argv[1]
    set -l branch $worktree_name

    if test (count $argv) -ge 2
        set branch $argv[2]
    end

    set -l repo_root (git rev-parse --show-toplevel 2>/dev/null)
    or begin
        printf 'clwt: not inside a Git repository\n' >&2
        return 1
    end

    set -l repo_name (basename "$repo_root")
    set -l safe_worktree_name (string replace -ra '[^A-Za-z0-9._-]+' '-' -- "$worktree_name")
    set -l worktree_path "$repo_root/../$repo_name-$safe_worktree_name"

    if test -e "$worktree_path"
        printf 'clwt: path already exists: %s\n' "$worktree_path" >&2
        return 1
    end

    if git -C "$repo_root" show-ref --verify --quiet "refs/heads/$branch"
        git -C "$repo_root" worktree add "$worktree_path" "$branch" >&2
    else
        git -C "$repo_root" worktree add "$worktree_path" -b "$branch" >&2
    end
    or return $status

    if test -f "$worktree_path/mise.toml"
        mise trust "$worktree_path" >&2
        or return $status
    end

    if command -sq bun
        for pkg in (git -C "$worktree_path" ls-files '*package.json')
            set -l pkg_dir (dirname "$worktree_path/$pkg")
            printf 'clwt: bun install in %s\n' "$pkg_dir" >&2
            pushd "$pkg_dir"
            or return $status
            bun install >&2
            set -l bun_status $status
            popd
            if test $bun_status -ne 0
                return $bun_status
            end
        end
    else
        printf 'clwt: bun command not found, skipping bun install\n' >&2
    end

    if set -q _flag_no_start
        printf '%s\n' "$worktree_path"
        return 0
    end

    set -l clwt_tty
    if tty -s
        set clwt_tty (tty)
    else if command true </dev/tty 2>/dev/null
        set clwt_tty /dev/tty
    end

    cd "$worktree_path"
    or return $status

    if test -n "$clwt_tty"
        claude --dangerously-skip-permissions <$clwt_tty
    else
        claude --dangerously-skip-permissions
    end
    set -l claude_status $status

    cd "$repo_root"
    or return $claude_status

    set -l changes (git -C "$worktree_path" status --porcelain)
    set -l status_status $status
    if test $status_status -ne 0
        printf 'clwt: could not inspect worktree status, leaving worktree: %s\n' "$worktree_path" >&2
        return $claude_status
    end

    if test -n "$changes"
        printf 'clwt: worktree has uncommitted changes: %s\n' "$worktree_path"
        if test -n "$clwt_tty"
            read --prompt-str "Remove dirty worktree $worktree_path and discard changes? [y/N] " answer <$clwt_tty
        else
            read --prompt-str "Remove dirty worktree $worktree_path and discard changes? [y/N] " answer
        end
        set -l answer (string lower -- (string trim -- "$answer"))
        if test "$answer" = y -o "$answer" = yes
            git -C "$repo_root" worktree remove --force "$worktree_path"
            or return $status
        else if test -n "$answer" -a "$answer" != n -a "$answer" != no
            printf 'clwt: not removing worktree; answer was not yes: %s\n' "$answer"
        end

        return $claude_status
    end

    if test -n "$clwt_tty"
        read --prompt-str "Remove worktree $worktree_path? [Y/n] " answer <$clwt_tty
    else
        read --prompt-str "Remove worktree $worktree_path? [Y/n] " answer
    end
    set -l answer (string lower -- (string trim -- "$answer"))
    if test -z "$answer" -o "$answer" = y -o "$answer" = yes
        git -C "$repo_root" worktree remove "$worktree_path"
        or return $status
    else if test "$answer" != n -a "$answer" != no
        printf 'clwt: not removing worktree; answer was not yes: %s\n' "$answer"
    end

    return $claude_status
end
