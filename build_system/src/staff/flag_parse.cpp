#include <functional>
#include <string>
#include "cfg/ConfigManager.h"

void flag_parse(int argc, char** argv) {
    typedef std::function<void(std::string)> OneArgHandler;
    typedef std::function<void()> NoArgsHandler;
#define S(str, f)                                    \
    {                                                \
        str, [](const std::string& arg) { f = arg; } \
    }

    std::unordered_map<std::string, OneArgHandler> oneArg{
        S("-c", ConfigManager::CONFIG_FILE),
    };
#undef S
#define S(str, k, v)         \
    {                        \
        str, []() { k = v; } \
    }
    std::unordered_map<std::string, NoArgsHandler> noArgs{
    };

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && ConfigManager::ROOT_PATH == ""){
            ConfigManager::ROOT_PATH = argv[i];
            continue;
        }
        auto noArgsFlag = noArgs.find(argv[i]);
        if (noArgsFlag != noArgs.end()) {
            (*noArgsFlag).second();
            continue;
        }
        auto oneArgFlag = oneArg.find(argv[i]);
        if (oneArgFlag == oneArg.end()) {
            throw FlagParseException(
                std::string("There is not such flag as \"") + argv[i] + "\"");
        }
        (*oneArgFlag).second(std::string(argv[i + 1]));
        i++;
    }
}