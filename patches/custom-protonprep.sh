#!/bin/bash

pushd wine
git reset --hard HEAD
git clean -xdf
git branch -D xiv-temp
git checkout -b xiv-temp
git revert --no-commit df43fd788455ed243af61ffb76102ab1ef6557e2
git commit -a -m "Revert problematic commit df43fd7"
popd

./patches/protonprep-valve-staging.sh

pushd wine

echo "WINE: -DualSense- Add PS5 Controller support"
patch -Np1 < ../patches/custom/dualsense1.patch
patch -Np1 < ../patches/custom/dualsense2.patch

echo "WINE: Add Wine-to-Unix PID mapping"
patch -Np1 < ../patches/custom/proton8-unix-pid-maps.patch

popd