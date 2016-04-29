#include "headers/cli.h"

int execute (char* input) {   
    pid_t process_id;
    int process_status;
    int inputbufferlength = strlen(input);
        
    if (input[inputbufferlength - 1] == '\n')
        input[inputbufferlength - 1] = '\0';
        
    char** parsed_input = parse(input, &argumentCount);

    fprintf(stdout, "[%d]\n", argumentCount);
    for(int i = 0; i < argumentCount; i++) {
        fprintf(stdout, "'%s'\n", parsed_input[i]);
    }
    
    process_id = fork();
    if (process_id < 0) {
        fprintf(stderr, "Fork failed.");
        return 0;
    }
    
    if (process_id == 0) {
        execvp (*parsed_input, parsed_input);
        exit(127);
    }
    
    if (wait (&process_status) < 0)
        fprintf(stderr, "Wait failed.");
        
    return 1;
}

int main (int argc, char* argv[]) {
    char inputbuffer[MAXINPUTLENGTH];
    
    while (1) {
        fprintf(stdout, "$> ");
        
        if (fgets(inputbuffer, MAXINPUTLENGTH, stdin) == NULL)
            break;
            
        execute(inputbuffer);
            
        // Reset argc
        argumentCount = 0;
    }
    
    return 0;
}