# Использовать debian OS в данном контейнере
FROM debian:buster

# Подпись
LABEL maintainer="cmalt@student.21-school.ru"

# Обновление системы и установка необходимых программ
RUN apt-get -y update && apt-get -y upgrade && \
    apt-get install -y vim nginx wget bash mariadb-server openssl wordpress && \
    apt-get -y install php7.3 php7.3-fpm php7.3-mysql php-common php-cli php-mbstring php-json && \
    mkdir -p /var/www/cmalt && chown -R www-data:www-data /var/www/cmalt

# Копирование файлов настроек в контейнер
COPY ./srcs/* ./

# Генерация ssl
RUN mkdir /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -out /etc/nginx/ssl/cmalt.crt \
    -keyout /etc/nginx/ssl/cmalt.key \
    -subj '/C=RU/ST=Kazan/L=Kazan/O=Ecole42/OU=School21/CN=cmalt' && \
    chmod -R 755 /etc/nginx/ssl/cmalt*

# Установка настроек nginx
RUN rm -Rf /etc/nginx/sites-enabled/default && \
    mv nginx.conf /etc/nginx/sites-available/cmalt && \
    ln -s /etc/nginx/sites-available/cmalt /etc/nginx/sites-enabled/ && \
    mv info.php /var/www/cmalt/

# Установка phpMyAdmin
RUN mkdir /var/www/cmalt/phpmyadmin && \
    wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-english.tar.gz && \
    tar -xzvf phpMyAdmin-4.9.5-english.tar.gz && mv phpMyAdmin-4.9.5-english/* /var/www/cmalt/phpmyadmin && \
    mv config.inc.php /var/www/cmalt/phpmyadmin && \
    rm -rf phpMyAdmin-4.9.5-english.tar.gz phpMyAdmin-5.0.2-all-languages && \
    chmod -R 755 /var/www/cmalt/phpmyadmin/config.inc.php

# Установка Wordpress
RUN mv /usr/share/wordpress /var/www/cmalt/wordpress && \
    mv wp-config.php /var/www/cmalt/wordpress

# Копирование файлов в докер
RUN mv start.sh /var/www/cmalt && mv autoindex.sh /var/www/cmalt && mv init.sql /var/www/cmalt

# Задание рабочей директории
WORKDIR /var/www/cmalt

# Создание базы данных
RUN service mysql start && mysql < init.sql

# Открытие портов
EXPOSE 80 443

# Установление инструкций при загрузке контейнера
ENTRYPOINT bash start.sh