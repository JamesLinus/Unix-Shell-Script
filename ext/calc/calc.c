#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
char** parse (char* input, int );
int    addition (int x, int y);         // x + y
int    subtraction (int x, int y);      // x - y
int    multiplication (int x, int y);   // x * y
int    division (int x, int y);         // x / y

int main () {
	fprintf(stdout, "%s\n", "External Test.");
	return 0;
}