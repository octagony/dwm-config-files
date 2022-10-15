# DWM Config

### Include slstatus, dmenu, st

#### Require: 

* **Feh** for backgrounds
* **NNN** as file manager
* **flameshot** - for screenshots
* **XF86keysym**(include), **brightnessctl** and **pulseaudio(pactl)** for the volume and brightness control
* **Ubuntu Mono Nerd Font** - for fonts
* **picom** - as compositor(i use fork from [pijulius](https://github.com/pijulius)) 

#### Installation

1. In `.xinitrc` file add this line 
    ```
    exec dwm
    ```
1. Create `.dwm` folder in `/home` directory
2. Put `autostart.sh` file into that folder
3. Make the `autostart.sh` executable with this command
    ```
    sudo chmod +x autostart.sh
    ```

#### Feh directory (for backgrounds):
```
/home/{user_name}/Downloads/wallpapers
```

#### DWM Patches:
* **alwayscenter**
* **activetagindicatorbar**
* **attachbottom**
* **autostart**
* **pertag**
* **preserveonrestart**
* **restartsig**
* **statuspadding**
* **fullgaps**

#### DMenu Patches:
* **caseinsensitive**
* **lineheight**
* **fuzzyhighlight**
* **center**
* **border**
* **grid**

#### St Patches:
* **alpha**
* **scrollback**
* **scrollback-mouse**
