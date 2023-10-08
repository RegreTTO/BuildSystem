add_library(staff flag_parse.cpp)
target_link_libraries(staff PUBLIC cfg FlagParseException)