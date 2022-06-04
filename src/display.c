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

        for (i = 0; i < 3; i++)     // Garbage values are displayed rip
        {
            pokemon = dex.collection[i];

            printf("Details for Entry Number %d\n", pokemon.entry);
            printf("Name: %s\n", pokemon.name);
            switch(pokemon.type)
            {
                case 'E': printf("Type: Electric\n"); break;
                case 'F': printf("Type: Fire\n"); break;
                case 'G': printf("Type: Grass\n"); break;
                case 'W': printf("Type: Water\n"); break;
                default: break;
            }
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