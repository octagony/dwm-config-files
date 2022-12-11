# DWM Config

### Include slstatus, dmenu, st and slock

![Alt text](/img/2.png?raw=true "Title")

#### Require: 

* **Feh** for backgrounds
* **NNN** as file manager
* **dunst** as notifications manager (include config)
* **flameshot** - for screenshots
* **XF86keysym**(include), **brightnessctl** and **pamixer** for the volume and brightness control
* **[Nerd Fonts](https://www.nerdfonts.com/)** - as fonts
* **picom** - as compositor(i use fork from [pijulius](https://github.com/pijulius)) 

#### Installation

1. In `.xinitrc` file add this line 

    ```
    exec dwm
    ```

1. Create `.dwm` folder in `/home` directory
2. Put `autostart.sh` file into that folder
3. Make the `autostart.sh`, `powermenu.sh`, `volumenotifications.sh` and `brightnessnotifications.sh` executable with this command:

    ```
    sudo chmod +x {namescript}.sh
    ```

4. In config.h (or config.def.h) changes the paths to the scripts:

    ```
    "/home/{user_name}/.config/dwm/scripts/{scriptname}.sh" 
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
* **glyph-wide-support**

#### Slock Patches:
* **capscolor**
* **message**
