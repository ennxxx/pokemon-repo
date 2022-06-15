#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"
#include "../include/researchTasks.h"
#include "../include/uiElements.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @Description Calculates and checks the total progress of research tasks
 *              per Pokemon
 *
 * @param mon Holds Pokemon details, such as entry number,
 *            name, type, description.
 */
void
updateProgress(Pokemon *mon)
{
  int i, total, average;

  total = 0;

  for (i = 0; i < mon->tasks.taskCount; i++) {
    total += mon->tasks.list[i].status;
  }

  average = (float)total / (mon->tasks.taskCount * DEFAULT_COMPLETE) * 100;

  mon->tasks.progress = average; // Progress is updated from here
}

/**
 * @Description Updates the research tasks per Pokemon
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
updateTasks(Pokedex *dex)
{

  if (dex->pokeCount == 0) {
    printf("\nNo entries found.\n");
    return;
  }

  int task, pokemon, back, complete, limit;
  Pokemon *mon;

  back = -1;
  limit = 0;

  do {
    clear_screen();
    printf("---Updating Research Tasks---\n\n");

    // Display task entries
    displayAllTasks(*dex);
    printf("\nWhich task would you like to update? ");
    task = intHandler(1, dex->collection[0].tasks.taskCount);

    // Display all Pokemon entries
    displayTaskEntries(*dex);
    printf("\nWhich Pokemon would you like to update? ");
    pokemon = intHandler(1, dex->pokeCount);

    mon = &dex->collection[pokemon - 1];

    if (mon->tasks.list[task - 1].status == DEFAULT_COMPLETE) {
      printf("\nThis task is already complete!\n");
      printf("\nPress [1] to UPDATE another task or [0] to RETURN: ");
      back = intHandler(0, 1);
    }

    else {
      limit = DEFAULT_COMPLETE - mon->tasks.list[task - 1].status;
      printf("\nHow many times did you complete this task? ");
      complete = intHandler(1, limit);

      // Update the task
      mon->tasks.list[task - 1].status += complete;
      updateProgress(mon);

      // Display the updated pokemon
      clear_screen();
      printf("Updating tasks...\n\n");
      displayPokemon(*mon);
      printf("-----Research Tasks Progress: %d%%-----\n", mon->tasks.progress);
      displayTaskStatus(*mon);

      printf("\nPress [1] to UPDATE another task or [0] to RETURN: ");
      back = intHandler(0, 1);
    }

  } while (back != 0);
}

/**
 * @Description Allows a user to add more task types
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 *
 * @Pre-condition: taskList.taskCount must be less than 10
 */
void
addTaskTypes(Pokedex *dex)
{
  int back, redo, taskcount, i, j;
  string input;
  resTasks taskList;
  Pokemon mon;

  back = -1;

  do {
    clear_screen();
    taskList = dex->collection[0].tasks;
    taskcount = taskList.taskCount;

    // Display all existing task types
    printf("Adding task...\n\n");
    displayAllTasks(*dex);

    // If task count is already 10, force user to stop adding
    if (taskcount == 10) {
      printf("\nTask list is already full!\n");
      printf("\nPress [0] to RETURN: ");
      back = intHandler(0, 1);
    }

    // If task list is not full, ask user to input their new task type
    else {
      do {
        printf("\nWhat type of task would you like to add? ");
        scanf("%s", input);

        // Must return 0 for the function to continue
        redo = checkTaskDup(taskList, input);

        if (redo == 1)
          printf(
              "\nThis tasks already exists! Please enter another task type.\n");
      } while (redo != 0);

      // Add the new type to the list
      for (i = 0; i < MAX_ENTRIES; i++) {
        j = taskcount;

        mon = dex->collection[i];
        strcpy(mon.tasks.list[j].type, input);
        mon.tasks.taskCount++;
        dex->collection[i] = mon;
      }

      // Display the updated list
      clear_screen();
      printf("Adding task...\n\n");
      displayAllTasks(*dex);

      printf("\nPress [1] to ADD another task or [0] to RETURN: ");
      back = intHandler(0, 1);
    }

  } while (back != 0);
}
