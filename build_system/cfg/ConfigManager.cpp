#include "ConfigManager.h"
#include <iostream>
#include <filesystem>

std::string ConfigManager::CONFIG_FILE = "build.yml";
std::string ConfigManager::ROOT_PATH = "";
std::string ConfigManager::MAIN_FILENAME = "main.cpp";

void ConfigManager::set_root_path(const char* path){
    ConfigManager::ROOT_PATH = std::filesystem::canonical(path);    
}
