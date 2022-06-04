// Modifies entries in the Pokedex

#include <stdio.h>
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

// Display all entries then then ask the user which one to modify
// Check if the entry number exists in the Pokedex
// Return the index of the Pokemon's entry if the entry entered exists
// Return -1 otherwise

int entryExists(Pokedex dex, int entry)
{
    
    int i, exists = 0;  // For all entities in the Pokedex
    int entryIndex;
    
    for(i = 0; i < 150; i++)
    {
        if(entry == dex.collection[i].entry)
        {
            exists = 1;
            entryIndex = i;
            i = 150;
        }
    }

    if(exists)
        return entryIndex;

    return -1;
}

void displayPokemon(Pokemon p)
{
    printf("Entry: %d\n", p.entry);
    printf("Name: %s\n", p.name);
    switch(p.type)
    {
        case 'E': printf("Type: Electric\n"); break;
        case 'F': printf("Type: Fire\n"); break;
        case 'G': printf("Type: Grass\n"); break;
        case 'W': printf("Type: Water\n"); break;
        default: break;
    }
    printf("Description: %s\n", p.description);
}

void modifyEntry(Pokedex dex)
{
    int redo;
    int exists, entry, entryIndex;
    char changeOpt;
    
    // Ask the user which entry they would like to modify
    // Set default value to negative 1 to indicate errors
    
    exists = entryIndex = entry = -1;

    while (exists == -1)
    {
        printf("\nWhich entry would you like to modify?: ");
        scanf("%d", &entry);
        exists = entryExists(dex, entry);
        if(exists == -1)
            printf("\nThat entry does not exist.\n");
    }

    // Guard clause to avoid errors
    // Will only set entryIndex to the index of the entry if the entry exists

    if(exists != -1)
        entryIndex = exists;

    // Modify the entry located at entryIndex
    Pokemon changeMon = dex.collection[entryIndex];

    changeOpt = ' ';
    do {
        clear_screen();
        displayPokemon(changeMon);
        printf("What would you like to change?\n");
        printf("[0] Save and Exit\n");
        printf("[1] Name\n");
        printf("[2] Type\n");
        printf("[3] Description\n");
        printf("[4] Cancel\n\n");
        printf("Input: ");
        scanf("%c", &changeOpt);

        switch(changeOpt){
            case '0':
                printf("\nSaving changes...\n");
                // Only assign the new Pokemon to the Pokedex if the user enters save
                dex.collection[entryIndex] = changeMon;
                break;
            case '1':
                do
                {
                    printf("\nChanging name to... ");
                    scanf("%s", changeMon.name);

                    redo = checkDup(dex, changeMon.name);  // Must return 1 for the function to continue

                    if (redo == 0)
                    {
                        printf("\nThis entry already exists! Please enter another Pokemon name.\n");
                    }
                } while (redo != 1);
                break;
            case '2':
                printf("\nChanging type to...\n");
                printf("[E]lectric\n");
                printf("[F]ire\n");
                printf("[G]rass\n");
                printf("[W]ater\n\n");
                printf("Type: ");
                scanf(" %c", &changeMon.type);
                break;
            case '3':
                fflush(stdin); 
                printf("\nChanging description to... ");
                fgets(changeMon.description, 50, stdin);
                break;
            case '4':
                printf("\nQuitting...\n");
                changeOpt = '0';
                break;
            default:
                printf("\nInvalid input.\n");
                break;
        }
    } while(changeOpt != '0');
}
