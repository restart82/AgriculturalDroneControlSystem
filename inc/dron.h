#ifndef DRON_H_
#define DRON_H_

#include "config.h"

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}command_t;

typedef struct
{
    int x;
    int y;
}basket_t;

typedef struct
{
    int x;
    int y;
    basket_t* basket;
    size_t basketNumber;
    command_t currentCommand;
}dron_t;

dron_t initDron(int x_0, int y_0);

void moveDron(dron_t* dron);

void moveBasket(dron_t* dron);

void setCommand(int keyPressed, dron_t* dron);

#endif