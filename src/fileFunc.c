// This exports and imports entries to and from the Pokedex

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void exportEntries(Pokedex* dex)
{
    char fileName[26];
    char extension[5] = ".txt";
    
    printf("\nExporting entries...\n\n");
    printf("Input a file name: ");
    scanf("%s", fileName);

    strcat(fileName, extension);
    
    FILE *fp = fopen(fileName, "w");
    
    int i;
    Pokemon pokemon;
    
    for (i = 0; i < dex->pokeCount; i++)
    {
        pokemon = dex->collection[i];

        fprintf(fp, "Name: %s\n", pokemon.name);
        switch(toUpper(pokemon.type)) 
        {
            case 'E': fprintf(fp, "Type: Electric\n"); break;
            case 'F': fprintf(fp, "Type: Fire\n"); break;
            case 'G': fprintf(fp, "Type: Grass\n"); break;
            case 'W': fprintf(fp, "Type: Water\n"); break;
            default: break;
        } 
        fprintf(fp, "Description: %s\n", pokemon.description);
    }

    fclose(fp);
}

void importEntries(Pokedex* dex)
{
    char fileName[26];
    char extension[5] = ".txt";
    int entryIndex, ch;
    int count;
    
    printf("\nImporting entries...\n\n");
    printf("Input a file name: ");
    scanf("%s", fileName);

    strcat(fileName, extension);
    
    FILE *fp = fopen(fileName, "r");

    while ((count = fgetc(fp)) != EOF)
    {
        clear_screen();
        
        entryIndex = dex->pokeCount; // Index is based on the last pokeCount
        Pokemon import = dex->collection[entryIndex]; // Importing Pokemon detials to a specific index

        printf("Loading entry...\n\n");
        fscanf(fp, "%s\n", import.name);
        fscanf(fp, "%c\n", &import.type);
        fgets(import.description, MAX_DESC_LEN, fp);

        import.entry = dex->pokeCount + 1; // Notes down entry number based on last pokeCount + 1
        printf("Name: %s\n", import.name);
        displayType(import);
        printf("Description: %s\n", import.description);

        printf("Press [1] to IMPORT or [0] to SKIP entry: ");
        ch = intHandler(0, 1);

        switch (ch)
        {
            case 0: break;
            case 1: dex->collection[entryIndex] = import; // Import the details into the Pokedex collection
                    dex->pokeCount++; break; // Increase the pokeCount
        }
    }

    if (feof(fp))
    {
        manageMenu(dex);
    }

    fclose(fp);
}