#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill) {
        assert(w>0 && h>0);

        iwidth = w;
        iheight = h;
        pixels = new color*[w];

        for(int i=0; i<w ;i++){
            pixels[i] = new color[h];
            for(int j=0; j< h ; j++){
                pixels[i][j] = fill;
            }
        }

    }
    image::~image() {
        delete [] pixels[0];
        delete [] pixels;
        // NOT SURE ABOUT THIS ONE, ASK TEACHER ! ! !
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
        for(int i=x; i<w ;i++){
            pixels[i] = new color[h];
            for(int j=y; j< h ; j++){
                pixels[i][j] = c;
            }
        }
    }
    void image::replace(const color& a, const color& b) {
        for(int i=0; i<iwidth; i++)
            for(int j=0; j<iheight; j++)
                if(pixels[i][j] == a)
                    pixels[i][j] = b;
    }
    void image::add(const image& img, const color& neutral,
                    int x, int y) {
        for(int i=0; i< img.width();i++){
            for(int j=0; j<img.height();j++){
                if( img.at(i,j) != neutral )
                    pixels[x+i][y+j] = img.at(i,j);
            }
        }
        /*
        for(int i=x; i< img.width();i++){
            for(int j=y; j< img.height();j++){
                if (img.at(i-x,j-x) != neutral ){
                    pixels[i][j] = img.at(i-x,j-y);
                }
            }
        }*/ // lul i'm so dumb
    }
    void image::crop(int x, int y, int w, int h) {

        image *temp = new image( w, h, color() );
        for(int i=0; i<w;i++){
            for(int j=0; j<h; j++){
                temp->pixels[i][j] = pixels[x+i][y+j];
                // replace( temp->pixels[i][j], pixels[x+i][y+j] );
            }
        }

        //this->~image();
        image(w,h,color());
        iwidth = w;
        iheight = h;
        for(int i=0; i<w;i++){
            for(int j=0; j<h; j++){
                pixels[i][j] = temp->at(i,j);
            }
        }

    }
    void image::rotate_left() {
        image *temp = new image( iheight, iwidth, color() );
        for(int i=0; i<iheight ;i++)
            for(int j=0; j<iwidth ;j++){
                temp->at(i,j) = pixels[j][i];
            }

        iwidth = temp->iwidth;
        iheight = temp->iheight;
        pixels = temp->pixels;
    }
    void image::rotate_right() {
        image *temp = new image( iheight, iwidth, color() );
        for(int i=0; i<iwidth ;i++)
            for(int j=0; j<iheight ;j++){
                temp->at(j,i) = pixels[i][j];
            }
        pixels = temp->pixels;
        iwidth = temp->iwidth;
        iheight = temp->iheight;

    }
    void image::mix(const image& img, int factor) {
        for(int i=0; i<iwidth; i++)
            for(int j=0; j<iheight; j++){
                pixels[i][j].mix( img.at(i,j), factor);
            }
    }
}
