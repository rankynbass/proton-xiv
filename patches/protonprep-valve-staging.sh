#!/bin/bash

### (1) PREP SECTION ###

# NOTE: Nvidia reflex patches are disabled now as they are currently not ready/problematic/known to cause stutters
# I was pinged about it from DXVK dev discord.
# https://github.com/doitsujin/dxvk/pull/3690#discussion_r1405306492

    pushd dxvk
    git reset --hard HEAD
    git clean -xdf
    #echo "DXVK: -Nvidia Reflex- Add NV low latency support"
    #pushd include/vulkan; git pull; git checkout bbe0f575ebd6098369f0ac6c6a43532732ed0ba6; popd
    #patch -Np1 < ../patches/proton/80-nv_low_latency_dxvk.patch
    popd

    pushd vkd3d-proton
    git reset --hard HEAD
    git clean -xdf
    
    #echo "VKD3D-PROTON: -Nvidia Reflex- Add NV low latency support"
    #pushd khronos/Vulkan-Headers; git pull; git checkout bbe0f575ebd6098369f0ac6c6a43532732ed0ba6; popd
    #patch -Np1 < ../patches/proton/81-nv_low_latency_vkd3d_proton.patch
    popd

    pushd dxvk-nvapi
    git reset --hard HEAD
    git clean -xdf
    #echo "DXVK-NVAPI: -Nvidia Reflex- Add support for Reflex"
    #patch -Np1 < ../patches/proton/82-nv_low_latency_dxvk_nvapi.patch
    popd

    pushd gstreamer
    git reset --hard HEAD
    git clean -xdf
    
    echo "GSTREAMER: fix for unclosable invisible wayland opengl windows in taskbar"
    patch -Np1 < ../patches/gstreamer/5509.patch
    patch -Np1 < ../patches/gstreamer/5511.patch
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

    ../wine-staging/staging/patchinstall.py DESTDIR="." --all \
    -W Compiler_Warnings \
    -W winex11-_NET_ACTIVE_WINDOW \
    -W user32-alttab-focus \
    -W winex11-WM_WINDOWPOSCHANGING \
    -W winex11-MWM_Decorations \
    -W ntdll-Syscall_Emulation \
    -W ntdll-Junction_Points \
    -W server-File_Permissions \
    -W server-Stored_ACLs \
    -W eventfd_synchronization \
    -W dbghelp-Debug_Symbols \
    -W ddraw-Device_Caps \
    -W Pipelight \
    -W server-PeekMessage \
    -W server-Realtime_Priority \
    -W server-Signal_Thread \
    -W loader-KeyboardLayouts \
    -W msxml3-FreeThreadedXMLHTTP60 \
    -W ntdll-ForceBottomUpAlloc \
    -W ntdll-WRITECOPY \
    -W ntdll-CriticalSection \
    -W ntdll-Hide_Wine_Exports \
    -W server-default_integrity \
    -W user32-rawinput-mouse \
    -W user32-rawinput-mouse-experimental \
    -W user32-recursive-activation \
    -W wineboot-ProxySettings \
    -W winex11-UpdateLayeredWindow \
    -W winex11-Vulkan_support \
    -W wintab32-improvements \
    -W kernel32-CopyFileEx \
    -W shell32-Progress_Dialog \
    -W shell32-ACE_Viewer \
    -W fltmgr.sys-FltBuildDefaultSecurityDescriptor \
    -W sapi-ISpObjectToken-CreateInstance \
    -W user32-FlashWindowEx \
    -W wined3d-zero-inf-shaders \
    -W kernel32-Debugger \
    -W ntdll-NtDevicePath \
    -W winspool.drv-ClosePrinter \
    -W winmm-mciSendCommandA \
    -W winex11-XEMBED \
    -W winex11-CandidateWindowPos \
    -W winex11-Window_Style \
    -W winex11-ime-check-thread-data \
    -W winex11.drv-Query_server_position \
    -W user32-Mouse_Message_Hwnd \
    -W d3dx9_36-D3DXStubs \
    -W ntdll-ext4-case-folder \
    -W ntdll-HashLinks \
    -W ntdll-NtQuerySection \
    -W ntdll-NtSetLdtEntries \
    -W ntdll-ProcessQuotaLimits \
    -W ntdll_reg_flush \
    -W odbc-remove-unixodbc \
    -W winedevice-Default_Drivers \
    -W winex11-Fixed-scancodes

    # NOTE: Some patches are applied manually because they -do- apply, just not cleanly, ie with patch fuzz.
    # A detailed list of why the above patches are disabled is listed below:

    # winex11-_NET_ACTIVE_WINDOW - Causes origin to freeze
    # winex11-WM_WINDOWPOSCHANGING - Causes origin to freeze
    # user32-alttab-focus - relies on winex11-_NET_ACTIVE_WINDOW -- may be able to be added now that EA Desktop has replaced origin?
    # winex11-MWM_Decorations - not compatible with fullscreen hack
    # winex11-key_translation - replaced by proton's keyboard patches, disabled in 8.0
    # ntdll-Syscall_Emulation - already applied
    # ntdll-Junction_Points - breaks CEG drm
    # server-File_Permissions - requires ntdll-Junction_Points
    # server-Stored_ACLs - requires ntdll-Junction_Points
    # eventfd_synchronization - already applied
    # ddraw-Device_Caps - conflicts with proton's changes
    # ddraw-version-check - conflicts with proton's changes, disabled in 8.0

    # dbghelp-Debug_Symbols - see below:
    # Sancreed — 11/21/2021
    # Heads up, it appears that a bunch of Ubisoft Connect games (3/3 I had installed and could test) will crash
    # almost immediately on newer Wine Staging/TKG inside pe_load_debug_info function unless the dbghelp-Debug_Symbols staging # patchset is disabled.

    # Compiler_Warnings - breaks some proton patches
    # ** ntdll-DOS_Attributes - disabled in 8.0
    # server-PeekMessage - eplaced by proton's version
    # server-Realtime_Priority - replaced by proton's patches
    # server-Signal_Thread - breaks steamclient for some games -- notably DBFZ
    # Pipelight - for MS Silverlight, not needed
    # dinput-joy-mappings - disabled in favor of proton's gamepad patches
    # ** loader-KeyboardLayouts - applied manually -- needed to prevent Overwatch huge FPS drop
    # msxml3-FreeThreadedXMLHTTP60 - already applied
    # ntdll-ForceBottomUpAlloc - already applied
    # ** ntdll-WRITECOPY - mostly already applied, needs specific manual patch
    # ntdll-CriticalSection - breaks ffxiv and deep rock galactic
    # ** ntdll-Hide_Wine_Exports - applied manually
    # server-default_integrity - causes steam.exe to stay open after a game closes
    # user32-rawinput-mouse - already applied
    # user32-rawinput-mouse-experimental - already applied
    # user32-recursive-activation - already applied
    # ** wineboot-ProxySettings - applied manually
    # ** winex11-UpdateLayeredWindow - applied manually
    # ** winex11-Vulkan_support - applied manually
    # wintab32-improvements - for wacom tablets, not needed
    # kernel32-CopyFileEx - breaks various installers
    # shell32-Progress_Dialog - relies on kernel32-CopyFileEx
    # shell32-ACE_Viewer - adds a UI tab, not needed, relies on kernel32-CopyFileEx
    # ** fltmgr.sys-FltBuildDefaultSecurityDescriptor - applied manually
    # sapi-ISpObjectToken-CreateInstance - already applied
    # ** user32-FlashWindowEx - applied manually
    # wined3d-zero-inf-shaders - already applied
    # ** kernel32-Debugger - applied manually
    # mfplat-streaming-support - already applied
    # ntdll-NtDevicePath - already applied
    # winspool.drv-ClosePrinter - not required, only adds trace lines, for printers.
    # winmm-mciSendCommandA - not needed, only applies to win 9x mode
    # ** winex11-XEMBED - applied manually
    # d3dx9_36-D3DXStubs - already applied
    # ** ntdll-ext4-case-folder - applied manually
    # ** ntdll-HashLinks - applied manually
    # ntdll_reg_flush - already applied
    # ** winedevice-Default_Drivers - applied manually
    # ** winex11-Fixed-scancodes - applied manually
    # odbc-remove-unixodbc - not required, used for ODBC drivers for use with SQL applications, not gaming related.
    #
    # Paul Gofman — Yesterday at 3:49 PM
    # that’s only for desktop integration, spamming native menu’s with wine apps which won’t probably start from there anyway

    # dinput-joy-mappings - disabled in favor of proton's gamepad patches -- currently also disabled in upstream staging
    # mfplat-streaming-support -- interferes with proton's mfplat -- currently also disabled in upstream staging
    # wined3d-SWVP-shaders -- interferes with proton's wined3d -- currently also disabled in upstream staging
    # wined3d-Indexed_Vertex_Blending -- interferes with proton's wined3d -- currently also disabled in upstream staging

    echo "WINE: -STAGING- loader-KeyboardLayouts manually applied"
    patch -Np1 < ../patches/wine-hotfixes/staging/loader-KeyboardLayouts/0001-loader-Add-Keyboard-Layouts-registry-enteries.patch
    patch -Np1 < ../patches/wine-hotfixes/staging/loader-KeyboardLayouts/0002-user32-Improve-GetKeyboardLayoutList.patch

    echo "WINE: -STAGING- ntdll-Hide_Wine_Exports manually applied"
    patch -Np1 < ../wine-staging/patches/ntdll-Hide_Wine_Exports/0001-ntdll-Add-support-for-hiding-wine-version-informatio.patch

    echo "WINE: -STAGING- ntdll-WRITECOPY manually applied"
    patch -Np1 < ../wine-staging/patches/staging/ntdll-WRITECOPY/0007-ntdll-Report-unmodified-WRITECOPY-pages-as-shared.patch

    echo "WINE: -STAGING- wineboot-ProxySettings manually applied"
    patch -Np1 < ../patches/wine-hotfixes/staging/wineboot-ProxySettings/0001-wineboot-Initialize-proxy-settings-registry-key.patch

    echo "WINE: -STAGING- winex11-Vulkan_support manually applied"
    patch -Np1 < ../patches/wine-hotfixes/staging/winex11-Vulkan_support/0001-winex11-Specify-a-default-vulkan-driver-if-one-not-f.patch

    echo "WINE: -STAGING- user32-FlashWindowEx manually applied"
    patch -Np1 < ../patches/wine-hotfixes/staging/user32-FlashWindowEx/0001-user32-Improve-FlashWindowEx-message-and-return-valu.patch

    echo "WINE: -STAGING- kernel32-Debugger manually applied"
    patch -Np1 < ../wine-staging/patches/kernel32-Debugger/0001-kernel32-Always-start-debugger-on-WinSta0.patch

    echo "WINE: -STAGING- ntdll-ext4-case-folder manually applied"
    patch -Np1 < ../wine-staging/patches/ntdll-ext4-case-folder/0002-ntdll-server-Mark-drive_c-as-case-insensitive-when-c.patch

    echo "WINE: -STAGING- ntdll-HashLinks manually applied"
    patch -Np1 < ../patches/wine-hotfixes/staging/ntdll-HashLinks/0001-ntdll-Implement-HashLinks-field-in-LDR-module-data.patch
    patch -Np1 < ../patches/wine-hotfixes/staging/ntdll-HashLinks/0002-ntdll-Use-HashLinks-when-searching-for-a-dll-using-t.patch

    echo "WINE: -STAGING- ntdll-NtQuerySection manually applied"
    patch -Np1 < ../wine-staging/patches/ntdll-NtQuerySection/0002-kernel32-tests-Add-tests-for-NtQuerySection.patch

    echo "WINE: -STAGING- ntdll-NtSetLdtEntries manually applied"
    patch -Np1 < ../wine-staging/patches/ntdll-NtSetLdtEntries/0001-ntdll-Implement-NtSetLdtEntries.patch
    patch -Np1 < ../wine-staging/patches/ntdll-NtSetLdtEntries/0002-libs-wine-Allow-to-modify-reserved-LDT-entries.patch

    echo "WINE: -STAGING- ntdll-ProcessQuotaLimits manually applied"
    patch -Np1 < ../wine-staging/patches/ntdll-ProcessQuotaLimits/0001-ntdll-Add-fake-data-implementation-for-ProcessQuotaL.patch

    echo "WINE: -STAGING- winedevice-Default_Drivers manually applied"
    patch -Np1 < ../wine-staging/patches/winedevice-Default_Drivers/0001-win32k.sys-Add-stub-driver.patch
    patch -Np1 < ../wine-staging/patches/winedevice-Default_Drivers/0002-dxgkrnl.sys-Add-stub-driver.patch
    patch -Np1 < ../wine-staging/patches/winedevice-Default_Drivers/0003-dxgmms1.sys-Add-stub-driver.patch
    patch -Np1 < ../wine-staging/patches/winedevice-Default_Drivers/0004-programs-winedevice-Load-some-common-drivers-and-fix.patch

    echo "WINE: -STAGING- winex11-Fixed-scancodes manually applied"
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0001-winecfg-Move-input-config-options-to-a-dedicated-tab.patch
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0002-winex11-Always-create-the-HKCU-configuration-registr.patch
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0003-winex11-Write-supported-keyboard-layout-list-in-regi.patch
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0004-winecfg-Add-a-keyboard-layout-selection-config-optio.patch
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0005-winex11-Use-the-user-configured-keyboard-layout-if-a.patch
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0006-winecfg-Add-a-keyboard-scancode-detection-toggle-opt.patch
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0007-winex11-Use-scancode-high-bit-to-set-KEYEVENTF_EXTEN.patch
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0008-winex11-Support-fixed-X11-keycode-to-scancode-conver.patch
    patch -Np1 < ../wine-staging/patches/winex11-Fixed-scancodes/0009-winex11-Disable-keyboard-scancode-auto-detection-by-.patch

    echo "WINE: -STAGING- fltmgr.sys-FltBuildDefaultSecurityDescriptor manually applied"
    patch -Np1 < ../wine-staging/patches/fltmgr.sys-FltBuildDefaultSecurityDescriptor/0001-fltmgr.sys-Implement-FltBuildDefaultSecurityDescript.patch
    patch -Np1 < ../wine-staging/patches/fltmgr.sys-FltBuildDefaultSecurityDescriptor/0002-fltmgr.sys-Create-import-library.patch
    patch -Np1 < ../wine-staging/patches/fltmgr.sys-FltBuildDefaultSecurityDescriptor/0003-ntoskrnl.exe-Add-FltBuildDefaultSecurityDescriptor-t.patch
    

