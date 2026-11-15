#include "filters.h"

void grayscale(Image& image) {
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
