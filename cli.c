#include "headers/cli.h"

int execute (char* input) {
    fprintf(stdout, "%s\n", input);
    return 1;
}

int main (int argc, char* argv[]) {
    char inputbuffer[MAXINPUTLENGTH];
    int argumentCount = 0;
    int inputbufferlength = 0;
    
    while (1) {
        fprintf(stdout, "$> ");
        
        if (fgets(inputbuffer, MAXINPUTLENGTH, stdin) == NULL)
            break;
            
        inputbufferlength = strlen(inputbuffer);
        
        if (inputbuffer[inputbufferlength - 1] == '\n')
            inputbuffer[inputbufferlength - 1] = '\0';
            
        execute(inputbuffer);
            
    }
    
    return 0;
}