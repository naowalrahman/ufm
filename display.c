#include "display.h"
#include "data.h"
#include <ncurses.h>

void display_dir(struct finfo **list, int size, int index, WINDOW *window) {
    for(int i = 0; i < size; i++) {
        struct dirent *entry = list[i]->entry;

        if(i == index) wattron(window, A_STANDOUT);
        wprintw(window, "%s%c\n", entry->d_name, entry->d_type == DT_DIR ? '/' : ' ');
        wattroff(window, A_STANDOUT);
    } 
}
