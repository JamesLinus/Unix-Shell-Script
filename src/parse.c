#include "../headers/cli.h"

/*
    Parses the input buffer into it's separate arguments.
    Returns argument count.
*/
char** parse (char* input, int *argc) {
	int len = sizeof(char*) * strlen(input);

	char** argvReal = malloc(len);
	char** argvTemp = argvReal;

    char*  idx;
    char*  argument = input;
    
    while (*argument != '\0') {        
        // Leading whitespaces
        while (*argument == ' ' || *argument == '\n') {
            *argument++ = '\0';
        }
        
        // Found argument
        if (*argument != '\0') {
            *argc += 1;
            idx = argument;
        }
        
        // Find end of argument
        while (*argument != '\0' && *argument != ' ' && *argument != '\n') {
        	argument++;
        }

        // Store argument location in argv array
        *argvTemp++ = idx;
    }
    
    // Set terminating character
    *argvTemp = '\0';
    
    // Return
    return argvReal;
}

/*
	Resolves pathing for running external commands.
*/
char* resolvepath(char* input) {
	char* command = '\0';

    if (!strcmp(input, "calc"))
        command = global_calculator_directory;
    else if (!strcmp(input, "listf"))
    	command = global_listf_directory;
    else
        command = input;

    return command;
}