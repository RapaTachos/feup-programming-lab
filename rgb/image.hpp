//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    class image {
    private:
        int iwidth;
        int iheight;
        color **pixels;
    public:
        image(int w, int h, const color& fill = color::WHITE);
        ~image();
        int width() const;
        int height() const;
        color& at(int x, int y);
        const color& at(int x, int y) const;
        void invert();
        void to_gray_scale();
        void replace(const color& a, const color& b);
        void fill(int x, int y, int w, int h, const color& c);
        void mix(const image& img, int factor);
        void crop(int x, int y, int w, int h);
        void rotate_left();
        void rotate_right();
        void add(const image& img, const color& neutral,
                 int x, int y);
    };
}


#endif
