#!/bin/bash

./patches/protonprep-valve-staging.sh

pushd wine

echo "WINE: -DualSense- Add PS5 Controller support"
patch -Np1 < ../patches/custom/dualsense1.patch
patch -Np1 < ../patches/custom/dualsense2.patch

echo "WINE: Add Wine-to-Unix PID mapping"
patch -Np1 < ../patches/custom/proton9-unix-pid-maps.patch

echo "WINE: Add Ping Fix"
patch -Np1 < ../patches/custom/ping-fix.patch

popd