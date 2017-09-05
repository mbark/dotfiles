function j() {
    eval "$(fasd --init auto)"
    local dir
    dir="$(fasd -Rdl "$1" | sk +m)" && cd "${dir}" || return 1
}

function fuzzy-kill() {
    local pid=$(ps -ef | sed 1d | fzf | awk '{print $2}')

    local killcode
    if [ -n "$1" ] ; then
        killcode="$1"
    else
        killcode=9
    fi

    if [ "x$pid" != "x" ]
    then
        kill -${1:-"$killcode"} $pid
    fi
}

function fuzzy-docker-clean() {
    docker images | tail -n +2 | sort | fzf -m | awk '{print $3}' | xargs -r -I % docker rmi % || true
}
