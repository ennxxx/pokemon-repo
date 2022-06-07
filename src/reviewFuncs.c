#include "../include/researchTasks.h"
#include "../include/pokedexTools.h"
#include "../include/manageMenu.h"
#include <stdio.h>

void reviewTasksByPokemon(Pokedex* dex)
{
    int input;
    Pokemon mon;
    
    displayEntries(dex);
    printf("Research Tasks Details: ");
    input = intHandler(1, dex->pokeCount);

    mon = dex->collection[input - 1];

    if (input != 0)
    {
        displayPokemon(mon);
        printf("-----Research Tasks-----\n");
        displayTask(mon);
    }
}

