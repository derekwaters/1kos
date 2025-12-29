#pragma once
#include "common.h"

__attribute__((noreturn)) void exit(int exitcode);
void putchar(char ch);
char getchar();
int readfile(const char *filename, char *buf, int len);
int writefile(const char *filename, const char *buf, int len);