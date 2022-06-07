#ifndef _POKEDEXTOOLS_H_
#define _POKEDEXTOOLS_H_

#define POKE_TYPES "EFGW"
#define MAX_ENTRIES 150
#define MAX_NAME_LEN 20
#define MAX_DESC_LEN 50
#define MAX_TASKS 10
#define DEFAULT_COMPLETE 15

typedef char string[20];

typedef struct{
    string type;
    int status;
} resType;

typedef struct{
    resType list[10];
    int taskCount;
} resTasks;

typedef struct {
    int entry;
    char name[MAX_NAME_LEN];
    char type;
    char description[MAX_DESC_LEN];
    resTasks tasks;
} Pokemon; 

typedef struct{
    Pokemon collection[MAX_ENTRIES];
    int pokeCount;
} Pokedex;

// Initialization
Pokemon initPokemon();              // This initalizes the Pokemon information
resType initTaskTypes();            // Initializes the individual task types 
void initTasks(resTasks* tasks);    // Initializes the task list
Pokedex initCollection();           // This is a separate struct that contains all 150 Pokemon  

// Utils for the Pokedex
void clear_screen();
int checkDup(Pokedex dex, char name[20]);
int entryExists(Pokedex dex, int entry);
void displayType(Pokemon p);
void displayPokemon(Pokemon p);
void displayTask(Pokemon mon);
char toUpper(char c);
int intHandler(int min, int max);
char charHandler(const char* chars);

#endif