//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    typedef unsigned char rgb_value;

    class color {
    private:
        rgb_value r;
        rgb_value g;
        rgb_value b;
    public:
        static const color RED;
        static const color GREEN;
        static const color BLUE;
        static const color BLACK;
        static const color WHITE;
        color();
        color(const color &c);
        color(rgb_value r, rgb_value g, rgb_value b);
        rgb_value red() const;
        rgb_value& red();
        rgb_value green() const;
        rgb_value& green();
        rgb_value blue() const;
        rgb_value& blue();
        color& operator=(const color&c);
        bool operator==(const color &c) const;
        bool operator!=(const color &c) const;
        void invert();
        void to_gray_scale();
        void mix(const color& c, int f);
    };
}
#endif
