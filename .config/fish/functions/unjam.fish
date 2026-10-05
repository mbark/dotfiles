function unjam --description 'Kill every gopls and restart fseventsd to free memory'
    set -l gopls_pids (pgrep -x gopls)
    if test (count $gopls_pids) -gt 0
        set -l rss_mb (ps -o rss= -p (string join , $gopls_pids) | awk '{s+=$1} END {printf "%d", s/1024}')
        echo "Killing $(count $gopls_pids) gopls ($rss_mb MB resident)"
        kill $gopls_pids
    else
        echo "No gopls running"
    end

    echo "Restarting fseventsd (needs sudo)"
    sudo killall fseventsd

    sleep 2
    top -l 1 | grep -E 'PhysMem|Load'
    sysctl vm.swapusage
end
