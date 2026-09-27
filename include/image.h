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
	// Returns 0 on failure.
	int write();

	// Frees image loaded.
	~Image();
};
