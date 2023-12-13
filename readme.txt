## 12/9/2023
in mac version, there's few problem

fortunetly, I solved most of them
however, there's still one exists, which is the libary "curses"

the iostream doesn't work properly with it's existence, and the whole table would be ruined by it 

maybe the only solution is to find another replacement for conio.h for mac 

and that't defenitely will not be "curses.h"

## 12/13/2023 update
"curses" issue is fixed, and also the issue of the unpresentable symbols is also solved

minor bug fixed, which is the field code that can't show the exit 
individual exit block added

officially announced repaired, maybe waited to be upgrade

## build process
$ mkdir build && cd build
$ cmake ..
$ make