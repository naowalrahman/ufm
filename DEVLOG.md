# Dev Log:

## Naowal

### 2024-01-02
Expanded description including how much time was spent on task.

### 2024-01-03
Wrote `PROPOSAL.md`. Spent about 40 minutes.

### 2024-01-04
Wrote `get_file_listing()`. Spent about 30 minutes including debugging.

### 2024-01-05
Fixed the `display_dir()` function and optimized to make the code shorter. The function was also skipping directories within the given directory, so I fixed that as well. This took around 15 minutes.

### 2024-01-06 to 2024-01-07
Created `process.h` file with functions necessary to open child processes and decide which program to run for some selected file in the file manager. Fixed an include guard inconsistency. 

### 2024-01-08
Code `open_file_program()` function under `process.c`, using `execlp()` and `xdg-open` to open some given file dynamically. Tested all the data functions. Fixed `get_file_listing()` function, which in particular was causing many segmentation faults. I also made the function use a custom `struct finfo` which combines data from a `struct dirent` and a `struct stat` to give all the possibly necessary information of the file in one data structure. Finally, I setup `ncurses` (edited the makefile accordingly with `-lncurses` flag) and tested moving the cursor around with the `wmove()` function.

### 2024-01-09
Advanced development of the terminal UI with `ncurses` significantly. Two windows are drawn side-by-side, one with directory listing and the other with metadata of the current file. Implemented directory browsing by accepting arrow-key input and adjusting index of current file in `struct finfo` list accordingly. The metadata is also updated accordingly whenever the user moves to a different file in the directory. Tested preliminary borders; found issue that drawing borders overwrites printed text. This will most likely be fixed by using `mvwprintw()`. Also created helper functions `display_dir()` and `display_metadata` in `display.c`. Took about 1.5 hours of time total. 

### 2024-01-10
Used `getch()` to detect if enter key was pressed and then open the hovered on directory/file accordingly. If it was a file, it is opened with xdg-open (through `execlp()`), and if it is a directory, the working directory of the program is changed and the file list is re-rendered. I also fixed Rahel's use of sorting the list with a custom comparator, making the parameters `const void *`. Also, the borders were being overwritten by the rendered text, so I used `mvwprintw()` instead to print the lines one extra character to the right so the border characters weren't touched. Finally, I increased `include.h` to include all of the imports for every file in the project. Took about 2 hours in total.

### 2024-01-11
Fixed directory switching and added for keybindings. Vim keys can now be used to move around the file managaer - j/k to go up and down the directory listing, and h/l to go back and forth between directories. I also fixed directory opening to remove segmentation faults. Tried to implement preview of a directory when hovered on on the right window (since there isn't much metadata to show about a directory), but there is a segmentation fault that needs to be addressed. I also optimized our directory listing sorting by only sorting when the working directory changes (i.e. when `get_file_listing()`) is called instead of every time the directory is displayed. Took about 1.5 hours in total.

### 2024-01-12 to 2024-01-15
Fixed segmentation faults ocurring due to dependence on the size of `d_name` in `struct dirent`. Changed `struct finfo` to accomodate file name and type without needing the store a dirent. Added a taskbar that displays current time and directory size. Colored directories and used signal handling to handle SIGINT and automatically redraw the screen when the terminal is resized. Took about 3 hours in total including debugging. 

## Rahel

### 2024-01-02
Expanded description including how much time was spent on task.

### 2024-01-03
Worked on `PROPOSAL.md` for 20 minutes

### 2024-01-04
Worked on data functions (create and display file) for 35 minutes including debugging

### 2024-01-05 to 2024-01-07
Created file manipulation functions (rename, delete, move) using stdio builtin functions

### 2024-01-08
Modified data.h with functions required for file manipulation.

### 2024-01-09
Implemented color customization for window division in UI. Redefined magenta and initialized in pair 1. Issues with borders and custom attributes on text. Created a sort function to sort the files displayed by display_dir. Looks very nice. Took about 50 minutes.

### 2024-01-10 to 2024-01-11
Resize contents if an xterm is resized. All windows are redrawn based on new height and width. Used sigwinch signal for sighandler. 1.2 hours.

### 2024-01-12 to 2024-01-15
Created file/dir functions that delete them. Incorporated recursive deletion into delete_dir. Also created file/dir functions that create them. Took about 4 hours including debugging.
