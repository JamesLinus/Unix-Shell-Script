# Unix-Shell-Script
A basic command line interpreter written in C, with limited functionality.
Script reads a command from the keyboard and executes it.  

## Basic Commands
### Internal
##### exit
Causes the command line interpreter to terminate, an alternative to [Ctrl-C]

##### cd *dir*
Changes the command line interpreter's current working directory to the relative or absolute path given as a command line argument.
Unlike, Bash, this function produces stdout output.

##### pwd
Displays the absolute path of the command line interpreter's current working directory.  Command does not skip to a new line and makes the absolute path available to the next command execution.

### External
##### listf *dir1* *dir2*
An alternative implementation of the Unix 'ls' command.  This lists the contents of one or more directories as specified by line arguments, or lack thereof.
###### Launch Flags
+ **-l** Displays the long form of the output.
+ **-a** Same as -l, however the last access time is shown instead of last modification time. Requires -l
+ **-c** Same as -l, however the creation time is shown instead of last modification time. Requires -l
+ **-m** Same as -l, requires -l
These flags may be used in conjunction with each other, i.e. -lmac, -la, -lac

##### calc
Simple calculator which takes single arithmetic operations from stdin and writes the formatted expression and the result to stdout.
Only handles Integer values and performs basic Addition / Subtraction / Multiplication / Division w/ possible rounding.

## I/O Redirection
The command line interpreter recognizes the two basic Unix redirection characters '>' and '<'.
'<' redirects stdin to a file specified after.
'>' redirects stdout to a file specified after.

