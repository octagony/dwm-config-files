#!/bin/bash

function powermenu {
	options="Cancel\nShutdown\nRestart\nSleep"
	selected=$(echo -e $options | dmenu -c -nb white -nf black -sb black -sf white)
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
