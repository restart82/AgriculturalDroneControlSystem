#include "inc/config.h"
#include "inc/dron.h"
#include "inc/view.h"
#include "inc/session.h"

int main(int argc, char const *argv[])
{
    dron_t dron = initDron(25, 5);
    session_t session = initSession();
    int keyPressed = 0;

    startView();
    printBorder();

    while(!session.stop)
    {
        info(&dron);
        keyPressed = getch();
        chekKey(keyPressed, &session);

        if (!session.pause)
        {
            setCommand(keyPressed, &dron);
            moveDron(&dron);
        }
        clearField();
        printDron(&dron);
        refresh();
        timeout(session.timeout);
    }

    endView();

    return 0;
}
