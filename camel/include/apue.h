#ifndef _APUE_H
#define _APUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE 4096

/* error.c */
void  err_quit(const char *, ...) __attribute__((noreturn));
void  err_sys(const char *, ...)__attribute__((noreturn));
void  err_ret(const char *, ...);
#endif

