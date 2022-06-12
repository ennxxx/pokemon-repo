// This adds and checks for duplicate entries in the Pokedex

#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"
#include "../include/uiElements.h"
#include <stdio.h>
#include <string.h>

/**
 * @Description Adds Pokemon entries to the Pokedex
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
addEntry(Pokedex *dex)
{
  int back, redo, index;
  char tmp[100];

  do {
    clear_screen();
    printf("---Adding Entries---\n\n");

    index = dex->pokeCount;
    dex->collection[index].entry = index + 1;
    printf("Inputting Entry %d...\n\n", dex->collection[index].entry);

    do {
      printf("Name: ");
      scanf("%s", dex->collection[index].name);

      // Must return 0 for the function to continue
      redo = checkDup(*dex, dex->collection[index].name);

      if (redo == 1)
        printf("\nThis entry already exists! Please enter another Pokemon "
               "name.\n\n");
    } while (redo != 0);

    printf("\nPlease choose from the following:\n");
    printf("[E]lectric\n");
    printf("[F]ire\n");
    printf("[G]rass\n");
    printf("[W]ater\n\n");
    printf("Type: ");
    dex->collection[index].type = charHandler(POKE_TYPES);

    fflush(stdin);
    printf("\nDescription: ");
    fgetc(stdin);
    fgets(tmp, MAX_DESC_LEN, stdin);
    trimString(tmp);
    strcpy(dex->collection[index].description, tmp);

    printf("\n...done inputting!\n\n");

    // Ensures that new entries will be added based on previous index
    dex->pokeCount = dex->collection[index].entry;

    printf("Press [1] to ADD another entry or [0] to RETURN: ");
    back = intHandler(0, 1);
  } while (back != 0);
}