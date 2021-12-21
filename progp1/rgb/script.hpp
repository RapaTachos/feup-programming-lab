
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script {
    private:
        //! Used to process input to command 'fill'
        void fill();
        //! Initializes image from a file
        void open();
        //! Initializes image with dimentions w*h and a color (r,g,b)
        void blank();
        //! Saves image to 'filename'
        void save();
    public:
        /*!
         * Opens script from a certain 'filename'
         * @param filename
         */
        script(const std::string& filename);
        /*!
         * Deletes image created by the scrips
         */
        ~script();
        /*!
         * Used to process script's input
         */
        void process();
    private:
        //! Image created by the script
        image* img;
        //! Input buffer
        std::ifstream input;
        //! Path to input file
        std::string root_path;
    };
}
#endif
