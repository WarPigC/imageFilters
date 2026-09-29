#include "../include/flags.h"
#include "../include/writer.h"
#include <filesystem>

void help();

int main(int argc, char** argv){

	if (argc != 3){
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

    
	// Write to file
	write(FILEPATH, flag->second);

	return 0;
}


void help() {
	std::cout << "help (more would be written soon here)" << std::endl;
}
