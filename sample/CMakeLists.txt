set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/sample/build)

find_library(3rd_SDL2 SDL2)

include_directories(../only2d)

set(cpp_sample_src
    cpp_sample/main.cpp
    cpp_sample/Sample.cpp
)

add_executable(cpp_sample ${cpp_sample_src})
target_link_libraries(cpp_sample only2d ${3rd_SDL2})