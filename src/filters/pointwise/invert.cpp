#include "../../../include/filters.h"

void invert(Image& image) {
    for (int y = 0; y < image.getY(); ++y){
        for (int x = 0; x < image.getX(); ++x){

            auto &R { image(x, y, 0) };
            auto &G { image(x, y, 1) };
            auto &B { image(x, y, 2) };

            R = static_cast<unsigned char>(255 - R);
            G = static_cast<unsigned char>(255 - G);
            B = static_cast<unsigned char>(255 - B);
        }
    }
}
