#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"
#include "../include/uiElements.h"
#include <stdio.h>
#include <string.h>

/**
 * @Description Exports entries from the Pokedex to a text file
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
exportEntries(Pokedex *dex)
{
  char fileName[26];
  char extension[5] = ".txt";
  int i;
  Pokemon pokemon;

  if (dex->pokeCount == 0) {
    printf("No entries to export");
    getchar();
    getchar();
    return;
  }

  printf("\nExporting entries...\n\n");

  printf("Input a file name: ");
  scanf("%s", fileName);

  strcat(fileName, extension);
  FILE *fp = fopen(fileName, "w");

  for (i = 0; i < dex->pokeCount; i++) {
    pokemon = dex->collection[i];

    trimString(pokemon.name);
    fprintf(fp, "Name: %s\n", pokemon.name);

    switch (toUpper(pokemon.type)) {
      case 'E':
        fprintf(fp, "Type: Electric\n");
        break;
      case 'F':
        fprintf(fp, "Type: Fire\n");
        break;
      case 'G':
        fprintf(fp, "Type: Grass\n");
        break;
      case 'W':
        fprintf(fp, "Type: Water\n");
        break;
      default:
        break;
    }

    // Removed newline filter to make EOF operation universal
    trimString(pokemon.description);
    fprintf(fp, "Description: %s\n", pokemon.description);
    if (i != dex->pokeCount - 1)
      fprintf(fp, "\n");
  }

  fclose(fp);
}

/**
 * @Description checks if a file exists in directory
 *
 * @param fileName the file to be checked
 *
 * @returns 1 if file exists, 0 if file does not exist
 */

int
fileExists(const char *fileName)
{
  FILE *fp;
  fp = fopen(fileName, "r");
  if (fp == NULL)
    return 0;
  else {
    fclose(fp);
    return 1;
  }
}

/**
 * @Description Import entries from a text file to the Pokedex
 *
 * @param dex Holds a collection of Pokemon entries and notes
 *            the number of Pokemon entered in the Pokedex
 */
void
importEntries(Pokedex *dex)
{
  char fileName[26];
  char extension[5] = ".txt";
  int entryIndex, ch, exists = 0;

  printf("\nImporting entries...\n\n");
  do {

    printf("Input a file name: ");
    scanf("%s", fileName);
    strcat(fileName, extension);
    exists = fileExists(fileName);

    if (!exists)
      printf("File does not exist. Try again\n");

  } while (!exists);

  FILE *fp = fopen(fileName, "r");
  char tmp[100];

  Pokemon import;

  do {
    clear_screen();

    // Pokemon is imported to index based on the last pokeCount
    entryIndex = dex->pokeCount;
    import = dex->collection[entryIndex];

    printf("Loading entry...\n\n");

    // Reading the name from the file
    fgets(tmp, MAX_NAME_LEN, fp);
    filterString(tmp, NAME);
    trimString(tmp);
    strcpy(import.name, tmp);

    // Reading the type from the file
    fgets(tmp, sizeof(char) * 20, fp);
    filterString(tmp, TYPE);
    trimString(tmp);
    import.type = tmp[0];

    // Reading the description from the file
    fgets(tmp, MAX_DESC_LEN, fp);
    filterString(tmp, DESCRIPTION);
    trimString(tmp);
    strcpy(import.description, tmp);

    // Displays the read entries
    // Notes down entry number based on last pokeCount + 1
    import.entry = dex->pokeCount + 1;
    printf("Name: %s\n", import.name);
    displayType(import);
    printf("Description: %s\n", import.description);

    printf("\nPress [1] to IMPORT or [0] to SKIP entry: ");
    ch = intHandler(0, 1);

    if (ch == 1 && !checkDup(*dex, import.name)) {
      dex->collection[entryIndex] = import;
      dex->pokeCount++;
      printf("Entry successfully imported!\n\n");
    }

  } while (fgetc(fp) != EOF);

  fclose(fp);
}
