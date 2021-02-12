minikube --vm-driver=virtualbox start
minikube dashboard &
minikube addons enable metallb
kubectl apply -f ./srcs/metallb.yaml
eval $(minikube docker-env);
docker build -t nginx_image ./srcs/nginx
docker build -t phpmyadmin_image ./srcs/phpmyadmin
docker build -t wordpress_image ./srcs/wordpress
docker build -t mysql_image ./srcs/mysql
docker build -t grafana_image ./srcs/grafana
docker build -t influxdb_image ./srcs/influxdb
docker build -t ftps_image ./srcs/ftps
kubectl apply -f ./srcs/nginx.yaml
kubectl apply -f ./srcs/phpmyadmin.yaml
kubectl apply -f ./srcs/wordpress.yaml
kubectl apply -f ./srcs/volumes.yaml
kubectl apply -f ./srcs/mysql.yaml
kubectl apply -f ./srcs/grafana.yaml
kubectl apply -f ./srcs/influxdb.yaml
kubectl apply -f ./srcs/ftps.yaml