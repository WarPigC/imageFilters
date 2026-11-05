#include "../include/flags.h"
#include "../include/writer.h"
#include <filesystem>
#include <iostream>


// handler for CLI arguments


void help();

int main(int argc, char** argv){

	if (argc < 3){
		std::cout << "Argument mismatch" << std::endl;
		help(); abort();
	}
	if (!std::filesystem::exists(argv[1])) {
		std::cout << "Image not found" << std::endl;
		help(); abort();
	}


	const std::string FILEPATH { std::filesystem::canonical( argv[1] ).generic_string() }, FLAG { argv[2] };


	// Validate flags
	auto flag { FilterMap.find(FLAG) };

	if (flag == FilterMap.end()) {
		std::cerr << "Flag not found\n";
		help(); abort();
	}

    // brightness delta value check
    if (flag->second == Filters::BRIGHTNESS) {
        BRIGHTNESS_DELTA = atoi(argv[3]);
    }
    
	// Write to file
	write(FILEPATH, flag->second);

	return 0;
}


void help() {
    std::cout << "\n\n" 
    << "Guide to ImageFilters." << "\n\n"
    << "Command format: <file path> <flag> <extra flag relevant parameter>" << "\n\n"
    << "Available flags:" << "\n"
    << "        -b: Brightness. Provide a 3rd argument for the change in brightness. 1 to 255 results in increase while -1 to -255 results in a decrease in the brightness intensity" << '\n'
    << "        -i: Invert. Inverts an image's colors" << '\n'
    << "        -g: Grayscale. Turns a colorful RGB image to grayscale."
    << std::endl;
}
