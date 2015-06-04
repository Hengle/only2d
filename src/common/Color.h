//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_COLOR_H
#define ONLY2D_COLOR_H

#include <cstdint>

#define ColorWhite Color(0xff, 0xff, 0xff, 0xff)
#define ColorSilver Color(0xc0, 0xc0, 0xc0, 0xff)
#define ColorGray Color(0x80, 0x80, 0x80, 0xff)
#define ColorBlack Color(0x00, 0x00, 0x00, 0xff)
#define ColorRed Color(0xff, 0x00, 0x00, 0xff)
#define ColorMaroon Color(0x80, 0x00, 0x00, 0xff)
#define ColorYellow Color(0xff, 0xff, 0x00, 0xff)
#define ColorOlive Color(0x80, 0x80, 0x00, 0xff)
#define ColorLime Color(0x00, 0xff, 0x00, 0xff)
#define ColorGreen Color(0x00, 0x80, 0x00, 0xff)
#define ColorAqua Color(0x00, 0xff, 0xff, 0xff)
#define ColorTeal Color(0x00, 0x80, 0x80, 0xff)
#define ColorBlue Color(0x00, 0x00, 0xff, 0xff)
#define ColorNavy Color(0x00, 0x00, 0x80, 0xff)
#define ColorFuchsia Color(0xff, 0x00, 0xff, 0xff)
#define ColorPurple Color(0x80, 0x00, 0x80, 0xff)

namespace only2d
{
    template<typename T>
    class ColorTemplate
    {
    public:
        ColorTemplate() : r(0), g(0), b(0), a(0)
        { };

        ColorTemplate(T r, T g, T b, T a) : r(r), g(g), b(b), a(a)
        { };

        ~ColorTemplate()
        { };

        void set(T r, T g, T b, T a)
        {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }

        ColorTemplate<T> &operator+=(const ColorTemplate<T> &color)
        {
            r += color.r;
            g += color.g;
            b += color.b;
            a += color.a;
            return *this;
        }

        ColorTemplate<T> &operator*=(T scale)
        {
            r *= scale;
            g *= scale;
            b *= scale;
            a *= scale;
            return *this;
        }

        ColorTemplate<T> &operator/=(T scale)
        {
            r /= scale;
            g /= scale;
            b /= scale;
            a /= scale;
            return *this;
        }

    public:
        T r;
        T g;
        T b;
        T a;
    };

    template<typename T>
    ColorTemplate<T> &operator+(const ColorTemplate<T> &a, const ColorTemplate<T> &b)
    {
        ColorTemplate<T> tmp(a);
        tmp += b;
        return tmp;
    }

    template<typename T>
    ColorTemplate<T> &operator*(const ColorTemplate<T> &a, T s)
    {
        ColorTemplate<T> tmp(a);
        tmp *= s;
        return tmp;
    }

    template<typename T>
    ColorTemplate<T> &operator/(const ColorTemplate<T> &a, T s)
    {
        ColorTemplate<T> tmp(a);
        tmp /= s;
        return tmp;
    }

    typedef ColorTemplate<uint8_t> Color;
    typedef ColorTemplate<float> FloatColor;
    typedef Color Pixel;

    static Color colorFromInt(int32_t color)
    {
        return Color(static_cast<uint8_t>((color >> 24) & 0xFF),
                     static_cast<uint8_t>((color >> 16) & 0xFF),
                     static_cast<uint8_t>((color >> 8) & 0xFF),
                     static_cast<uint8_t>(color & 0xFF));
    }
}

#endif //ONLY2D_COLOR_H