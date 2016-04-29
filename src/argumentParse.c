#include "../headers/cli.h"

/*
    Parses the input buffer into it's separate arguments.
    Returns argument count.
*/
int parse (char** input) {
    int argument_count = 0;
    int quotes_count = 0;
    char* idx;
    char** argument = input;
    
    while (**argument != 0) {
        
        // Leading whitespaces
        while (**argument == ' ' || **argument == '\n') {
            **argument++ = 0;
        }
        
        // Found argument
        if (**argument != 0) {
            argument_count++;
            idx = argument;
        }
        
        while (**argument != 0 && **argument != ' ' && **argument != '\n') {
            if(**argument == '\"') {
                quotes_count++;
                argument++;
                
                **(argument - quotes_count) = **argument;
                while (**argument != '\"') {
                    argument++;
                    *(argument - quotes_count);
                }
                quotes_count++;
                
                argument++;
                **(argument - quotes_count) = **argument;
                **(argument - (quotes_count - 1)) = **argument;
            } else {
                argument++;
                **(argument - quotes_count) = **argument;
            }
        }
        quotes_count = 0;
        *argument++ = idx;
    }
    
    *argument = 0;
    
    return argument_count;
}