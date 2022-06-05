// Display function (WIP)

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void displayEntries(Pokedex dex)
{   
    int i, back, limit;

    Pokemon pokemon;
    limit = 5;
    back = -1;
    i = 0;

    do
    {
        clear_screen();

        printf("Displaying entries...\n\n");


        for (; i < limit; i++)     // Garbage values are displayed rip
        {
            pokemon = dex.collection[i];
            printf("Details for Entry Number %d\n", pokemon.entry);
            printf("Name: %s\n", pokemon.name);
            displayType(pokemon);
            printf("Description: %s\n", pokemon.description);
        }
        
        printf("Press [1] for the next page, [0] to RETURN to the manage menu: ");
        scanf("%d", &back); // put an input handler here

        if (back == 1)
            limit += 5 + 1;

    } while (back != 0);
}