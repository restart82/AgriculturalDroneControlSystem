#include "../inc/dron.h"

dron_t initDron(int x_0, int y_0, dronColor_t _color)
{
    dron_t dron;
    
    dron.x = ZERO_X + x_0;
    dron.y = ZERO_Y + y_0;
    dron.basketNumber = START_BASKET_NUMBER;
    dron.basket = (basket_t*)calloc(BASKET_BUFFER, sizeof(basket_t));
    for (int i = 0; i < dron.basketNumber; i++)
    {
        dron.basket[i].x = dron.x + i + 1;
        dron.basket[i].y = dron.y;
    }
    dron.currentCommand = LEFT;
    dron.color = _color;

    return dron;
}

void moveDron(dron_t* dron)
{   
    switch (dron->currentCommand)
    {
    case UP:
        if (dron->y >= 1)
        {
            moveBasket(dron);
            dron->y = dron->y - 1;
        }
        break;
    case DOWN:
        if (dron->y < FIELD_SIZE_Y - 1)
        {
            moveBasket(dron);
            dron->y = dron->y + 1;
        }
        break;
    case LEFT:
        if (dron->x >= 1)
        {
            moveBasket(dron);
            dron->x = dron->x - 1;
        }
        break;
    case RIGHT:
        if (dron->x < FIELD_SIZE_X - 1)
        {
            moveBasket(dron);
            dron->x = dron->x + 1;
        }
        break;
    }
}

void moveBasket(dron_t* dron)
{
    for (int  i = dron->basketNumber - 1; i > 0; i--)
    {
        dron->basket[i] = dron->basket[i - 1];
    }
    dron->basket[0].x = dron->x;
    dron->basket[0].y = dron->y;
}

void setCommand(int keyPressed, dron_t* dron)
{
    switch (keyPressed)
    {
    case 'w':
    case 'W':
        if (dron->currentCommand != DOWN)
        {
            dron->currentCommand = UP;
        }
        break;
    case 'd':
    case 'D':
        if (dron->currentCommand != LEFT)
        {
            dron->currentCommand = RIGHT;
        }
        break;
    case 's':
    case 'S':
        if (dron->currentCommand != UP)
        {
            dron->currentCommand = DOWN;
        }
        break;
    case 'a':
    case 'A':
        if (dron->currentCommand != RIGHT)
        {
            dron->currentCommand = LEFT;
        }
        break;
    }
}

void autoPilot(dron_t* dron, field_t* field)
{
    static bool isDetected = false;
    static int pumpkinIndex;
    static int x, y;
    static int counter = 0;
    static int counter2 = 0;

    if (!isDetected)
    {
        counter++;
        pumpkinIndex = findPumpkin(dron, field);
        x = field->pumpkin[pumpkinIndex].x;
        y = field->pumpkin[pumpkinIndex].y;
        isDetected = true;
    }

    if (isDetected)
    {
        counter2++;
        goToPumpkin(dron, x, y);
        if (field->pumpkin[pumpkinIndex].state == IS_COLLECT)
        {
            isDetected = false;
        }
    }

    #ifdef DEBUG_MOD
    mvprintw(2, 0, "%d", pumpkinIndex);
    mvprintw(3, 0, "%d", x);
    mvprintw(4, 3, "%d", y);
    mvprintw(6, 0, "%d", isDetected);
    mvprintw(8, 0, "%d", counter);
    mvprintw(9, 0, "%d", counter2);
    mvprintw(11, 0, "%d", field->pumpkin[0].state);
    mvprintw(12, 0, "%d", field->pumpkin[1].state);
    mvprintw(13, 0, "%d", field->pumpkin[2].state);
    #endif
}

int findPumpkin(dron_t* dron, field_t* field)
{
    int min_i;
    int temp;
    int min = 9999;

    for (int i = 0; i < PUMPKIN_NUMBER; i++)
    {
        if (field->pumpkin[i].state == IS_COLLECT)
        {
            continue;
        }
        temp =  abs(field->pumpkin[i].x - dron->x) +
                abs(field->pumpkin[i].y - dron->y);
        if (temp < min)
        {
            min_i = i;
        }
    }

    return min_i;
}

void goToPumpkin(dron_t* dron, int x, int y)
{
    switch (dron->currentCommand)
    {
    case LEFT:
        if (dron->x == x)
        {
            (dron->y > y) ? (dron->currentCommand = UP) :
                            (dron->currentCommand = DOWN);
        }
        else if (dron->x < x)
        {
            (dron->y > y) ? (dron->currentCommand = UP) :
                            (dron->currentCommand = DOWN);
        }
        break;
    case RIGHT:
        if (dron->x == x)
        {
            (dron->y > y) ? (dron->currentCommand = UP) :
                            (dron->currentCommand = DOWN);
        }
        else if (dron->x > x)
        {
            (dron->y > y) ? (dron->currentCommand = UP) :
                            (dron->currentCommand = DOWN);
        }
        break;
    case UP:
        if (dron->y == y)
        {
            (dron->x > x) ? (dron->currentCommand = LEFT) :
                            (dron->currentCommand = RIGHT);
        }
        else if (dron->y < y)
        {
            (dron->x > x) ? (dron->currentCommand = LEFT) :
                            (dron->currentCommand = RIGHT);
        }
        break;
    case DOWN:
        if (dron->y == y)
        {
            (dron->x > x) ? (dron->currentCommand = LEFT) :
                            (dron->currentCommand = RIGHT);
        }
        else if (dron->y > y)
        {
            (dron->x > x) ? (dron->currentCommand = LEFT) :
                            (dron->currentCommand = RIGHT);
        }
        break;
    }
}

void collectPumpkin(dron_t* dron, field_t* field)
{
    for (int i = 0; i < PUMPKIN_NUMBER; i++)
    {
        if (field->pumpkin[i].state == IS_RIPE &&
            dron->x == field->pumpkin[i].x &&
            dron->y == field->pumpkin[i].y)
        {
            field->pumpkin[i].state = IS_COLLECT;
            field->pumpkinNumber--;
            dron->basketNumber++;
        }
    }
}
