#!/bin/bash

groupmod -g "$HOST_GID" ubuntu
usermod -u "$HOST_UID" -g "$HOST_GID" ubuntu
chown -R "$HOST_UID:$HOST_GID" /home/ubuntu

exec runuser -u ubuntu -- "$@"
