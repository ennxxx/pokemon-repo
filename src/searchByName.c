#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

//Comments need to be polished
// Function that accepts a key from the user which is used to search for a Pokemon name in the array
void 
searchByName(Pokemon pokemon[])
{
    int i, j, k, l;
    int ctr, found, inputlen, pokemonlen;
    string input, currentMon;

    found = 0;

    // Ask user for input
    printf("\nPlease enter the name of the Pokemon you are looking for.\n");
    
    printf("Input Pokemon Name: ");
    scanf("%s", input);
    
    inputlen = strlen(input);
    
    // For loop that iterates through the pokemon array
    for (i = 0; i < 5; i++)
    {
        // assign pokemon[i].name to a variable to avoid multiple array access calls
        strcpy(currentMon, pokemon[i].name);
        pokemonlen = strlen(currentMon);
        
        ctr = 0;
        k = 0;

        // Loop through all the characters in currentMon
        for(j = 0; j < pokemonlen;j++)  
        {
            // only enters if the first character matches
            // I realized that you don't have to check whether user input matches UNLESS the very first character matches
            if(toUpper(input[0]) == toUpper(currentMon[j]))
            {
                ctr = 1; // first match

                for(k = 1; k < inputlen;){
                    
                    if (toUpper(input[k] == currentMon[j + k]))
                    {
                        ctr++;
                        k++;
                    }
                    
                    else
                    {
                        // once it doesnt match, dont even consider the next characters
                        // if it doesnt match even once, we don't care anymore 
                        ctr = 0;
                        k = inputlen;
                    }
                }
            }

            // if we already have enough matches, it means we found the pokemon already
            // no need to keep checking the rest of the characters
            if(ctr >= inputlen)
                j = pokemonlen; // forces an exit

        }

        if(ctr == inputlen)
        {
            printf("\nEntry Number %d\n", pokemon[i].entry);
            printf("Name: %s\n", pokemon[i].name);
            printf("Type: %s\n", pokemon[i].type);
            printf("Description: %s\n", pokemon[i].description);
            
            found++;
        }
    }
    
    //Prompts for the user about the input they entered 
    if(found == 0)
        printf("\n---Pokemon not found in the list!---\n");
    
    else
        printf("\n---Found %d pokemon(s)---\n", found);

}
