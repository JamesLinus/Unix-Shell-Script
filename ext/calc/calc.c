#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINPUTLENGTH 256
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

// Prototypes
char** parse (char* input);
int    controller(char** input);
int    addition (int x, int y);         // x + y
int    subtraction (int x, int y);      // x - y
int    multiplication (int x, int y);   // x * y
int    division (int x, int y);         // x / y

int main (int argc, char* argv[])  {
	char inputbuffer[MAXINPUTLENGTH];

	while(1) {
		if (fgets(inputbuffer, MAXINPUTLENGTH, stdin) == NULL)
            break;

        int inputbufferlength = strlen(inputbuffer);
        
	    if (inputbuffer[inputbufferlength - 1] == '\n')
	        inputbuffer[inputbufferlength - 1] = '\0';

        char** parsed_input = parse(inputbuffer);

        for(int i = 0; i < 5; i++) {
        	fprintf(stdout, "'%s' ", parsed_input[i]);
        }

        fprintf(stdout, "\n");
	}

	return 0;
}

/*
    Parses the input buffer into it's separate arguments.
    Returns argument count.
*/
char** parse (char* input) {
	int len = sizeof(char*) * strlen(input);

	char** argvReal = malloc(len);
	char** argvTemp = argvReal;

    char*  idx;
    char*  argument = input;
    
    while (*argument != '\0') {        
        // Leading whitespaces
        while (*argument == ' ' || *argument == '\n')
            *argument++ = '\0';
        
        // Found argument
        if (*argument != '\0')
            idx = argument;
        
        // Find end of argument
        while (*argument != '\0' && *argument != ' ' && *argument != '\n' 
        	&& *argument != '+' && *argument != '-' && *argument != '*' && *argument != '/') {
        	argument++;
        }

        if (*argument == '+' || *argument == '-' || *argument == '*' || *argument == '/')
        	argument--;

        // Store argument location in argv array
        *argvTemp++ = idx;
    }
    
    // Set terminating character
    *argvTemp = '\0';
    
    // Return
    return argvReal;
}

int controller (char** input) {
	int operation = 0;

	return operation;
}