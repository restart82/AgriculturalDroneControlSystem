#include "inc/config.h"
#include "inc/dron.h"
#include "inc/view.h"

int main(int argc, char const *argv[])
{
    dron_t dron = initDron();

    startView();

    printBorder();
    printDron(&dron);
    
    refresh();
    getch();

    endView();

    return 0;
}
