// This exports and imports entries to and from the Pokedex

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void exportEntries(Pokedex* dex)
{
    FILE *fp = fopen(FILENAME, "a+");
    
    int i;
    Pokemon pokemon;
    
    for (i = 0; i < dex->pokeCount; i++)
    {
        pokemon = dex->collection[i];

        fprintf(fp, "Details for Entry Number %d\n", pokemon.entry);
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