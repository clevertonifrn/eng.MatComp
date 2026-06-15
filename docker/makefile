bn=devgcc

D=sudo docker
build:
	$(D) build -t $(bn) -f Dockerfile .

run:
	$(D) run -it $(bn) /bin/bash

clean:
	$(D) rmi $(shell sudo docker images --filter=reference="$(bn)" -q)

gccVer:
	$(D) run -it $(bn) gcc --version