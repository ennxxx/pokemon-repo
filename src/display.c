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
    
    limit = 3;
    back = -1;
    i = 1;

    do
    {
        system("clear || cls");

        printf("Displaying entries...\n\n");


        for (; i <= limit; i++)     // Garbage values are displayed rip
        {
            pokemon = dex.collection[i];
            printf("Details for Entry Number %d\n", pokemon.entry);
            printf("Name: %s\n", pokemon.name);
            displayType(pokemon);
            printf("Description: %s\n", pokemon.description);

        }

        printf("[0] RETURN\n");
        printf("[1] NEXT\n");
        printf("[2] PREV\n\n");
        printf("Input: ");
        scanf("%d", &back); // Put an input handler here

        if (back == 1)
        {
            limit += 3;
        }

        // Put previous function here

    } while (back != 0);
}