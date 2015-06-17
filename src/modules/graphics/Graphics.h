//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_GRAPHICS_H
#define ONLY2D_GRAPHICS_H

#include "OpenGL.h"
#include "Shader.h"
#include "Image.h"
#include "ImageBatch.h"
#include "ImageData.h"

#include "common/Color.h"
#include "common/Module.h"

namespace only2d
{
    class Graphics : public Module
    {
    public:
        Graphics();

        virtual ~Graphics();

        virtual ModuleType getType() const override;

        virtual const char *getName() const override;

        void setResolution(int32_t width, int32_t height);

        void clear();

        void checkOpenGLError();

        std::shared_ptr<Shader> createShader(std::string &vertex, std::string fragment);

        std::shared_ptr<ImageData> createImageData(int32_t width, int32_t height, std::shared_ptr<Data> data);

        std::shared_ptr<Image> createImage(std::shared_ptr<ImageData> data);

        std::shared_ptr<ImageBatch> createImageBatch();

        std::shared_ptr<ImageShader> getImageShader();

        std::shared_ptr<ImageBatchShader> getImageBatchShader();

        Color getBackgroundColor() const;

        void setBackgroundColor(const Color &backgroundColor);

        const Matrix &getProjectionMatrix() const;

        std::shared_ptr<OpenGL> &getOpenGL();

    private:
        std::shared_ptr<OpenGL> gl;
        std::shared_ptr<ImageShader> imageShader;
        std::shared_ptr<ImageBatchShader> imageBatchShader;
        FloatColor backgroundColor;
        Viewport viewport;
        Matrix projectionMatrix;
    };
}

#endif //ONLY2D_GRAPHICS_H
