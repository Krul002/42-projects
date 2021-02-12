#!/bin/bash

cmalt="/etc/nginx/sites-available/cmalt"
on="autoindex on"
off="autoindex off"

if [ "$1" == "on" ]
then
        sed -i "s/$off/$on/g" "$cmalt"
else
        sed -i "s/$on/$off/g" "$cmalt"
fi

service nginx restart
