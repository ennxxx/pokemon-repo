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

resType initTaskTypes()
{
    resType task;

    task.type = '\0';
    task.status = 0;

    return task;
}

resTasks initTasks()
{
    int i;
    resTasks tasks;

    for (i = 0; i < 10; i++)
    {
        tasks.list[i] = initTaskTypes();
    }
    tasks.taskCount = 0;

    return tasks;
}

Pokemon initPokemon()
{
    Pokemon p;

    p.entry = 0;
    strcpy(p.name, "");
    p.type = '\0';
    strcpy(p.description, "");
    p.tasks = initTasks();

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
        printf("[0] Exit\n\n");
        printf("Input: ");
        mainOpt = intHandler(0, 2);

        switch(mainOpt)
        {
            case 1: manageMenu(dex); break;
            case 2: researchMenu(dex); break;
            case 3: clear_screen();
                    printf("Exiting the Pokédex...\n"); break;
            default: break;
        }

    } while (mainOpt != 0);
}

void manageMenu(Pokedex dex)
{
    int manOpt;
    do{
    system("clear || cls");
    printf("Accessing Data Files...\n\n");
    printf("[1] Add Entry\t\t\t[5] Search Pokemon by Name\n");
    printf("[2] Modify Entry\t\t[6] Search Pokemon by Type\n");
    printf("[3] Delete Entry\t\t[7] Export\n");
    printf("[4] Display All Entries\t\t[8] Import\n\n");

    printf("Press [0] to return to Main Menu\n\n");

    printf("Input: ");
    manOpt = intHandler(0, 8);

    switch(manOpt)
    {
        case 1: addEntry(&dex); break;
        case 2: modifyEntry(&dex); break;
        case 3: 
        case 4: displayEntries(dex); break;
        case 5: searchByName(dex); break;
        case 6: searchByType(dex); break;
        case 7: exportEntries(dex); break;
        case 8: 
        default: break;
    }
    } while (manOpt != 0);
}

void researchMenu(Pokedex dex)
{
    int resOpt;

    do{
    system("clear || cls");
    printf("Accessing Research Tasks...\n\n");
    printf("[1] Review Research Task per Pokemon\n");
    printf("[2] Review Research Task per Task Type\n");
    printf("[3] Update Research Task\n\n");

    printf("Press [0] to return to Main Menu\n\n");

    printf("Input: ");
    resOpt = intHandler(0, 3);

    switch(resOpt)
    {
        case 1: 
        case 2: 
        case 3: 
        default: break;
    }
    } while (resOpt != 0);        
}
