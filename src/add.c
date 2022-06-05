// This adds and checks for duplicate entries in the Pokedex

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void addEntry(Pokedex dex)
{   
    int back, redo;

    Pokemon pokemon;

    do
    {
        clear_screen();
        printf("---Adding Entries---\n\n");

        pokemon.entry = dex.pokeCount + 1;
        
        printf("Inputting Entry %d...\n\n", pokemon.entry);

        do
        {
            printf("Name: ");
            scanf("%s", pokemon.name); 

            redo = checkDup(dex, pokemon.name);  // Must return 1 for the function to continue

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
        scanf(" %c", &pokemon.type);

        fflush(stdin);
        printf("\nDescription: ");
        fgetc(stdin);
        fgets(pokemon.description, 50, stdin);
                
        printf("\n...done inputting!\n\n");

        dex.collection[pokemon.entry] = pokemon;      // Adds Pokemon to database
        dex.pokeCount = pokemon.entry;    // Ensures that new entries will be added based on previous index

        printf("Press [1] to ADD another entry or [0] to RETURN to the manage menu: ");
        scanf("%d", &back);
        
    } while (back != 0);
}