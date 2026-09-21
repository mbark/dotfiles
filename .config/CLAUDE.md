# Dotfiles

Config here (and a few files elsewhere in `$HOME`) is versioned with a bare
git repo at `~/dotfiles`, work tree `$HOME`, pushed to
`github.com/mbark/dotfiles` on `master`. See `~/README.md` for the full story.

## Running `dots` from Claude

`dots` is a fish function, so it doesn't exist in the Bash tool's shell. Use
the full command, and pass `-C ~` so paths resolve from `$HOME` no matter the
cwd (otherwise `ls-files` and friends print paths relative to `.config`):

```sh
/usr/bin/git -C ~ --git-dir=$HOME/dotfiles --work-tree=$HOME <args>
```

Paths in `add`, `rm` etc. are then relative to `$HOME`, e.g. `.config/ghostty/config`.

## The repo is public

Everything committed is world-readable. Before adding a file, read it and
check for tokens, API keys, hostnames, emails, or work-specific config. If a
tool mixes config and secrets, don't track it; say so instead. Known
never-track: `.claude/settings.json`, `.config/fish/fish_variables`,
`.config/worktrunk/approvals.toml`, anything under `op/`, `1Password/`, `gh/hosts.yml`,
`configstore/`, `github-copilot/`, `tcld/`, `temporalio/`.

Things that stay local go in `~/.gitignore` (itself tracked) with a short
comment saying why.

## Untracked files are invisible

`status.showUntrackedFiles=no` is set, so `dots status` only reports tracked
files. A new config file must be added explicitly with `dots add <path>`.
To see whether a path is tracked: `dots ls-files <path>`.

Only track hand-written config. Plugin-installed files (fisher's `pure`,
`fzf`, `bass` functions under `.config/fish/functions` and `conf.d`) and
runtime state stay out.

## Workflow for a config change

1. Make the change to the real file in place.
2. `dots status` and `dots diff` to see everything that's dirty. Other tracked
   files are often already modified (drift) — commit only the files that
   belong to this change; mention the rest to the user rather than sweeping
   them in.
3. `dots add <specific paths>` — never `add -A` or `add .` over `$HOME`.
4. Commit with a message in the existing style: one sentence, imperative,
   saying why (e.g. "Track md_slack.rb, which config.fish already aliases").
5. Ask before `dots push` unless the user already said to push.

## Layout notes

- Fish: `fish/config.fish`, `fish/fish_plugins` (fisher), hand-written
  functions in `fish/functions/`.
- Neovim is LazyVim; plugins pinned in `nvim/lazy-lock.json`.
- Homebrew packages live in `~/.Brewfile` (`brew bundle dump --global --force`
  to regenerate from what's installed).
- QMK keymaps in `private/qmk/`.
- VS Code settings are tracked under `~/Library/Application Support/Code/User/`.
