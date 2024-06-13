#ifndef VIEW_H_
#define VIEW_H_

#include "config.h"
#include "dron.h"
#include "field.h"

typedef enum
{
    BORDER_PAIR = 1,
    BLUE_DRON_PAIR,
    GREEN_DRON_PAIR,
    RED_DRON_PAIR,
    YELLOW_DRON_PAIR,
    CYAN_DRON_PAIR,
    WHITE_DRON_PAIR,
    RIPE_PUMPKIN_PAIR,
    NOT_RIPE_PUNPKIN_PAIR
}colorPair_t;

void printDron(dron_t* dron);

void printBorder();

void printPumpkins(field_t* field);

void startView();

void endView();

void clearField();

colorPair_t getColorPair(dron_t* dron);

void info(dron_t* dron);

#endif