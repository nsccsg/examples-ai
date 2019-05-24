FROM nvcr.io/nvidia/tensorflow:19.05-py3

ENV DISPLAY=localhost:1
COPY keyboard /etc/default/keyboard

RUN apt-get update && apt-get install -y apt-transport-https
COPY sources.list /etc/apt/
RUN apt-get update && apt-get clean && apt-get install -y \
	kmod libyaml-dev \
	libopencv-calib3d2.4v5 \
	libopencv-contrib2.4v5 \
	libopencv-core2.4v5 \
	libopencv-features2d2.4v5 \
	libopencv-flann2.4v5 \
	libopencv-gpu2.4v5 \
	libopencv-highgui2.4v5 \
	libopencv-imgproc2.4v5 \
	libopencv-legacy2.4v5 \
	libopencv-ml2.4v5 \
	libopencv-objdetect2.4v5 \
	libopencv-ocl2.4v5 \
	libopencv-photo2.4v5 \
	libopencv-stitching2.4v5 \
	libopencv-superres2.4v5 \
	libopencv-ts2.4v5 \
	libopencv-video2.4v5 \
	libopencv-videostab2.4v5 \
		xfce4 \
		xfce4-goodies \
		tightvncserver\
	less \
	vim \
	emacs \
	rsync \
	curl \
	wget \
	tmux \
	ed \
	git \
	zip \
	unzip
#    && apt-get clean \
#    && rm -rf /var/lib/apt/lists/*
### installing the following breaks python3
#	r-base-dev \
#	r-recommended \
#	mercurial \

## Proxy for downloaded packages
ARG DEVPI_ARGS="--trusted-host 192.168.160.16 -i http://192.168.160.16:3141/root/pypi"
## Upgrade or keep the installed version?
ARG PYPI_UPGRADE=""
#ARG PYPI_UPGRADE="-U"
RUN pip install $DEVPI_ARGS --no-cache-dir --upgrade pip && pip install $DEVPI_ARGS --no-cache-dir $PYPI_UPGRADE \
	scikit-learn \
	matplotlib \
	keras \
	Augmentor \
	opencv-python \
	pillow \
	bokeh \
	scikit-image \
	visdom

RUN wget -q https://github.com/fatedier/frp/releases/download/v0.20.0/frp_0.20.0_linux_amd64.tar.gz && \
	tar -C /opt -xf frp_0.20.0_linux_amd64.tar.gz && rm -f frp_0.20.0_linux_amd64.tar.gz && \
	echo 'PATH="$PATH:/opt/frp_0.20.0_linux_amd64" ; export PATH' >> /etc/bash.bashrc