### END WINE STAGING APPLY SECTION ###

### (2-3) GAME PATCH SECTION ###

    echo "WINE: -GAME FIXES- assetto corsa hud fix"
    patch -Np1 < ../patches/game-patches/assettocorsa-hud.patch

    echo "WINE: -GAME FIXES- add file search workaround hack for Phantasy Star Online 2 (WINE_NO_OPEN_FILE_SEARCH)"
    patch -Np1 < ../patches/game-patches/pso2_hack.patch

### END GAME PATCH SECTION ###

### (2-4) WINE HOTFIX/BACKPORT SECTION ###

### END WINE HOTFIX/BACKPORT SECTION ###

### (2-5) WINE PENDING UPSTREAM SECTION ###

    # https://github.com/Frogging-Family/wine-tkg-git/commit/ca0daac62037be72ae5dd7bf87c705c989eba2cb
    echo "WINE: -PENDING- unity crash hotfix"
    patch -Np1 < ../patches/wine-hotfixes/pending/unity_crash_hotfix.patch

    # https://github.com/ValveSoftware/wine/pull/205
    # https://github.com/ValveSoftware/Proton/issues/4625
    echo "WINE: -PENDING- Add WINE_DISABLE_SFN option. (Yakuza 5 cutscenes fix)"
    patch -Np1 < ../patches/wine-hotfixes/pending/ntdll_add_wine_disable_sfn.patch

### END WINE PENDING UPSTREAM SECTION ###


### (2-6) PROTON-GE ADDITIONAL CUSTOM PATCHES ###

    echo "WINE: -FSR- fullscreen hack fsr patch"
    patch -Np1 < ../patches/proton/47-proton-fshack-AMD-FSR-complete.patch

    #echo "WINE: -Nvidia Reflex- Support VK_NV_low_latency2"
    #patch -Np1 < ../patches/proton/83-nv_low_latency_wine.patch

    popd

### END PROTON-GE ADDITIONAL CUSTOM PATCHES ###
### END WINE PATCHING ###

