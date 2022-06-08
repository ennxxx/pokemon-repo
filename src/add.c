// This adds and checks for duplicate entries in the Pokedex

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void addEntry(Pokedex* dex)
{   
    int back, redo, index;

    do
    {
        clear_screen();
        printf("---Adding Entries---\n\n");

        index = dex->pokeCount;
        
        dex->collection[index].entry = index + 1;
        
        printf("Inputting Entry %d...\n\n", dex->collection[index].entry);

        do
        {
            printf("Name: ");
            scanf("%s", dex->collection[index].name); 

            redo = checkDup(*dex, dex->collection[index].name);  // Must return 1 for the function to continue

            if (redo == 0)
            {
                printf("\nThis entry already exists! Please enter another Pokemon name.\n\n");
            }

        } while (redo != 1);
        
        printf("\nPlease choose from the following:\n");
        printf("[E]lectric\n");
        printf("[F]ire\n");
        printf("[G]rass\n");
        printf("[W]ater\n\n");
        printf("Type: ");
        dex->collection[index].type = charHandler(POKE_TYPES);

        fflush(stdin);
        printf("\nDescription: ");
        fgetc(stdin);
        fgets(dex->collection[index].description, MAX_DESC_LEN, stdin);
                
        printf("\n...done inputting!\n\n");

        dex->pokeCount = dex->collection[index].entry;                 // Ensures that new entries will be added based on previous index

        printf("Press [1] to ADD another entry or [0] to RETURN: ");
        back = intHandler(0, 1);
        
    } while (back != 0);
}