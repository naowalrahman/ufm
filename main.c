#include "data.h"
#include "display.h"
#include "process.h"
#define COLOR_NAVY 0



int main() {
    initscr();
    
    // start_color();
    // init_color(COLOR_NAVY, 5 * 1000 / 255, 3 * 1000 / 255, 26 * 1000 / 255);
    // init_color(COLOR_NAVY, 1000, 1000, 1000);
    // init_pair(1, COLOR_WHITE, COLOR_NAVY);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *dir_win = newwin(LINES, COLS / 2, 0, 0);
    // wbkgd(dir_win, COLOR_PAIR(1));
    WINDOW *metadata_win = newwin(LINES, COLS / 2, 0, COLS / 2);
    refresh();
    

    int size;
    struct finfo **list = get_file_listing(".", &size);

    int index = 0;
    while (1) {
        if (index < 0) index = size - 1;
        index %= size;

        wclear(dir_win);

        display_dir(list, size, index, dir_win);
        box(dir_win, 0, 0);

        wrefresh(dir_win);

        wclear(metadata_win);

        if (list[index]->entry->d_type != DT_DIR) {
            display_metadata(list[index]->stat_buffer, metadata_win);
        }
        box(metadata_win, 0, 0);

        wrefresh(metadata_win);

        int ch = getch();
        if (ch == KEY_DOWN) ++index;
        else if (ch == KEY_UP) --index;
        else if (ch == '\n') {
            struct dirent *entry = list[index]->entry;
            if (entry->d_type == DT_DIR) {
                char path[] = "./";
                strcat(path, entry->d_name);
                chdir(path);
                list = get_file_listing(".", &size);
                index = 0;
            }
            else open_file_program(entry->d_name);
        }
    }

    // endwin();
}
