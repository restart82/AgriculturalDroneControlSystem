#ifndef SESSION_H_
#define SESSION_H_

#include "config.h"
#include "dron.h"

typedef enum
{
    HAND,
    AUTO
}mode_t;

typedef struct
{
    bool pause;
    bool stop;
    int _timeout;
    mode_t mode;
}session_t;

session_t initSession(mode_t _mode);

void chekKey(int key, session_t* session);

void chekCrash(dron_t* dron, session_t* session);

mode_t startMenu();

#endif