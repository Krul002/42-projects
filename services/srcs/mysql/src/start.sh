#!/bin/sh
openrc default
/etc/init.d/mariadb setup
rc-service mariadb start

echo "CREATE USER 'root'@'%';" | mysql
echo "CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';" | mysql
echo "CREATE DATABASE wordpress;" | mysql
echo "GRANT ALL PRIVILEGES ON *.* TO 'admin'@'%';" | mysql
echo "FLUSH PRIVILEGES;" | mysql

mysql wordpress -u root < /wordpress.sql

rc-service mariadb stop
/usr/bin/mysqld_safe --datadir='/var/lib/mysql'