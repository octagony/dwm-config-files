#!/bin/bash

function powermenu {
	options="Cancel\nShutdown\nRestart\nSleep"
	selected=$(echo -e $options | dmenu -c -g 2 -fn "Hack Bold Nerd Font" -nb "#1c1c1c" -nf "#f8f8f2" -sb "#f9ce74" -sf "#1c1c1c" -l 2 -h 54  ) 
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
