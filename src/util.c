#include "../include/pokedexTools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @Description A function thats clears the console depending on the system
 *
 */
void
clear_screen()
{
#ifdef WINDOWS
  {
    system("cls");
  }
#else
  {
    system("clear");
  }
#endif
}

/**
 * @Description : Capitalizes all characters in a string
 *
 * @param str The string to capitalize
 * @return The capitalized string
 */
char *
capitalize(char *str)
{
  int i;
  for (i = 0; str[i]; i++)
    str[i] = toUpper(str[i]);

  return str;
}

/**
 * @Description Checks if inputted task type exists by returning a value
 *
 * @param taskList The task list to print
 * @param taskName The name of the task
 * @return 1 if the task is a duplate, 0 otherwise
 */
int
checkTaskDup(resTasks taskList, string taskName)
{
  int i, retval, cont;

  // Assume provided string is not a duplicate
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
 * @Description Checks if a Pokemon's name already exists inside dex
 *
 * @param dex   Holds a collection of Pokemon entries and notes
 *              the number of Pokemon entered in the Pokedex
 * @param name  Array under Pokemon struct to hold name of Pokemon
 * @return 1 if the Pokemon is a duplicate, 0 otherwise
 */
int
checkDup(Pokedex dex, char name[MAX_NAME_LEN])
{
  int i, isDup = 0;

  if (dex.pokeCount != 0) {
    string incoming, basename;
    strcpy(incoming, name);
    for (i = 0; i < dex.pokeCount && !isDup; i++) {
      strcpy(basename, dex.collection[i].name);
      if (strcmp(capitalize(incoming), capitalize(basename)) == 0)
        isDup = 1;
    }
  }

  return isDup; // Returns 0 if not a duplicate
}

/**
 * @Description Check if an entry exists inside the Pokedex
 *
 * @param dex   Holds a collection of Pokemon entries and notes
 *              the number of Pokemon entered in the Pokedex
 * @param entry Entry number of a Pokemon
 * @return entryIndex if it exists, -1 otherwise
 */
int
entryExists(Pokedex dex, int entry)
{
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

/**
 * @Description Displays Pokemon type depending on input character
 *
 * @param p Holds Pokemon details, such as entry number,
 *          name, type, description.
 */
void
displayType(Pokemon p)
{
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

/**
 * @Description Displays Pokemon's entry number, name, type, and description
 *
 * @param p Holds Pokemon details, such as entry number,
 *          name, type, description.
 */
void
displayPokemon(Pokemon p)
{
  printf("Entry: %d\n", p.entry);
  printf("Name: %s\n", p.name);
  displayType(p);
  printf("Description: %s\n", p.description);
  printf("\n");
}

/**
 * @Description Displays all existing Pokemon tasks
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
displayAllTasks(Pokedex dex)
{
  int i;

  for (i = 0; i < dex.collection[0].tasks.taskCount; i++) {
    printf("[%d] %s\n", i + 1, dex.collection[0].tasks.list[i].type);
  }
}

/**
 * @Description Displays all existing task status
 *
 * @param mon Holds details of a Pokemon regarding their task types and progress
 */
void
displayTaskStatus(Pokemon mon)
{
  int i, tasklen, width;

  for (i = 0; i < mon.tasks.taskCount; i++) {
    tasklen = strlen(mon.tasks.list[i].type);
    width = 33 - tasklen;
    printf("%s:", mon.tasks.list[i].type);
    printf("%*s", width, " ");
    printf("%d/%d \n", mon.tasks.list[i].status, mon.tasks.list[i].complete);
  }
}

/**
 * @Description   Remove a certain number of characters from a string
 *
 * @param str     A string of words
 * @param filter  An enum of three integers defined as NAME,
 *                DESCRIPTION, and TYPE
 */
void
filterString(char *str, FT filter)
{
  switch (filter) {
    case NAME:
      strcpy(str, str + 6);
      break;
    case DESCRIPTION:
      strcpy(str, str + 13);
      break;
    case TYPE:
      strcpy(str, str + 6);
      break;
    default:
      break;
  }
}

/**
 * @Description Removes all newlines from a string
 *
 * @param str A string of words
 */
void
trimString(char *str)
{
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] == '\n') {
      str[i] = '\0';
      break;
    }
    i++;
  }
}

/**
 * @Description Changes lowercase characters to uppercase
 *
 * @param c A character input or character from a string
 * @return  Uppercase c
 */
char
toUpper(char c)
{
  if (c >= 'a' && c <= 'z')
    c = c - 32;

  return c;
}

/**
 * @Description Checks for validity of an integer input
 *
 * @param min Minimum value to be inputted
 * @param max Maximum value to be inputted
 * @return    Integer input if valid, otherwise inform user to try again
 */
int
intHandler(int min, int max)
{
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

/**
 * @Description Checks for validity of a character input
 *
 * @param chars A string of characters
 * @return Character input if valid, otherwise inform user to try again
 */
char
charHandler(const char *chars)
{
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
