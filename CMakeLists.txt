cmake_minimum_required(VERSION 3.2)
project(only2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/sample/build)

find_library(3rd_SDL2 SDL2)
if(MINGW)
    add_definitions("-DSDL_MAIN_HANDLED")
elseif(APPLE)
    include_directories(/usr/local/include)
endif()

include_directories(src)
add_definitions("-DSTB_IMAGE_IMPLEMENTATION")

set(common_src
    src/common/Color.h
    src/common/Console.cpp
    src/common/Data.cpp
    src/common/Matrix.cpp
    src/common/Module.cpp
    src/common/Vector.cpp
    src/common/Vertex.h
)

set(library_glad_src
    src/library/glad/glad.c
)

set(library_stb_src
    src/library/stb/stb_image.h
)

set(library_src
    ${library_glad_src}
    ${library_stb_src}
)

set(module_application_src
    src/modules/application/Application.cpp
)

set(module_event_src
    src/modules/event/Event.cpp
)

set(module_filesystem_src
    src/modules/filesystem/File.cpp
    src/modules/filesystem/FileData.cpp
    src/modules/filesystem/FileSystem.cpp
)

set(module_graphics_src
    src/modules/graphics/Drawable.cpp
    src/modules/graphics/Graphics.cpp
    src/modules/graphics/Image.cpp
    src/modules/graphics/ImageData.cpp
    src/modules/graphics/ImageShader.cpp
    src/modules/graphics/OpenGL.cpp
    src/modules/graphics/Shader.cpp
    src/modules/graphics/Viewport.cpp
)

set(module_texture_src
    src/modules/texture/Texture.cpp
    src/modules/texture/TextureData.cpp
    src/modules/texture/TextureParser.cpp
)

set(module_timer_src
    src/modules/timer/Timer.cpp
)

set(module_window_src
    src/modules/window/Window.cpp
    src/modules/window/WindowSettings.cpp
)

set(module_src
    ${module_application_src}
    ${module_event_src}
    ${module_filesystem_src}
    ${module_graphics_src}
    ${module_only2d_src}
    ${module_texture_src}
    ${module_timer_src}
    ${module_window_src}
)

set(only2d_src src/Only2D.h
    ${common_src}
    ${library_src}
    ${module_src}
)

add_library(only2d ${only2d_src})

set(sample_src
    sample/src/main.cpp
    sample/src/Sample.cpp
)

add_executable(sample ${sample_src})
target_link_libraries(sample only2d ${3rd_SDL2})