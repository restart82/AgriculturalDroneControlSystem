#include <stdio.h>
// #include <ncurses/ncurses.h>

#include "inc/dron.h"
#include "inc/view.h"

int main(int argc, char const *argv[])
{
    dron_t dron = initDron();

    initscr();
    curs_set(FALSE);

    printDron(&dron);

    refresh();
    getch();
    endwin();

    return 0;
}
