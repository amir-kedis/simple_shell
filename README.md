# Simple Shell Project
## Description
This is a simple shell project for ALX Software Engineering. It is a simple UNIX command interpreter that replicates the basic functionalities of the sh shell. This was made as part of the first sprint curiculum of the ALX Software Engineering program.

## Authors
* **Sarah Kamal** 
* **Amir Kedis** 

## TODOS:
[X] Make STUPS
[X] Make Main Structure
[ ] implement linked list class
[ ] implement string functions

## Allowed Functions and System Calls
| Function  | Header        |
|---------- | ------------- |
| access    | unistd.h      | 
| chdir     | unistd.h      | 
| close     | unistd.h      | 
| closedir  | dirent.h      | 
| execve    | unistd.h      | 
| exit      | stdlib.h      | 
| _exit     | stdlib.h      | 
| fflush    | stdio.h       | 
| fork      | sys/types.h   | 
| free      | stdlib.h      | 
| getcwd    | unistd.h      | 
| getline   | stdio.h       | 
| getpid    | sys/types.h   | 
| isatty    | unistd.h      | 
| kill      | signal.h      | 
| malloc    | stdlib.h      | 
| open      |  sys/types.h <sys/stat.h> <fcntl.h> |
| opendir   | dirent.h      |
| perror    | stdio.h       | 
| read      | unistd.h      | 
| readdir   | dirent.h      | 
| signal    | signal.h      | 
| stat      | unistd.h <sys/stat.h> |
| lstat     | unistd.h <sys/stat.h> |
| fstat     | unistd.h <sys/stat.h> |
| strtok    | string.h      | 
| wait      | sys/wait.h    | 
| waitpid   | sys/wait.h    | 
| wait3     | sys/wait.h    | 
| wait4     | sys/wait.h    | 
| write     | unistd.h      | 

## Compilation
The shell should be compiled this way:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
To start the shell in interactive mode:
```bash
chmod u+x hsh
./hsh
```

To run tests:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c \
tests/{your-test-name}.c -o test_driver.out
```

