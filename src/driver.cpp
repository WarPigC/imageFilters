#include "../include/flags.h"
#include "../include/writer.h"
#include <filesystem>
#include <iostream>
#include <stdexcept>


// handler for CLI arguments


void help();

int main(int argc, char** argv){
    try {
        if (argc < 3){
            throw std::invalid_argument("Invalid arguments provided");
        }
        if (!std::filesystem::exists(argv[1])) {
            throw std::invalid_argument("Image provided was not found");
        }

        const std::string FILEPATH { std::filesystem::canonical( argv[1] ).generic_string() }, FLAG { argv[2] };


        // Validate flags
        auto flag { FilterMap.find(FLAG) };

        if (flag == FilterMap.end()) {
            throw std::invalid_argument("Flag provided is invalid");
        }

        // brightness delta value check
        if (flag->second == Filters::BRIGHTNESS) {
            BRIGHTNESS_DELTA = atoi(argv[3]);
        }
        
        // Write to file
            write(FILEPATH, flag->second);
    }
    catch (std::exception& e){
        std::cout << '\n' << e.what() << std::endl;
        help();
    }

	return 0;
}


void help() {
    std::cout << R"(
Guide to ImageFilters.

Command format: <file path> <flag> <extra flag relevant parameter>

Available flags:
     -b: Brightness. Provide a 3rd argument for the change in brightness.
         1 to 255 results in increase while -1 to -255 results in a decrease in the brightness intensity.
     -i: Invert. Inverts an image's colors.
     -g: Grayscale. Turns a colorful RGB image to grayscale.
    )" << std::endl;
}
