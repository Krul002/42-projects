NAME = server

VERSION = latest

HTTP = 80:80

HTTPS = 443:443

DOCKER = sudo docker

.PHONY: build
build:
	$(DOCKER) build -t $(NAME):$(VERSION) .

.PHONY: run
run:
	$(DOCKER) run --name $(NAME) -p $(HTTP) -p $(HTTPS) -it $(NAME):$(VERSION)

.PHONY: start
start:
	$(DOCKER) start -ai $(NAME)

.PHONY: stop
stop:
	$(DOCKER) stop $(NAME)

.PHONY: exec
exec:
	$(DOCKER) exec -it $(NAME) bash

.PHONY: rm
rm: stop
	$(DOCKER) rm $(NAME)

.PHONY: rmi
rmi:
	$(DOCKER) rmi $(NAME):$(VERSION)

	