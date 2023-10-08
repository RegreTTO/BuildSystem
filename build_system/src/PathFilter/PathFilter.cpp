#include "PathFilter.h"
#include <iostream>
#include <regex>
#include <string>

std::vector<const char*> PathFilter::BANLIST = {"build", "target", "\\..+",
                                                ".*Make.*"};
std::regex PathFilter::BANLIST_REGEXP{""};

void PathFilter::init() {
    std::string regexp = "";
    for (const char* w : BANLIST) {
        regexp += std::string("^(?:") + w + ")$|";
    }
    regexp.pop_back();
    std::cout << regexp << '\n';
    PathFilter::BANLIST_REGEXP = std::regex{regexp};
}
void PathFilter::free() {
    for (auto v : PathFilter::BANLIST)
        delete v;
}

bool PathFilter::isInBanlist(const char path[]) {
    return std::regex_match(path, PathFilter::BANLIST_REGEXP);
}

void PathFilter::banlistAppend(const char* v) {
    PathFilter::BANLIST.push_back(v);
}