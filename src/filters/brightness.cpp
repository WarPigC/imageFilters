#include "../../include/filters.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <iostream>

void applyBrightness(Image& image, const int DELTA) {
    if (DELTA > 255 || DELTA < -255) throw std::invalid_argument("Brightness value" + std::to_string(DELTA) + " out of bounds\n");
    
    for (int y = 0; y < image.getY(); ++y){
        for (int x = 0; x < image.getX(); ++x){

            auto &R { image(x, y, 0) };
            auto &G { image(x, y, 1) };
            auto &B { image(x, y, 2) };


            R = static_cast<unsigned char>(std::clamp(R + DELTA, 0, 255));
            G = static_cast<unsigned char>(std::clamp(G + DELTA, 0, 255));
            B = static_cast<unsigned char>(std::clamp(B + DELTA, 0, 255));
        }
    }
}


int brightness(Image &image, const int DELTA) {

    try {
        applyBrightness(image, DELTA);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
