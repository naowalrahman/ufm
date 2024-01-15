#ifndef DATA_H

#define DATA_H

#include "include.h"

struct finfo {
    char *name;
    unsigned char type;
    struct stat *stat_buffer;
};

struct finfo **get_file_listing(char *dir, int *size);
void free_finfo_list(struct finfo **list, int size);
bool create_file(char *name);
bool rename_file(char *old, char *cur);
bool delete_file(char *name);
bool move_file(char *old, char *cur);

#endif
