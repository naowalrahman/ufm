#include "display.h"
#include "data.h"
#include "process.h"

void display_dir_simple(char *dir, WINDOW *window) {
    fprintf(stderr, "%s\n", dir);
    
    DIR *d = opendir(dir);
    err("display_dir_simple 1");
    struct dirent *entry;

    int y = 0;
    while ((entry = readdir(d))) {
        char name[256];
        strcpy(name, entry->d_name);
        if(strcmp(name, ".") == 0 || strcmp(name, "..") == 0) continue;

        mvwprintw(window, ++y, 2, "%s%c", name, entry->d_type == DT_DIR ? '/' : ' ');
        err("display_dir_simple 2");
    }

    free(entry);
    closedir(d);
}

void display_dir(struct finfo **list, int size, int index, WINDOW *window) {
    for (int i = 0; i < size; i++) {
        if (i == index) wattron(window, A_STANDOUT);
        mvwprintw(window, i + 1, 2, "%s%c", list[i]->name, list[i]->type == DT_DIR ? '/' : ' ');
        err("display_dir 1");
        wattroff(window, A_STANDOUT);
    }
}

void display_metadata(struct stat *stat_buffer, WINDOW *window) {
    int y = 0;
    mvwprintw(window, ++y, 2, "size: %ld bytes", stat_buffer->st_size);
    mvwprintw(window, ++y, 2, "user id: %d", stat_buffer->st_uid);
    mvwprintw(window, ++y, 2, "group id: %d", stat_buffer->st_gid);
    mvwprintw(window, ++y, 2, "permissions: %o", stat_buffer->st_mode);
    mvwprintw(window, ++y, 2, "last accessed: %s", ctime(&stat_buffer->st_atime));
    mvwprintw(window, ++y, 2, "last modified: %s", ctime(&stat_buffer->st_mtime));
}

// static void resize_handler(int sig) {
//     int h, w;
//     getmaxyx(stdscr, h, w); // Get the new terminal size

//     // Redraw windows based on the new size
//     wresize(dir_win, h, w / 2);
//     wresize(metadata_win, h, w / 2);
//     mvwin(metadata_win, 0, w / 2);

//     // Refresh the windows
//     wrefresh(dir_win);
//     wrefresh(metadata_win);
// }
