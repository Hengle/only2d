//
// Created by leafnsand on 2015/7/21.
//

#ifndef ONLY2D_QUAD_H
#define ONLY2D_QUAD_H

#include "Drawable.h"
#include "Shader.h"

#include <memory>

namespace only2d
{
    class Quad : public Drawable
    {
    public:
	    explicit Quad(int32_t width, int32_t height);

	    virtual ~Quad();

	    virtual void draw() override;

	    int32_t getHeight() const;

	    void setHeight(int32_t height);

	    int32_t getWidth() const;

	    void setWidth(int32_t width);

    private:
	    void updateVertices();

    protected:
	    std::shared_ptr<Shader> shader;
	    std::vector<Vertex> vertices;
	    int32_t width;
	    int32_t height;

	    friend class QuadBatch;
    };
}

#endif //ONLY2D_QUAD_H