#include "inc/config.h"
#include "inc/dron.h"
#include "inc/view.h"
#include "inc/session.h"
#include "inc/field.h"

int main(int argc, char const *argv[])
{
    mode_t currentMode = startMenu();
    dron_t dron = initDron(2, 2, RED);
    field_t field = initPumpkinField();
    session_t session = initSession(currentMode);
    int keyPressed = 0;

    startView();
    printBorder();
    printInfo(&session);

    while(!session.stop)
    {
        #ifdef DEBUG_MOD
        info(&dron);
        #endif

        keyPressed = getch();
        chekKey(keyPressed, &session);

        if (!session.pause)
        {
            switch (session.mode)
            {
            case HAND:
                setCommand(keyPressed, &dron);
                break;
            case AUTO:
                autoPilot(&dron, &field);
                break;
            }
            collectPumpkin(&dron, &field);
            moveDron(&dron);
            updatePumpkinField(&field);
            if (session.mode == HAND)
                chekCrash(&dron, &session);
        }
        printInfo(&session);
        clearField();
        printPumpkins(&field);
        printDron(&dron);
        refresh();
        timeout(session._timeout);
    }

    endView();
    system("cls");
    printf("Press ENTER to exit...");
    while (getch() != '\n');

    return 0;
}
