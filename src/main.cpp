#include "helper.hpp"

/*

*/

int main(int argc, char *args[]) {

    std::ofstream file;
    std::string path = "../Notes/", flag, content;

    if (argc < 3 || argc > 4) Usage(args[0]);

    // read the arguments sent into the program
    //for (int i=0; i<argc; i++) {
    //    std::cout << "Argument " << i+1 << ": " << args[i] << std::endl;
    //}

    /*
        Possible Flags
        -o : overwrite the contents of the file
        -d : delete the specified file
    */

    // if there is a flag
    if (args[1][0] == '-') {

        char flag = args[1][1];
        path += args[2];

        switch (flag-'0') {
            case ('o'-'0'):
                std::cout << "Overwriting the file" << std::endl;
                content = args[3];
                file.open(path);
                break;
            case ('d'-'0'):
                if (remove(path.c_str()) != 0) std::cout << "Error deleting " << args[2] << std::endl;
                else std::cout << "Successfully deleted " << args[2] << std::endl;
                exit(0);
            default:
                std::cout << "Flag not matched" << std::endl;
                exit(0);
        }
    } 
    // if no flag, we just append
    else {
        path += args[1];
        content = args[2];
        file.open(path, std::ios::app);
    }

    if (file.is_open()) {
        file << content << "\n";

        std::cout << "Wrote \"" << content << "\" to " << path << std::endl;
        file.close();
    }


    return 0;
}