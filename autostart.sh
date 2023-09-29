# Setup Feh
feh --bg-fill --randomize ~/.wallpapers/*

#Setup Picom
"$HOME"/.config/picom/build/src/./picom -b --animations --animation-window-mass 0.5 --animation-for-open-window zoom --animation-stiffness 500 &

#Exec slstatus
exec slstatus &

#Exec dunst
exec dunst &

#Helper for keyboard layout
setxkbmap -model pc105 -layout us,ru -option grp:alt_shift_toggle
