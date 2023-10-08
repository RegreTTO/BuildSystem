#include <functional>
#include <iostream>
#include <map>
#include <string>
#include "cfg/ConfigManager.h"
#include "src/DependencyGraph/DependencyGraph.h"
#include "src/Exception/FlagParseException/FlagParseException.h"
#include "src/PathFilter/PathFilter.h"
#include "src/staff/flag_parse.cpp"

int main(int argc, char** argv) {
    try {
        flag_parse(argc, argv);
    } catch (FlagParseException& e) {
        std::cout << e.getMessage();
        exit(1);
    }
    std::printf("Current working directory: %s\n", ConfigManager::ROOT_PATH.c_str());
    PathFilter::init();
    try {
        DependencyGraph gr;
    } catch (FlagParseException& e) {
        std::cout << e.getMessage();
        exit(1);
    }

    exit(0);
}
