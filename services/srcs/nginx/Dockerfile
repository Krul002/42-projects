FROM alpine

RUN apk update && apk upgrade
RUN apk add nginx openssl openssh supervisor

COPY ./src/start_nginx.sh /tmp/
COPY ./src/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./src/supervisord.conf /etc/supervisord.conf

RUN openssl req -x509 -nodes -days 90 -newkey rsa:2048 \
-out /etc/ssl/certs/cmalt.crt \
-keyout /etc/ssl/certs/cmalt.key \
-subj '/C=RU/ST=Kazan/L=Kazan/O=Ecole42/OU=School21/CN=localhost' && \
chmod -R 755 /etc/ssl/certs/cmalt*

RUN sed -i s/#PermitRootLogin.*/PermitRootLogin\ yes/ /etc/ssh/sshd_config \
    && echo "root:root" | chpasswd

RUN sed -ie 's/#Port 22/Port 22/g' /etc/ssh/sshd_config && \
    sed -ri 's/#HostKey \/etc\/ssh\/ssh_host_key/HostKey \/etc\/ssh\/ssh_host_key/g' /etc/ssh/sshd_config && \
    sed -ir 's/#HostKey \/etc\/ssh\/ssh_host_rsa_key/HostKey \/etc\/ssh\/ssh_host_rsa_key/g' /etc/ssh/sshd_config && \
    sed -ir 's/#HostKey \/etc\/ssh\/ssh_host_dsa_key/HostKey \/etc\/ssh\/ssh_host_dsa_key/g' /etc/ssh/sshd_config && \
    sed -ir 's/#HostKey \/etc\/ssh\/ssh_host_ecdsa_key/HostKey \/etc\/ssh\/ssh_host_ecdsa_key/g' /etc/ssh/sshd_config && \
    sed -ir 's/#HostKey \/etc\/ssh\/ssh_host_ed25519_key/HostKey \/etc\/ssh\/ssh_host_ed25519_key/g' /etc/ssh/sshd_config && \
    /usr/bin/ssh-keygen -A && \
    ssh-keygen -t rsa -b 4096 -f  /etc/ssh/ssh_host_key

EXPOSE 22 80 443

RUN chmod +x /tmp/start_nginx.sh
RUN mkdir -p /run/nginx

CMD /tmp/start_nginx.sh