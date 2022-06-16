#ifndef _POKEDEXTOOLS_H_
#define _POKEDEXTOOLS_H_

#define POKE_TYPES "EFGW"
#define MAX_ENTRIES 150
#define MAX_NAME_LEN 21
#define MAX_DESC_LEN 51
#define MAX_TASKS 10
#define DEFAULT_COMPLETE 15

typedef char string[20];
typedef enum FILTERTYPE { NAME, DESCRIPTION, TYPE } FT;

typedef struct {
  string type;
  int status;
  int complete;
} resType;

typedef struct {
  resType list[10];
  int taskCount;
  int progress;
} resTasks;

typedef struct {
  int entry;
  char name[MAX_NAME_LEN];
  char type;
  char description[MAX_DESC_LEN];
  resTasks tasks;
} Pokemon;

typedef struct {
  Pokemon collection[MAX_ENTRIES];
  int pokeCount;
} Pokedex;

// Initialization
Pokemon initPokemon();           // This initalizes the Pokemon information
resType initTaskTypes();         // Initializes the individual task types
void initTasks(resTasks *tasks); // Initializes the task list
Pokedex initCollection();        // Holds the 150 Pokemon and initializes
                                 // number of Pokemon

// Utils for the Pokedex
void clear_screen();
void displayType(Pokemon p);
void displayPokemon(Pokemon p);
void displayAllTasks(Pokedex dex);
void displayTaskStatus(Pokemon mon);
void trimString(char *str);
void filterString(char *str, FT filter);
int checkDup(Pokedex dex, char name[MAX_NAME_LEN]);
int checkTaskDup(resTasks taskList, string taskName);
int entryExists(Pokedex dex, int entry);
int fileExists(const char *fileName);
int pokeRank(Pokedex dex, int *sortedEntries);
int intHandler(int min, int max);
char charHandler(const char *chars);
char toUpper(char c);
char *allCaps(char *str);

#endif
