#ifndef _MANAGEMENU_H_
#define _MANAGEMENU_H_

#include "pokedexTools.h"

void addEntry(Pokedex *dex);

void deleteEntry(Pokedex *dex);

void displayEntries(Pokedex dex, const char *button);

void modifyEntry(Pokedex *dex);

void searchByName(Pokedex dex);

void searchByType(Pokedex dex);

void exportEntries(Pokedex *dex);

void importEntries(Pokedex *dex);

int fileExists(const char *fileName);
#endif
