// Display function (WIP)

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void displayEntries(Pokedex dex)
{   
    int i, back;

    Pokemon pokemon;

    do
    {
        clear_screen();

        printf("Displaying entries...\n\n");

        for (i = 0; i < 5; i++)     // Garbage values are displayed rip
        {
            pokemon = dex.collection[i];

            printf("Details for Entry Number %d\n", pokemon.entry);
            printf("Name: %s\n", pokemon.name);
            displayType(pokemon);
            printf("Description: %s\n", pokemon.description);
        }
        
        printf("Press [1] for the next page, [0] to RETURN to the manage menu: ");
        scanf("%d", &back);

        switch(back)    // Previous and next pages have not been implemented
        {
            case 0: manageMenu(dex);
            case 1: break;
            default: printf("Invalid option! Please try again.\n\n"); break;
        }

    } while (back != 0);
}