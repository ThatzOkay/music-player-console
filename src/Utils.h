#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "../libs/chesto/src/colorspaces.hpp"

#ifdef __WIIU__
#include <whb/log.h>
#include <whb/log_cafe.h>
#include <whb/log_udp.h>
#endif

#define ROOT_PATH "fs:/vol/external01/"

// folder functions
bool mkpath(const std::string& path);

bool fileExists(const std::string& path);

// for cross platform dir creation
int my_mkdir(const std::string& path, int perms = 0700);

// for color conversion
int hexToInt(const char* hex);
rgb hexToRgb(const char* hex);

// for log
void logMessage(const char* message, ...);

#endif // UTILS_H