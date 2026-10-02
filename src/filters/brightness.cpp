#include "../../include/filters.h"

void applyBrightness(Image& image, int delta) {
    for (int y = 0; y < image.getY(); ++y){
        for (int x = 0; x < image.getX(); ++x){

            auto &R { image(x, y, 0) };
            auto &G { image(x, y, 1) };
            auto &B { image(x, y, 2) };

            R = static_cast<unsigned char>(R + delta);
            G = static_cast<unsigned char>(G + delta);
            B = static_cast<unsigned char>(B + delta);
        }
    }
}


int brightness(Image &image, int delta) {

    try {
        applyBrightness(image, delta);
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }


    return 0;
}
