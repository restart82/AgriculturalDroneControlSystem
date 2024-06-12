#include "../inc/field.h"

field_t initPumpkinField()
{
    field_t field;
    field.pumpkinNumber = PUMPKIN_NUMBER;
    field.pumpkin = (pumpkin_t*)calloc(PUMPKIN_NUMBER, sizeof(pumpkin_t));
    generatePumpkins(&field);
    return field;
}

void updatePumpkinField(field_t* field)
{
    static int counter = 0;
    if (counter < 15)
    {
        counter++;
    }
    
    if (counter == 7)
    {
        for (int i = 0; i < PUMPKIN_NUMBER; i++)
        {
            field->pumpkin[i].state = LEVEL_2;
        }
    }
    else if (counter == 15)
    {
        for (int i = 0; i < PUMPKIN_NUMBER; i++)
        {
            field->pumpkin[i].state = IS_RIPE;
        }
    }

    if (field->pumpkinNumber == 0)
    {
        generatePumpkins(field);
        field->pumpkinNumber = PUMPKIN_NUMBER;
        counter = 0;
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

