#include <cassert>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../include/image.h"
#include <iostream>


Image::Image(const std::string filepath)
	:FILEPATH { filepath },
	channels { 4 }
{
	int originalChannels;
	image = stbi_load(FILEPATH.c_str(), &X, &Y, &originalChannels, channels);

	if (!image){
		std::cerr << "Image not loaded" << std::endl;
		abort();
	}
	std::cout << "Image loaded" << std::endl;
	
	if (originalChannels != channels)
		std::cout << "Image channels changed from " 
			<< originalChannels << " to " << channels
			<< std::endl;
}

stbi_uc& Image::operator() (int x, int y, int channel){
	if ( x < 0 || x >= X || y < 0 || y >= Y || channel < 0 || channel >= channels) {
		std::cerr << "Pixel out of bounds at xyChannel: ( "
			<< x << ", " << y << ", " << channel << ")"
			<< std::endl;
		abort();
	}

	return image[(y * X * channels) + x * channels + channel]; // 1d array of bytes; rows + columns + channel offset
}

int Image::write(){

	//TODO: save files to assets regardless from where original file exists.
	// 		Current implementation saves in-place

	return !stbi_write_png(FILEPATH.c_str(), X, Y, channels, image, 0);
}


Image::~Image(){
	stbi_image_free(image);
}
