#!/bin/bash
CONF=$HOME/.config

cd "$HOME" || exit 
sudo pacman -Sy base-devel xorg-server xorg-xinit libx11 libxinerama libxft libxext libxcb xcb-util-renderutil xcb-util-image pixman dbus libconfig libglvnd pcre libev uthash xorgproto xcb-util meson ninja webkit2gtk dunst pcmanfm ranger flameshot feh brightnessctl pamixer ttf-ubuntumono-nerd firefox

if [ ! -d "$CONF" ];
then
mkdir .config
fi

cp -r dwm-config-files/{dmenu,dunst,dwm,slock,slstatus,st} "$HOME"/.config/

touch .xinitrc
echo "exec dwm" > .xinitrc

cd "$HOME"/.config/st || exit
sudo make clean install
cd "$HOME"/.config/dwm || exit
sudo make clean install
cd "$HOME"/.config/dmenu || exit
sudo make clean install
cd "$HOME"/.config/slock || exit
sudo make clean install
cd "$HOME"/.config/slstatus || exit
sudo make clean install

sudo chmod +x "$HOME"/.config/dwm/scripts/{powermenu.sh,volumenotifications.sh,brightnessnotifications.sh}

cd "$HOME" || exit
mkdir .dwm
cp "$HOME"/dwm-config-files/autostart.sh "$HOME"/.dwm/
cp -r "$HOME"/dwm-config-files/.wallpapers "$HOME"

cd "$HOME/.config"
sudo git clone https://github.com/pijulius/picom.git
cd picom/
sudo git submodule update --init --recursive
sudo meson --buildtype=release . build
sudo ninja -C build

echo "Now, just type startx"

