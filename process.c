#include "process.h"

void open_file_program(char *file) {
    pid_t pid = fork();

    if (pid == 0) execlp("xdg-open", file, NULL);
    else {
        int status;
        wait(&status);
    }
}
