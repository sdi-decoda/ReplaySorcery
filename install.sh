#!/bin/sh

git submodule update --init
cmake -B bin -DCMAKE_BUILD_TYPE=Release && \
make -C bin && \
sudo make -C bin install
