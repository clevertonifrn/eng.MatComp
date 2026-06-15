ARG VER=daedalus
FROM devuan/devuan:${VER}
ARG VER

ENV TZ="America/Fortaleza"

ENV DEBIAN_FRONTEND=noninteractive

RUN echo 'APT::Install-Recommends "false";\nAPT::Install-Suggests "false";' >> /etc/apt/apt.conf

RUN echo "deb http://devuan.c3sl.ufpr.br/merged ${VER} main" > /etc/apt/sources.list \
 && echo "deb http://devuan.c3sl.ufpr.br/merged ${VER}-updates main" >> /etc/apt/sources.list \
 && echo "deb http://devuan.c3sl.ufpr.br/merged ${VER}-security main" >> /etc/apt/sources.list

RUN apt -y update
RUN apt -y install bash openssl curl ca-certificates
RUN apt -y install make git gcc
RUN apt -y autoremove --purge
 
RUN echo 'alias la="ls -lha --color"' >> ~/.bashrc \
 && echo 'alias lat="ls -lha --color -tr"' >> ~/.bashrc
 
#Clean up
RUN apt clean && rm -rf /var/lib/apt/lists/*