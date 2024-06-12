#include "../inc/session.h"

session_t initSession()
{
    session_t session;
    session.pause = false;
    session.stop = false;
    session.timeout = DEFOULT_TIMEOUT;
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