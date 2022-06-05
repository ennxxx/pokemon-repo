// Pokedex utility functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pokedexTools.h"

void clear_screen()
{
    #ifdef WINDOWS
    {
        system("cls");
    }
    #else
    {
        system("clear");
    }
    #endif
}

int checkDup(Pokedex dex, char name[20])
{
    int i;

    for (i = 0; i < dex.pokeCount; i++)
    {
        if (strcmp(name, dex.collection[i].name) == 0)   
        {
            return 0;   // Returns 0 if the entry has already been entered previously
        }
    }

    return 1;
} 

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

void displayType(Pokemon p)
{
    switch(toUpper(p.type))
    {
        case 'E': printf("Type: Electric\n"); break;
        case 'F': printf("Type: Fire\n"); break;
        case 'G': printf("Type: Grass\n"); break;
        case 'W': printf("Type: Water\n"); break;
        default: break;
    }
}

void displayPokemon(Pokemon p)
{
    printf("Entry: %d\n", p.entry);
    printf("Name: %s\n", p.name);
    displayType(p);
    printf("Description: %s\n", p.description);
}

char toUpper(char c) 
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    
    return c;
}