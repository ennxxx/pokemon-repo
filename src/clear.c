// Clear screen function

#include <stdlib.h>
#include "../include/pokedexTools.h"

void clear_screen()
{
    #ifdef WINDOWS
    {
        system("cls");
    }
    #else
    {
        system("clear");
    }
    #endif
}