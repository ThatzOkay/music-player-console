#if defined(SWITCH)
#include <switch.h>
#endif

#if defined(__WIIU__)
#include <unistd.h>

#include <proc_ui/procui.h>
#include <sysapp/launch.h>
#include <whb/log.h>
#include <whb/log_cafe.h>
#include <whb/log_udp.h>

#include <nn/ac.h>

#include <sys/iosupport.h>
#include <unistd.h>
#endif

#include "main.h"
#include "Utils.h"
#include "ThemeManager.h"
#include "MainDisplay.h"

//#include <sqlite3.h>
#include <stdio.h>

void quit() {
    #ifdef __WIIU__
	// will exit via procui loop in RootDisplay
	SYSLaunchMenu();
    #else
	RootDisplay::mainDisplay->isRunning = false;
    #endif
}

#if defined(__WIIU__)
void wiiuSetPwd()
{
#define MUSIC_PLAYER_PATH ROOT_PATH "wiiu/apps/spotify/"

    // create and cd into the spotiy directory
    mkpath(MUSIC_PLAYER_PATH);
    chdir(MUSIC_PLAYER_PATH);
}
#endif

// void initDatabase()
// {
//     const char *database_name = ROOT_PATH "music_player.db";
//     FILE *fp = fopen(database_name, "r");
//     if (fp == NULL) {
//         fclose(fopen(database_name, "w"));
//     } else {
//         fclose(fp);
//     }

//     sqlite3 *db;
//     int rc = sqlite3_open(database_name, &db);

//     if (rc != SQLITE_OK) {
//         logMessage("Error opening database: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);
//         return;
//     }
// }

int main(int argc, char **argv)
{
    logMessage("Starting Music Player\n");
    #if defined(__WIIU__)
    wiiuSetPwd();
    //initDatabase();

    nn::ac::ConfigIdNum configId;

    nn::ac::Initialize();
    nn::ac::GetStartupId(&configId);
    nn::ac::Connect(configId);
    #endif

    MUSIC_PLAYER::ThemeManager::themeManagerInit();

    // initialize main title screen
    MainDisplay *display = new MainDisplay();

    auto events = display->events;
    events->quitaction = quit;

    // start primary app
    display->mainLoop();

    return 0;
}
