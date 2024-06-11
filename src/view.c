#include "../inc/view.h"

void printDron(dron_t* dron)
{
    mvprintw(0, 0, "%d", dron->number);
    printf("%d\n", dron->number);
}