// Display function (WIP)

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void displayEntries(Pokedex* dex, const char* button)
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

        // Display buttons

        if (dex->pokeCount <= 3) // No next or previous buttons at first page IF there are less than 3 entries   
        {
            printf("[0] %s\n\n", button); 
            printf("Input: ");
            back = intHandler(0, 0);
        }

        else    
        {
            printf("[0] %s\n", button);         
            printf("[1] NEXT\n");
            printf("[2] PREV\n\n");
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

void displayTaskEntries(Pokedex* dex)
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
            printf("Entry: %d\n", pokemon.entry);
            printf("Name: %s\n", pokemon.name);
            printf("Research Progress: %d%%\n\n", pokemon.tasks.progress);
        }

        // Display buttons

        if (dex->pokeCount <= 3) // No next or previous buttons at first page IF there are less than 3 entries   
        {
            printf("[0] CHOOSE ENTRY\n\n"); 
            printf("Input: ");
            back = intHandler(0, 0);
        }

        else    
        {
            printf("[0] CHOOSE ENTRY\n");         
            printf("[1] NEXT\n");
            printf("[2] PREV\n\n");
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