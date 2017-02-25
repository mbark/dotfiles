#!/bin/bash

# rofi-power
# Use rofi to call systemctl for shutdown, reboot, etc

# 2016 Oliver Kraitschy - http://okraits.de

OPTIONS="Lock\nLogout\nReboot system\nPower-off system\nSuspend system\nHibernate system"

LAUNCHER="rofi -dmenu -i -p rofi-power:"
USE_LOCKER="true"
LOCKER="$HOME/dotfiles/zsh/scripts/lock.sh"

option=`echo -e $OPTIONS | $LAUNCHER | awk '{print $1}' | tr -d '\r\n'`
if [ ${#option} -gt 0 ]
then
    case $option in
        Exit)
            eval $1
            ;;
        Lock)
            "$LOCKER"
            ;;
        Logout)
            i3-msg exit
            ;;
        Reboot)
            systemctl reboot
            ;;
        Power-off)
            systemctl poweroff
            ;;
        Suspend)
            $($USE_LOCKER) && "$LOCKER"; systemctl suspend
            ;;
        Hibernate)
            $($USE_LOCKER) && "$LOCKER"; systemctl hibernate
            ;;
        *)
            ;;
    esac
fi
