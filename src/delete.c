#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"
#include "../include/researchTasks.h"
#include "../include/uiElements.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @Description Deletes existing entries in the Pokedex
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 *
 * @Pre-condition: dex.collection[entryIndex] must exist.
 */
void
deleteEntry(Pokedex *dex)
{
  int exists, entry, entryIndex;
  int i, back;

  exists = -1;

  do {
    // Checks if entry exists in the Pokedex
    while (exists == -1) {
      displayEntries(*dex, "DELETE");
      printf("\nWhich entry would you like to delete?: ");
      scanf("%d", &entry);
      exists = entryExists(*dex, entry);
      if (exists == -1)
        printf("\nThat entry does not exist.\n");
    }

    if (exists != -1)
      entryIndex = exists;

    // If it exists, delete entry based on its index
    for (i = entryIndex; i < dex->pokeCount; i++) {
      dex->collection[i] = dex->collection[i + 1];
      dex->collection[i].entry -= 1; // Since we are just passing information
                                     // backwards the entry number this updates
    }

    // If deleting last entry
    if (entry == dex->pokeCount)
      initPokemon();

    dex->pokeCount -= 1; // Decrease number of Pokemon after deleting

    printf("\nPokemon Entry %d has been DELETED. Press [0] to RETURN: ", entry);
    back = intHandler(0, 1);

  } while (back != 0);
}
