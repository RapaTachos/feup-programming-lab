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
        /**
         * Default color constructor that takes no parameters
         */
        color();

        /**
         * Color constructor that recieves another color
         * @param c
         */
        color(const color &c);

        /**
         *  Color constructor that recieves each rgb value individually
         * @param r
         * @param g
         * @param b
         */
        color(rgb_value r, rgb_value g, rgb_value b);

        rgb_value red() const;
        rgb_value& red();
        rgb_value green() const;
        rgb_value& green();
        rgb_value blue() const;
        rgb_value& blue();

        /**
         * Simple assignment operator. Assigns values from right side operands to left side operand
         * @param c
         * @return
         */
        color& operator=(const color&c);

        /**
         * Equality Comparator - checks if the values of two colors are equal or not
         * @param c
         * @return 'true' if values of two colors are equal. And 'false' otherwise.
         */
        bool operator==(const color &c) const;

        /**
         * Inequality Comparator
         * @param c
         * @return 'true' if values of two colors are not equal. And 'false' otherwise.
         */
        bool operator!=(const color &c) const;

        /**
         * Inverts the pixel color
         */
        void invert();

        /**
         * Transforms the current color to the correspondent gray tone
         */
        void to_gray_scale();

        /**
         * Mixes the current color with another (c) with a factor of 'f' (int between 0-100)
         * @param c
         * @param f
         */
        void mix(const color& c, int f);
    };
}
#endif
