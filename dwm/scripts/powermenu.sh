#!/bin/bash

function powermenu {
	options="Shutdown\nRestart\nExit\nSleep\nCancel"
	selected=$(echo -e $options | dmenu -c -g 1 -fn "JetBrainsMono Nerd Font" -nb "#1e1d2d" -nf "#abe9b3" -sb "#d5aeea" -sf "#1e1d2d" -shb "#cba6f7" -shf "#585b70" -nhb "#1e1e2e" -nfh "#585b70" -l 5 -h 40 -p '') 
	if [[ $selected = "Shutdown" ]]; then
		systemctl poweroff
	elif [[ $selected = "Restart" ]]; then
		systemctl reboot
	elif [[ $selected = "Sleep" ]]; then
		systemctl suspend	
	elif [[ $selected = "Exit" ]]; then
		systemctl exit	
	elif [[ $selected = "Cancel" ]]; then
		return
	fi
}

powermenu
