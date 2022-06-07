// Display function (WIP)

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void displayEntries(Pokedex* dex)
{   
    int i, back, limit, count;

    Pokemon pokemon;
    
    limit = 3;  // Displays 3 Pokemon from index 0 to 2
    count = 0;  // Counts the number of pages
    
    do
    {
        clear_screen();
        printf("Displaying entries...\n\n");

        for (i = 3 * count; i < limit && i < dex->pokeCount; i++)
        {
            pokemon = dex->collection[i];
            //Maybe use the display pokemon func here?
            printf("Details for Entry Number %d\n", pokemon.entry);
            printf("Name: %s\n", pokemon.name);
            displayType(pokemon);
            printf("Description: %s\n", pokemon.description);
        }

        printf("[0] Return\n");         
        printf("[1] Next\n");
        printf("[2] Previous\n\n");
        printf("Input: ");
        back = intHandler(0, 2);

        if (back == 1)
        {
            clear_screen();
            printf("Displaying entries...\n\n");
            count++;        
            limit += 3;     
        }

        else if (back == 2)
        {
            clear_screen();
            printf("Displaying entries...\n\n");
            count--;         
            limit -= 3;
        }

    } while (back != 0);
}