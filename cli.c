#include "headers/cli.h"

#define DEBUG 0

int execute (char* input) {   
    pid_t process_id;
    int process_status;
    int inputbufferlength = strlen(input);
        
    if (input[inputbufferlength - 1] == '\n')
        input[inputbufferlength - 1] = '\0';
           
    char** parsed_input = parse(input, &global_argument_count);

    #if DEBUG 
    fprintf(stdout, "[%d] ", global_argument_count);
    for(int i = 0; i < global_argument_count; i++) {
        fprintf(stdout, "'%s' ", parsed_input[i]);
    }
    fprintf(stdout, "\n");
    #endif

    if (!internal_controller (parsed_input, global_argument_count)) {

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

    }
            
    return 1;
}

int main (int argc, char* argv[]) {
    char inputbuffer[MAXINPUTLENGTH];

    set_current_working_directory();
    
    while (1) {
        fprintf(stdout, "$> ");
        
        if (fgets(inputbuffer, MAXINPUTLENGTH, stdin) == NULL)
            break;
            
        execute(inputbuffer);
            
        // Reset argc
        global_argument_count = 0;
    }
    
    return 0;
}