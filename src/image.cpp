#include <cassert>
#include <stdexcept>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "image.h"
#include <iostream>


Image::Image(const std::string filepath)
	:channels { 4 },
	FILEPATH { filepath }
{
	int originalChannels;
	image = stbi_load(FILEPATH.c_str(), &X, &Y, &originalChannels, channels);

	if (!image)
        throw std::runtime_error(stbi_failure_reason());
	
	std::cout << "Image loaded" << std::endl;
	
	if (originalChannels != channels)
		std::cout << "Image channels changed from " 
			<< originalChannels << " to " << channels
			<< std::endl;
}

stbi_uc& Image::operator() (int x, int y, int channel){
	if ( x < 0 || x >= X || y < 0 || y >= Y || channel < 0 || channel >= channels) {
        throw std::out_of_range("Pixel access out of bounds at xyChannel: ( "
			+ std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(channel) + ")");
	}

	return image[(y * X * channels) + x * channels + channel]; // 1d array of bytes; rows + columns + channel offset
}

void Image::write(){
    int success { 0 };

	//TODO: save files to assets regardless from where original file exists.
	// 		Current implementation saves in-place
	success = stbi_write_png(FILEPATH.c_str() , X, Y, channels, image, 0);

    if (!success)
        throw std::runtime_error(stbi_failure_reason());
    std::cout << "Saved to " << FILEPATH.c_str() << std::endl;
}

int Image::getX() const {
    return X;
}

int Image::getY() const {
    return Y;
}

int Image::getChannels() const {
    return channels;
}


Image::~Image(){
	stbi_image_free(image);
}
