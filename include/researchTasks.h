#ifndef RESEARCHTASKS_H
#define RESEARCHTASKS_H

#include "pokedexTools.h"

//Function that displays all pokemon entries and their research task status
void reviewTasksByPokemon(Pokemon pokemon);

//Function that displays the the research tasks per type
void reviewTasksByType(Pokemon pokemon);

//Function that updates the research tasks per pokemon
void updateTasks(Pokemon pokemon);

//Function that sorts the pokemon according to research tasks completion
void rankPokemon(Pokemon pokemon);

#endif