/*
 * Copyright (c) 2015, 2019, 2020, 2021, 2022 Valve Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* This is a stub steam.exe implementation for use inside Proton. It provides
 * a small subset of the actual Steam functionality for games that expect
 * Windows version of Steam running. */

#include <stddef.h>
#include <stdarg.h>

#include <wchar.h>
#include <wctype.h>

#include "ntstatus.h"
#define WIN32_NO_STATUS
#include <windows.h>
#include <winsvc.h>
#include <winternl.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#define _USE_GNU
#include <dlfcn.h>

#pragma push_macro("_WIN32")
#pragma push_macro("__cdecl")
#pragma push_macro("strncpy")
#undef _WIN32
#undef __cdecl
#undef strncpy
#include "steam_api.h"
#pragma pop_macro("_WIN32")
#pragma pop_macro("__cdecl")
#pragma pop_macro("strncpy")

#include "wine/debug.h"

#include "wine/unixlib.h"
#include "wine/heap.h"
#include "wine/vulkan.h"

#include <msi.h>

WINE_DEFAULT_DEBUG_CHANNEL(steam);

static bool env_nonzero(const char *env)
{
    const char *v = getenv(env);
    return v != NULL && *v && v[0] != '0';
}

static void set_active_process_pid(void)
{
    DWORD pid = GetCurrentProcessId();
    RegSetKeyValueA(HKEY_CURRENT_USER, "Software\\Valve\\Steam\\ActiveProcess", "pid", REG_DWORD, &pid, sizeof(pid));
}

static DWORD WINAPI create_steam_window(void *arg)
{
    static WNDCLASSEXW wndclass = { sizeof(WNDCLASSEXW) };
    static const WCHAR class_nameW[] = {'v','g','u','i','P','o','p','u','p','W','i','n','d','o','w',0};
    static const WCHAR steamW[] = {'S','t','e','a','m',0};
    MSG msg;

    wndclass.lpfnWndProc = DefWindowProcW;
    wndclass.lpszClassName = class_nameW;

    RegisterClassExW(&wndclass);
    CreateWindowW(class_nameW, steamW, WS_POPUP, 40, 40,
                  400, 300, NULL, NULL, NULL, NULL);

    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}

