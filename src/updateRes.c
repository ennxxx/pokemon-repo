#include "../include/researchTasks.h"
#include "../include/pokedexTools.h"
#include "../include/manageMenu.h"
#include <stdio.h>
#include <string.h>

void updateTasks(Pokedex* dex)
{
    int input, back;
    Pokemon mon;
    
    do
    {
        clear_screen();
        printf("---Updating Tasks Per Pokemon---\n\n");
        displayEntries(dex, "CHOOSE ENTRY");
        printf("Which Pokemon would you like to update tasks for? ");
        input = intHandler(1, dex->pokeCount);
    
        mon = dex->collection[input - 1];
    
        if (input)
        {
            clear_screen();
            displayPokemon(mon);
            printf("-----Research Tasks Progress: %d%%-----\n", mon.tasks.progress);
            displayTask(mon);
        }
    
        printf("\nPress [1] to UPDATE other details or [0] to RETURN: ");
        back = intHandler(0, 1);
    
    } while (back != 0);
}