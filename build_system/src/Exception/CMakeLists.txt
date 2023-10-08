add_subdirectory(FlagParseException)
add_library(Exception FlagParseException)
target_link_libraries(Exception 
    FlagParseException
)