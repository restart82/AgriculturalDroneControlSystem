#include "inc/config.h"
#include "inc/dron.h"
#include "inc/view.h"
#include "inc/session.h"
#include "inc/field.h"

int main(int argc, char const *argv[])
{
    dron_t dron = initDron(2, 2);
    field_t field = initPumpkinField();
    session_t session = initSession();
    int keyPressed = 0;

    startView();
    printBorder();

    while(!session.stop)
    {
        #ifdef DEBUG_MOD
        info(&dron);
        #endif

        keyPressed = getch();
        chekKey(keyPressed, &session);

        if (!session.pause)
        {
            setCommand(keyPressed, &dron);
            moveDron(&dron);
        }
        updatePumpkinField(&field);
        clearField();
        printPumpkins(&field);
        printDron(&dron);
        refresh();
        timeout(session._timeout);
    }

    endView();

    return 0;
}
