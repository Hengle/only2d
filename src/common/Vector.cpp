//
// Created by leafnsand on 2015/6/1.
//

#include "Vector.h"

#include <cmath>

namespace only2d
{
    Vector::Vector() :
            x(0.0f),
            y(0.0f)
    {
    }

    Vector::Vector(float x, float y) :
            x(x),
            y(y)
    {
    }

    void Vector::set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    float Vector::getLength() const
    {
        return sqrtf(x * x + y * y);
    }

    float Vector::normalize(float length)
    {
        auto length_current = getLength();
        if (length_current > 0)
        {
            (*this) *= length / length_current;
        }
        return length_current;
    }

    Vector Vector::getNormal() const
    {
        return Vector(-y, x);
    }

    Vector Vector::getNormal(float scale) const
    {
        return Vector(-y * scale, x * scale);
    }

    Vector Vector::operator+(const Vector &vector) const
    {
        return Vector(x + vector.x, y + vector.y);
    }

    Vector Vector::operator-(const Vector &vector) const
    {
        return Vector(x - vector.x, y - vector.y);
    }

    Vector Vector::operator*(float scale) const
    {
        return Vector(x * scale, y * scale);
    }

    Vector Vector::operator/(float scale) const
    {
        return Vector(x / scale, y / scale);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    void Vector::operator+=(const Vector &vector)
    {
        x += vector.x;
        y += vector.y;
    }

    void Vector::operator-=(const Vector &vector)
    {
        x -= vector.x;
        y -= vector.y;
    }

    void Vector::operator*=(float scale)
    {
        x *= scale;
        y *= scale;
    }

    void Vector::operator/=(float scale)
    {
        x /= scale;
        y /= scale;
    }

    float Vector::operator*(const Vector &vector) const
    {
        return x * vector.x + y * vector.y;
    }

    float Vector::operator^(const Vector &vector) const
    {
        return x * vector.y - y * vector.x;
    }

    bool Vector::operator==(const Vector &vector) const
    {
        return getLength() == vector.getLength();
    }

    bool Vector::operator<(const Vector &vector) const
    {
        return getLength() < vector.getLength();
    }
}