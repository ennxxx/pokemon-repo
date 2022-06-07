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
            displayPokemon(pokemon);
        }

        // Displaying buttons

        if (dex->pokeCount <= 3) // No next or previous buttons at first page IF there are less than 3 entries   
        {
            printf("[0] Return\n\n"); 
            printf("Input: ");
            back = intHandler(0, 0);
        }

        else if (count == 0 && dex->pokeCount > 3) // No previous button at first page IF there are more than 3 entries
        {
            printf("[0] Return\n");         
            printf("[1] Next\n\n");
            printf("Input: ");
            back = intHandler(0, 1);
        }

        else if (pokemon.entry == dex->pokeCount) // No next button if at the last page
        {
            printf("[0] Return\n");         
            printf("[2] Previous\n\n");
            printf("Input: ");
            back = intHandler(0, 2);
        }

        else    
        {
            printf("[0] Return\n");         
            printf("[1] Next\n");
            printf("[2] Previous\n\n");
            printf("Input: ");
            back = intHandler(0, 2);
        }

        // Button functions

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