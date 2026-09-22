# Dotfiles

Dotfiles managed as a bare git repo checked out over `$HOME`.

## Installation

```sh
alias dots='/usr/bin/git --git-dir=$HOME/dotfiles/ --work-tree=$HOME'
echo "dotfiles" > $HOME/.gitignore
git clone --bare https://github.com/mbark/dotfiles $HOME/dotfiles
dots checkout
dots config --local status.showUntrackedFiles no
```

Then install Homebrew and everything it manages:

```sh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew bundle install --global
```

Neovim installs its own plugins on first launch via lazy.nvim, pinned to
`.config/nvim/lazy-lock.json`. Fish installs its plugins on first launch via
fisher, from `.config/fish/fish_plugins`.

## Remote access

SSH and mosh into this machine go through Tailscale SSH, not macOS Remote
Login, which MDM keeps disabled. Tailscale SSH only runs on the open-source
`tailscaled`, not the App Store or standalone Tailscale.app, so don't install
the app. `brew bundle` installs the `tailscale` formula; start it as root and
join with SSH on:

```sh
sudo brew services start tailscale
sudo tailscale up --ssh --hostname=<machine name>
```

The tailnet policy (admin console, not tracked here) needs an `accept` rule so
the phone can connect without a browser re-auth:

```json
"ssh": [
  {"action": "accept", "src": ["autogroup:member"], "dst": ["autogroup:self"], "users": ["<local user>"]}
]
```

Moshi on the phone connects to the machine's MagicDNS name on port 22.
Tailscale SSH ignores `~/.ssh/authorized_keys`, so no key pairing is needed.

## What is tracked

Shell (fish), git, neovim (LazyVim), VS Code, Ghostty, mise, and the small
per-tool configs under `.config`. QMK keymaps live in `.config/private/qmk`.

`status.showUntrackedFiles=no` is what makes a `$HOME` work tree usable, but
it also means drift is invisible: files already tracked can sit modified for
years without `dots status` saying anything. Run `dots status -uno` from time
to time.

## What is deliberately not tracked

- Plugin-installed files: everything under `.config/fish/conf.d` and most of
  `.config/fish/functions` belongs to fisher plugins (`pure`, `fzf`, `bass`).
  Only hand-written functions are tracked.
- Runtime state that rewrites itself: `.config/fish/fish_variables`.
- Work machine config, and anything holding a credential or a token. This
  repo is public; assume everything in it is world-readable.
