#include "../../include/filters.h"

void applyGrayscale (Image& image){
    for (int y = 0; y < image.getY(); ++y){
        for (int x = 0; x < image.getX(); ++x){

            auto &R { image(x, y, 0) };
            auto &G { image(x, y, 1) };
            auto &B { image(x, y, 2) };

            int pixelAvg { (R + G + B) / 3 };

            // Flags internal narrowing as intentional
            // unsigned char -> int (0-255)
            R = static_cast<unsigned char>(pixelAvg);
            G = static_cast<unsigned char>(pixelAvg);
            B = static_cast<unsigned char>(pixelAvg);
        }
    }
}

int grayscale(Image& image) {

    try {
        applyGrayscale(image);
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

