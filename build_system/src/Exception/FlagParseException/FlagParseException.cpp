#include "FlagParseException.h"
#include "string"

FlagParseException::FlagParseException(std::string msg){
    this->msg = msg + '\n';
}