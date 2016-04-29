#include "headers/cli.h"

int execute (char* input) {
    char** parsed_input = &input;
    
    pid_t process_id;
    int process_status;
    int argumentCount = 0;
    int inputbufferlength = strlen(input);
        
    if (input[inputbufferlength - 1] == '\n')
        input[inputbufferlength - 1] = '\0';
        
    argumentCount = parse(parsed_input);
    
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
            
    }
    
    return 0;
}