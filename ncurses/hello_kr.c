// sudo apt install libncurses5-dev libncursesw5-dev
// cc hello_kr.c -o hello_kr -lncursesw

// to print Korean characters:
// 1. include <locale.h>
// 2. setlocale(LC_ALL, "") before initscr()
// 3. compile with -lncursesw instead of -lncurses
// 4. <ncursesw/ncurses.h> is not required (<ncurses.h> is sufficient)

#include <ncurses.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    initscr();
    printw("안녕하세요!");
    refresh();
    getch();
    endwin();
    return 0;
}
