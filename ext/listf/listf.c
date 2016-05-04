#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {
	fprintf(stdout, "%s\n", "Listf External Test.");
	for (int i = 0; i < argc; i++) {
		fprintf(stdout, "'%s' ", argv[i]);
	}
	fprintf(stdout, "\n");

	return 0;
}