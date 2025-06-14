#!/bin/bash
CONF=$HOME/.config
SUCKLESS=$HOME/suckless

cd "$HOME" || exit
sudo pacman -Sy base-devel xorg-server xorg-xinit libx11 libxinerama libxft libxext libxcb xcb-util-renderutil xcb-util-image pixman dbus libconfig libglvnd pcre libev uthash xorgproto xcb-util meson ninja webkit2gtk dunst pcmanfm flameshot feh brightnessctl pamixer ttf-ubuntu-mono-nerd ttf-jetbrains-mono playerctl imlib2

if [ ! -d "$CONF" ]; then
  mkdir .config
fi

if [ ! -d "$SUCKLESS" ]; then
  mkdir "$HOME/.config/suckless"
fi

cp -r dwm-config-files/{dmenu,dunst,dwm,slock,slstatus,st} "$HOME"/.config/suckless

touch .xinitrc
echo "exec dwm" >.xinitrc

cd "$HOME"/.config/suckless/st || exit
sudo make clean install
cd "$HOME"/.config/suckless/dwm || exit
sudo make clean install
cd "$HOME"/.config/suckless/dmenu || exit
sudo make clean install
cd "$HOME"/.config/suckless/slock || exit
sudo make clean install
cd "$HOME"/.config/suckless/slstatus || exit
sudo make clean install

sudo chmod +x "$HOME"/.config/suckless/dwm/scripts/{powermenu.sh,volumenotifications.sh,brightnessnotifications.sh,config.sh}

cd "$HOME" || exit
mkdir .dwm
cp "$HOME"/dwm-config-files/autostart.sh "$HOME"/.dwm/
cp -r "$HOME"/dwm-config-files/.wallpapers "$HOME"

cd "$HOME/.config" || exit
sudo git clone https://github.com/fdev31/picom.git
cd picom/ || exit
sudo git submodule update --init --recursive
sudo meson --buildtype=release . build
sudo ninja -C build

echo "---------------------"
echo "Now, just type 'startx'"
echo "---------------------"
