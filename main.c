#include "data.h"
#include "display.h"
#include "process.h"

static void signal_handler(int signo) {
    if (signo == SIGINT) {
        endwin();
        printf("Quit file manager.\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    initscr();
    signal(SIGINT, signal_handler);

    use_default_colors();
    start_color();
    init_pair(PAIR_DIR, COLOR_BLUE, COLOR_BLACK);
    curs_set(0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *dir_win = newwin(LINES - 1, COLS / 2, 0, 0);
    WINDOW *metadata_win = newwin(LINES - 1, COLS / 2, 0, COLS / 2);
    WINDOW *bar_win = newwin(1, COLS, LINES - 1, 0);
    // scrollok(dir_win, true);
    // idlok(dir_win, true);
    // clearok(dir_win, true);
    refresh();

    int size, index = 0;
    struct finfo **list = get_file_listing(".", &size);
    char *cwd_size = get_cwd_size();

    while (1) {
        if (index < 0) index = size - 1;
        else if (index >= size) index = 0;
        
        // if(index > LINES - 3) scroll(dir_win);

        wclear(dir_win);
        wclear(metadata_win);
        wclear(bar_win);

        display_bar(bar_win, cwd_size);
        display_dir(list, size, index, dir_win);
        if (list[index]->type == DT_DIR) display_dir_simple(list[index]->name, metadata_win);
        else display_metadata(list[index]->stat_buffer, metadata_win);
        box(dir_win, 0, 0);
        box(metadata_win, 0, 0);
        
        wrefresh(bar_win);
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
                cwd_size = get_cwd_size();
                index = 0;
            }
            else open_file_program(list[index]->name);
        }
        else if (ch == KEY_LEFT || ch == 'h') {
            chdir("..");
            free_finfo_list(list, size);
            list = get_file_listing(".", &size);
            cwd_size = get_cwd_size();
            index = 0;
        }
        else if (ch == KEY_RESIZE) {
            dir_win = newwin(LINES - 1, COLS / 2, 0, 0);
            metadata_win = newwin(LINES - 1, COLS / 2, 0, COLS / 2);
            bar_win = newwin(1, COLS, LINES - 1, 0);
            refresh();
        }
        else if (ch == KEY_BACKSPACE){
            if (list[index]->type == DT_DIR){
                delete_dir(list[index]->name);
                
            }
            else {
                delete_file(list[index]->name);
                free_finfo_list(list, size);
                list = get_file_listing(".", &size);
                cwd_size = get_cwd_size();
            } 
            
        }
        // else if (ch == 'd') {
        //     scroll(dir_win);
        // }
    }
}
