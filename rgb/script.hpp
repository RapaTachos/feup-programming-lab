
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script {
    private:
        void fill();
        void open();
        void blank();
        void save();
    public:
        script(const std::string& filename);
        ~script();
        void process();
    private:
        image* img;
        std::ifstream input;
        std::string root_path;
    };
}
#endif
