FROM alpine

RUN apk update && apk upgrade
RUN apk add nginx supervisor \
		php7 php7-fpm php7-opcache php7-json php7-iconv php7-mbstring php7-gettext \
		php7-gd php7-mysqli php7-zlib php7-curl php7-session php7-phar\
		wget

RUN mkdir -p /run/nginx /run/php

COPY ./src/default.conf /etc/nginx/conf.d/default.conf
COPY ./src/supervisor.conf /etc/supervisord.conf
COPY ./src/setup.sh ./

RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-english.tar.gz
RUN tar -xf phpMyAdmin-4.9.5-english.tar.gz
RUN mv phpMyAdmin-4.9.5-english /var/www/phpmyadmin/
RUN rm -f phpMyAdmin-4.9.5-english.tar.gz
RUN mkdir /var/www/phpmyadmin/tempdir
RUN chmod 777 -R /var/www/*
COPY ./src/config.inc.php /var/www/phpmyadmin/config.inc.php
RUN chmod 755 /var/www/phpmyadmin/config.inc.php

RUN chmod +x /setup.sh

EXPOSE 5000

CMD ./setup.sh