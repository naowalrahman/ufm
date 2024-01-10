#ifndef DISLPAY_H

#define DISLPAY_H

#include "data.h"
#include <ncurses.h>

void display_dir(struct finfo **list, int size, int index, WINDOW *window);
void display_metadata(struct stat *stat_buffer, WINDOW *window);

#endif
