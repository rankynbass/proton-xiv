#!/bin/bash

pushd wine

echo "WINE: Add Wine-to-Unix PID mapping"
patch -Np1 < ../patches/custom/proton9-unix-pid-maps.patch

echo "WINE: Add Ping Fix"
patch -Np1 < ../patches/custom/ping-fix.patch

popd
