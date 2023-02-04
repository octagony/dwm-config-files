
function powermenu {
	options="Shutdown\nRestart\nExit\nSleep\nCancel"
	selected=$(echo -e $options | dmenu -c -g 1 -fn "Ubuntu Mono Nerd Font" -nb "#1e1d2d" -nf "#abe9b3" -sb "#d5aeea" -sf "#1e1d2d" -l 5 -h 54) 
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
