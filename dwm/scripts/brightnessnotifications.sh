#!/bin/bash

function send_notification(){
    brightness=$(rumos -p get)
    dunstify -a "brightnessnotification" -u normal -r "9994" -h int:value:"$brightness" "Brightness: ${brightness}" -t 2000
}

case $1 in
up)
    rumos inc 5
    send_notification $1
    ;;
down)
    rumos dec 5 
    send_notification $1
    ;;
esac
