FROM nvcr.io/nvidia/tensorflow:19.12-tf1-py3

# local mirror for Ubuntu packages
COPY sources.list /etc/apt/
RUN DEBIAN_FRONTEND=noninteractive apt update

# packages if required to natively mount Lustre
RUN  DEBIAN_FRONTEND=noninteractive apt install -y \
	kmod libyaml-dev \
	&& apt clean

# a few utilities
RUN  DEBIAN_FRONTEND=noninteractive apt install -y \
	gfortran \
	tmux \
	ed \
	screen \
	parallel \
	&& apt clean

# OpenCV packages
RUN  DEBIAN_FRONTEND=noninteractive apt install -y \
	python3-opencv

# A VNC server and desktop
ENV DISPLAY=localhost:1
COPY keyboard /etc/default/keyboard
RUN  DEBIAN_FRONTEND=noninteractive apt install -y \
	xfce4 \
	xfce4-goodies \
	tightvncserver \
	&& apt clean

# Proxy for downloading python packages
ARG DEVPI_ARGS="--trusted-host 192.168.153.9 -i http://192.168.153.9:3141/root/pypi"
ARG PYPI_UPGRADE=""
RUN pip install $DEVPI_ARGS --no-cache-dir $PYPI_UPGRADE \
	scikit-learn \
	matplotlib \
	keras \
	Augmentor \
	pillow \
	bokeh \
	scikit-image \
	visdom

# A reverse proxy client
RUN wget -q https://github.com/fatedier/frp/releases/download/v0.20.0/frp_0.20.0_linux_amd64.tar.gz && \
	tar -C /opt -xf frp_0.20.0_linux_amd64.tar.gz && rm -f frp_0.20.0_linux_amd64.tar.gz && \
	echo 'PATH="$PATH:/opt/frp_0.20.0_linux_amd64" ; export PATH' >> /etc/bash.bashrc

# Another reverse proxy client
COPY lt.tgz /
RUN tar -C/ -zxf /lt.tgz && rm -f /lt.tgz
