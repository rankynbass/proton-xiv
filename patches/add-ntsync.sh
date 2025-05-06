#!/bin/bash

pushd wine

echo "WINE: Add NTSync for Valve Wine 10"
patch -Np1 < ../patches/custom/proton10-ntsync.patch

popd
