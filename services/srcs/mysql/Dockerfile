FROM alpine:3.7
 
RUN apk update && apk upgrade
RUN apk add mysql mysql-client --allow-untrusted --no-cache
RUN apk add openrc --allow-untrusted --no-cache

VOLUME [ "/var/lib/mysql" ]
VOLUME [ "/sys/fs/cgroup" ]

COPY ./src/start.sh /start.sh
COPY ./src/wordpress.sql /wordpress.sql
COPY ./src/my.cnf /etc/mysql/my.cnf

RUN chmod 744 /etc/mysql/my.cnf

EXPOSE 3306
RUN chmod +x /start.sh

CMD ./start.sh