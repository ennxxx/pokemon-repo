// Main program of the Pokedex

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/manageMenu.h"
#include "../include/uiElements.h"
#include "../include/pokedexTools.h"

int main()
{   
    Pokedex dex;
    dex = initCollection();   // Access the entries through this function
    
    mainMenu(dex);            // Opens up the main menu of the Pokedex

    return 0;
}

// Initialization

Pokemon initPokemon()
{
    Pokemon p;

    p.entry = 0;
    strcpy(p.name, "");
    strcpy(p.description, "");
    
    return p;
}

Pokedex initCollection()
{
    int i;
    Pokedex dex;

    for (i = 0; i < MAX_ENTRIES; i++)
    {
        dex.collection[i] = initPokemon(); // Access the information of each Pokemon
    }

    dex.pokeCount = 0;

    return dex;
}

// Menu Pages

void mainMenu(Pokedex dex)
{
    int mainOpt;
    
    do
    {
        system("clear || cls");
        printf("Welcome to your Pokédex!\n\n");
        printf("What would you like to do?\n\n");
        printf("[1] Manage Data\n");
        printf("[2] Research Tasks\n");
        printf("[3] Exit\n\n");
        printf("Input: ");
        scanf("%d", &mainOpt);

        switch(mainOpt)
        {
            case 1: manageMenu(dex); break;
            case 2: researchMenu(dex); break;
            case 3: system("clear || cls");
                    printf("Exiting the Pokédex...\n"); break;
            default: break;
        }

    } while (mainOpt!= 3);
}

void manageMenu(Pokedex dex)
{
    int manOpt;
    
    do
    {
        system("clear || cls");
        printf("Accessing Data Files...\n\n");
        printf("[1] Add Entry\t\t\t[5] Search Pokemon by Name\n");
        printf("[2] Modify Entry\t\t[6] Search Pokemon by Type\n");
        printf("[3] Delete Entry\t\t[7] Export\n");
        printf("[4] Display All Entries\t\t[8] Import\n\n");

        printf("Press [0] to return to Main Menu\n\n");

        printf("Input: ");
        scanf("%d", &manOpt);

        switch(manOpt)
        {
            case 0: mainMenu(dex); break;
            case 1: addEntry(dex); break;
            case 2: modifyEntry(dex); break;
            case 3: 
            case 4: displayEntries(dex); break;
            case 5: 
            case 6: 
            case 7: 
            case 8: 
            default: break;
        }

    } while (manOpt != 0); 
}

void researchMenu(Pokedex dex)
{
    int resOpt;

    do
    {
        system("clear || cls");
        printf("Accessing Research Tasks...\n\n");
        printf("[1] Review Research Task per Pokemon\n");
        printf("[2] Review Research Task per Task Type\n");
        printf("[3] Update Research Task\n\n");

        printf("Press [0] to return to Main Menu\n\n");

        printf("Input: ");
        scanf("%d", &resOpt);

        switch(resOpt)
        {
            case 0: mainMenu(dex); break;
            case 1: 
            case 2: 
            case 3: 
            default: break;
        }        

    } while (resOpt != 0);
}
