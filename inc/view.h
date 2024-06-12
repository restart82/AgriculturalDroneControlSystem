#ifndef VIEW_H_
#define VIEW_H_

#include "config.h"
#include "dron.h"
#include "field.h"

typedef enum
{
    BORDER_PAIR = 1,
    DRON_PAIR
}colorPair_t;

void printDron(dron_t* dron);

void printBorder();

void printPumpkins(field_t* field);

void startView();

void endView();

void clearField();

void info(dron_t* dron);

#endif