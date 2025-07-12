#!/bin/bash

# patch functions
apply_patch() {
    local patch_path="$1"
    patch -Np1 < "$patch_path"
}

apply_all_in_dir() {
    local dir="$1"
    for patch in "$dir"/*.patch; do
        apply_patch "$patch"
    done
}

### (1) PREP SECTION ###

    pushd dxvk
    git reset --hard HEAD
    git clean -xdf
    popd

    pushd vkd3d-proton
    git reset --hard HEAD
    git clean -xdf
    popd

    pushd dxvk-nvapi
    git reset --hard HEAD
    git clean -xdf
    popd

    pushd gstreamer
    git reset --hard HEAD
    git clean -xdf
    echo "GSTREAMER: fix for unclosable invisible wayland opengl windows in taskbar"
    apply_all_in_dir "../patches/gstreamer/"
    popd

    pushd protonfixes
    git reset --hard HEAD
    git clean -xdf
    pushd subprojects
    pushd libmspack
    git reset --hard HEAD
    git clean -xdf
    popd
    pushd umu-database
    git reset --hard HEAD
    git clean -xdf
    popd
    pushd unzip
    git reset --hard HEAD
    git clean -xdf
    popd
    pushd winetricks
    git reset --hard HEAD
    git clean -xdf
    echo "WINETRICKS: fix broken gnutls when fetching https"
    apply_patch "../../../patches/winetricks/winetrick_gnutls_fix.patch"
    popd
    popd
    popd

### END PREP SECTION ###

### (2) WINE PATCHING ###

    pushd wine
    git reset --hard HEAD
    git clean -xdf

### (2-1) PROBLEMATIC COMMIT REVERT SECTION ###

# Bring back configure files. Staging uses them to regenerate fresh ones
# https://github.com/ValveSoftware/wine/commit/e813ca5771658b00875924ab88d525322e50d39f

    git revert --no-commit e813ca5771658b00875924ab88d525322e50d39f

### END PROBLEMATIC COMMIT REVERT SECTION ###


### (2-2) WINE STAGING APPLY SECTION ###

    echo "WINE: -STAGING- applying staging patches"

    ../wine-staging/staging/patchinstall.py DESTDIR="." --all --no-autoconf\
    -W winex11-_NET_ACTIVE_WINDOW \
    -W winex11-WM_WINDOWPOSCHANGING \
    -W user32-alttab-focus \
    -W winex11-MWM_Decorations \
    -W server-Signal_Thread \
    -W ntdll-Junction_Points \
    -W server-Stored_ACLs \
    -W server-File_Permissions \
    -W kernel32-CopyFileEx \
    -W shell32-Progress_Dialog \
    -W shell32-ACE_Viewer \
    -W dbghelp-Debug_Symbols \
    -W ntdll-Syscall_Emulation \
    -W eventfd_synchronization \
    -W server-PeekMessage \
    -W server-Realtime_Priority \
    -W msxml3-FreeThreadedXMLHTTP60 \
    -W ntdll-ForceBottomUpAlloc \
    -W ntdll-NtDevicePath \
    -W ntdll_reg_flush \
    -W user32-rawinput-mouse \
    -W user32-recursive-activation \
    -W d3dx11_43-D3DX11CreateTextureFromMemory \
    -W d3dx9_36-D3DXStubs \
    -W wined3d-zero-inf-shaders \
    -W ntdll-RtlQueryPackageIdentity \
    -W loader-KeyboardLayouts \
    -W ntdll-Hide_Wine_Exports \
    -W kernel32-Debugger \
    -W ntdll-ext4-case-folder \
    -W user32-FlashWindowEx \
    -W winex11-Fixed-scancodes \
    -W winex11-Window_Style \
    -W winex11-ime-check-thread-data \
    -W winex11.drv-Query_server_position \
    -W wininet-Cleanup \
    -W cryptext-CryptExtOpenCER \
    -W wineboot-ProxySettings \
    -W version-VerQueryValue \
    -W setupapi-DiskSpaceList

    # NOTE: Some patches are applied manually because they -do- apply, just not cleanly, ie with patch fuzz.
    # A detailed list of why the above patches are disabled is listed below:

    # winex11-_NET_ACTIVE_WINDOW - Causes origin to freeze
    # winex11-WM_WINDOWPOSCHANGING - Causes origin to freeze
    # user32-alttab-focus - relies on winex11-_NET_ACTIVE_WINDOW -- may be able to be added now that EA Desktop has replaced origin?
    # winex11-MWM_Decorations - not compatible with fullscreen hack
    # server-Signal_Thread - breaks steamclient for some games -- notably DBFZ
    # ntdll-Junction_Points - breaks CEG drm
    # server-Stored_ACLs - requires ntdll-Junction_Points
    # server-File_Permissions - requires ntdll-Junction_Pointsv
    # kernel32-CopyFileEx - breaks various installers
    # shell32-Progress_Dialog - relies on kernel32-CopyFileEx
    # shell32-ACE_Viewer - adds a UI tab, not needed, relies on kernel32-CopyFileEx
    # dbghelp-Debug_Symbols - Ubisoft Connect games (3/3 I had installed and could test) will crash inside pe_load_debug_info function with this enabled

    # ntdll-Syscall_Emulation - already applied
    # eventfd_synchronization - already applied
    # server-PeekMessage - already applied
    # server-Realtime_Priority - already applied
    # msxml3-FreeThreadedXMLHTTP60 - already applied
    # ntdll-ForceBottomUpAlloc - already applied
    # ntdll-NtDevicePath - already applied
    # ntdll_reg_flush - already applied
    # user32-rawinput-mouse - already applied
    # user32-recursive-activation - already applied
    # d3dx11_43-D3DX11CreateTextureFromMemory - already applied
    # d3dx9_36-D3DXStubs - already applied
    # wined3d-zero-inf-shaders - already applied
    # ntdll-RtlQueryPackageIdentity - already applied
    # version-VerQueryValue - just a test and doesn't apply cleanly. not relevant for gaming

    # applied manually:
    # ** loader-KeyboardLayouts - note -- always use and/or rebase this --  needed to prevent Overwatch huge FPS drop
    # ntdll-Hide_Wine_Exports
    # kernel32-Debugger
    # ntdll-ext4-case-folder
    # user32-FlashWindowEx
    # winex11-Fixed-scancodes
    # winex11-Window_Style
    # winex11-ime-check-thread-data
    # winex11.drv-Query_server_position
    # wininet-Cleanup

    # rebase and applied manually:
    # ** loader-KeyboardLayouts - note -- always use and/or rebase this --  needed to prevent Overwatch huge FPS drop
    # cryptext-CryptExtOpenCER
    # wineboot-ProxySettings

    # dinput-joy-mappings - disabled in favor of proton's gamepad patches -- currently also disabled in upstream staging
    # mfplat-streaming-support -- interferes with proton's mfplat -- currently also disabled in upstream staging
    # wined3d-SWVP-shaders -- interferes with proton's wined3d -- currently also disabled in upstream staging
    # wined3d-Indexed_Vertex_Blending -- interferes with proton's wined3d -- currently also disabled in upstream staging
    # setupapi-DiskSpaceList -- upstream commits were brought in for dualsense fixes, the staging patches are no longer needed

    echo "WINE: -STAGING- loader-KeyboardLayouts manually applied"
    apply_all_in_dir "../wine-staging/patches/loader-KeyboardLayouts/"

    echo "WINE: -STAGING- ntdll-Hide_Wine_Exports manually applied"
    apply_all_in_dir "../wine-staging/patches/ntdll-Hide_Wine_Exports/"

    echo "WINE: -STAGING- kernel32-Debugger manually applied"
    apply_all_in_dir "../wine-staging/patches/kernel32-Debugger/"

    echo "WINE: -STAGING- ntdll-ext4-case-folder manually applied"
    apply_all_in_dir "../wine-staging/patches/ntdll-ext4-case-folder/"

    echo "WINE: -STAGING- user32-FlashWindowEx manually applied"
    apply_all_in_dir "../wine-staging/patches/user32-FlashWindowEx/"

    echo "WINE: -STAGING- winex11-Fixed-scancodes manually applied"
    apply_all_in_dir "../wine-staging/patches/winex11-Fixed-scancodes/"

    echo "WINE: -STAGING- winex11-Window_Style manually applied"
    apply_all_in_dir "../wine-staging/patches/winex11-Window_Style/"

    echo "WINE: -STAGING- winex11-ime-check-thread-data manually applied"
    apply_all_in_dir "../wine-staging/patches/winex11-ime-check-thread-data/"

    echo "WINE: -STAGING- winex11.drv-Query_server_position manually applied"
    apply_all_in_dir "../wine-staging/patches/winex11.drv-Query_server_position/"

    echo "WINE: -STAGING- wininet-Cleanup manually applied"
    apply_all_in_dir "../wine-staging/patches/wininet-Cleanup/"

    echo "WINE: -STAGING- cryptext-CryptExtOpenCER manually applied"
    apply_all_in_dir "../patches/wine-hotfixes/staging/cryptext-CryptExtOpenCER/"

    echo "WINE: -STAGING- wineboot-ProxySettings manually applied"
    apply_all_in_dir "../patches/wine-hotfixes/staging/wineboot-ProxySettings/"


### END WINE STAGING APPLY SECTION ###

### (2-3) GAME PATCH SECTION ###

    echo "WINE: -GAME FIXES- assetto corsa hud fix"
    apply_patch "../patches/game-patches/assettocorsa-hud.patch"

    echo "WINE: -GAME FIXES- add file search workaround hack for Phantasy Star Online 2 (WINE_NO_OPEN_FILE_SEARCH)"
    apply_patch "../patches/game-patches/pso2_hack.patch"

    echo "WINE: -GAME FIXES- add set current directory workaround for Vanguard Saga of Heroes"
    apply_patch "../patches/game-patches/vgsoh.patch"

    echo "WINE: -GAME FIXES- add xinput support to Dragon Age Inquisition"
    apply_patch "../patches/game-patches/dai_xinput.patch"

### END GAME PATCH SECTION ###

### (2-4) WINE HOTFIX/BACKPORT SECTION ###

### END WINE HOTFIX/BACKPORT SECTION ###

### (2-5) WINE PENDING UPSTREAM SECTION ###

    # https://github.com/Frogging-Family/wine-tkg-git/commit/ca0daac62037be72ae5dd7bf87c705c989eba2cb
    echo "WINE: -PENDING- unity crash hotfix"
    apply_patch "../patches/wine-hotfixes/pending/unity_crash_hotfix.patch"

    # https://bugs.winehq.org/show_bug.cgi?id=58476
    echo "WINE: -PENDING- RegGetValueW dwFlags hotfix (R.E.A.L VR mod)"
    apply_patch "../patches/wine-hotfixes/pending/registry_RRF_RT_REG_SZ-RRF_RT_REG_EXPAND_SZ.patch"

    # https://github.com/ValveSoftware/wine/pull/205
    # https://github.com/ValveSoftware/Proton/issues/4625
    echo "WINE: -PENDING- Add WINE_DISABLE_SFN option. (Yakuza 5 cutscenes fix)"
    apply_patch "../patches/wine-hotfixes/pending/ntdll_add_wine_disable_sfn.patch"

    echo "WINE: -PENDING- ncrypt: NCryptDecrypt implementation (PSN Login for Ghost of Tsushima)"
    apply_patch "../patches/wine-hotfixes/pending/NCryptDecrypt_implementation.patch"

    # https://gitlab.winehq.org/wine/wine/-/merge_requests/7032
    # https://bugs.winehq.org/show_bug.cgi?id=56259
    # https://forum.winehq.org/viewtopic.php?t=38443
    echo "WINE: -PENDING- add webview2 patches for GIRLS' FRONTLINE 2: EXILIUM"
    apply_patch "../patches/wine-hotfixes/pending/webview2.patch"


### END WINE PENDING UPSTREAM SECTION ###


### (2-6) PROTON-GE ADDITIONAL CUSTOM PATCHES ###

    echo "WINE: -FSR- fullscreen hack fsr patch"
    apply_patch "../patches/proton/0001-fshack-Implement-AMD-FSR-upscaler-for-fullscreen-hac.patch"

    echo "WINE: -Nvidia Reflex- Support VK_NV_low_latency2"
    apply_patch "../patches/proton/83-nv_low_latency_wine.patch"

    echo "WINE: -CUSTOM- Add nls to tools"
    apply_patch "../patches/proton/build_failure_prevention-add-nls.patch"

    echo "WINE: -CUSTOM Add options to disable proton media converter."
    apply_patch "../patches/proton/add-envvar-to-gate-media-converter.patch"

    echo "WINE: -CUSTOM- Downgrade MESSAGE to TRACE to remove write_watches spam"
    apply_patch "../patches/proton/0001-ntdll-Downgrade-using-kernel-write-watches-from-MESS.patch"

    echo "WINE: -CUSTOM- Add WINE_NO_WM_DECORATION option to disable window decorations so that borders behave properly"
    apply_patch "../patches/proton/0001-win32u-add-env-switch-to-disable-wm-decorations.patch"

    echo "WINE: -CUSTOM- Fix a crash in ID2D1DeviceContext if no target is set"
    apply_patch "../patches/proton/fix-a-crash-in-ID2D1DeviceContext-if-no-target-is-set.patch"

    echo "WINE: -CUSTOM- ETASSH WINE-WAYLAND+ PATCHES"
    apply_all_in_dir "../patches/wine-hotfixes/wine-wayland/"

    echo "WINE: RUN AUTOCONF TOOLS/MAKE_REQUESTS"
    autoreconf -f
    ./tools/make_requests

    popd



### END PROTON-GE ADDITIONAL CUSTOM PATCHES ###
### END WINE PATCHING ###
