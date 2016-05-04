#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "parse.h"
#include "internal.h"

#define MAXINPUTLENGTH    1024
#define DIRECTORY_LENGTH  256

int   global_argument_count;
char  global_current_working_directory[DIRECTORY_LENGTH];
char       global_calculator_directory[DIRECTORY_LENGTH];
char            global_listf_directory[DIRECTORY_LENGTH];

// Prototypes
void execute (char* input);
void set_external_paths();
int set_current_working_directory();