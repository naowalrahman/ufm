#include "data.h"
#include "process.h"
#include <ncurses.h>

int main() {
    // testing data.c
    // create_file("hola.txt");
    
    // printf("get_file_listing()\n---\n");
    // int size;
    // struct finfo **list = get_file_listing(".", &size);
    // for (int i = 0; i < size; i++) {
    //     printf("name: %s, size: %ld\n", list[i]->entry->d_name, list[i]->stat_buffer->st_size);
    // }    
    //
    // printf("\ndisplay_dir()\n---\n");
    // display_dir("/home/naowal/Documents");
    //
    //
    // printf("\nopen_file_program()\n---");
    // char dir[] = "/home/naowal/Documents/integral.pdf";
    // open_file_program(dir);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *win = newwin(LINES, COLS, 0, 0);   
    wmove(win, 10, 10);
    wrefresh(win);

    sleep(2);

    endwin();
}
