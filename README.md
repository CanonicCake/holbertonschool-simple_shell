SHELL README.md

INTRO
This is Holberton Simple Shell, a simple shell created by Nathan Ellis and Nicholas Young. This was made for a project at Holberton School Tulsa, and is intended to perform some of the functions that a shell can do, specifically executing commands read from the command line string, standard input, or a specified file as well as finding the PATH.

REQUIREMENTS
These are the specifications for this specific project, as laid out by Holberton School.
Editors allowed are vi, vim, and emacs
Files are to be compiled on Ubuntu 20.04 LTS using gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
All files end with a new line
This README.md will be at the root of the project
Code will be in the Betty coding style
The shell should not have any memory leaks
No more than 5 functions per file
All header files will use guarded
System Calls are to be used only when necessary

TESTING 
This project ideally functions like this in interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit 
$

And like this in non-interactive mode:
$ echo “/bin/ls” | ./hsh
hsh main.c shell.c test_ls_2 
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

