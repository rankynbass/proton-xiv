#!/bin/bash

pushd wine

echo "WINE: Add NTSync for Valve Bleeding Edge"
patch -Np1 < ../patches/custom/proton10-ntsync.patch

popd
