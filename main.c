#include "data.h"
#include "display.h"
#include "process.h"
#include <ncurses.h>

int main() {
    initscr();
    start_color();
    init_color(COLOR_MAGENTA, 5 * 1000 / 255, 3 * 1000 / 255, 26 * 1000 / 255);
    init_pair(1, COLOR_WHITE, COLOR_MAGENTA);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *dir_win = newwin(LINES, COLS * 2 / 3, 0, 0);
    wbkgd(dir_win, COLOR_PAIR(1));
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
