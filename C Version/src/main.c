#include "helper.h"


int main(int argc, char **args) {

    FILE *fileptr;
    char path[32] = "../../Notes/", content[256];
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
        pathCheck(args[2]);
        addToCharBuff(path, args[2], sizeof(path));
        addToCharBuff(path, ".txt", sizeof(path)); // add extension

        switch (flag-'0') {
            case ('o'-'0'):
                printf("Overwriting the file");
                addToCharBuff(content, args[3], sizeof(content));
                fileptr = fopen(path, "w");
                break;
            case ('d'-'0'):
                if (remove(path) != 0) printf("Error deleting %s", args[2]);
                else printf("Successfully deleted %s\n", args[2]);
                exit(0);
            default:
                printf("Flag not matched");
                exit(0);
        }
    } 
    // if no flag, we just append
    else {
        pathCheck(args[1]);
        addToCharBuff(path, args[1], sizeof(path));
        addToCharBuff(path, ".txt", sizeof(path)); // add extension

        addToCharBuff(content, args[2], sizeof(content));
        //addToCharBuff(content, '\n');
        fileptr = fopen(path, "a");
        
    }

    if (fileptr != NULL) {
        fprintf(fileptr, "%s\n", content);

        printf("Wrote %s to %s\n", content, path);

        fclose(fileptr);
    }

    return 0;
}