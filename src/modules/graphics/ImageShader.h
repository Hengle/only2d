//
// Created by leafnsand on 2015/6/5.
//

#ifndef ONLY2D_IMAGESHADER_H
#define ONLY2D_IMAGESHADER_H

#include "Shader.h"

namespace only2d
{
    class ImageShader : public Shader
    {
    public:
        ImageShader();

        virtual ~ImageShader();

        void setVertexData(const std::vector<Vertex> &vertices);

        void setColor(const Color &color);

        void setAlpha(const float &alpha);

        void setMVPMatrix(const Matrix &matrix);

        void draw();
    };
}

#endif //ONLY2D_IMAGESHADER_H