/* requires steam API to be initialized */
static void setup_steam_registry(void)
{
    const char *ui_lang, *language, *languages, *locale = NULL;
    uint32 appid;
    char buf[256];
    HKEY key;
    LSTATUS status;
    const int system_locale_appids[] = {
        1284210 /* Guild Wars 2 */
    };

    ui_lang = SteamUtils()->GetSteamUILanguage();
    WINE_TRACE("UI language: %s\n", wine_dbgstr_a(ui_lang));
    RegSetKeyValueA(HKEY_CURRENT_USER, "Software\\Valve\\Steam", "language",
                    REG_SZ, ui_lang, strlen(ui_lang) + 1);

    appid = SteamUtils()->GetAppID();
    WINE_TRACE("appid: %u\n", appid);
    sprintf(buf, "Software\\Valve\\Steam\\Apps\\%u", appid);
    status = RegCreateKeyA(HKEY_CURRENT_USER, buf, &key);
    if (!status)
    {
        DWORD value;
        value = 1;
        RegSetKeyValueA(key, NULL, "Installed", REG_DWORD, &value, sizeof(value));
        RegSetKeyValueA(key, NULL, "Running", REG_DWORD, &value, sizeof(value));
        value = 0;
        RegSetKeyValueA(key, NULL, "Updating", REG_DWORD, &value, sizeof(value));
        RegCloseKey(key);
    }
    else WINE_ERR("Could not create key: %u\n", status);

    language = SteamApps()->GetCurrentGameLanguage();
    languages = SteamApps()->GetAvailableGameLanguages();
    WINE_TRACE( "Game language %s, available %s\n", wine_dbgstr_a(language), wine_dbgstr_a(languages) );

    if (strchr(languages, ',') == NULL) /* If there is a list of languages then respect that */
    {
        for (int i = 0; i < (sizeof(system_locale_appids) / sizeof(*system_locale_appids)); i++)
        {
            if (system_locale_appids[i] == appid)
            {
                WINE_TRACE("Not changing system locale for application %i\n",appid);
                language = NULL;
            }
        }
    }

    if (!language) locale = NULL;
    else if (!strcmp( language, "arabic" )) locale = "ar_001.UTF-8";
    else if (!strcmp( language, "bulgarian" )) locale = "bg_BG.UTF-8";
    else if (!strcmp( language, "schinese" )) locale = "zh_CN.UTF-8";
    else if (!strcmp( language, "tchinese" )) locale = "zh_TW.UTF-8";
    else if (!strcmp( language, "czech" )) locale = "cs_CZ.UTF-8";
    else if (!strcmp( language, "danish" )) locale = "da_DK.UTF-8";
    else if (!strcmp( language, "dutch" )) locale = "nl_NL.UTF-8";
    else if (!strcmp( language, "english" )) locale = "en_US.UTF-8";
    else if (!strcmp( language, "finnish" )) locale = "fi_FI.UTF-8";
    else if (!strcmp( language, "french" )) locale = "fr_FR.UTF-8";
    else if (!strcmp( language, "german" )) locale = "de_DE.UTF-8";
    else if (!strcmp( language, "greek" )) locale = "el_GR.UTF-8";
    else if (!strcmp( language, "hungarian" )) locale = "hu_HU.UTF-8";
    else if (!strcmp( language, "italian" )) locale = "it_IT.UTF-8";
    else if (!strcmp( language, "japanese" )) locale = "ja_JP.UTF-8";
    else if (!strcmp( language, "koreana" )) locale = "ko_KR.UTF-8";
    else if (!strcmp( language, "norwegian" )) locale = "nb_NO.UTF-8";
    else if (!strcmp( language, "polish" )) locale = "pl_PL.UTF-8";
    else if (!strcmp( language, "portuguese" )) locale = "pt_PT.UTF-8";
    else if (!strcmp( language, "brazilian" )) locale = "pt_BR.UTF-8";
    else if (!strcmp( language, "romanian" )) locale = "ro_RO.UTF-8";
    else if (!strcmp( language, "russian" )) locale = "ru_RU.UTF-8";
    else if (!strcmp( language, "spanish" )) locale = "es_ES.UTF-8";
    else if (!strcmp( language, "latam" )) locale = "es_419.UTF-8";
    else if (!strcmp( language, "swedish" )) locale = "sv_SE.UTF-8";
    else if (!strcmp( language, "thai" )) locale = "th_TH.UTF-8";
    else if (!strcmp( language, "turkish" )) locale = "tr_TR.UTF-8";
    else if (!strcmp( language, "ukrainian" )) locale = "uk_UA.UTF-8";
    else if (!strcmp( language, "vietnamese" )) locale = "vi_VN.UTF-8";
    else WINE_FIXME( "Unsupported game language %s\n", wine_dbgstr_a(language) );

    /* HACK: Bug 23597 Granado Espada Japan (1219160) launcher needs Japanese locale to display correctly */
    if (appid == 1219160)
        locale = "ja_JP.UTF-8";

    if (locale)
    {
        WINE_FIXME( "Game language %s, defaulting LC_CTYPE / LC_MESSAGES to %s.\n", wine_dbgstr_a(language), locale );
        setenv( "LC_CTYPE", locale, FALSE );
        setenv( "LC_MESSAGES", locale, FALSE );
    }
}

/* requires steam API to be initialized */
static void setup_battleye_bridge(void)
{
    const unsigned int be_runtime_appid = 1161040;
    char path[2048];

    if (!SteamApps()->BIsAppInstalled(be_runtime_appid))
        return;

    if (!SteamApps()->GetAppInstallDir(be_runtime_appid, path, sizeof(path)))
        return;

    WINE_TRACE("Found battleye runtime at %s\n", path);

    setenv("PROTON_BATTLEYE_RUNTIME", path, 1);
}

static void setup_eac_bridge(void)
{
    const unsigned int eac_runtime_appid = 1826330;
    char path[2048];

    if (!SteamApps()->BIsAppInstalled(eac_runtime_appid))
        return;

    if (!SteamApps()->GetAppInstallDir(eac_runtime_appid, path, sizeof(path)))
        return;

    WINE_TRACE("Found easyanticheat runtime at %s\n", path);

    setenv("PROTON_EAC_RUNTIME", path, 1);
}

static void setup_proton_voice_files(void)
{
    const unsigned int proton_voice_files_appid = 3086180;
    char path[2048];
    char *path_end;

    if (!SteamApps()->BIsAppInstalled(proton_voice_files_appid))
        return;

    if (!SteamApps()->GetAppInstallDir(proton_voice_files_appid, path, sizeof(path)))
        return;

    WINE_TRACE("Found proton voice files at %s\n", path);

    setenv("PROTON_VOICE_FILES", path, 1);
}

