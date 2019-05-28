FROM nvcr.io/nvidia/pytorch:19.05-py3

ENV DISPLAY=localhost:1
COPY keyboard /etc/default/keyboard

RUN apt-get update && apt-get install -y apt-transport-https
COPY sources.list /etc/apt/
RUN apt-get update && apt-get clean && apt-get install -y \
	kmod libyaml-dev \
		xfce4 \
		xfce4-goodies \
		tightvncserver\
		emacs \
	less \
	vim \
	rsync \
	curl \
	wget \
	tmux \
	ed \
	git \
	zip \
	unzip \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*
### installing the following breaks python3
#	r-base-dev \
#	r-recommended \
#	mercurial \

RUN wget -q https://github.com/fatedier/frp/releases/download/v0.20.0/frp_0.20.0_linux_amd64.tar.gz && \
	tar -C /opt -xf frp_0.20.0_linux_amd64.tar.gz && rm -f frp_0.20.0_linux_amd64.tar.gz && \
	echo 'PATH="$PATH:/opt/frp_0.20.0_linux_amd64" ; export PATH' >> /etc/bash.bashrc
