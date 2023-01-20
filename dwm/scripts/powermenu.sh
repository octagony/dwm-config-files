#!/bin/bash

function powermenu {
	options="Cancel\nShutdown\nRestart\nSleep"
	selected=$(echo -e $options | dmenu -c -g 2 -fn "Ubuntu Mono Nerd Font" -nb "#1e1d2d" -nf "#abe9b3" -sb "#d5aeea" -sf "#1e1d2d" -l 2 -h 54  ) 
	if [[ $selected = "Shutdown" ]]; then
		poweroff
	elif [[ $selected = "Restart" ]]; then
		reboot
	elif [[ $selected = "Sleep" ]]; then
		systemctl suspend	
	elif [[ $selected = "Cancel" ]]; then
		return
	fi
}

powermenu
