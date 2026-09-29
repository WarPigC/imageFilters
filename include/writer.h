#pragma once

#include <iostream>
#include "flags.h"

// Forward declaration
class Image;

// Creates an image instance to write onto a file based on the filter.
void write(const std::string, Filters);

// Picks the filter based on the switch case.
// Returns 0 if succesful.
int applyFilter( Image&, Filters );
