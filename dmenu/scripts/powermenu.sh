#!/bin/bash

function powermenu {
	options="Cancel\nShutdown\nRestart\nSleep"
	selected=$(echo -e $options | dmenu -c -g 2 -fn "Hack Bold Nerd Font" -nb "#1d1817" -nf "#d8d5d5" -sb "#f14f42" -sf "#fff" -l 2 -h 54  ) 
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
