#include "../headers/cli.h"

/*
	Checks the input argument array for internal
	commands.
	Returns 1 on internal execution.
	Returns 0 otherwise.
*/
int internal_controller (char** input, int argument_count) {
	int status = 0;

	// if (launch_external(input, argument_count))
	// 	return 1;

	if (!input[0]) 
		status = 1;

	else if (!strcmp(input[0], "exit")) 
		exit(0);

	else if (!strcmp(input[0], "cd")) 
		status = change_directory(input, argument_count);

	else if (!strcmp(input[0], "pwd")) {
		status = set_current_working_directory();
		fprintf(stdout, "%s ", global_current_working_directory);
	}

	return status;
}

/*  
	Changes the current working directory and sets the
	global value.
	Returns 1 for the controller.
*/
int change_directory(char** input, int argument_count) {
	int error_check = 0;

	if (argument_count < 2)
		error_check = chdir(getenv("HOME"));
	else
		error_check = chdir(input[1]);

	set_current_working_directory();

	if (error_check)
		fprintf(stderr, "No such directory: %s\n", input[1]);
	else
		fprintf(stdout, "cwd changed to %s\n", global_current_working_directory);

	return 1;
}