//
// Created by leafnsand on 2015/6/15.
//

#ifndef ONLY2D_IMAGEBATCH_H
#define ONLY2D_IMAGEBATCH_H

#include "Image.h"
#include "ImageBatchShader.h"
#include "VertexData.h"
#include "VertexIndexData.h"

namespace only2d
{
    class ImageBatch : public Drawable
    {
    public:
        ImageBatch();

        virtual ~ImageBatch();

        void addImage(std::shared_ptr<Image> image);

        void clear();

        void draw();

    private:
        std::shared_ptr<ImageData> data;
        std::shared_ptr<ImageBatchShader> shader;
        VertexIndexData indices;
        VertexData vertices;
        bool needSyncBuffer;
    };
}

#endif //ONLY2D_IMAGEBATCH_H
