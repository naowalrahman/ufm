#ifndef DATA_H

#define DATA_H

#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct finfo {
    struct dirent *entry;
    struct stat *stat_buffer;
};

struct finfo **get_file_listing(char *dir, int *size);
bool create_file(char *name);
void display_dir(char *dir);

#endif
