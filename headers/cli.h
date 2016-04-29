#include <fcntl.h>
#include <unistd.h>
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

#define MAXINPUTLENGTH 1024

int argumentCount;

// Prototypes