#ifndef VIEW_H_
#define VIEW_H_

#include "config.h"
#include "dron.h"

typedef enum
{
    BORDER_PAIR = 1,
    DRON_PAIR
}colorPair_t;

void printDron(dron_t* dron);

void printBorder();

void startView();

void endView();

#endif