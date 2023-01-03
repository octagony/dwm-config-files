feh --bg-fill --randomize ~/.wallpapers/*
"$HOME"/.config/picom/build/src/./picom -b --animations --animation-window-mass 0.5 --animation-for-open-window zoom --animation-stiffness 500 &
exec slstatus &
exec dunst &
