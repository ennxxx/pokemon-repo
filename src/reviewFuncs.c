#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"
#include "../include/researchTasks.h"
#include <stdio.h>
#include <string.h>

/**
 * @Description Reviews Pokemon tasks based on chosen Pokemon
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
reviewTasksByPokemon(Pokedex dex)
{
  int input, back;
  Pokemon mon;

  do {
    clear_screen();
    printf("---Reviewing Tasks Per Pokemon---\n\n");
    displayTaskEntries(dex);
    printf("\nWhich Pokemon would you like to review tasks for? ");
    input = intHandler(1, dex.pokeCount);

    mon = dex.collection[input - 1];

    if (input) {
      clear_screen();
      displayPokemon(mon);
      printf("-----Research Tasks Progress: %d%%-----\n", mon.tasks.progress);
      displayTaskStatus(mon);
    }

    printf("\nPress [1] to REVIEW other Pokemon or [0] to RETURN: ");
    back = intHandler(0, 1);

  } while (back != 0);
}

/**
 * @Description Reviews Pokemon tasks based on chosen task type
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
reviewTasksByType(Pokedex dex)
{
  int task, back;
  int width = 33, tasklen;
  int i = 0, j = 0;
  int namelen;
  string taskStr;
  Pokemon mon;

  do {
    clear_screen();
    printf("---Reviewing Task per Task Type---\n\n");

    displayAllTasks(dex);
    printf("\nWhich task would you like to review? ");
    task = intHandler(1, dex.collection[0].tasks.taskCount);

    strcpy(taskStr, dex.collection[0].tasks.list[task - 1].type);
    tasklen = strlen(taskStr);
    width += tasklen;
    j = task - 1;

    clear_screen();
    printf("---Research Tasks Progress: %s---\n",
           dex.collection[0].tasks.list[j].type);

    for (i = 0; i < dex.pokeCount; i++) {
      mon = dex.collection[i]; // Access entries
      namelen = strlen(mon.name);

      if (mon.tasks.list[j].status != 0) {
        printf("⟢ %s", mon.name);
        printf("%*s", width - namelen - (8 + mon.tasks.list[j].status / 10),
               " ");
        printf("%d/%d \n", mon.tasks.list[j].status,
               mon.tasks.list[j].complete);
      }
    }

    printf("\n< END OF LIST >\n\n");

    printf("Press [1] to REVIEW other tasks or [0] to RETURN: ");
    back = intHandler(0, 1);

  } while (back != 0);
}