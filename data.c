#include "data.h"

int compare(const void *a, const void *b) {
    char *name_a = (*(struct finfo **)a)->name;
    char *name_b = (*(struct finfo **)b)->name;
    return strcmp(name_a, name_b);
}

struct finfo **get_file_listing(char *dir, int *size) {
    DIR *d = opendir(dir);
    struct dirent *entry;

    *size = 0;
    while ((entry = readdir(d))) ++(*size);
    --*size;

    closedir(d);
    d = opendir(dir);
    struct finfo **list = malloc(*size * sizeof(struct finfo *));
    struct finfo **itr = list;

    while ((entry = readdir(d))) {
        if (strcmp(entry->d_name, ".") == 0) continue;
        struct finfo *f = malloc(sizeof(struct finfo));

        f->name = malloc(256 * sizeof(char));
        strcpy(f->name, entry->d_name);
        f->type = entry->d_type;

        if (f->type == DT_DIR) f->stat_buffer = NULL;
        else {
            f->stat_buffer = malloc(sizeof(struct stat));
            stat(f->name, f->stat_buffer);
        }

        *itr = f;
        ++itr;
    }
    closedir(d);

    qsort(list, *size, sizeof(struct finfo *), compare);

    return list;
}

void free_finfo_list(struct finfo **list, int size) {
    for (int i = 0; i < size; i++) {
        free(list[i]->name);
        free(list[i]->stat_buffer);
        free(list[i]);
    }
    free(list);
}

//FILE FUNCTIONS

bool create_file(char *name) {
    int fd = open(name, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) return false;
    close(fd);
    return true;
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

bool delete_dir(char *name) {
    if (remove(name) == 0) {
        return true;
    }
    else {
        perror("Error deleting directory");
        return false;
    }
}
