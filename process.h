#ifndef PROCESS_H

#define PROCESS_H

#include "data.h"
#include "include.h"

void open_file_program(char *name);
struct finfo **cd(char *dir, int *size);
void err(char *src);

#endif
