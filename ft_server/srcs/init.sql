CREATE DATABASE my_database;
CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';
GRANT ALL PRIVILEGES ON my_database.* TO 'admin'@'localhost';
UPDATE mysql.user SET plugin='mysql_native_password' WHERE user='admin';
FLUSH PRIVILEGES;