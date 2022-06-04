#ifndef _POKEDEXTOOLS_H_
#define _POKEDEXTOOLS_H_

#define MAX_ENTRIES 150
#define MAX_NAME_LEN 20
#define MAX_TYPE_LEN 10
#define MAX_DESC_LEN 50

typedef struct {
    int entry;
    char name[MAX_NAME_LEN];
    char type[MAX_TYPE_LEN];
    char description[MAX_DESC_LEN];
} Pokemon; 

typedef struct{
    Pokemon collection[MAX_ENTRIES];
    int pokeCount;
} Pokedex;

typedef char string[20];

// Initialization
Pokemon initPokemon();          // This initalizes the Pokemon information
Pokedex initCollection();       // This is a separate struct that contains all 150 Pokemon  

// Utils for the Pokedex
void clear_screen();
int checkDup(Pokedex dex, char name[]);
int entryExists(Pokedex dex, int entry);
void displayPokemon(Pokemon p);
char toUpper(char c);

#endif