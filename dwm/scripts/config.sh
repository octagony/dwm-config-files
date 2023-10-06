
#!/bin/bash

options=(
"Alacritty
Dmenu
DWM
Dunst
Fastfetch
Fish
Nvim
St
Slstatus
Tmux
Tmux Statusline")

choice=$(echo -e "${options[@]}" | dmenu -c -g 1 -fn "JetBrainsMono Nerd Font" -nb '#1e1e2d' -nf "#abe9b3" -sb "#d5aeea" -sf "#1e1d2d" -shb "#cba6f7" -shf "#585b70" -nhb "#1e1e2e" -nfh "#585b70" -l 15 -h 30 -p 'Dotfiles: ')

case "$choice" in
Alacritty)
	choice="$HOME/.config/alacritty/"
	;;
DWM)
	choice="$HOME/.config/suckless/dwm/"
	;;
Dmenu)
	choice="$HOME/.config/suckless/dmenu/"
	;;
Dunst)
	choice="$HOME/.config/dunst/"
	;;
Fastfetch)
	choice="$HOME/.config/fastfetch/"
	;;
Fish)
	choice="$HOME/.config/fish/"
	;;
Nvim)
    choice="$HOME/.config/nvim"
    ;;
St)
    choice="$HOME/.config/suckless/st/"
    ;;
Slstatus)
    choice="$HOME/.config/suckless/slstatus/"
    ;;
Tmux)
    choice="$HOME/.tmux.conf"
    ;;
'Tmux Statusline')
    choice="$HOME/.config/tmux/statusline.conf"
    ;;
*)
	exit 1
	;;
esac

st -e nvim "$choice"
