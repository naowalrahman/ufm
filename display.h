#ifndef DISLPAY_H

#define DISLPAY_H

#include "data.h"
#include "include.h"

void display_dir_simple(char *dir, WINDOW *window);
void display_dir(struct finfo **list, int size, int index, WINDOW *window);
void display_metadata(struct stat *stat_buffer, WINDOW *window);

#endif
