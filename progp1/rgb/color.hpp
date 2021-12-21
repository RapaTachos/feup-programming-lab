//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    typedef unsigned char rgb_value;

    class color {
    private:
        //! red value of a pixel
        rgb_value r;
        //! green value of a pixel
        rgb_value g;
        //! blue value of a pixel
        rgb_value b;
    public:
        //! rgb values for red color
        static const color RED;
        //! rgb values for green color
        static const color GREEN;
        //! rgb values for blue color
        static const color BLUE;
        //! rgb values for black color
        static const color BLACK;
        //! rgb values for white color
        static const color WHITE;

        /*!
         * Default color constructor that takes no parameters
         */
        color();

        /*!
         * Color constructor that recieves another color
         * @param c
         */
        color(const color &c);

        /*!
         *  Color constructor that recieves each rgb value individually
         * @param r
         * @param g
         * @param b
         */
        color(rgb_value r, rgb_value g, rgb_value b);

        /*!
         * Get's rgb values for red color
         * @return constant reference for red color
         */
        rgb_value red() const;
        /*!
         * Get's rgb values for red color
         * @return variable reference for red color
         */
        rgb_value& red();
        /*!
         * Get's rgb values for green color
         * @return constant reference for green color
         */
        rgb_value green() const;
        /*!
         * Get's rgb values for green color
         * @return variable reference for green color
         */
        rgb_value& green();
        /*!
         * Get's rgb values for blue color
         * @return constant reference for blue color
         */
        rgb_value blue() const;
        /*!
         * Get's rgb values for blue color
         * @return variable reference for blue color
         */
        rgb_value& blue();

        /*!
         * Simple assignment operator. Assigns values from right side operands to left side operand
         * @param c
         * @return color of the left operand after the assignment
         */
        color& operator=(const color&c);

        /*!
         * Equality Comparator - checks if the values of two colors are equal or not
         * @param c
         * @return 'true' if values of two colors are equal. And 'false' otherwise.
         */
        bool operator==(const color &c) const;

        /*!
         * Inequality Comparator
         * @param c
         * @return 'true' if values of two colors are not equal. And 'false' otherwise.
         */
        bool operator!=(const color &c) const;

        /*!
         * Inverts the pixel color
         */
        void invert();

        /*!
         * Transforms the current color to the correspondent gray tone
         */
        void to_gray_scale();

        /*!
         * Mixes the current color with another (c) with a factor of 'f' (int between 0-100)
         * @param c
         * @param f
         */
        void mix(const color& c, int f);
    };
}
#endif
