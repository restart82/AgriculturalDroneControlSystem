#include "../inc/session.h"

session_t initSession(mode_t _mode)
{
    session_t session;
    session.pause = false;
    session.stop = false;
    session._timeout = DEFOULT_TIMEOUT;
    session.mode = _mode;
    return session;
}

void chekKey(int key, session_t* session)
{
    if (key == 'q' || key == 'Q')
    {
        session->stop = true;
    }
    if (key == 'p' || key == 'P')
    {
        session->pause = !session->pause;
    }
}

void chekCrash(dron_t* dron, session_t* session)
{
    for (int i = 0; i < dron->basketNumber; i++)
    {
        if (dron->x == dron->basket[i].x &&
            dron->y == dron->basket[i].y)
        {
            session->stop = true;
        }
    }
}

mode_t startMenu()
{
    system("cls");
    printf("\n\nHello!\nChoose dron work mode:\n\n");
    printf( " 1. hand mode\n"
            " 2. auto mode\n");   

    int mode;
    do
    {
        scanf("%c", &mode);
    } while (!(mode == '1' || mode == '2'));

    switch (mode)
    {
    case '1':
        printf("HAND MODE\n");
        return HAND;
    case '2':
        printf("AUTO MODE\n");
        return AUTO;
    }
}