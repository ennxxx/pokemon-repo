/*
 * This is to certify that this project is our own work, based on our personal
 * efforts in studying and applying the concepts learned. We have constructed
 * the functions and their respective algorithms and corresponding code by
 * ourselves. The program was run, tested, and debugged by our own efforts.
 * We further certify that we have not copied in part or whole or otherwise
 * plagiarized the work of other students and/or persons.
 *
 * AEINNOR A. REYES, 121113542
 * PAULA ENXI D.V. PACHECO, 12133655
 */

#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"
#include "../include/researchTasks.h"
#include "../include/uiElements.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main()
{
  Pokedex dex;
  dex = initCollection(); // Access the entries through this function

  mainMenu(dex); // Opens up the main menu of the Pokedex

  return 0;
}

// Initialization

/**
 * @Description Initializes Pokemon information with default values
 *
 * @return Pokemon, which holds all the Pokemon information
 */
Pokemon
initPokemon()
{
  Pokemon p;

  p.entry = 0;
  strcpy(p.name, "");
  p.type = '\0';
  strcpy(p.description, "");
  initTasks(&p.tasks);

  return p;
}

/**
 * @Description Initialize collection of Pokedex entries and the starting
 *              count of entries in the Pokedex
 *
 * @return Pokedex, which holds the collection of Pokemon entries and pokeCount
 */
Pokedex
initCollection()
{
  int i;
  Pokedex dex;

  for (i = 0; i < MAX_ENTRIES; i++) {
    dex.collection[i] = initPokemon(); // Access the information of each Pokemon
  }

  dex.pokeCount = 0;

  return dex;
}

/**
 * @Description Initializes tasks used in the Pokedex
 *
 * @param tasks Holds details regarding research types, progress of
 *              tasks, and research progress.
 */
void
initTasks(resTasks *tasks)
{
  int i;
  resType task;

  i = 0;

  // Initializes default task types
  strcpy(task.type, "Seen");
  task.status = 0;
  task.complete = DEFAULT_COMPLETE;
  tasks->list[0] = task;

  strcpy(task.type, "Caught");
  task.status = 0;
  task.complete = DEFAULT_COMPLETE;
  tasks->list[1] = task;

  strcpy(task.type, "Defeated");
  task.status = 0;
  task.complete = DEFAULT_COMPLETE;
  tasks->list[2] = task;

  for (i = 3; i < 10; i++) {
    tasks->list[i] = initTaskTypes();
  }

  tasks->taskCount = 3;
  tasks->progress = 0;
}

/**
 * @Description Initializes task types with its default values
 *
 * @return resType, which holds the progress and name of a Pokemon task type
 */
resType
initTaskTypes()
{
  resType task;

  strcpy(task.type, "DEFAULT_VALUE");
  task.status = 0;
  task.complete = DEFAULT_COMPLETE;

  return task;
}

// Menu Pages

/**
 * @Description Displays the Main Menu of the Pokedex
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
mainMenu(Pokedex dex)
{
  int mainOpt;

  do {
    clear_screen();
    printf("Welcome to your Pokédex!\n\n");
    printf("What would you like to do?\n\n");
    printf("[1] Manage Data\n");
    printf("[2] Research Tasks\n");
    printf("[0] Exit\n\n");
    printf("Input: ");
    mainOpt = intHandler(0, 2);

    switch (mainOpt) {
      case 1:
        manageMenu(&dex);
        break;
      case 2:
        researchMenu(&dex);
        break;
      case 3:
        clear_screen();
        printf("Exiting the Pokédex...\n");
        break;
      default:
        break;
    }

  } while (mainOpt != 0);
}

/**
 * @Description Displays the Manage Menu of the Pokedex
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
manageMenu(Pokedex *dex)
{
  int manOpt = 0;
  do {
    system("clear || cls");
    printf("Accessing Data Files...\n\n");
    printf("[1] Add Entry\t\t\t[5] Search Pokemon by Name\n");
    printf("[2] Modify Entry\t\t[6] Search Pokemon by Type\n");
    printf("[3] Delete Entry\t\t[7] Export\n");
    printf("[4] Display All Entries\t\t[8] Import\n\n");

    printf("Press [0] to return to Main Menu\n\n");
    printf("Input: ");
    manOpt = intHandler(0, 8);

    switch (manOpt) {
      case 1:
        addEntry(dex);
        break;
      case 2:
        modifyEntry(dex);
        break;
      case 3:
        deleteEntry(dex);
        break;
      case 4:
        displayEntries(*dex, "RETURN");
        break;
      case 5:
        searchByName(*dex);
        break;
      case 6:
        searchByType(*dex);
        break;
      case 7:
        exportEntries(dex);
        break;
      case 8:
        importEntries(dex);
        break;
      default:
        break;
    }
  } while (manOpt != 0);
}

/**
 * @Description Displays the Manage Menu of the Pokedex
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
researchMenu(Pokedex *dex)
{
  int resOpt;

  do {
    system("clear || cls");
    printf("Accessing Research Tasks...\n\n");
    printf("[1] Review Research Task per Pokemon\n");
    printf("[2] Review Research Task per Task Type\n");
    printf("[3] Update Research Task\n");
    printf("[4] Create Additional Task Types\n");
    printf("[5] Show Top 5 Pokemon\n\n");

    printf("Press [0] to return to Main Menu\n\n");
    printf("Input: ");
    resOpt = intHandler(0, 5);

    switch (resOpt) {
      case 1:
        reviewTasksByPokemon(*dex);
        break;
      case 2:
        reviewTasksByType(*dex);
        break;
      case 3:
        updateTasks(dex);
        break;
      case 4:
        addTaskTypes(dex);
        break;
      case 5:
        rankPokemon(*dex);
        break;
      default:
        break;
    }
  } while (resOpt != 0);
}
