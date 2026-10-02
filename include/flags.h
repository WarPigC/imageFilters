#pragma once

#include <map>
#include <string>

enum class Filters {
	GRAYSCALE,
    INVERT,
    BRIGHTNESS
};

const inline std::map<std::string, Filters> FilterMap {
    {"-g" , Filters::GRAYSCALE},
    {"-i", Filters::INVERT},
    {"-b", Filters::BRIGHTNESS}
};