static void write_file( const WCHAR *filename, const char *data, size_t len )
{
    DWORD written;
    HANDLE file;

    file = CreateFileW( filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
    if (file == INVALID_HANDLE_VALUE) ERR( "Could not open %s.\n", debugstr_w(filename) );
    else
    {
        if (!WriteFile( file, data, len, &written, NULL )) ERR( "Could not write to %s.\n", debugstr_w(filename) );
        CloseHandle( file );
    }
}

static char *escape_path_unix_to_dos( const char *path )
{
    WCHAR *dos, *tmp = NULL, *src, *dst;
    char *escaped = NULL;
    UINT len;

    if (!(dos = wine_get_dos_file_name( path )) || !(len = lstrlenW( dos ))) goto done;
    if (!(tmp = (WCHAR *)heap_alloc( (len * 2 + 1) * sizeof(*tmp) ))) goto done;
    for (src = dos, dst = tmp; *src; src++, dst++) if ((*dst = *src) == '\\') *++dst = '\\';

    if (!(len = WideCharToMultiByte( CP_UTF8, 0, tmp, (dst - tmp), NULL, 0, NULL, NULL ))) goto done;
    if ((escaped = (char *)heap_alloc( len ))) WideCharToMultiByte( CP_UTF8, 0, tmp, (dst - tmp), escaped, len, NULL, NULL );

done:
    heap_free( dos );
    heap_free( tmp );
    return escaped;
}

size_t strappend( char **buf, size_t *len, size_t pos, const char *fmt, ... )
{
    size_t size;
    va_list ap;
    char *ptr;
    int n;

    if (*buf)
    {
        size = *len;
        ptr = *buf;
    }
    else
    {
        size = 100;
        ptr = (char *)malloc( size );
    }

    for (;;)
    {
        va_start( ap, fmt );
        n = vsnprintf( ptr + pos, size - pos, fmt, ap );
        va_end( ap );
        if (n == -1) size *= 2;
        else if (pos + (size_t)n >= size) size = pos + n + 1;
        else break;
        ptr = (char *)realloc( ptr, size );
    }

    *len = size;
    *buf = ptr;
    return n;
}

static void setup_vr_registry(void)
{
    BOOL (CDECL *init)(void);
    HMODULE vrclient;
    HANDLE thread;

#ifdef _WIN64
    if (!(vrclient = LoadLibraryA( "vrclient_x64" )))
#else
    if (!(vrclient = LoadLibraryA( "vrclient" )))
#endif
    {
        ERR( "Failed to load vrclient module, skipping initialization\n" );
        return;
    }

    if ((init = (decltype(init))GetProcAddress( vrclient, "vrclient_init_registry" ))) init();
    else ERR( "Failed to find vrclient_init_registry export\n" );

    TRACE( "Queued VR info initialization.\n" );
    FreeLibrary(vrclient);
}

static WCHAR *strchrW(WCHAR *h, WCHAR n)
{
    do
    {
        if(*h == n)
            return h;
    } while (*h++);

    return NULL;
}

int strncmpW(const WCHAR *l, const WCHAR *r, int n)
{
    if(n <= 0)
        return 0;

    while(--n > 0 && *l && *l == *r){
        l++;
        r++;
    }

    return *l - *r;
}

static WCHAR *find_quote(WCHAR *str)
{
    WCHAR *end = strchrW(str, '"'), *ch;
    int odd;
    while (end)
    {
        odd = 0;
        ch = end - 1;
        while (ch >= str && *ch == '\\')
        {
            odd = !odd;
            --ch;
        }
        if (!odd)
            return end;
        end = strchrW(end + 1, '"');
    }
    return NULL;
}

static BOOL WINAPI console_ctrl_handler(DWORD dwCtrlType)
{
    return TRUE;
}

static BOOL streq_niw(const WCHAR *l, const WCHAR *r, size_t len)
{
    while(len > 0){
        if(towlower(*l) != towlower(*r))
            return FALSE;
        ++l; ++r; --len;
    }
    return TRUE;
}

static WCHAR* get_end_of_excutable_name(WCHAR *cmdline)
{
    BOOL quoted = FALSE;
    WCHAR *executable_name_end = cmdline;

    /* find the end of the first arg...*/
    while (*executable_name_end != '\0' &&
           (*executable_name_end != ' ' || quoted))
    {
        quoted ^= *executable_name_end == '"';

        executable_name_end++;
    }

    return executable_name_end;
}

static BOOL should_use_shell_execute(WCHAR *cmdline)
{
    BOOL use_shell_execute = TRUE;
    const WCHAR *executable_name_end = (const WCHAR*)get_end_of_excutable_name(cmdline);

    /* if the executable is quoted backtrack a bit */
    if (*(executable_name_end - 1) == '"')
        --executable_name_end;


    /* backtrack to before the end of the arg
     * and check if we end in .exe or not
     * and determine whether to use ShellExecute
     * based on that */
    executable_name_end -= strlen(".exe");

    if (executable_name_end >= cmdline)
    {
        static const WCHAR exeW[] = {'.','e','x','e',0};

        if (streq_niw(executable_name_end, exeW, sizeof(exeW) / sizeof(*exeW) - 1))
            use_shell_execute = FALSE;
    }

    return use_shell_execute;
}

static HANDLE run_process(BOOL *should_await, BOOL game_process)
{
    static const WCHAR link2eaW[] = {'l','i','n','k','2','e','a',':','/','/',0};
    static const WCHAR link2ea_pathW[] =
    {
        'S','o','f','t','w','a','r','e','\\','C','l','a','s','s','e','s','\\','l','i','n','k','2','e','a',0
    };
    static const WCHAR ea_desktop_pathW[] =
    {
        'S','o','f','t','w','a','r','e','\\','E','l','e','c','t','r','o','n','i','c',' ','A','r','t','s',
        '\\','E','A',' ','D','e','s','k','t','o','p',0
    };
    static const WCHAR ea_core_pathW[] =
    {
        'S','o','f','t','w','a','r','e','\\','E','l','e','c','t','r','o','n','i','c',' ','A','r','t','s',
        '\\','E','A',' ','C','o','r','e',0
    };
    static const WCHAR IsUnavailableW[] = {'I','s','U','n','a','v','a','i','l','a','b','l','e',0};
    WCHAR *cmdline = GetCommandLineW();
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    DWORD flags = CREATE_UNICODE_ENVIRONMENT;
    BOOL use_shell_execute = TRUE, link2ea = FALSE;
    BOOL hide_window;

    /* skip argv[0] */
    if (*cmdline == '"')
    {
        cmdline = find_quote(cmdline + 1);
        if (cmdline) cmdline++;
    }
    else
    {
        cmdline = strchrW(cmdline, ' ');
    }
    if (!cmdline)
    {
        WINE_ERR("Invalid command\n");
        return INVALID_HANDLE_VALUE;
    }
    while (*cmdline == ' ') cmdline++;

    /* convert absolute unix path to dos */
    if (cmdline[0] == '/' ||
            (cmdline[0] == '"' && cmdline[1] == '/'))
    {
        WCHAR *scratchW;
        char *scratchA;
        WCHAR *start, *end, *dos, *remainder, *new_cmdline;
        size_t argv0_len;
        int r;
        DWORD_PTR console;
        SHFILEINFOW sfi;

        static const WCHAR dquoteW[] = {'"',0};

        WINE_TRACE("Converting unix command: %s\n", wine_dbgstr_w(cmdline));

        if (cmdline[0] == '"')
        {
            start = cmdline + 1;
            end = find_quote(start);
            if (!end)
            {
                WINE_ERR("Unmatched quote? %s\n", wine_dbgstr_w(cmdline));
                goto run;
            }
            remainder = end + 1;
        }
        else
        {
            start = cmdline;
            end = strchrW(start, ' ');
            if (!end)
                end = strchrW(start, '\0');
            remainder = end;
        }

        argv0_len = end - start;

        scratchW = (WCHAR *)HeapAlloc(GetProcessHeap(), 0, (argv0_len + 1) * sizeof(WCHAR));
        memcpy(scratchW, start, argv0_len * sizeof(WCHAR));
        scratchW[argv0_len] = '\0';

        r = WideCharToMultiByte(CP_UNIXCP, 0, scratchW, -1,
                NULL, 0, NULL, NULL);
        if (!r)
        {
            WINE_ERR("Char conversion size failed?\n");
            goto run;
        }

        scratchA = (char *)HeapAlloc(GetProcessHeap(), 0, r);

        r = WideCharToMultiByte(CP_UNIXCP, 0, scratchW, -1,
                scratchA, r, NULL, NULL);
        if (!r)
        {
            WINE_ERR("Char conversion failed?\n");
            goto run;
        }

        dos = wine_get_dos_file_name(scratchA);

        CoInitialize(NULL);

        console = SHGetFileInfoW(dos, 0, &sfi, sizeof(sfi), SHGFI_EXETYPE);
        if (console)
        {
            if (!HIWORD(console))
                flags |= CREATE_NEW_CONSOLE;
        }

        new_cmdline = (WCHAR *)HeapAlloc(GetProcessHeap(), 0,
                (lstrlenW(dos) + 3 + lstrlenW(remainder) + 1) * sizeof(WCHAR));
        lstrcpyW(new_cmdline, dquoteW);
        lstrcatW(new_cmdline, dos);
        lstrcatW(new_cmdline, dquoteW);
        lstrcatW(new_cmdline, remainder);

        cmdline = new_cmdline;
    }

run:
    WINE_TRACE("Running command %s\n", wine_dbgstr_w(cmdline));

    SetConsoleCtrlHandler( console_ctrl_handler, TRUE );

    use_shell_execute = should_use_shell_execute(cmdline);
    if (use_shell_execute && lstrlenW(cmdline) > 10 && !memcmp(cmdline, link2eaW, 10 *sizeof(WCHAR)))
    {
        HDESK desktop = GetThreadDesktop(GetCurrentThreadId());
        DWORD is_unavailable, type, size;
        SC_HANDLE manager, service;
        SERVICE_STATUS status;
        DWORD timeout = 3000;
        HKEY eakey;
        BOOL ret;

        link2ea = TRUE;
        if (!SetUserObjectInformationA(desktop, 1000, &timeout, sizeof(timeout)))
            WINE_ERR("Failed to set desktop timeout, err %u.\n", GetLastError());

        if (!RegOpenKeyExW(HKEY_LOCAL_MACHINE, ea_desktop_pathW, 0, KEY_ALL_ACCESS, &eakey))
        {
            size = sizeof(is_unavailable);
            if (!RegQueryValueExW(eakey, IsUnavailableW, NULL, &type, (BYTE *)&is_unavailable, &size)
                    && type == REG_DWORD && is_unavailable)
            {
                WINE_ERR("EA Desktop\\IsUnavailable is set, clearing.\n");
                is_unavailable = 0;
                RegSetValueExW(eakey, IsUnavailableW, 0, REG_DWORD, (BYTE *)&is_unavailable, sizeof(is_unavailable));
            }
            RegCloseKey(eakey);
        }
        if ((manager = OpenSCManagerA(NULL, SERVICES_ACTIVE_DATABASEA, SERVICE_QUERY_STATUS)))
        {
            if ((service = OpenServiceA(manager, "EABackgroundService", SERVICE_QUERY_STATUS)))
            {
                if (QueryServiceStatus(service, &status))
                {
                    TRACE("dwCurrentState %#x.\n", status.dwCurrentState);
                    if (status.dwCurrentState == SERVICE_STOP_PENDING || status.dwCurrentState == SERVICE_STOPPED)
                    {
                        ret = DeleteFileA("C:\\ProgramData\\EA Desktop\\backgroundservice.ini");
                        WARN("Tried to delete backgroundservice.ini, ret %d, error %u.\n", ret, GetLastError());
                    }
                }
                else ERR("Could not query service status, error %u.\n", GetLastError());
                CloseServiceHandle(service);
            }
            else TRACE("Could not open EABackgroundService, error %u.\n", GetLastError());
            CloseServiceHandle(manager);
        }
        else ERR("Could not open service manager, error %u.\n", GetLastError());
    }
    hide_window = env_nonzero("PROTON_HIDE_PROCESS_WINDOW");

    /* only await the process finishing if we launch a process directly...
     * Steam simply calls ShellExecuteA with the same parameters.
     * this avoids the edge case where we could ShellExecute and
     * then that process ends up ShellExecuting something as a throw away */
    *should_await = !use_shell_execute;

    WINE_TRACE("Executing via %s\n",
        wine_dbgstr_a(use_shell_execute ? "ShellExecuteW" : "CreateProcessW"));

    if (use_shell_execute)
    {
        WCHAR *param = NULL;
        WCHAR *executable_name_end = get_end_of_excutable_name(cmdline);
        if (*executable_name_end != '\0')
        {
            *executable_name_end = '\0';
            param = executable_name_end+1;
        }
        static const WCHAR verb[] = { 'o', 'p', 'e', 'n', 0 };
        INT_PTR ret;

        if ((ret = (INT_PTR)ShellExecuteW(NULL, verb, cmdline, param, NULL, hide_window ? SW_HIDE : SW_SHOWNORMAL)) < 32)
        {
            WINE_ERR("Failed to execute %s, ret %u.\n", wine_dbgstr_w(cmdline), (unsigned int)ret);
            if (game_process && ret == SE_ERR_NOASSOC && link2ea)
            {
                static const WCHAR msi_guidW[] = {'{','C','2','6','2','2','0','8','5','-','A','B','D','2','-','4','9','E','5','-','8','A','B','9','-','D','3','D','6','A','6','4','2','C','0','9','1','}',0};
                static const WCHAR REMOVE_ALL_W[] = {'R','E','M','O','V','E','=','A','L','L',0};

                /* Try to uninstall EA desktop so it is set up from prerequisites on the next run. */
                UINT ret = MsiConfigureProductExW(msi_guidW, 0, INSTALLSTATE_DEFAULT, REMOVE_ALL_W);

                WINE_TRACE("MsiConfigureProductExW ret %u.\n", ret);
                /* If uninstall failed this should trigger interactive repair window on the EA setup run. */
                RegDeleteTreeW(HKEY_LOCAL_MACHINE, link2ea_pathW);
                RegDeleteTreeW(HKEY_LOCAL_MACHINE, ea_desktop_pathW);
                RegDeleteTreeW(HKEY_LOCAL_MACHINE, ea_core_pathW);
            }
        }
        return INVALID_HANDLE_VALUE;
    }
    else
    {
        if (hide_window)
        {
            si.dwFlags |= STARTF_USESHOWWINDOW;
            si.wShowWindow = SW_HIDE;
        }

        if (!CreateProcessW(NULL, cmdline, NULL, NULL, FALSE, flags, NULL, NULL, &si, &pi))
        {
            WINE_ERR("Failed to create process %s: %u\n", wine_dbgstr_w(cmdline), GetLastError());
            return INVALID_HANDLE_VALUE;
        }

        CloseHandle(pi.hThread);

        return pi.hProcess;
    }
}

/* Forward stub steam.exe commands to the native steam client */
static BOOL steam_command_handler(int argc, char *argv[])
{
    typedef NTSTATUS (WINAPI *__WINE_UNIX_SPAWNVP)(char *const argv[], int wait);
    static __WINE_UNIX_SPAWNVP p__wine_unix_spawnvp;
    NTSTATUS status = STATUS_UNSUCCESSFUL;
    BOOL restart_self = FALSE;
    char **unix_argv;
    HMODULE module;
    const char *sgi;
    int i, j;
    static char *unix_steam[] =
    {
        (char *)"steam-runtime-steam-remote",
        (char *)"steam",
        NULL,
    };

    /* If there are command line options, only forward steam:// and options start with - */
    if (argc > 1 && StrStrIA(argv[1], "steam://") != argv[1] && argv[1][0] != '-')
        return FALSE;

    if (argc > 2 && !strcmp(argv[1], "--") && (sgi = getenv("SteamGameId")))
    {
        char s[64];

        snprintf(s, sizeof(s), "steam://launch/%s", sgi);
        if (!(restart_self = !strcmp(argv[2], s)))
        {
            snprintf(s, sizeof(s), "steam://rungameid/%s", sgi);
            restart_self = !strcmp(argv[2], s);
        }
    }
    if (restart_self)
    {
        HANDLE event;

        event = OpenEventA(SYNCHRONIZE, FALSE, "PROTON_STEAM_EXE_RESTART_APP");
        if (event)
        {
            SetEvent(event);
            CloseHandle(event);
            WINE_TRACE("Signalled app restart.\n");
        }
        else
            WINE_ERR("Restart event not found.\n");
        return TRUE;
    }

    if (!p__wine_unix_spawnvp)
    {
        module = GetModuleHandleA("ntdll.dll");
        p__wine_unix_spawnvp = (__WINE_UNIX_SPAWNVP)GetProcAddress(module, "__wine_unix_spawnvp");
        if (!p__wine_unix_spawnvp)
        {
            WINE_ERR("Failed to load __wine_unix_spawnvp().\n");
            return FALSE;
        }
    }

    if (!(unix_argv = static_cast<char **>(malloc((argc + 1) * sizeof(*unix_argv)))))
    {
        WINE_ERR("Out of memory.\n");
        return FALSE;
    }

    for (i = 1; i < argc; ++i)
        unix_argv[i] = argv[i];
    unix_argv[argc] = NULL;

    for (i = 0; i < ARRAY_SIZE(unix_steam); ++i)
    {
        unix_argv[0] = unix_steam[i];

        WINE_TRACE("Trying");
        for (j = 0; j < argc; ++j)
            WINE_TRACE(" %s", wine_dbgstr_a(unix_argv[j]));
        WINE_TRACE("\n");

        status = p__wine_unix_spawnvp(unix_argv, TRUE);
        if (status == STATUS_SUCCESS)
            break;
    }
    free(unix_argv);

    if (status == STATUS_SUCCESS)
    {
        WINE_TRACE("Forwarded command to native steam.\n");
    }
    else
    {
        WINE_ERR("Forwarding");
        for (i = 0; i < argc; ++i)
            WINE_ERR(" %s", wine_dbgstr_a(argv[i]));
        WINE_ERR(" to native steam failed, status %#x.\n", status);
    }
    return TRUE;
}

static void setup_steam_files(void)
{
    static const WCHAR config_pathW[] =
    {
        'C',':','\\','P','r','o','g','r','a','m',' ','F','i','l','e','s',' ','(','x','8','6',')','\\','S','t','e','a','m',
        '\\','c','o','n','f','i','g',0,
    };
    static const WCHAR steamapps_pathW[] =
    {
        'C',':','\\','P','r','o','g','r','a','m',' ','F','i','l','e','s',' ','(','x','8','6',')','\\','S','t','e','a','m',
        '\\','s','t','e','a','m','a','p','p','s',0,
    };
    static const WCHAR libraryfolders_nameW[] =
    {
        'C',':','\\','P','r','o','g','r','a','m',' ','F','i','l','e','s',' ','(','x','8','6',')','\\','S','t','e','a','m',
        '\\','s','t','e','a','m','a','p','p','s','\\','l','i','b','r','a','r','y','f','o','l','d','e','r','s','.','v','d','f',0,
    };
    const char *steam_install_path = getenv("STEAM_COMPAT_CLIENT_INSTALL_PATH");
    const char *steam_library_paths = getenv("STEAM_COMPAT_LIBRARY_PATHS");
    const char *start, *end, *next;
    size_t len = 0, pos = 0;
    char *buf = NULL, *str;
    unsigned int index = 0;

    if (!CreateDirectoryW(config_pathW, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
    {
        WINE_ERR("Failed to create config directory, GetLastError() %u.\n", GetLastError());
        return;
    }

    if (!CreateDirectoryW(steamapps_pathW, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
    {
        WINE_ERR("Failed to create steamapps directory, GetLastError() %u.\n", GetLastError());
        return;
    }

    pos += strappend( &buf, &len, pos, "\"LibraryFolders\"\n{\n" );

    TRACE( "steam_install_path %s.\n", debugstr_a(steam_install_path) );
    if (steam_install_path)
    {
        if (!(str = escape_path_unix_to_dos( steam_install_path )))
            ERR( "Could not convert %s to win path.\n", debugstr_a(steam_install_path) );
        else
        {
            pos += strappend( &buf, &len, pos, "\t\"%u\"\n\t{\n\t\t\"path\"\t\t\"%s\"\n\t}\n", index, str );
            heap_free( str );
        }
    }

    TRACE( "steam_library_paths %s.\n", debugstr_a(steam_library_paths) );
    start = steam_library_paths;
    while (start && *start)
    {
        char *path;

        if (!(next = strchr( start, ':' ))) next = start + strlen( start );
        end = next;

        if (end != start && end[-1] == '/') --end;
        while (end != start && end[-1] != '/') --end;

        path = (char *)heap_alloc( end - start + 1 );
        lstrcpynA( path, start, end - start );
        if (!(str = escape_path_unix_to_dos( path )))
            ERR( "Could not convert %s to win path.\n", debugstr_a(path) );
        else
        {
            pos += strappend( &buf, &len, pos, "\t\"%u\"\n\t{\n\t\t\"path\"\t\t\"%s\"\n\t}\n", index, str );
            heap_free( str );
        }
        heap_free( path );

        if (*next == ':') ++next;
        start = next;
    }

    pos += strappend( &buf, &len, pos, "}\n" );
    write_file( libraryfolders_nameW, buf, len );
}

#ifndef DIRECTORY_QUERY
#define DIRECTORY_QUERY 0x0001
#endif

static HANDLE find_ack_event(void)
{
    static const WCHAR steam_ack_event[] = {'S','T','E','A','M','_','S','T','A','R','T','_','A','C','K','_','E','V','E','N','T',0};
    static const WCHAR name[] = {'\\','B','a','s','e','N','a','m','e','d','O','b','j','e','c','t','s','\\','S','e','s','s','i','o','n','\\','1',0};
    DIRECTORY_BASIC_INFORMATION *di;
    OBJECT_ATTRIBUTES attr;
    HANDLE dir, ret = NULL;
    ULONG context, size;
    UNICODE_STRING str;
    char buffer[1024];
    NTSTATUS status;

    di = (DIRECTORY_BASIC_INFORMATION *)buffer;

    RtlInitUnicodeString(&str, name);
    InitializeObjectAttributes(&attr, &str, 0, 0, NULL);
    status = NtOpenDirectoryObject( &dir, DIRECTORY_QUERY, &attr );
    if (status)
    {
        WINE_WARN("Failed to open directory %s, status %#x.\n", wine_dbgstr_w(name), status);
        return NULL;
    }

    status = NtQueryDirectoryObject(dir, di, sizeof(buffer), TRUE, TRUE, &context, &size);
    while (!status)
    {
        if (!strncmpW(di->ObjectName.Buffer, steam_ack_event, ARRAY_SIZE(steam_ack_event) - 1))
        {
            WINE_TRACE("Found event %s.\n", wine_dbgstr_w(di->ObjectName.Buffer));
            ret = OpenEventW(SYNCHRONIZE, FALSE, di->ObjectName.Buffer);
            if (!ret)
                WINE_WARN("Failed to create event, err %u.\n", GetLastError());
            break;
        }
        status = NtQueryDirectoryObject(dir, di, sizeof(buffer), TRUE, FALSE, &context, &size);
    }
    if (status && status != STATUS_NO_MORE_ENTRIES)
        WINE_WARN("NtQueryDirectoryObject failed, status %#x.\n", status);
    WINE_TRACE("ret %p.\n", ret);

    CloseHandle(dir);
    return ret;
}

static DWORD WINAPI steam_drm_thread(void *arg)
{
    HANDLE consume, produce;
    HANDLE start_ack = NULL;
    HANDLE child = arg;
    DWORD pid;
    LONG prev;

    consume = CreateSemaphoreA(NULL, 0, 512, "STEAM_DIPC_CONSUME");
    if (!consume)
    {
        WINE_ERR("Failed to create consume semaphore, err %u.\n", GetLastError());
        return -1;
    }
    produce = CreateSemaphoreA(NULL, 1, 512, "SREAM_DIPC_PRODUCE");
    if (!produce)
    {
        CloseHandle(consume);
        WINE_ERR("Failed to create produce semaphore, err %u.\n", GetLastError());
        return -1;
    }

    pid = GetProcessId(child);

    WINE_TRACE("Child pid %04x.\n", pid);

    while (WaitForSingleObject(consume, INFINITE) == WAIT_OBJECT_0)
    {
        WINE_TRACE("Got event.\n");

        if (!start_ack)
            start_ack = find_ack_event();
        if (start_ack)
            SetEvent(start_ack);
        ReleaseSemaphore(produce, 1, &prev);
        WINE_TRACE("prev %d.\n", prev);
    }

    return 0;
}

BOOL is_ptraced(void)
{
    char key[50];
    int value;
    FILE *fp = fopen("/proc/self/status", "r");
    BOOL ret = FALSE;

    if (!fp) return FALSE;

    while (fscanf(fp, " %s	%d\n", key, &value) > 0)
    {
        if (!strcmp("TracerPid:", key))
        {
            ret = (value != 0);
            break;
        }
    }

    fclose(fp);
    return ret;
}

int main(int argc, char *argv[])
{
    HANDLE wait_handle = INVALID_HANDLE_VALUE;
    HANDLE event2 = INVALID_HANDLE_VALUE;
    HANDLE event = INVALID_HANDLE_VALUE;
    HANDLE child = INVALID_HANDLE_VALUE;
    BOOL game_process = FALSE;
    DWORD rc = 0;

    WINE_TRACE("\n");

    if (steam_command_handler(argc, argv))
        return 0;

    if (getenv("SteamGameId"))
    {
        /* do setup only for game process */
        event = CreateEventA(NULL, FALSE, FALSE, "Steam3Master_SharedMemLock");

        /* For 2K Launcher. */
        event2 = CreateEventA(NULL, FALSE, FALSE, "Global\\Valve_SteamIPC_Class");

        CreateThread(NULL, 0, create_steam_window, NULL, 0, NULL);

        set_active_process_pid();

        if (SteamAPI_Init())
        {
            setup_steam_registry();
            setup_battleye_bridge();
            setup_eac_bridge();
            setup_proton_voice_files();
        }
        else
        {
            WINE_ERR("SteamAPI_Init failed\n");
        }

        setup_steam_files();

        if (env_nonzero("PROTON_WAIT_ATTACH"))
        {
            unsigned int sleep_count = 0;
            WINE_TRACE("PROTON_WAIT_ATTACH is set, waiting for debugger...\n");
            while (!IsDebuggerPresent() && !is_ptraced())
            {
                Sleep(100);
                ++sleep_count;
                if (sleep_count >= 10)
                {
                    WINE_TRACE("still waiting for debugger...\n");
                    sleep_count = 0;
                }
            }
        }

        SteamAPI_Shutdown();

        game_process = TRUE;
    }

    if (argc > 1)
    {
        BOOL should_await;

        if (game_process)
            setup_vr_registry();

        child = run_process(&should_await, game_process);

        if (should_await)
        {
            if (child == INVALID_HANDLE_VALUE)
                return 1;

            wait_handle = child;
        }

        if (game_process)
            CreateThread(NULL, 0, steam_drm_thread, child, 0, NULL);
    }

    if (game_process)
        NtSetInformationProcess( GetCurrentProcess(), (PROCESSINFOCLASS)1000 /* ProcessWineMakeProcessSystem */,
                                 &wait_handle, sizeof(HANDLE *) );

    if(wait_handle != INVALID_HANDLE_VALUE)
    {
        HANDLE waits[2];
        DWORD ret;
        int wait_count;

        waits[0] = wait_handle;
        waits[1] = NULL;
        wait_count = 1;
        if (game_process)
        {
            if ((waits[1] = CreateEventA(NULL, FALSE, FALSE, "PROTON_STEAM_EXE_RESTART_APP")))
            {
                ++wait_count;
            }
            else
            {
                WINE_ERR("Failed to create restart event, err %lu.\n", GetLastError());
            }
        }
        FreeConsole();
        while ((ret = WaitForMultipleObjects(wait_count, waits, FALSE, INFINITE) != WAIT_OBJECT_0))
        {
            BOOL should_await;

            if (ret != WAIT_OBJECT_0 + 1)
            {
                WINE_ERR("Wait failed.\n");
                break;
            }
            if (child != INVALID_HANDLE_VALUE)
            {
                if (WaitForSingleObject(child, 0) == WAIT_TIMEOUT)
                {
                    WINE_ERR("Child is still running, not restarting.\n");
                    continue;
                }
                CloseHandle(child);
            }
            child = run_process(&should_await, game_process);
        }
        CloseHandle(waits[1]);
    }

    if (event != INVALID_HANDLE_VALUE)
        CloseHandle(event);
    if (event2 != INVALID_HANDLE_VALUE)
        CloseHandle(event2);

    if (child != INVALID_HANDLE_VALUE)
    {
        GetExitCodeProcess(child, &rc);
        CloseHandle(child);
    }

    return rc;
}
