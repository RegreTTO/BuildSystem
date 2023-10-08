#ifndef INCLUDE_PATH_FILTER
#include <regex>
class PathFilter {
private:
    // Must be written in RegExp syntax
    static std::vector<const char*> BANLIST;
    static std::regex BANLIST_REGEXP;

public:
    static void init();
    static bool isInBanlist(const char path[]);
    static void banlistAppend(const char* v);
    static void free();
};
#endif
#define INCLUDE_PATH_FILTER