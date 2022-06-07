#include <stdio.h> // I/O library
#include <stdlib.h>
#include <string.h>


void Usage(char* progName) {
    printf("Usage: %s <optional flag> <file to add text to> <optional text to add>", progName);
    printf("Flags:\n\t-o : Overwrite file contents, requires file path and content to write\n\t-d : Delete a notes file, requires file path\n");
    exit(0);
}

void pathCheck(char *path) {
    // check inputted path to make sure there is no forward slashes
    for (int i=0; i<strlen(path); i++) {
        if (path[i] == '/' || path[i] == '.') {
            printf("Illegal path was used\n");
            exit(0);
        }
    }
}

void addToCharBuff(char *buffer, char *toAdd, int size) {
    int newLength = strlen(buffer) + strlen(toAdd) + 1; // with the null character
    if (size < newLength) {
        fprintf(stderr, "String '%s' is too long\n", toAdd);
        exit(0);
    }
    strncat(buffer, toAdd, (size-strlen(buffer)));
}