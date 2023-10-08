#include "DependencyGraph.h"
#include <dirent.h>
#include <cstring>
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
void DependencyGraph::filetreeDFS(const char* starting_dir, short max_depth) {
    DIR* dir = opendir(starting_dir);
    if (!dir) {
        throw FlagParseException(
            std::string("Given path is not exist. Path: ") + starting_dir);
    } else if (max_depth - 1 <= 0) {
        return;
    }
    dirent* ent;
    std::vector<const char*> next_directories;
    while ((ent = readdir(dir)) != NULL) {
        if (PathFilter::isInBanlist(ent->d_name) ||
            std::strcmp(ent->d_name, ".") == 0)
            continue;
        if (ent->d_type == DT_DIR) {
            next_directories.push_back(ent->d_name);
            continue;
        }
    }
    for (auto d : next_directories) {
        DependencyGraph::filetreeDFS(
            (std::string(starting_dir) + "/" + d).c_str(), max_depth - 1);
    }
    delete ent;
    free(dir);
}

DependencyGraph::DependencyGraph() {
    filetreeDFS(ConfigManager::ROOT_PATH.c_str());
}