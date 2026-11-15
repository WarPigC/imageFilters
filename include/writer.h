#pragma once

#include "flags.h"

// Help function, prints the help text.
void help();

// Formats a bit of error's code with colors. Prints the error message too.
void formatErrorText(const std::exception&);

// Forward declaration
class Image;

// Creates an image instance to write onto a file based on the filter.
void processImage(const std::string, Filters);

// Picks the filter based on the switch case.
void applyFilter( Image&, Filters );


// variable for brightness delta.
extern int BRIGHTNESS_DELTA;
