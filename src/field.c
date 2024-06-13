#include "../inc/field.h"

field_t initPumpkinField()
{
    field_t field;
    field.pumpkinNumber = PUMPKIN_NUMBER;
    field.pumpkin = (pumpkin_t*)calloc(PUMPKIN_NUMBER, sizeof(pumpkin_t));
    field.isReady = false;
    generatePumpkins(&field);
    return field;
}

void updatePumpkinField(field_t* field)
{
    static int counter = 0;
    static int delay = 5;
    if (counter < PUMPKIN_GROW_TIME + 1)
    {
        counter++;
    }
    
    if (counter == PUMPKIN_GROW_TIME / 2)
    {
        for (int i = 0; i < PUMPKIN_NUMBER; i++)
        {
            field->pumpkin[i].state = LEVEL_2;
        }
    }
    else if (counter == PUMPKIN_GROW_TIME)
    {
        for (int i = 0; i < PUMPKIN_NUMBER; i++)
        {
            field->pumpkin[i].state = IS_RIPE;
        }
        field->isReady = true;
    }

    if (field->pumpkinNumber == 0)
    {
        delay--;
        if (delay == 0)
        {
            generatePumpkins(field);
            field->pumpkinNumber = PUMPKIN_NUMBER;
            field->isReady = false;
            counter = 0;
            delay = 5;
        }
    }
}

void generatePumpkins(field_t* field)
{
    srand(time(0));
    bool flag;
    int counter;
    for (int i = 0; i < PUMPKIN_NUMBER; i++)
    {
        flag = true;
        while (flag)
        {
            field->pumpkin[i].x = rand() % FIELD_SIZE_X;
            field->pumpkin[i].y = rand() % FIELD_SIZE_Y;

            counter = 0;
            for (int j = 0; j < i; j++)
            { 
                if (field->pumpkin[i].x == field->pumpkin[j].x &&
                    field->pumpkin[i].y == field->pumpkin[j].y)
                {
                    break;
                }
                else
                {
                    counter++;
                }
            }
            if (counter == i)
            {
                flag = false;
            }
        }
        field->pumpkin[i].state = LEVEL_1;
    }
}

