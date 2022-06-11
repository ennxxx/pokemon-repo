// This exports and imports entries to and from the Pokedex

#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"
#include "../include/uiElements.h"
#include <stdio.h>
#include <string.h>

typedef enum FILTERTYPE { NAME, DESCRIPTION, TYPE } FT;

void
filterString(char *str, FT filter) {

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

void
trimString(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == '\n') {
      str[i] = '\0';
      break;
    }
    i++;
  }
}

void
exportEntries(Pokedex *dex) {

  if (dex->pokeCount == 0) {
    printf("No entries to export");
    getchar();
    getchar();
    return;
  }

  char fileName[26];
  char extension[5] = ".txt";

  printf("\nExporting entries...\n\n");
  printf("Input a file name: ");
  scanf("%s", fileName);

  strcat(fileName, extension);

  FILE *fp = fopen(fileName, "w");

  int i;
  Pokemon pokemon;

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
    // removed newline filter to make EOF operation universal
    trimString(pokemon.description);
    fprintf(fp, "Description: %s\n", pokemon.description);
    if (i != dex->pokeCount - 1)
      fprintf(fp, "\n");
  }

  fclose(fp);
  
}

void
importEntries(Pokedex *dex) {
  char fileName[26];
  char extension[5] = ".txt";
  int entryIndex, ch;

  printf("\nImporting entries...\n\n");
  printf("Input a file name: ");
  scanf("%s", fileName);

  strcat(fileName, extension);

  FILE *fp = fopen(fileName, "r");
  char tmp[100];

  Pokemon import;

  do {
    clear_screen();

    entryIndex = dex->pokeCount; // Index is based on the last pokeCount
    import = dex->collection[entryIndex]; // Importing Pokemon detials
                                          // to a specific index

    // Reads the content of the file
    printf("Loading entry...\n\n");

    fgets(tmp, MAX_NAME_LEN, fp);
    filterString(tmp, NAME);
    trimString(tmp);

      strcpy(import.name, tmp);

      fgets(tmp, sizeof(char) * 20, fp);
      filterString(tmp, TYPE);
      trimString(tmp);
      import.type = tmp[0];

      fgets(tmp, MAX_DESC_LEN, fp);
      filterString(tmp, DESCRIPTION);
      trimString(tmp);
      strcpy(import.description, tmp);

      // Displays the read entries
      import.entry = dex->pokeCount +
                     1; // Notes down entry number based on last pokeCount + 1
      printf("Name: %s\n", import.name);
      displayType(import);
      printf("Description: %s\n", import.description);

      printf("\nPress [1] to IMPORT or [0] to SKIP entry: ");
      ch = intHandler(0, 1);

      if (ch == 1 && checkDup(*dex, import.name)) {
        dex->collection[entryIndex] = import;
        dex->pokeCount++;
      }

  } while (fgetc(fp) != EOF);

  fclose(fp);
}