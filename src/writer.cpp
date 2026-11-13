#include "../include/writer.h"
#include "../include/image.h"
#include "../include/filters.h"
#include <iostream>

int BRIGHTNESS_DELTA {};

//TODO: remove return type int
void applyFilter( Image& image, Filters filter ) {

    // switch b/w filter files
    switch( filter ){

     case Filters::GRAYSCALE: {
         grayscale( image );
         break;
     }
     
     case Filters::INVERT: {
         invert( image );
         break;
     }
     
     case Filters::BRIGHTNESS: {
         brightness( image, BRIGHTNESS_DELTA );
         break;
     }

     default: {
         // throw std::
     }
    }
}


void write(const std::string FILEPATH, Filters filter) {

    // image instantiated 
    Image image { FILEPATH };

	
    std::cout << "Starting process." << std::endl;
    applyFilter( image, filter );

        
    // std::cerr << "Filter failed to apply" << std::endl;
    std::cout << "Image processed." << std::endl;

   image.write();

        // std::cerr << "Image couldn't be written to file" << std::endl;
    std::cout << "Image written to file" << std::endl;

}
