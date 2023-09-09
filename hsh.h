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
#define INTERACTIVE_MODE 0

/* ===================================================== */
/* ===================== STRUCTS ======================= */
/* ===================================================== */

/* NOTE: Will be added later */
/* TODO: Add an envirmoent struct */

/* ===================================================== */
/* ===================== PROTOTYPES ==================== */
/* ===================================================== */

/* MAIN hsh functions - hsh.c */
/* FIXME: this function prototype is not final yet */
void hsh(char **env);

/* STRING functions - string_lib_{0,1}.c */
unsigned int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _strcpy(char *src, char *dest);

/* PRINTING functions print_lib.c */
int _putchar(char c);
int _puts(char *str);

/* EXECUTE COMMANDS functions - exec_lib.c */
void execute_command(char **args, char **env);

#endif
