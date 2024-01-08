#include "data.h"

bool create_file(char *name) {
    int fd = open(name, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) return false;
    close(fd);
    return true;
}

int get_file_listing(char *dir, struct finfo ***list) {
    DIR *d = opendir(dir);
    struct dirent *entry;

    int size = 0;
    while ((entry = readdir(d))) {
        if (entry->d_type != DT_DIR) ++size;
    }

    closedir(d);
    d = opendir(dir);
    *list = malloc(size * sizeof(struct finfo *));
    struct finfo **itr = *list;

    while ((entry = readdir(d))) {
        if (entry->d_type != DT_DIR) {
            struct finfo *f = malloc(sizeof(struct finfo));

            f->entry = entry;
            f->stat_buffer = malloc(sizeof(struct stat));
            stat(entry->d_name, f->stat_buffer);

            *itr = f;
            ++itr;
        }
    }
    closedir(d);

    return size;
}

void display_dir(char *dir) {
    DIR *d = opendir(dir);

    struct dirent *entry;
    while ((entry = readdir(d))) printf("%s\n", entry->d_name);

    closedir(d);
}
