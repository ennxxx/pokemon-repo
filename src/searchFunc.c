#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"
#include "../include/uiElements.h"
#include <stdio.h>
#include <string.h>

/**
 * @Description Searches for a Pokemon by inputting their name, or a part of it
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
searchByName(Pokedex dex)
{
  int back;
  int i, j, k;
  int ctr, found, inputlen, pokemonlen;
  string input, currentMon;

  do {
    clear_screen();

    found = 0;
    printf("Searching Pokemon by Name...\n\n");
    printf("Who are you looking for? ");
    scanf("%s", input);
    printf("\n");

    inputlen = strlen(input);

    // For loop that iterates through the Pokemon array
    for (i = 0; i < dex.pokeCount; i++) {
      // Assign the Pokemon name string to a variable to avoid multiple array
      // access calls
      strcpy(currentMon, dex.collection[i].name);
      pokemonlen = strlen(currentMon);

      ctr = 0;
      k = 0;

      // Loop through all the characters in currentMon
      for (j = 0; j < pokemonlen; j++) {
        // Only enters if the first character matches
        // There is no need to check unless the first character matches
        if (toUpper(input[0]) == toUpper(currentMon[j])) {
          ctr = 1; // First match

          for (k = 1; k < inputlen;) {
            if (toUpper(input[k] == currentMon[j + k])) {
              ctr++;
              k++;
            }
            else {
              // If it does not match even once, exit the loop
              ctr = 0;
              k = inputlen;
            }
          }
        }

        // If the matches are equal to the number of letters in len, the pokemon
        // is already found
        if (ctr >= inputlen)
          j = pokemonlen; // Forces an exit
      }

      // Prints the found pokemon
      if (ctr == inputlen) {
        displayPokemon(dex.collection[i]);
        found++;
      }
    }

    // Displays number of Pokemon found
    if (found == 0)
      printf("---Pokemon not found in the list!---\n");

    else
      printf("---Found %d Pokemon(s)---\n", found);

    // Returns to Manage Menu
    printf("\nPress [1] to SEARCH again or [0] to RETURN: ");
    back = intHandler(0, 1);

  } while (back != 0);
}

/**
 * @Description Searches for a Pokemon by inputting their Pokemon type
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
searchByType(Pokedex dex)
{
  int back;
  int i, found;
  char input;
  string typeInput;

  do {
    clear_screen();

    found = 0;

    printf("Searching Pokemon by Type...\n\n");

    // Asks the user for input
    printf("Please choose from the following:\n");
    printf("[E]lectric\n");
    printf("[F]ire\n");
    printf("[G]rass\n");
    printf("[W]ater\n\n");
    printf("What Pokemon type are you looking for? ");
    input = charHandler(POKE_TYPES);
    printf("\n");

    // Each character is assigned with a corresponding type to be displayed
    switch (toUpper(input)) {
      case 'E':
        strcpy(typeInput, "Electric");
        break;
      case 'F':
        strcpy(typeInput, "Fire");
        break;
      case 'G':
        strcpy(typeInput, "Grass");
        break;
      case 'W':
        strcpy(typeInput, "Water");
        break;
    }

    // For loop that iterates through the Pokemon array
    // If a Pokemon's type matches the input, it will be displayed and found
    // increments
    for (i = 0; i < dex.pokeCount; i++) {
      if (toUpper(input) == toUpper(dex.collection[i].type)) {
        displayPokemon(dex.collection[i]);
        found++;
      }
    }

    // Displays number of Pokemon found based on type
    if (found == 0)
      printf("---No %s Pokemon found!---\n", typeInput);

    else
      printf("---Found %d %s Pokemon(s)---\n", found, typeInput);

    // Returns to Manage Menu
    printf("\nPress [1] to SEARCH again or [0] to RETURN: ");
    back = intHandler(0, 1);

  } while (back != 0);
}