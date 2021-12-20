#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill) {
        assert(w>0 && h>0);

        iwidth = w;
        iheight = h;

        pixels = new color*[w];
        color *data = new color[w*h];

        for(int i=0; i<w ;i++){
            pixels[i] = data + i * h;

            for(int j=0; j< h ; j++)
                pixels[i][j] = fill;
        }

    }
    image::~image() {
        delete[] pixels[0];
        delete[] pixels;
    }
    int image::width() const {
        return iwidth;
    }
    int image::height() const {
        return iheight;
    }
    color& image::at(int x, int y) {
        return pixels[x][y];
    }
    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }
    void image::invert() {
        for(int i=0; i<iwidth; i++)
            for(int j=0; j<iheight; j++)
                pixels[i][j].invert();
    }
    void image::to_gray_scale() {
        for(int i=0; i<iwidth; i++)
            for(int j=0; j<iheight; j++)
                pixels[i][j].to_gray_scale();
    }
    void image::fill(int x, int y, int w, int h, const color& c) {
        for(int i=x; i< x+ w ;i++)
            for(int j=y; j< y+h ; j++)
                pixels[i][j] = c;

    }
    void image::replace(const color& a, const color& b) {
        for(int i=0; i<iwidth; i++)
            for(int j=0; j<iheight; j++)
                if(pixels[i][j] == a)
                    pixels[i][j] = b;
    }
    void image::add(const image& img, const color& neutral, int x, int y) {
        for(int i=0; i< img.width();i++)
            for(int j=0; j<img.height();j++)
                if( img.at(i,j) != neutral )
                    pixels[x+i][y+j] = img.at(i,j);

    }
    void image::crop(int x, int y, int w, int h) {
        image *temp = new image( w, h, color() );

        for(int i=0; i<w;i++)
            for(int j=0; j<h; j++)
                temp->pixels[i][j] = pixels[x+i][y+j];


        iwidth = w;
        iheight = h;

        for(int i=0; i<w;i++)
            for(int j=0; j<h; j++)
                pixels[i][j] = temp->at(i,j);

        delete(temp);
    }
    void image::rotate_left() {
        color **new_pixels = new color*[iheight];
        color *new_data = new color[height()*iwidth];
        for(int i=0; i<iheight;i++)
            new_pixels[i] = new_data + i*iwidth;

        for(int i=0; i<width();i++)
            for(int j=0; j<height();j++)
                new_pixels[j][width() - i - 1] = pixels[i][j];

        this->~image();

        int temp_width = iheight;
        iheight = iwidth;
        iwidth = temp_width;

        pixels = new_pixels;
    }
    void image::rotate_right() {
        color **new_pixels = new color*[iheight];
        color *new_data = new color[height()*iwidth];

        for(int i=0; i<iheight;i++)
            new_pixels[i] = new_data + i*iwidth;

        for(int i=0; i<iwidth;i++)
            for(int j=0; j<iheight;j++)
                new_pixels[iheight-j-1][i] = pixels[i][j];

        this->~image();

        int temp_width = iheight;
        iheight = iwidth;
        iwidth = temp_width;

        pixels = new_pixels;
    }
    void image::mix(const image& img, int factor) {
        for(int i=0; i<iwidth; i++)
            for(int j=0; j<iheight; j++)
                pixels[i][j].mix( img.at(i,j), factor);
    }
}
