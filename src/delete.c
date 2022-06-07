// Deletes entries

#include <stdio.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void deleteEntry(Pokedex* dex)
{
    int exists, entry;
    int i, back;
    
    exists = -1;

    do
    {
    
    while (exists == -1)
    {
        printf("\nWhich entry would you like to delete?: ");
        scanf("%d", &entry);
        exists = entryExists(*dex, entry);
        if (exists == -1)
        {
            printf("\nThat entry does not exist.\n"); 
        }
    }
    
    for (i = entry - 1; i < dex->pokeCount; i++)  // Deletes based on index
    {  
        dex->collection[i] = dex->collection[i + 1]; 
        dex->collection[i].entry -= 1;  // This updates the entry number
        dex->pokeCount -= 1; // Number of Pokemon decreases
    }  
    
    printf("\nPokemon Entry %d has been DELETED. Press [0] to return: ", entry);
    back = intHandler(0, 1);
    
    } while (back != 0);
}