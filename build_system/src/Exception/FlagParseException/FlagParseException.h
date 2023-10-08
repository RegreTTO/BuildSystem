#ifndef INCLUDE_FLAG_PARSE_EXCEPTION
#include <string>
class FlagParseException{
private:
    std::string msg;

public:
    FlagParseException(std::string msg);
    std::string getMessage(){return this->msg;} 
};
#endif
#define INCLUDE_FLAG_PARSE_EXCEPTION