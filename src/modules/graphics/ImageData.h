//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_IMAGEDATA_H
#define ONLY2D_IMAGEDATA_H

#include "OpenGL.h"

#include "common/Data.h"
#include "common/Vertex.h"

#include <cstdint>
#include <memory>

namespace only2d
{
    enum class ImageDataWrapMode
    {
        CLAMP,
        REPEAT,
        MIRRORED_REPEAT
    };

    enum class ImageDataFilterMode
    {
        LINEAR,
        NEAREST
    };

    struct ImageDataWrap
    {
        ImageDataWrapMode s = ImageDataWrapMode::CLAMP;
        ImageDataWrapMode t = ImageDataWrapMode::CLAMP;
    };

    struct ImageDataFilter
    {
        ImageDataFilterMode min = ImageDataFilterMode::LINEAR;
        ImageDataFilterMode mag = ImageDataFilterMode::LINEAR;
    };

    class ImageData
    {
    public:
        ImageData(int32_t width, int32_t height, std::shared_ptr<Data> data);

        virtual ~ImageData();

        int32_t getWidth() const;

        void setWidth(int32_t width);

        int32_t getHeight() const;

        void setHeight(int32_t height);

        const Vertex *getVertices() const;

        const ImageDataWrap &getWrap() const;

        void setWrap(const ImageDataWrap &wrap);

        const ImageDataFilter &getFilter() const;

        void setFilter(const ImageDataFilter &filter);

    private:
        void prepareVertices();

        void loadData();

        void loadDefaultData();

        void unloadData();

    protected:
        int32_t width;
        int32_t height;
        Vertex vertices[4];
        GLuint texture;
        ImageDataWrap wrap;
        ImageDataFilter filter;
        std::shared_ptr<Data> data;
        std::shared_ptr<OpenGL> gl;
        bool usingDefaultData;
    };
}

#endif //ONLY2D_IMAGEDATA_H
