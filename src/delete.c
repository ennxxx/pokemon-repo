// Deletes entries

#include <stdio.h>
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void deleteEntry(Pokedex* dex)
{
    int exists, entry, entryIndex;
    int i, back;
    
    exists = entryIndex = entry = -1;

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

    if (exists != -1)
    {
        entryIndex = exists;
    }
    
    for (i = entry - 1; i < dex->pokeCount - 1; i++)  
    {  
        dex->collection[i] = dex->collection[i + 1]; 
        dex->collection[i].entry -= 1;  // This updates the entry number
    }  
    
    printf("\nPokemon Entry %d has been DELETED. Press [0] to return: ", entry);
    scanf("%d", &back);

    switch(back)
    {
        case 0: manageMenu(*dex); break;
        default: break;
    }
}