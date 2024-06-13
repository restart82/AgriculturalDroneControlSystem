#ifndef SESSION_H_
#define SESSION_H_

#include "config.h"
#include "dron.h"

typedef struct
{
    bool pause;
    bool stop;
    int _timeout;
}session_t;

session_t initSession();

void chekKey(int key, session_t* session);

void chekCrash(dron_t* dron, session_t* session);

#endif