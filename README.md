# UFM (UNIX File Manager)

**Team Members:** Naowal Rahman, Rahel Arka
       
### Project Description

UFM is a simple file manager that can be used to browser directories and files. You can preview hovered-on directories and see metadata for hovered-on files. Files can be deleted or opened in an applicable program. The current date and size of the current directory are displayed at the bottom of the screen.
  
### Instructions

#### Compilation
Ncurses is required. This should be installed on most UNIX systems, but refer to your Linux distribution's package manager for installing the library. 

This is how you run the program:
```bash
make compile
make run
```

Just `make` also suffices.

#### Usage
There are several keybinds:
| Key      | Action |
| ----------- | ----------- |
| `h` or `left arrow`      | Go back a directory       |
| `l` or `right arrow` or `Enter`   | If hovering on directory, go to that directory. If hovering on file, open that file in an applicable program      |
| `j` or `down arrow`   | Go down a file      |
| `k` or `up arrow`   | Go up a file     |
| `Backspace`   | Delete hovered-on file or directory       |
| `f`   | Create a file       |
| `d`   | Create a directory       |
