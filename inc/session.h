#ifndef SESSION_H_
#define SESSION_H_

#include "config.h"

typedef struct
{
    bool pause;
    bool stop;
    int timeout;
}session_t;

session_t initSession();

void chekKey(int key, session_t* session);


#endif