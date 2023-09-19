#ifndef HSH_H
#define HSH_H

/* ===================================================== */
/* =====================  HSH.H  ======================= */
/* NOTE: This file name is subject to change.            */

/* This file is the main file for this project.          */
/* hsh => Hoblerton SHell                                */
/* ===================================================== */

/* ===================================================== */
/* ===================== HEADERS ======================= */
/* ===================================================== */

/* List of allowed functinos and assioted headers can be found in README.md */
#include "./list.h"
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/* ===================================================== */
/* ===================== MACROS ======================== */
/* ===================================================== */
#define UNUSED(x) (void)(x)

/* ===================================================== */
/* ===================== DEFINES ======================= */
/* ===================================================== */
/* buffer constants */
#define BUF_SIZE 1024
#define BUF_FLUSH -1

#define PROMPT "$ "
#define DILIM " \t\r\n\a"

#define TEST_FILE_MODE 0

#define AND_DELIM 1
#define OR_DELIM 2
#define SEMI_DELIM 3

/* TODO: remove if not needed any more */
/*environment variable*/
extern char **environ;
/* ===================================================== */
/* ===================== STRUCTS ======================= */
/* ===================================================== */

/**
 * struct environment - structure for environment variables and arguments
 * @env: environment variables
 * @env_list: environment variables in a linked list
 * @argv: arguments
 * @argc: argument count
 * @token_arr: array of tokens (cur command and its argument)
 * @last_exit_status: last exit status
 * @CHAIN_TYPE: type of command chaining
 * Description: This structure holds the environment variables and
 * arguments for the shell
 * it is made to unify the function signutures for the builtins function
 */
typedef struct environment
{
	char **env;
	list_t *env_list;
	char **argv;
	int argc;
	char **token_arr;
	int last_exit_status;
	/* TODO: remove chaing type, don't foget to remoce it from doc and init */
	int CHAIN_TYPE;
	/* NOTE: add more members as needed */
} env_t;

/**
 * struct builtin_enum - structure for builtin functions
 * @builtin: builtin name
 * @func: builtin function
 * Description: This structure holds the builtin functions
 * and their names
 */
typedef struct builtin_enum
{
	char *builtin;
	int (*func)(env_t *env);
} builtin_t;

/* ===================================================== */
/* ===================== PROTOTYPES ==================== */
/* ===================================================== */

/* MAIN hsh functions - hsh.c */
void hsh(env_t *env);

/* STRING functions - string_lib_{0,1}.c */
unsigned int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _strcpy(char *src, char *dest);
void _strcpylen(char *src, char *ogdest, int size);
int custom_atoi(const char *str);
int isnumerical(const char *str);
char **copy_str_array(char **str_array);
void free_str_array(char **str_array);
int is_delim(char c, char *delim);
char *_strtok(char *str, char *delim);
int _strncmp(char *s1, char *s2, int n);
char **_str_to_word_array(char *str, char *delim);

/* PRINTING functions print_lib.c */
int _putchar(char c);
int _putchar_fd(char c, int fd);
int _puts(char *str);
int _puts_fd(char *str, int fd);

/*parcing funcs*/
/* TODO: Move to mem_lib.c */
int allocate(char **s, size_t *startlen, size_t);

/* MEMORY functions - mem_lib.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* EXECUTE COMMANDS functions - exec_lib.c */
void execute_command(env_t *env);
/* TODO: remove those two code has been moved to new funcs */
int exitcheck(char **s, char *filename);
int printenv(char **s, char *file_name, char **env);

/* BUILTIN functions - builtin_lib_{0}.c */
int builtin_exit(env_t *env);
int builtin_env(env_t *env);
int builtin_setenv(env_t *env);
int builtin_unsetenv(env_t *env);

/* COMMAND CHIANING AND COMMENTS functions - cmd_chain_lib.c */
/* TODO: remove what is not used any more */
size_t count_commands(char *line);
void remove_comments(char *line);
size_t get_command(char **line, size_t *strlen);
int is_chain_delim(char *str);

/* Reading from files functions */
size_t custom_getline(char **line, size_t *startlen, FILE *f);
/* TODO: move to exec_lib.c */
char *get_path(char *command, char **env);

/* ENVIROMENT functions - env_lib.c */
char *_getenv(char *name, char **env);

/* BUILTIN Mux function - builtin_mux.c */
int (*builtin_mux(char *builtin))(env_t *env);

/* ERROR functions - error_lib.c */
void exit_error(char *file_name, int line_number, char *exc, char *msg,
								int exit_code, char *msgarg, env_t *env);

#endif
