#!/bin/bash

pushd wine
git reset --hard HEAD
git clean -xdf
git branch -D xiv-temp
git checkout -b xiv-temp
git revert --no-commit 97688ca3cfdd6e5ea6f51e9eda0716d1946aae31
git commit -a -m "Revert problematic commit df43fd7"
popd

./patches/protonprep-valve-staging.sh

pushd wine

echo "WINE: -DualSense- Add PS5 Controller support"
patch -Np1 < ../patches/custom/dualsense1.patch
patch -Np1 < ../patches/custom/dualsense2.patch

echo "WINE: Add Wine-to-Unix PID mapping"
patch -Np1 < ../patches/custom/proton9-unix-pid-maps.patch

echo "WINE: Add Ping Fix"
patch -Np1 < ../patches/custom/ping-fix.patch

echo "WINE: Add Hide Wine Exports"
patch -Np1 < ../patches/custom/add-hide-wine-exports-to-mainline.patch

popd
