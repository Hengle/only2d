//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_IMAGE_H
#define ONLY2D_IMAGE_H

#include "Drawable.h"
#include "ImageData.h"
#include "ImageShader.h"

#include <memory>

namespace only2d
{
    class Image : public Drawable
    {
    public:
        explicit Image(std::shared_ptr<ImageData> data);

        ~Image();

        virtual void draw() override;

        const Color &getColor() const;

        void setColor(const Color &color);

        int32_t getHeight() const;

        void setHeight(int32_t height);

        int32_t getWidth() const;

        void setWidth(int32_t width);

    private:
        void updateVertices();

    protected:
        std::shared_ptr<ImageData> data;
        std::shared_ptr<ImageShader> shader;
        Color color;
        std::vector<Vertex> vertices;
        int32_t width;
        int32_t height;
    };
}

#endif //ONLY2D_IMAGE_H
