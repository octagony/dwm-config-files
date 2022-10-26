#!/bin/bash

function send_notification(){
    brightness=$(brightnessctl -m | grep -oP '\d+(?=%)')
    dunstify -a "brightnessnotification" -u low -r "9994" -h int:value:"$brightness" "Brightness:${brightness}%" -t 2000
}

case $1 in
up)
    brightnessctl set +10%
    send_notification $1
    ;;
down)
    brightnessctl set 10%-
    send_notification $1
    ;;
esac
