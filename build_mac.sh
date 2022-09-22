#!/bin/sh

# ensure the PATH includes cmake
PATH=/usr/local/bin:$PATH

cmake -S . -B build_mac  -G "Xcode" $@ 