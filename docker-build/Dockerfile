FROM nvcr.io/nvidia/tensorflow:latest-py3

COPY keyboard /etc/default/keyboard

COPY sources.list /etc/apt/
RUN	apt-get update && apt-get -y upgrade && apt-get install -y xfce4 \
	xfce4-goodies \
	tightvncserver \
    	wget && rm -rf /var/lib/apt/lists/*

ARG DEVPI_ARGS="--trusted-host 192.168.160.16 -i http://192.168.160.16:3141/root/pypi"

RUN pip install $DEVPI_ARGS --upgrade pip && pip install $DEVPI_ARGS -U scikit-learn
