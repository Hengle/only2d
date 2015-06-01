//
// Created by leafnsand on 2015/6/1.
//

#include "Drawable.h"

namespace only2d
{
    Drawable::Drawable() :
            x(0.0f),
            y(0.0f),
            rotation(0.0f),
            scaleX(1.0f),
            scaleY(1.0f),
            offsetX(0.0f),
            offsetY(0.0f),
            skewX(0.0f),
            skewY(0.0f),
            alpha(1.0f),
            visible(true)
    {
    }

    Drawable::~Drawable()
    {
    }

    float Drawable::getX() const
    {
        return x;
    }

    void Drawable::setX(float x)
    {
        this->x = x;
    }

    float Drawable::getY() const
    {
        return y;
    }

    void Drawable::setY(float y)
    {
        this->y = y;
    }

    float Drawable::getRotation() const
    {
        return rotation;
    }

    void Drawable::setRotation(float rotation)
    {
        this->rotation = rotation;
    }

    float Drawable::getScaleX() const
    {
        return scaleX;
    }

    void Drawable::setScaleX(float scaleX)
    {
        this->scaleX = scaleX;
    }

    float Drawable::getScaleY() const
    {
        return scaleY;
    }

    void Drawable::setScaleY(float scaleY)
    {
        this->scaleY = scaleY;
    }

    float Drawable::getOffsetX() const
    {
        return offsetX;
    }

    void Drawable::setOffsetX(float offsetX)
    {
        this->offsetX = offsetX;
    }

    float Drawable::getOffsetY() const
    {
        return offsetY;
    }

    void Drawable::setOffsetY(float offsetY)
    {
        this->offsetY = offsetY;
    }

    float Drawable::getSkewX() const
    {
        return skewX;
    }

    void Drawable::setSkewX(float skewX)
    {
        this->skewX = skewX;
    }

    float Drawable::getSkewY() const
    {
        return skewY;
    }

    void Drawable::setSkewY(float skewY)
    {
        this->skewY = skewY;
    }

    float Drawable::getAlpha() const
    {
        return alpha;
    }

    void Drawable::setAlpha(float alpha)
    {
        this->alpha = alpha;
    }

    bool Drawable::isVisible() const
    {
        return visible;
    }

    void Drawable::setVisible(bool visible)
    {
        this->visible = visible;
    }
}