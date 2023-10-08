#include "DependencyGraph.h"
#include <dirent.h>
#include <iostream>
#include <regex>
#include "../../cfg/ConfigManager.h"
#include "../../src/Exception/FlagParseException/FlagParseException.h"
#include "../../src/PathFilter/PathFilter.h"

DependencyGraph::~DependencyGraph() {
    for (auto v : graph) {
        for (const char* c : v.second) {
            delete c;
        }
        delete v.first;
    }
}
DependencyGraph::DependencyGraph() {
    find_main();
}
void DependencyGraph::find_main() {
    DIR* dir = opendir(ConfigManager::ROOT_PATH.c_str());
    if (!dir) {
        throw FlagParseException("Given path is not exist");
    }
    dirent* ent;
    while ((ent = readdir(dir)) != NULL) {
        if (PathFilter::isInBanlist(ent->d_name))
            continue;
        std::cout << ent->d_name << " ";
    }
}