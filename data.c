#include "data.h"


struct finfo **get_file_listing(char *dir, int *size) {
    DIR *d = opendir(dir);
    struct dirent *entry;

    *size = 0;
    while ((entry = readdir(d))) ++(*size);

    closedir(d);
    d = opendir(dir);
    struct finfo **list = malloc(*size * sizeof(struct finfo *));
    struct finfo **itr = list;

    while ((entry = readdir(d))) {
        struct finfo *f = malloc(sizeof(struct finfo));

        f->entry = entry;
        if (entry->d_type == DT_DIR) f->stat_buffer = NULL;
        else {
            f->stat_buffer = malloc(sizeof(struct stat));
            stat(entry->d_name, f->stat_buffer);
        }

        *itr = f;
        ++itr;
    }
    closedir(d);

    return list;
}
//FILE FUNCTIONS
bool create_file(char *name) {
    int fd = open(name, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) return false;
    close(fd);
    return true;
}
bool rename_file(char *old, char *cur) {
    if (rename(cur, cur) == 0) {
        return true;
    }
    else {
        perror("Error renaming file");
        return false;
    }
}

bool delete_file(char *name) {
    if (remove(name) == 0) {
        return true;
    }
    else {
        perror("Error deleting file");
        return false;
    }
}
// DIR FUNCTIONS
bool create_dir(char *name) {
    if (mkdir(name, 0755) == -1) return false;
    return true;
}
bool rename_directory(char *old, char *cur) {
    if (rename(old, cur) == 0) {
        return true;
    }
    else {
        perror("Error renaming directory");
        return false;
    }
}
bool delete_directory(char *name) {
    if (remove(name) == 0) {
        return true;
    }
    else {
        perror("Error deleting directory");
        return false;
    }
}
