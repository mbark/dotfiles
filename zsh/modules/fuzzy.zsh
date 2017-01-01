function j() {
    eval "$(fasd --init auto)"
    local dir
    dir="$(fasd -Rdl "$1" | sk +m)" && cd "${dir}" || return 1
}

function pass() {
    lpass show -c --password $(lpass ls  | sk | awk '{print $(NF)}' | sed 's/\]//g')
}

function fuzzy-kill() {
    local pid=$(ps -ef | sed 1d | sk -m | awk '{print $2}')

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
