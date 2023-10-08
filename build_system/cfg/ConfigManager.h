#pragma once
#include <string>
struct ConfigManager {
    static std::string CONFIG_FILE;
    static std::string ROOT_PATH;
    static void find_root_path();
};
