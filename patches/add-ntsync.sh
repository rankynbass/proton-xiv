#!/bin/bash

pushd wine

echo "WINE: Add NTSync for Valve Bleeding Edge"
patch -Np1 < ../patches/custom/ntsync-valvexbe.patch

popd
