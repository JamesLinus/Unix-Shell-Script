#include "headers/cli.h"

#define DEBUG 0

/*
    Takes the input line given from main and runs parse.
    Checks the command arguments returned for internal
    execution.
    Executes the command arguments if not internal.
*/
void execute (char* input) {   
    pid_t process_id;
    int process_status;
    int inputbufferlength = strlen(input);
        
    if (input[inputbufferlength - 1] == '\n')
        input[inputbufferlength - 1] = '\0';
           
    char** parsed_input = parse(input, &global_argument_count);

    #if DEBUG
        fprintf(stdout, "\n\x1b[36m[%d] ", global_argument_count);
        for(int i = 0; i < global_argument_count; i++) {
            fprintf(stdout, "'%s' ", parsed_input[i]);
        }

        fprintf(stdout, "\n\x1b[35mLISTPATH\x1b[34m '%s'\x1b[0m\n", global_listf_directory);
        fprintf(stdout, "\x1b[35mCALCPATH\x1b[34m '%s'\n", global_calculator_directory);
        fprintf(stdout, "\x1b[35mCURRPATH\x1b[34m '%s'\x1b[0m\n\n", global_current_working_directory);
    #endif

    if (!internal_controller (parsed_input, global_argument_count)) {
        process_id = fork();
        if (process_id < 0) {
            fprintf(stderr, "Fork failed.");
            return;
        }
        
        if (process_id == 0) {
            execvp (resolvepath(*parsed_input), parsed_input);
            exit(127);
        }
        
        if (wait (&process_status) < 0)
            fprintf(stderr, "Wait failed.");

    }
}

/*  
    Sets global paths for external program execution.
*/
void set_external_paths() {
    // Calc
    char* buf = malloc(DIRECTORY_LENGTH);
    char* ptr;
    ptr = getcwd(buf, DIRECTORY_LENGTH);
    snprintf(global_calculator_directory, DIRECTORY_LENGTH, "%s/ext/calc/calc", ptr);
    snprintf(global_listf_directory, DIRECTORY_LENGTH, "%s/ext/listf/listf", ptr);
    free(buf);
}

/*  
    Sets the global working directory value to the 
    current working directory.
    Returns 1 for the controller.
*/
int set_current_working_directory() {
    char* buf = malloc(DIRECTORY_LENGTH);
    char* ptr;
    ptr = getcwd(buf, DIRECTORY_LENGTH);
    strcpy(global_current_working_directory, ptr);
    free(buf);

    return 1;
}

/*
    Main execution routine.
*/
int main (int argc, char* argv[]) {
    char inputbuffer[MAXINPUTLENGTH];

    set_current_working_directory();
    set_external_paths();
    
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