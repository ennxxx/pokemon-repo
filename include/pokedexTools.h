#ifndef _POKEDEXTOOLS_H_
#define _POKEDEXTOOLS_H_

typedef struct {
    int entry;
    char name[20];
    char type[10];
    char description[50];
} Pokemon; 

typedef struct{
    Pokemon collection[150];
    int lastEntry;
} Pokedex;

// Initialization
Pokemon initPokemon();          // This initalizes the Pokemon information
Pokedex initCollection();       // This is a separate struct that contains all 150 Pokemon  

// Utils for the Pokedex
int checkDup(Pokedex dex, char name[]);
int entryExists(Pokedex dex, int entry);
void displayPokemon(Pokemon p);

#endif