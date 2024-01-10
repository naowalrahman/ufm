#include "process.h"

void open_file_program(struct finfo ***list, int index, int *size) {
    struct dirent *entry = (*list[index])->entry;
    if (entry->d_type == DT_DIR) {
        char dir[] = "./";
        strcat(dir, entry->d_name);
        chdir(dir);
        *list = get_file_listing(".", size);
        return;
    }

    pid_t pid = fork();

    if (pid == 0) execlp("xdg-open", "xdg-open", entry->d_name, NULL);
    else {
        int status;
        wait(&status);
    }
}
