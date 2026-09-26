#pragma once

#include <map>
#include <string>

enum class Filters {
	GRAYSCALE
};

const inline std::map<std::string, Filters> FilterMap {
	{"-g" , Filters::GRAYSCALE}
};
