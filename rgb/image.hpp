//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    class image {
    private:
        //! image width
        int iwidth;
        //! image height
        int iheight;
        //! 2D matrix to represent the pixels of an image
        color **pixels;
    public:
        /*!
         * Constructor for an image with width 'w', height 'h' and an initial color of 'fill'
         * @param w
         * @param h
         * @param fill
         */
        image(int w, int h, const color& fill = color::WHITE);
        /*!
         * Used to deconstruct an image
         */
        ~image();
        /*!
         * Getter for image width
         * @return image width
         */
        int width() const;
        /*!
         * Getter for image height
         * @return image height
         */
        int height() const;
        /*!
         * Gets a mutable reference for the color of a pixel at (x,y)
         * @param x
         * @param y
         * @return reference for a pixel's color at point (x,y)
         */
        color& at(int x, int y);
        /*!
         * Gets a constant reference for the color of a pixel at (x,y)
         * @param x
         * @param y
         * @return reference for a pixel's color at point (x,y)
         */
        const color& at(int x, int y) const;
        /*!
         * Inverts all pixels of an Image using color.invert()
         */
        void invert();
        /*!
         * Converts all pixels of an Image to gray scale
         */
        void to_gray_scale();
        /*!
         * Replaces all pixels with color 'a' with color 'b'
         * @param a
         * @param b
         */
        void replace(const color& a, const color& b);
        /*!
         * Replaces all pixels starting at ( x , y ) to ( x+w , y+h ) with color 'c'
         * @param x
         * @param y
         * @param w width
         * @param h height
         * @param c
         */
        void fill(int x, int y, int w, int h, const color& c);
        /*!
         * Mixes the picture with another (img) using a certain 'factor'
         * @param img
         * @param factor
         */
        void mix(const image& img, int factor);
        /*!
         * Reduces the image dimensions, ( x , y ) to ( x+w , y+h )
         * @param x
         * @param y
         * @param w
         * @param h
         */
        void crop(int x, int y, int w, int h);
        /*!
         * Rotates image counter-clockwise
         */
        void rotate_left();
        /*!
         * Rotates image clockwise
         */
        void rotate_right();
        /*!
         * Adds img's content replacing pixels starting at (x,y) except for those of color 'neutral'
         * @param img
         * @param neutral
         * @param x
         * @param y
         */
        void add(const image& img, const color& neutral, int x, int y);
    };
}


#endif
