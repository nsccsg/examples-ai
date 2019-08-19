#!/bin/bash
nvidia-smi | sed -e "s/^/$OMPI_COMM_WORLD_RANK $HOSTNAME /"
exit 0
