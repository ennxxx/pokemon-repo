#include "../include/researchTasks.h"
#include "../include/pokedexTools.h"
#include "../include/manageMenu.h"
#include <stdio.h>

void reviewTasksByPokemon(Pokedex* dex)
{
    int input, back;
    Pokemon mon;
    
    do
    {
        clear_screen();
        printf("---Reviewing Tasks Per Pokemon---\n\n");
        displayEntries(dex);
        printf("Research Tasks Details: ");
        input = intHandler(1, dex->pokeCount - 1);

        mon = dex->collection[input - 1];

        if (input)
        {
            clear_screen();
            displayPokemon(mon);
            printf("-----Research Tasks Progress: %d%%-----\n", mon.tasks.list[input].progress);
            displayTask(mon);
        }

        printf("Look at other Details [1] or RETURN [0]: ");
        back = intHandler(0, 1);

    } while (back != 0);
}

