#include "data.h"
#include "display.h"
#include "process.h"
#define PAIR_DIR 1
#define COLOR_NAVY 0

static void signal_handler(int signo) {
    if (signo == SIGINT) {
        endwin();
        printf("Quit file manager.\n");
        exit(0);
    }
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    initscr();

    signal(SIGINT, signal_handler);

    use_default_colors();
    start_color();
    // init_color(COLOR_NAVY, 5 * 1000 / 255, 3 * 1000 / 255, 26 * 1000 / 255);
    init_pair(PAIR_DIR, COLOR_BLUE, COLOR_BLACK);
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
        else if (index >= size) index = 0;

        wclear(dir_win);
        wclear(metadata_win);

        display_dir(list, size, index, dir_win);
        if (list[index]->type == DT_DIR) display_dir_simple(list[index]->name, metadata_win);
        else display_metadata(list[index]->stat_buffer, metadata_win);
        box(dir_win, 0, 0);
        box(metadata_win, 0, 0);

        wrefresh(dir_win);
        wrefresh(metadata_win);

        int ch = getch();
        if (ch == KEY_DOWN || ch == 'j') ++index;
        else if (ch == KEY_UP || ch == 'k') --index;
        else if (ch == '\n' || ch == KEY_RIGHT || ch == 'l') {
            if (list[index]->type == DT_DIR) {
                chdir(list[index]->name);
                free_finfo_list(list, size);
                list = get_file_listing(".", &size);
                index = 0;
            }
            else open_file_program(list[index]->name);
        }
        else if (ch == KEY_LEFT || ch == 'h') {
            chdir("..");
            free_finfo_list(list, size);
            list = get_file_listing(".", &size);
            index = 0;
        }
        else if (ch == KEY_RESIZE) {
            dir_win = newwin(LINES, COLS / 2, 0, 0);
            metadata_win = newwin(LINES, COLS / 2, 0, COLS / 2);
            refresh();
        }
    }
}
