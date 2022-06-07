#include <iostream>
#include <fstream>
/*

    Header file for common functions

*/

void Usage();

void Usage(char* progName) {
    std::cout << "Usage: " << progName << " <optional flag> <file to add text to> <optional text to add>" << std::endl;
    std::cout << "Flags:\n\t-o : Overwrite file contents, requires file path and content to write\n\t-d : Delete a notes file, requires file path"
        << std::endl;
    exit(0);
}