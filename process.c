#include "process.h"

void open_file_program(char *name) {
    pid_t pid = fork();

    if (pid == 0) execlp("xdg-open", "xdg-open", name, NULL);
    else {
        int status;
        wait(&status);
    }
}

char *get_cwd_size() {
    FILE *f = popen("du -sh", "r");
    char *size = malloc(256 * sizeof(char));
    fgets(size, 256, f);

    return size;
}

void err(char *src) {
    if (errno != 0) {
        fprintf(stderr, "%s errno %d: %s\n", src, errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
}
