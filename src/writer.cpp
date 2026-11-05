#include "../include/writer.h"
#include "../include/image.h"
#include "../include/filters.h"
#include <iostream>

int BRIGHTNESS_DELTA {};

int applyFilter( Image& image, Filters filter ) {
    int success {};

    // switch b/w filter files
    switch( filter ){

     case Filters::GRAYSCALE: {
         success = grayscale( image );
         break;
     }
     
     case Filters::INVERT: {
         success = invert( image );
         break;
     }
     
     case Filters::BRIGHTNESS: {
         success = brightness( image, BRIGHTNESS_DELTA );
         break;
     }

     default: {
         std::cerr << "No filter Case found" << std::endl;
         abort();
     }
    }

    return success;
}


void write(const std::string FILEPATH, Filters filter) {

    // image instantiated 
    Image image { FILEPATH };

	
    std::cout << "Starting process." << std::endl;
    int filterapplied { applyFilter( image, filter ) };

    if (filterapplied){
        std::cerr << "Filter failed to apply" << std::endl;
        abort();
    }
    std::cout << "Image processed." << std::endl;

    int writtentofile { image.write() };

    if (writtentofile) {
        std::cerr << "Image couldn't be written to file" << std::endl;
        abort();
    }
    std::cout << "Image written to file" << std::endl;

}
