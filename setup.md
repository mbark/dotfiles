# Setting up a new Mac

Run these in order, in Terminal. Use the same username as the old Mac, because
some config contains the full home path. Paste one block at a time.

## 1. Developer tools

Wait for the installer to finish before continuing.

```sh
xcode-select --install
```

## 2. Dotfiles

```sh
cd ~
alias dots='/usr/bin/git --git-dir=$HOME/dotfiles/ --work-tree=$HOME'
git clone --bare https://github.com/mbark/dotfiles dotfiles
dots checkout
dots config --local status.showUntrackedFiles no
```

## 3. Private files

Secrets and local state are not in this repo. They move in encrypted archives,
copied to `~/Downloads` on the new Mac. Do this before opening fish for the
first time. Each archive asks for its passphrase.

```sh
cd ~/Downloads
openssl enc -d -aes-256-cbc -pbkdf2 -in migration.tar.gz.enc | tar -xzpf - -C ~
find ~/.local/share/atuin \( -name '*-wal' -o -name '*-shm' \) -delete 2>/dev/null
openssl enc -d -aes-256-cbc -pbkdf2 -in migration-2.tar.gz.enc | tar -xzpf - -C ~
cd ~
```

## 4. Homebrew and packages

The last command takes a while. If it reports failures, fix those before
moving on.

```sh
u=https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh
/bin/bash -c "$(curl -fsSL $u)"
eval "$(/opt/homebrew/bin/brew shellenv)"
brew bundle install --global
```

## 5. Fish

```sh
echo /opt/homebrew/bin/fish | sudo tee -a /etc/shells
chsh -s /opt/homebrew/bin/fish
```

Open a new terminal window, which now runs fish. The first launch installs
fisher and prints its help text. Then install the plugins:

```fish
fisher update
```

## 6. Tools and services

```fish
mise install
curl -fsSL https://claude.ai/install.sh | bash
wt config shell install
herdr --skill > ~/.agents/skills/herdr/SKILL.md
herdr integration install claude
brew services start moshi-hook
brew services start postgresql@14
```

## 7. macOS settings

Log out and back in afterwards so key repeat applies.

```fish
defaults write -g KeyRepeat -int 5
defaults write -g InitialKeyRepeat -int 25
defaults write com.apple.dock autohide -bool true
killall Dock
```

## 8. Logins

Keychain items and login sessions do not transfer.

```fish
op signin
gh auth login
docker login
aws sso login
stripe login
tcld login
terraform login
argocd login <server>
secrun --set-token
security add-generic-password -a "$USER" -s linear-api-key -w
```

Log in to the Coralogix CLI (`cx`) too if you use it.

## 9. Remaining by hand

- Set up Tailscale using the Remote access section of `README.md`.
- Import your Raycast settings, exported from its Advanced settings.
- Install App Store apps: Xcode, Things, Magnet, Excel, Outlook, PowerPoint and
  Steam Link.
- Install YubiKey Manager, which is not available through Homebrew.
- In Claude Code, run `/plugin` and confirm `claude-security`, `figma`,
  `worktrunk` and `gopls-capped` are enabled.
- Clone the repos you need into `~/repos`.

For the keyboard, this clones QMK and links the keymaps:

```fish
mkdir -p ~/repos
~/.config/private/qmk/symlink.sh
```

## 10. Clean up

Once everything works, delete the archives from both Macs. They contain private
keys and credentials.

```fish
rm ~/Downloads/migration.tar.gz.enc ~/Downloads/migration-2.tar.gz.enc
```
