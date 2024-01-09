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
Code `open_file_program()` function under `process.c`, using `execlp()` and `xdg-open` to open some given file dynamically. Tested all the data functions. Fixed `get_file_listing()` function, which in partticular was causing many segmentation faults. I also made the function use a custom `struct finfo` which combines data from a `struct dirent` and a `struct stat` to give all the possibly necessary information of the file in one data structure. Finally, I setup `ncurses` (edited the makefile accordingly with `-lncurses` flag) and tested moving the cursor around with the `wmove()` function.

## Rahel

### 2024-01-02
Expanded description including how much time was spent on task.

### 2024-01-03
Worked on `PROPOSAL.md` for 20 minutes

### 2024-01-04
Worked on data functions (create and display file) for 35 minutes including debugging

### 2024-01-05 to 2024-01-07
Created file manipulation functions (rename, delete, move)

### 2024-01-08
