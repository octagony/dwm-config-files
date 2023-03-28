#!/bin/bash


run_term="st -e nvim"
config_path="$HOME/.config"

config ()
{
    options="Alacritty\nFastfetch\nFish\nNvim\nDWM\nSt\nSlstatus\nDmenu\nTmux Main\nTmux Statusline" 
    selected=$(echo -e $options | dmenu -c -g 1 -fn "JetBrainsMono Nerd Font" -nb '#1e1e2d' -nf "#abe9b3" -sb "#d5aeea" -sf "#1e1d2d" -shb "#cba6f7" -shf "#585b70" -nhb "#1e1e2e" -nfh "#585b70" -l 15 -h 30 -p '')
     if [[ $selected = "Alacritty" ]]; then
        $run_term "$config_path/alacritty/alacritty.yml"
     elif [[ $selected = "Fastfetch" ]]; then
        $run_term "$config_path/fastfetch/config.conf"
     elif [[ $selected = "Fish" ]]; then
        cd "$config_path/fish"
        $run_term "$config_path/fish/config.fish"
     elif [[ $selected = "Nvim" ]]; then
        cd "$config_path/nvim"
        $run_term "$config_path/nvim/init.lua"
     elif [[ $selected = "DWM" ]]; then
        cd "$config_path/suckless/dwm"
        $run_term "$config_path/suckless/dwm/config.def.h"
     elif [[ $selected = "St" ]]; then
        cd "$config_path/suckless/st"
        $run_term "$config_path/suckless/st/config.def.h"
     elif [[ $selected = "Slstatus" ]]; then
        cd "$config_path/suckless/slstatus"
        $run_term "$config_path/suckless/slstatus/config.def.h"
     elif [[ $selected = "Dmenu" ]]; then
        cd "$config_path/suckless/dmenu"
        $run_term "$config_path/suckless/dmenu/config.def.h"
     elif [[ $selected = "Tmux Main" ]]; then
        $run_term "$HOME/.tmux.conf"
     elif [[ $selected = "Tmux Statusline" ]]; then
        $run_term "$config_path/tmux/statusline.conf"
     fi
}


config
