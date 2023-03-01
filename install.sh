#!/bin/sh

sudo apt install libx11-xcb-dev openbox

git submodule update --init
cmake -B bin -DCMAKE_BUILD_TYPE=Release && \
make -C bin && \
sudo make -C bin install
