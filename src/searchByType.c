// This searches for Pokemon based on type and name
// Needs to be reworked to fit the new main file
#include "../include/manageMenu.h"
#include "../include/pokedexTools.h"

//WIP
// function that allows the user to choose a specific type of Pokemon and display all Pokemon of that type
void 
searchByType(Pokemon pokemon[])
{
    int i, found;
    char input;
    string typeInput;

    found = 0;

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
    for(i = 0; i < 5; i++)
    {
        if(strcmp(typeInput, pokemon[i].type) == 0)
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
        printf("\n---No %s Pokemon found!---\n", typeInput);
    
    else
        printf("\n---Found %d %s pokemon(s)---\n", found, typeInput);
}