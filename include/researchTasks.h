#ifndef RESEARCHTASKS_H
#define RESEARCHTASKS_H

#include "pokedexTools.h"

//Function that displays all pokemon entries and their research task status
void reviewTasksByPokemon(Pokedex dex);

//Function that displays the the research tasks per type
void reviewTasksByType(Pokedex dex);

//Function that updates the research tasks per pokemon
void updateTasks(Pokedex* dex);

//Function that sorts the pokemon according to research tasks completion
void rankPokemon(Pokedex* dex);

void addTaskTypes(Pokedex* dex);

void updateProgress(Pokemon* mon);

#endif