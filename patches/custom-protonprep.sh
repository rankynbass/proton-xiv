#!/bin/bash

./patches/protonprep-valve-staging.sh

pushd wine

echo "WINE: Add Wine-to-Unix PID mapping"
patch -Np1 < ../patches/custom/proton10-unix-pid-maps.patch

popd
