#include <stdio.h>
#include <string.h>
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

// Changes all inputs to uppercase
char 
toUpper(char c) 
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    
    return c;
}

//Comments need to be polished
// Function that accepts a key from the user which is used to search for a Pokemon name in the array
void 
searchByName(Pokedex dex)
{
    int i, j, k;
    int ctr, found, inputlen, pokemonlen, pokeIndex;
    string input, currentMon;

    found = 0;

    // Ask user for input
    printf("\nPlease enter the name of the Pokemon you are looking for.\n");
    
    printf("Input Pokemon Name: ");
    scanf("%s", input);
    
    inputlen = strlen(input);
    pokeIndex = dex.pokeCount - 1;
    
    // for loop that iterates through the pokemon array
    for (i = 0; i < pokeIndex; i++)
    {
        // assign the pokemon name string to a variable to avoid multiple array access calls
        strcpy(currentMon, dex.collection[i].name);
        pokemonlen = strlen(currentMon);
        
        ctr = 0;
        k = 0;

        // loop through all the characters in currentMon
        for(j = 0; j < pokemonlen;j++)  
        {
            // only enters if the first character matches
            // because no need to check unless the first character matches 
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
                        // if it does not match even once, exit the loop
                        ctr = 0;
                        k = inputlen;
                    }
                }
            }

            // if the matches are equal to the number of letters in len, the pokemon is already found
            if(ctr >= inputlen)
                j = pokemonlen; // forces an exit

        }

        // prints the found pokemon
        if(ctr == inputlen)
        {
            printf("\nEntry Number %d\n", dex.collection[i].entry);
            printf("Name: %s\n", dex.collection[i].name);
            printf("Type: %s\n", dex.collection[i].type);
            printf("Description: %s\n", dex.collection[i].description);
            
            found++;
        }
    }
    
    // prompts for user input 
    if(found == 0)
        printf("\n---Pokemon not found in the list!---\n");
    
    else
        printf("\n---Found %d pokemon(s)---\n", found);

}

// function that allows the user to choose a specific type of Pokemon and display all Pokemon of that type
void 
searchByType(Pokedex dex)
{
    int i, found, pokeIndex;
    char input;
    string typeInput;

    found = 0;
    pokeIndex = dex.pokeCount - 1;

    // asks the user for input
    printf("\nAvailable Pokemon Types:\n");
    printf("[E]lectric\n");
    printf("[F]ire\n");
    printf("[G]rass\n");
    printf("[W]ater\n");
    printf("Enter the type of the Pokemon you are looking for: ");
    scanf(" %c", &input);

    // each char is assigned with a corresponding type which will be used as a key
    switch(toUpper(input))
    {
        case 'E': strcpy(typeInput, "Electric");
                  break;
        case 'F': strcpy(typeInput, "Fire");
                  break;
        case 'G': strcpy(typeInput, "Grass");
                  break;
        case 'W': strcpy(typeInput, "Water");
                  break;
    }
    
    
    // for loop that iterates through the pokemon array
    // if a pokemon's type matches the input, it will be displayed and found increments
    for(i = 0; i < pokeIndex; i++)
    {
        if(strcmp(typeInput, dex.collection[i].type) == 0)
        {
            printf("\nEntry Number %d\n", dex.collection[i].entry);
            printf("Name: %s\n", dex.collection[i].name);
            printf("Type: %s\n", dex.collection[i].type);
            printf("Description: %s\n", dex.collection[i].description);
            
            found++;
        }
    }
    
    //Prompts for the user about the input they entered 
    if(found == 0)
        printf("\n---No %s Pokemon found!---\n", typeInput);
    
    else
        printf("\n---Found %d %s Pokemon(s)---\n", found, typeInput);
}