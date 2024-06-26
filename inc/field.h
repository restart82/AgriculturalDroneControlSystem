#ifndef FIELD_H_
#define FIELD_H_

#include "config.h"
#include <time.h>

typedef enum
{
    LEVEL_1,
    LEVEL_2,
    IS_RIPE,
    IS_COLLECT
}pumpkinState_t;

typedef struct
{
    int x;
    int y;
    pumpkinState_t state;
}pumpkin_t;

typedef struct
{
    int pumpkinNumber;
    pumpkin_t* pumpkin;
    bool isReady;
}field_t;

field_t initPumpkinField();

void updatePumpkinField(field_t* field);

void generatePumpkins(field_t* field);

#endif