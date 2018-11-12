FROM nvcr.io/nvidia/tensorflow:latest

ENV DISPLAY=localhost:1

COPY keyboard /etc/default/

COPY sources.list /etc/apt/
RUN apt-get update && apt-get install -y \
	xfce4 \
	xfce4-goodies \
	tightvncserver \
    && rm -rf /var/lib/apt/lists/*
