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
