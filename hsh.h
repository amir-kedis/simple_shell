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
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
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

/* ===================================================== */
/* ===================== STRUCTS ======================= */
/* ===================================================== */

/* NOTE: Will be added later - we will need linked list */
/* I think we should make in a sperate files and included sperately */

/* ===================================================== */
/* ===================== PROTOTYPES ==================== */
/* ===================================================== */

/* STRING functions - string_lib.h */
unsigned int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* PRINTING functions print_lib.h */
int _putchar(char c);
int _puts(char *str);

#endif
