#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int internal_controller (char** input, int argument_count);
int change_directory(char** input, int argument_count);
int set_current_working_directory();