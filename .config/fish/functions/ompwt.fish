function ompwt --description 'Create a Git worktree and start OMP'
    argparse h/help n/no-start -- $argv
    or return 2

    if set -q _flag_help
        printf 'Usage: ompwt [--no-start] <worktree-name> [branch]\n'
        printf 'Creates a sibling Git worktree and starts OMP there.\n'
        return 0
    end

    if test (count $argv) -lt 1
        printf 'Usage: ompwt [--no-start] <worktree-name> [branch]\n' >&2
        return 2
    end

    if not set -q _flag_no_start
        if not command -sq omp
            printf 'ompwt: omp command not found\n' >&2
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
        printf 'ompwt: not inside a Git repository\n' >&2
        return 1
    end

    set -l repo_name (basename "$repo_root")
    set -l safe_worktree_name (string replace -ra '[^A-Za-z0-9._-]+' '-' -- "$worktree_name")
    set -l worktree_path "$repo_root/../$repo_name-$safe_worktree_name"

    if test -e "$worktree_path"
        printf 'ompwt: path already exists: %s\n' "$worktree_path" >&2
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
            printf 'ompwt: bun install in %s\n' "$pkg_dir" >&2
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
        printf 'ompwt: bun command not found, skipping bun install\n' >&2
    end

    if set -q _flag_no_start
        printf '%s\n' "$worktree_path"
        return 0
    end

    cd "$worktree_path"
    or return $status

    omp
    set -l omp_status $status

    cd "$repo_root"
    or return $omp_status

    set -l changes (git -C "$worktree_path" status --porcelain)
    set -l status_status $status
    if test $status_status -ne 0
        printf 'ompwt: could not inspect worktree status, leaving worktree: %s\n' "$worktree_path" >&2
        return $omp_status
    end

    if test -n "$changes"
        printf 'ompwt: leaving worktree with uncommitted changes: %s\n' "$worktree_path"
        return $omp_status
    end

    read --prompt-str "Remove worktree $worktree_path? [Y/n] " answer
    set -l answer (string lower -- (string trim -- "$answer"))
    if test -z "$answer" -o "$answer" = y -o "$answer" = yes
        git -C "$repo_root" worktree remove "$worktree_path"
        or return $status
    else if test "$answer" != n -a "$answer" != no
        printf 'ompwt: not removing worktree; answer was not yes: %s\n' "$answer"
    end

    return $omp_status
end
