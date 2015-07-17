add_definitions("-DSTB_IMAGE_IMPLEMENTATION")

include_directories(.)

set(common_src
    common/Color.h
    common/Console.cpp
    common/Data.cpp
    common/Matrix.cpp
    common/Module.cpp
    common/Vector.cpp
    common/Vertex.h
)

set(library_glad_src
    library/glad/glad.c
)

set(library_stb_src
    library/stb/stb_image.h
)

set(library_src
    ${library_glad_src}
    ${library_stb_src}
)

set(module_application_src
    modules/application/Application.cpp
)

set(module_event_src
    modules/event/Event.cpp
)

set(module_filesystem_src
    modules/filesystem/File.cpp
    modules/filesystem/FileData.cpp
    modules/filesystem/FileSystem.cpp
)

set(module_graphics_src
    modules/graphics/BlendMode.h
    modules/graphics/Drawable.cpp
    modules/graphics/Graphics.cpp
    modules/graphics/Image.cpp
    modules/graphics/ImageBatch.cpp
    modules/graphics/ImageBatchShader.cpp
    modules/graphics/ImageData.cpp
    modules/graphics/ImageShader.cpp
    modules/graphics/OpenGL.cpp
    modules/graphics/OpenGLData.cpp
    modules/graphics/Shader.cpp
    modules/graphics/VertexData.cpp
    modules/graphics/VertexIndexData.cpp
    modules/graphics/Viewport.cpp
)

set(module_texture_src
    modules/texture/Texture.cpp
    modules/texture/TextureData.cpp
    modules/texture/TextureParser.cpp
)

set(module_timer_src
    modules/timer/Timer.cpp
)

set(module_window_src
    modules/window/Window.cpp
    modules/window/WindowSettings.cpp
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

set(only2d_src Only2D.h
    ${common_src}
    ${library_src}
    ${module_src}
)

add_library(only2d ${only2d_src})