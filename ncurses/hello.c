// sudo apt install libncurses5-dev libncursesw5-dev
// cc hello.c -o hello -lncurses

#include <ncurses.h>

int main(int argc, char *argv[]) {
    initscr();
    printw("Hello World");
    refresh();
    getch();
    endwin();
    return 0;
}
