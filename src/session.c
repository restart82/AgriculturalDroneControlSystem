#include "../inc/session.h"

session_t initSession()
{
    session_t session;
    session.pause = false;
    session.stop = false;
    session._timeout = DEFOULT_TIMEOUT;
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