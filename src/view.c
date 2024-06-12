#include "../inc/view.h"

void printDron(dron_t* dron)
{
    attron(COLOR_PAIR(DRON_PAIR));
    mvprintw(ZERO_Y, ZERO_X, ".");
    mvprintw(ZERO_Y + FIELD_SIZE_Y - 1, ZERO_X + FIELD_SIZE_X - 1, ".");
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
    start_color();
    curs_set(FALSE);

    init_pair(BORDER_PAIR, BORDER_COLOR, BACKGROUND_COLOR);
    init_pair(DRON_PAIR, DRON_COLOR, BACKGROUND_COLOR);
    
}

void endView()
{
    endwin();
}