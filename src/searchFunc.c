// Searches for Pokemon based on name or type

#include <stdio.h>
#include <string.h>
#include "../include/uiElements.h"
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

void searchByName(Pokedex dex)
{
    int back;
    int i, j, k;
    int ctr, found, inputlen, pokemonlen, pokeIndex;
    string input, currentMon;

    do
    {
        clear_screen();
        
        found = 0;

        printf("Searching Pokemon...\n\n");
        printf("Who are you looking for? ");
        scanf("%s", input);
        
        inputlen = strlen(input);
        pokeIndex = dex.pokeCount;  // Removed -1 here so it looks at all entries
        
        // For loop that iterates through the Pokemon array
        for (i = 0; i < pokeIndex; i++)
        {
            // Assign the Pokemon name string to a variable to avoid multiple array access calls
            strcpy(currentMon, dex.collection[i].name);
            pokemonlen = strlen(currentMon);
            
            ctr = 0;
            k = 0;

            // Loop through all the characters in currentMon
            for (j = 0; j < pokemonlen; j++)  
            {
                // Only enters if the first character matches
                // There is no need to check unless the first character matches 
                if (toUpper(input[0]) == toUpper(currentMon[j]))
                {
                    ctr = 1; // First match

                    for (k = 1; k < inputlen;){
                        
                        if (toUpper(input[k] == currentMon[j + k]))
                        {
                            ctr++;
                            k++;
                        }
                        
                        else
                        {
                            // If it does not match even once, exit the loop
                            ctr = 0;
                            k = inputlen;
                        }
                    }
                }

                // If the matches are equal to the number of letters in len, the pokemon is already found
                if (ctr >= inputlen)
                    j = pokemonlen; // Forces an exit
            }

            // Prints the found pokemon
            if (ctr == inputlen)
            {
                printf("\nEntry Number %d\n", dex.collection[i].entry);
                printf("Name: %s\n", dex.collection[i].name);
                switch(dex.collection[i].type)
                {
                    case 'E': printf("Type: Electric\n"); break;
                    case 'F': printf("Type: Fire\n"); break;
                    case 'G': printf("Type: Grass\n"); break;
                    case 'W': printf("Type: Water\n"); break;
                    default: break;
                }                
                printf("Description: %s", dex.collection[i].description);
                
                found++;
            }
        }
        
        // Prompts for user input 
        if (found == 0)
            printf("\n---Pokemon not found in the list!---\n");
        
        else
            printf("\n---Found %d pokemon(s)---\n", found);

        // Returns to Manage Menu
        printf("\nPress [1] to search again, [0] to RETURN to the manage menu: ");
        scanf("%d", &back);

        switch(back)    // Previous and next pages have not been implemented
        {
            case 0: manageMenu(dex);
            case 1: break;
            default: printf("Invalid input."); break;
        }
    
    } while (back != 0);
}