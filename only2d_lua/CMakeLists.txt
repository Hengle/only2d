set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/sample/build)

find_library(3rd_SDL2 SDL2)

include_directories(. ../only2d)

set(common_src
    common/Lua.cpp
    common/LuaData.cpp
    common/LuaObject.cpp
)

set(library_lua_src
    library/lua/lapi.c
    library/lua/lcorolib.c
    library/lua/ldump.c
    library/lua/llex.c
    library/lua/lopcodes.c
    library/lua/lstrlib.c
    library/lua/lutf8lib.c
    library/lua/lauxlib.c
    library/lua/lctype.c
    library/lua/lfunc.c
    library/lua/lmathlib.c
    library/lua/loslib.c
    library/lua/ltable.c
    library/lua/lvm.c
    library/lua/lbaselib.c
    library/lua/ldblib.c
    library/lua/lgc.c
    library/lua/lmem.c
    library/lua/lparser.c
    library/lua/ltablib.c
    library/lua/lzio.c
    library/lua/lbitlib.c
    library/lua/ldebug.c
    library/lua/linit.c
    library/lua/loadlib.c
    library/lua/lstate.c
    library/lua/ltm.c
    library/lua/lcode.c
    library/lua/ldo.c
    library/lua/liolib.c
    library/lua/lobject.c
    library/lua/lstring.c
    library/lua/lundump.c
)

set(module_application_src
    modules/application/LuaApplication.cpp
)

set(module_event_src
    modules/event/LuaEvent.cpp
)

set(module_filesystem_src
    modules/filesystem/LuaFile.cpp
    modules/filesystem/LuaFileData.cpp
    modules/filesystem/LuaFileReadMode.cpp
    modules/filesystem/LuaFileSystem.cpp
)

set(module_graphics_src
    modules/graphics/LuaBlendMode.cpp
    modules/graphics/LuaDrawable.cpp
    modules/graphics/LuaGraphics.cpp
    modules/graphics/LuaImage.cpp
    modules/graphics/LuaImageBatch.cpp
    modules/graphics/LuaImageData.cpp
    modules/graphics/LuaImageDataFilterMode.cpp
    modules/graphics/LuaImageDataWrapMode.cpp
    modules/graphics/LuaShader.cpp
)

set(module_keyboard_src
    modules/keyboard/LuaKey.cpp
    modules/keyboard/LuaKeyboard.cpp
)

set(module_texture_src
    modules/texture/LuaTexture.cpp
    modules/texture/LuaTextureData.cpp
)

set(module_timer_src
    modules/timer/LuaTimer.cpp
)

set(module_window_src
    modules/window/LuaWindow.cpp
)

set(module_src
    ${module_application_src}
    ${module_event_src}
    ${module_filesystem_src}
    ${module_graphics_src}
    ${module_keyboard_src}
    ${module_texture_src}
    ${module_timer_src}
    ${module_window_src}
    ${module_event_src}
)

set(library_src
    ${library_lua_src}
)

set(only2d_lua_src main.cpp LuaOnly2D.cpp
    ${common_src}
    ${library_src}
    ${module_src}
)

add_executable(only2d_lua ${only2d_lua_src})
target_link_libraries(only2d_lua only2d ${3rd_SDL2})