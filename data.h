#ifndef DATA

#define DATA

#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

struct stat **get_dir_listing(char *dir);
bool create_file(char* name);

#endif // DATA
