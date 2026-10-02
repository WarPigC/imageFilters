#pragma once

#include "image.h"
#include <iostream>


// Grayscale filter
// Returns 0 for successful processing
int grayscale(Image& image);


// Invert filter
// Returns 0 for successful processing
int invert(Image& image);


// Changes brightness
// Returns 0 for successful processing
int brightness(Image& image);
