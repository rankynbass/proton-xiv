#!/bin/bash

pushd wine

echo "WINE: Add Wine-to-Unix PID mapping"
patch -Np1 < ../patches/custom/proton9-unix-pid-maps.patch

echo "WINE: Add Ping Fix"
patch -Np1 < ../patches/custom/ping-fix.patch

echo "WINE: Add DualSense patches"
patch -Np1 < ../patches/custom/dualsense1.patch
patch -Np1 < ../patches/custom/dualsense2.patch

popd
