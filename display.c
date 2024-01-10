#include "display.h"
#include "data.h"

#define VARNAME(Variable) (#Variable)
extern WINDOW *dir_win;
extern WINDOW *metadata_win;
int compare(const void *a, const void *b) {
    char *name_a = (*(struct finfo **)a)->entry->d_name;
    char *name_b = (*(struct finfo **)b)->entry->d_name;
    return strcmp(name_a, name_b);
}

void display_dir(struct finfo **list, int size, int index, WINDOW *window) {
    qsort(list, size, sizeof(struct finfo *), compare);
    for (int i = 0; i < size; i++) {
        struct dirent *entry = list[i]->entry;

        if (i == index) wattron(window, A_STANDOUT);
        mvwprintw(window, i + 1, 2, "%s%c\n", entry->d_name, entry->d_type == DT_DIR ? '/' : ' ');
        wattroff(window, A_STANDOUT);
    }
}

void display_metadata(struct stat *stat_buffer, WINDOW *window) {
    int y = 0;
    mvwprintw(window, ++y, 2, "size: %ld bytes\n", stat_buffer->st_size);
    mvwprintw(window, ++y, 2, "user id: %d\n", stat_buffer->st_uid);
    mvwprintw(window, ++y, 2, "group id: %d\n", stat_buffer->st_gid);
    mvwprintw(window, ++y, 2, "permissions: %o\n", stat_buffer->st_mode);
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