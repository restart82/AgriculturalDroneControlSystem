#include "../inc/view.h"

void printDron(dron_t* dron)
{
    attron(COLOR_PAIR(DRON_PAIR));

    mvprintw(dron->y + ZERO_Y, dron->x + ZERO_X, "X");
    for (int i = 0; i < dron->basketNumber; i++)
    {
        mvprintw(dron->basket[i].y + ZERO_Y, dron->basket[i].x + ZERO_X, "u");
    }

    attroff(COLOR_PAIR(DRON_PAIR));
}

void printBorder()
{
    attron(COLOR_PAIR(BORDER_PAIR));
    mvprintw(ZERO_Y - 1, ZERO_X - 1, "#");
    mvprintw(ZERO_Y - 1, ZERO_X + FIELD_SIZE_X , "#");
    mvprintw(ZERO_Y + FIELD_SIZE_Y, ZERO_X - 1, "#");
    mvprintw(ZERO_Y + FIELD_SIZE_Y, ZERO_X + FIELD_SIZE_X, "#");
    
    for (int i = 0; i < FIELD_SIZE_X; i++)
    {
        mvprintw(ZERO_Y - 1, ZERO_Y + i, "-");
        mvprintw(ZERO_Y + FIELD_SIZE_Y, ZERO_Y + i, "-");
    }
    
    for (int i = 0; i < FIELD_SIZE_Y; i++)
    {
        mvprintw(i + ZERO_Y, ZERO_X - 1, "|");
        mvprintw(i + ZERO_Y, ZERO_X + FIELD_SIZE_X, "|");
    }
    attroff(COLOR_PAIR(BORDER_PAIR));
}

void startView()
{
    initscr();
    keypad(stdscr, true);
    raw();
    noecho();
    curs_set(FALSE);

    start_color();
    init_pair(BORDER_PAIR, BORDER_COLOR, BACKGROUND_COLOR);
    init_pair(DRON_PAIR, DRON_COLOR, BACKGROUND_COLOR);
}

void endView()
{
    endwin();
}

void clearField()
{
    for (int i = 0; i < FIELD_SIZE_X; i++)
    {
        for (int j = 0; j < FIELD_SIZE_Y; j++)
        {
            mvprintw(ZERO_Y + j, ZERO_X + i, " ");
        }
    }
}