#ifndef DRON_H_
#define DRON_H_

#include "config.h"
#include "field.h"
#include <math.h>

#define START_BASKET_NUMBER 0

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}command_t;

typedef enum
{
    BLUE,
    GREEN,
    RED,
    YELLOW,
    CYAN,
    WHITE
}dronColor_t;

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
    dronColor_t color;
}dron_t;

dron_t initDron(int x_0, int y_0, dronColor_t _color);

void moveDron(dron_t* dron);

void moveBasket(dron_t* dron);

void setCommand(int keyPressed, dron_t* dron);

void autoPilot(dron_t* dron, field_t* field);

void collectPumpkin(dron_t* dron, field_t* field);

int findPumpkin(dron_t* dron, field_t* field);

void goToPumpkin(dron_t* dron, int x, int y);

#endif