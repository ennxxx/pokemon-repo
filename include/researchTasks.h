#ifndef RESEARCHTASKS_H
#define RESEARCHTASKS_H

#include "pokedexTools.h"

//Function that displays all Pokemon entries and their research task status
void displayTaskEntries(Pokedex dex);
void reviewTasksByPokemon(Pokedex dex);

//Function that displays the the research tasks per type
void reviewTasksByType(Pokedex dex);

//Function that updates the research tasks per Pokemon
void updateTasks(Pokedex* dex);

// Function that checks the progress of research tasks per Pokemon
void updateProgress(Pokemon* mon);

// Function that sorts the Pokemon according to research tasks completion
void rankPokemon(Pokedex* dex);

// Function that allows a user to add more task types
void addTaskTypes(Pokedex* dex);

#endif