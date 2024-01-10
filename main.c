#include "data.h"
#include "display.h"
#include "process.h"
#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *dir_win = newwin(LINES, COLS * 2 / 3, 0, 0);
    WINDOW *metadata_win = newwin(LINES, COLS / 3, 0, COLS * 2 / 3);
    refresh();

    int size;
    struct finfo **list = get_file_listing(".", &size);

    int index = 0;
    while (1) {
        if (index < 0) index = size - 1;
        index %= size;

        wclear(dir_win);

        box(dir_win, 0, 0);
        display_dir(list, size, index, dir_win);

        wrefresh(dir_win);

        wclear(metadata_win);

        box(metadata_win, 0, 0);
        if (list[index]->entry->d_type != DT_DIR) {
            display_metadata(list[index]->stat_buffer, metadata_win);
        }

        wrefresh(metadata_win);

        int ch = getch();
        switch (ch) {
        case KEY_DOWN:
            ++index;
            break;
        case KEY_UP:
            --index;
            break;
        }
    }

    // endwin();
}
