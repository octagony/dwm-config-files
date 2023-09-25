# Arch ❤️ DWM

### All in one suckless tools(dwm, dmenu, st, slstatus, slock)

![Alt text](/img/s1.png?raw=true "First image")
![Alt text](/img/s2.png?raw=true "Second image")
![Alt text](/img/s3.png?raw=true "Third image")

#### What i use:

- **Feh** as wallpapers manager
- **dunst** as notifications manager (include config)
- **flameshot** for screenshots
- **brightnessctl** and **pamixer** for volume and brightness control
- **playerctl** for multimedia control
- **[Ubuntu Mono Nerd Font](https://archlinux.org/packages/community/any/ttf-ubuntumono-nerd/)** & **[JetBrainsMono Font](https://archlinux.org/packages/community/any/ttf-jetbrains-mono/)** - as fonts
- **picom** - as compositor(i use fork from [pijulius](https://github.com/pijulius))

#### Installation

1.  Install `git`

    ```
    sudo pacman -Sy git
    ```

2.  Copy this repository to home folder

    ```
    cd $HOME
    sudo git clone https://github.com/octagony/dwm-config-files.git
    ```

3.  Make `script.sh` executable and run it

    ```
    sudo chmod +x script.sh
    ./script.sh
    ```

4.  **(Optional)** By default, script does not check for `.desktop` files in `xsessions` folder. If you use display manager(like sddm or others), add `dwm.desktop` file in `xsessions` folder with following content:

    ```
    [Desktop Entry]
    Name=DWM
    Comment=Dynamic Window Manager
    Exec=dwm
    Type=Application
    ```

#### Feh directory (for backgrounds):

```
/home/{user_name}/.wallpapers
```

#### DWM Patches:

- **alwayscenter**
- **attachbottom**
- **autostart**
- **pertag**
- **preserveonrestart**
- **restartsig**
- **rotatestack**
- **stairs**
- **status2d**
- **status2d-systray**
- **titlecolor**
- **vanitygaps**
- **winicon**

#### DMenu Patches:

- **border**
- **caseinsensitive**
- **center**
- **fuzzyhighlight**
- **grid**
- **lineheight**

#### St Patches:

- **alpha**
- **font2**
- **glyph-wide-support**
- **scrollback-mouse**

#### Slock Patches:

- **capscolor**
- **message**
