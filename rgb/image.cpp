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
            for(int j=0; j< h ; j++){
                pixels[i][j] = fill;
            }
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
        /*
        color **new_pixels;
        new_pixels = new color*[ iheight ];

        for(int i=0; i< iwidth ;i++){
            new_pixels[i] = new color[ iwidth ];
            for(int j=0; j< iheight ;j++)
                new_pixels[j][iheight-i-1]= pixels[i][j];
        }

        int temp = iwidth;
        iwidth = iheight;
        iheight = temp;

        //this->~image();
        pixels = new_pixels;
        */


        image *temp = new image(iheight, iwidth, color());
        for(int i=0; i<iwidth;i++)
            for(int j=0; j<iheight;j++)
                temp->pixels[j][iwidth-i-1] = pixels[i][j];


        image( iheight , iwidth, color() );


        pixels = temp->pixels; // FUNCIONA COMO O CODIGO AQUI A BAIXO
        /*
        for(int i=0; i<iwidth;i++)
            for(int j=0; j<iheight; j++)
                pixels[i][j] = temp->at(i,j);
        */

    }
    void image::rotate_right() {
        image *temp = new image(iheight, iwidth, color());
        for(int i=0; i<iwidth;i++)
            for(int j=0; j<iheight;j++)
                temp->pixels[iheight-j-1][i] = pixels[i][j];

        image( iheight , iwidth, color() );


        pixels = temp->pixels;
        /*
        for(int i=0; i<iwidth;i++)
            for(int j=0; j<iheight; j++)
                pixels[i][j] = temp->at(i,j);
        */
    }
    void image::mix(const image& img, int factor) {
        for(int i=0; i<iwidth; i++)
            for(int j=0; j<iheight; j++){
                pixels[i][j].mix( img.at(i,j), factor);
            }
    }
}
