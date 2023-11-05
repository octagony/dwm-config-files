#!/bin/sh

options=(
" DuckDuckGo
 Github
 Youtube
 Piped
 Trello
 Simplenote
󰊿 DeepL
 Reddit")

choice=$(echo -e "${options[@]}" | dmenu -c -g 1 -fn "JetBrainsMono Nerd Font" -nb '#1e1e2d' -nf "#abe9b3" -sb "#d5aeea" -sf "#1e1d2d" -shb "#cba6f7" -shf "#585b70" -nhb "#1e1e2e" -nfh "#585b70" -l 15 -h 30 -p 'Bookmarks: ')

case "$choice" in
" DuckDuckGo")
    choice="https://duckduckgo.com/"
    ;;
" Github")
    choice="https://github.com/"
    ;;
" Youtube")
    choice="https://youtube.com/"
    ;;
" Trello")
    choice="https://trello.com/"
    ;;
" Simplenote")
    choice="https://app.simplenote.com/"
    ;;
"󰊿 DeepL")
    choice="https://www.deepl.com/translator"
    ;;
" Piped")
    choice="https://piped.garudalinux.org/"
    ;;
" Reddit")
    choice="https://www.reddit.com/"
    ;;
*)
	exit 1
	;;
esac

thorium-browser "$choice"
