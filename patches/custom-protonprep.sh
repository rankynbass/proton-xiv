#!/bin/bash

./patches/protonprep-valve-staging.sh

pushd wine

echo "WINE: Add Wine-to-Unix PID mapping"
patch -Np1 < ../patches/custom/proton10-unix-pid-maps.patch

echo "WINE: Add winedbg patch to fix a Dalamud crash"
patch -Np1 < ../patches/custom/portable-pdb.patch

popd
