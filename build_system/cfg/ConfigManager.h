#pragma once
#include <string>
struct ConfigManager {
    static std::string CONFIG_FILE;
    static std::string ROOT_PATH;
    static std::string MAIN_FILENAME;
    static int MAX_DEPTH;
    static void set_root_path(const char* path);
};
