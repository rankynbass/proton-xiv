#!/bin/bash

./patches/protonprep-valve-staging.sh

pushd wine

echo "WINE: Add Wine-to-Unix PID mapping"
patch -Np1 < ../patches/custom/proton9-unix-pid-maps.patch

echo "WINE: Add winedbg patch to fix a Dalamud crash"
patch -Np1 < ../patches/custom/portable-pdb.patch

echo "WINE: Add Ping Fix"
patch -Np1 < ../patches/custom/ping-fix.patch

echo "WINE: Add DualSense patches"
patch -Np1 < ../patches/dualsense/0001-pending-review-mmdevapi-support-VT_CLSID-for-contain.patch
patch -Np1 < ../patches/dualsense/0002-pending-review-mmdevapi-decode-ContainerId-property-.patch
patch -Np1 < ../patches/dualsense/0003-pending-review-mmdevapi-copy-ContainerID-from-audio-.patch
patch -Np1 < ../patches/dualsense/0004-pending-review-mmdevapi-Invalidate-ContainerID-of-un.patch
patch -Np1 < ../patches/dualsense/0005-draft-winepulse-Store-PulseAudio-device-s-sysfs-path.patch
patch -Np1 < ../patches/dualsense/0006-draft-winepulse-Add-support-for-containerId-property.patch
patch -Np1 < ../patches/dualsense/0007-draft-winebus-store-container-sysfs-path-from-udev-b.patch
patch -Np1 < ../patches/dualsense/0008-draft-winebus-implement-BusQueryContainerID-based-on.patch
patch -Np1 < ../patches/dualsense/0009-WiP-Implement-SetupDiGetDeviceInterfacePropertyW-for.patch

popd
