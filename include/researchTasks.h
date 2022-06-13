#ifndef RESEARCHTASKS_H
#define RESEARCHTASKS_H

#include "pokedexTools.h"

void displayTaskEntries(Pokedex dex);

void reviewTasksByPokemon(Pokedex dex);

void reviewTasksByType(Pokedex dex);

void updateProgress(Pokemon *mon);

void updateTasks(Pokedex *dex);

void addTaskTypes(Pokedex *dex);

void rankPokemon(Pokedex dex);

#endif
