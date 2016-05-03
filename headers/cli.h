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

#include "argumentParse.h"
#include "internal.h"

#define MAXINPUTLENGTH       1024
#define CURR_WORKING_DIR_LEN 256

int   global_argument_count;
char  global_current_working_directory[CURR_WORKING_DIR_LEN];

// Prototypes
int execute (char* input);