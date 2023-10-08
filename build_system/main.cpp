#include <functional>
#include <iostream>
#include <map>
#include <string>
#include "cfg/ConfigManager.h"
#include "src/Exception/FlagParseException/FlagParseException.h"
#include "src/staff/flag_parse.cpp"

int main(int argc, char** argv) {
    try {
        flag_parse(argc, argv);
    } catch (FlagParseException& e) {
        std::cout << e.getMessage();
    }
    std::cout<<ConfigManager::ROOT_PATH;
}
