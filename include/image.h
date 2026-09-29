#pragma once

#include <string>
#include "../lib/stb_image.h"
#include "../lib/stb_image_write.h"

// Image handler class.
class Image {
	int X, Y, channels;
	const std::string FILEPATH;

	stbi_uc* image;
	
public:
	// Loads image upon initialization.
	Image(const std::string filepath);


	// rule of 0
	Image(Image&) = delete;
	Image(Image&&) = delete;
	Image& operator= (Image&) = delete;
	Image& operator= (Image&&) = delete;


	// get/set for pixel values.
	stbi_uc& operator() (int x, int y, int channel);

	// Writes buffer to the file.
	// Returns 0 on success.
	int write();

    // Gets width of the image
    int getX() const;

    // Gets height of the image
    int getY() const;

    // Gets channel count in the image
    int getChannels() const;

	// Frees image loaded.
	~Image();
};
