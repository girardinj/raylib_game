
file(GLOB sources_files
    "*.h"
    "*.cpp"
    "*.hpp"
    "*.hxx"
    "*.cxx")

    
add_executable(Game ${sources_files} ${BINARY_DIR})

target_link_libraries(${PROJECT_NAME} raylib)