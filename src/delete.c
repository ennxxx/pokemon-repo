// Deletes entries

#include <stdio.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void deleteEntry(Pokedex* dex)
{
    int exists, entry, entryIndex;
    int i, back;
    
    exists = -1;

    do
    {
    
        while (exists == -1)
        {
            displayEntries(dex, "DELETE");
            printf("\nWhich entry would you like to delete?: ");
            scanf("%d", &entry);
            exists = entryExists(*dex, entry);
            if (exists == -1)
            {
                printf("\nThat entry does not exist.\n"); 
            }
        }

        if (exists != -1)
        {
            entryIndex = exists;
        }
        
        for (i = entryIndex; i < dex->pokeCount; i++)  // Deletes based on index
        {  
            dex->collection[i] = dex->collection[i + 1]; 
            dex->collection[i].entry -= 1;  // This updates the entry number
        } 

        if (entry == dex->pokeCount) // Deletes the last entry
        {
            initPokemon();
        }

        dex->pokeCount -= 1; // Number of Pokemon decreases
        
        printf("\nPokemon Entry %d has been DELETED. Press [0] to RETURN: ", entry);
        back = intHandler(0, 1);
    
    } while (back != 0);
}

