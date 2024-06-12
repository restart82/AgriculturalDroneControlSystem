#ifndef DRON_H_
#define DRON_H_

#include "config.h"

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

}dron_t;

dron_t initDron();

void moveDron();

#endif