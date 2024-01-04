# Final Project Proposal

## Group Members:

Naowal Rahman, Rahel Arka

## Intentions:

Develop a terminal-based file manager that allows the user to navigate through directories, manipulate/create files, and view metadata.
    
## Intended usage:

Upon startup, the user will be greeted with the contents of the working directory on the left side of the terminal buffer. If hovering above a file, the top right will display a preview of the file when possible. If hovering above a directory, the top right will display a preview of the contents of that directory. The bottom right will always display metadata about a file/directory. There will be keyboard shortcuts (vim/arrow keys) to navigate between directories and manipulate files and open files in a specified editor. 
  
## Technical Details:

The project will:
* Trivially use `sys/stat.h` for file metadata and use `unistd.h` for creating files (and obviously work with lots of files).
* Processes (fork, exec, etc.) for opening files in a terminal-based editor when desired
* Signals for quitting suspending program; upon `ctrl-c` or `q` the program will print time elapsed and info about what was done.
* Allocate memory for buffers and such when, for example, renaming a file or when creating a `stat` buffer.

Breakdown:
* Both Naowal and Rahel will work on creating all of the functions to get data (directory contents, metadata, file contents, etc.) and split them up evenly.
* Naowal will work on using a library to get started with a TUI (potentially `ncurses`).
* Naowal will work on the left side of the UI, which deals with navigating directories.
* Rahel will work on getting file previews and metadata list to work on the right side of the UI.

Data structures/algorithms:
* Many arrays for storing directory listings. 
* Custom structs to organize information as needed
    
## Intended pacing:

Timeline:
| Period      | Description                                                       |
| ----------- | ----------------------------------------------------------------- |
| Jan 4-7     | Finish data functions                                             |
| Jan 8-12    | Organize UI into sections with listing, preview, metadata working |
| Jan 13-16   | Incorporate keystrokes                                            |

