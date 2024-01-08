#include "data.h"

bool create_file(char* name) {
    int fd = open(name, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) return false;
    close(fd);
    return true;
}

struct stat **get_file_listing(char *dir) {
    DIR *d = opendir(dir);
    struct dirent *entry;

    int size = 0;
    while((entry = readdir(d))) {
        if(entry->d_type != DT_DIR) ++size;
    }
    
    closedir(d);
    d = opendir(dir);
    struct stat **list = malloc(size * sizeof(struct stat));
    struct stat **itr = list;
    
    while((entry = readdir(d))) {
        if(entry->d_type != DT_DIR) {
            stat(entry->d_name, *itr);
            ++itr;
        }
    }
    closedir(d);
    return list;
}

void display_dir(char *dir) {
    DIR *d = opendir(dir);

    struct dirent *entry;
    while ((entry = readdir(d))) printf("%s\n", entry->d_name);

    closedir(d);
}
bool rename_file(char* old_name, char* new_name) {
    if (rename(old_name, new_name) == 0) {
        return true;
    } else {
        perror("Error renaming file");
        return false;
    }
}

bool delete_file(char* name) {
    if (remove(name) == 0) {
        return true;
    } else {
        perror("Error deleting file");
        return false;
    }
}

bool move_file(char* old, char* new) {
    return rename_file(old, new);
}