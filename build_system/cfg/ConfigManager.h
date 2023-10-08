#pragma once
#include <string>
struct ConfigManager {
    static std::string CONFIG_FILE;
    static std::string ROOT_PATH;
    static std::string MAIN_FILENAME;
    static void set_root_path(const char* path);
};
