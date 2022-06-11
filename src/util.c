// Pokedex utility functions

#include "../include/pokedexTools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
clear_screen() {
#ifdef WINDOWS
  { system("cls"); }
#else
  { system("clear"); }
#endif
}

/**
 * @Description  Prints a message to the screen
 *
 * @Param taskList The task list to print
 * @Param taskName The name of the task
 *
 * @Returns 1 if the task is a duplate, 0 otherwise
 */
int
checkTaskDup(resTasks taskList, string taskName) {
  int i, retval, cont;

  // assume provided string is not a duplicate
  i = 0, retval = 0;
  cont = 1;

  for (i = 0; i < taskList.taskCount && cont; i++) {
    if (strcmp(taskList.list[i].type, taskName) == 0) {
      retval = 1;
      cont = 0;
    }
  }

  return retval;
}

/**
 * @Description  Checks if a pokemon's name already exists inside dex
 *
 * @Param dex
 * @Param name[MAX_NAME_LEN]
 *
 * @Returns   1 if the pokemon is a duplicate, 0 otherwise
 */
int 
checkDup(Pokedex dex, char name[MAX_NAME_LEN]) {
    int i, j;
    int counter = 0;

    if (dex.pokeCount < 1) {
        return 1; // Does not check first entry
    }
    
    for (i = 0; i < dex.pokeCount; i++) {
        if (strlen(name) != strlen(dex.collection[i].name)) {
            return 1; // Automatically returns 1 if they are not the same length
        }
        for (j = 0; j < strlen(name); j++) {
            if (toUpper(name[j]) == toUpper(dex.collection[i].name[j])) {
                counter++; // If the same character is encountered, counter++
            }
        }
        if (counter == strlen(name)) { 
            return 0; // If it all matches, return 0 and stop loop 
        }
    }

    return 1; // Returns 1 if not a duplicate
}

/**
 * @Description  Checks if a pokemon's entry number already exists inside dex
 *
 * @Param dex
 * @Param entry
 *
 * @Returns returns the index of the pokemon if it exists, -1 otherwise
 */
int
entryExists(Pokedex dex, int entry) {

  int i, exists = 0; // For all entities in the Pokedex
  int entryIndex;

  for (i = 0; i < 150; i++) {
    if (entry == dex.collection[i].entry) {
      exists = 1;
      entryIndex = i;
      i = 150;
    }
  }

  if (exists)
    return entryIndex;

  return -1;
}

void
displayType(Pokemon p) {
  switch (toUpper(p.type)) {
    case 'E':
      printf("Type: Electric\n");
      break;
    case 'F':
      printf("Type: Fire\n");
      break;
    case 'G':
      printf("Type: Grass\n");
      break;
    case 'W':
      printf("Type: Water\n");
      break;
    default:
      break;
  }
}

void
displayPokemon(Pokemon p) {
  printf("Entry: %d\n", p.entry);
  printf("Name: %s\n", p.name);
  displayType(p);
  printf("Description: %s\n", p.description);

  printf("\n");
}

void
displayAllTasks(Pokedex dex) {
  int i;

  for (i = 0; i < dex.collection[0].tasks.taskCount; i++) {
    printf("[%d] %s\n", i + 1, dex.collection[0].tasks.list[i].type);
  }
}

void
displayTaskStatus(Pokemon mon) {
  int i, tasklen, width;

  for (i = 0; i < mon.tasks.taskCount; i++) {
    tasklen = strlen(mon.tasks.list[i].type);
    width = 33 - tasklen;
    printf("%s:", mon.tasks.list[i].type);
    printf("%*s", width, " ");
    printf("%d/%d \n", mon.tasks.list[i].status, mon.tasks.list[i].complete);
  }
}

char
toUpper(char c) {
  if (c >= 'a' && c <= 'z')
    c = c - 32;

  return c;
}

int
intHandler(int min, int max) {
  int input;
  int valid = 0;

  while (!valid) {
    scanf("%d", &input);
    if (input >= min && input <= max)
      valid = 1;
    else
      printf("Invalid input. Please try again: ");
  }

  return input;
}

char
charHandler(const char *chars) {
  char input;
  int valid = 0, i, types;

  while (!valid) {
    scanf(" %c", &input);

    input = toUpper(input);
    types = strlen(chars);

    for (i = 0; i < types; i++) {
      if (input == chars[i])
        valid = 1;
    }

    if (valid == 0)
      printf("Invalid input. Please try again: ");
  }

  return input;
}
