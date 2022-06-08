#include "../include/researchTasks.h"
#include "../include/pokedexTools.h"
#include "../include/manageMenu.h"
#include <stdio.h>
#include <string.h>

void reviewTasksByPokemon(Pokedex dex)
{
    int input, back;
    Pokemon mon;
    
    do
    {
        clear_screen();
        printf("---Reviewing Tasks Per Pokemon---\n\n");
        displayTaskEntries(dex);
        printf("\nWhich Pokemon would you like to review tasks for? ");
        input = intHandler(1, dex.pokeCount);

        mon = dex.collection[input - 1];

        if (input)
        {
            clear_screen();
            displayPokemon(mon);
            printf("-----Research Tasks Progress: %d%%-----\n", mon.tasks.progress);
            displayTaskStatus(mon);
        }

        printf("\nPress [1] to REVIEW other details or [0] to RETURN: ");
        back = intHandler(0, 1);

    } while (back != 0);
}

void reviewByType(Pokedex dex)
{
    //put the func heree!! :>
}