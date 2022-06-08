#include "../include/researchTasks.h"
#include "../include/pokedexTools.h"
#include "../include/manageMenu.h"
#include <stdio.h>
#include <string.h>

void updateProgress(Pokemon* mon)
{
    int i, total, average;

    total = 0;

    for(i = 0; i < mon->tasks.taskCount; i++)
    {
        total += mon->tasks.list[i].status;
    }

    average = (float)total / (mon->tasks.taskCount * DEFAULT_COMPLETE) * 100;

    mon->tasks.progress = average;
}

void updateTasks(Pokedex* dex)
{
    int task, pokemon, back, complete;
    Pokemon* mon;
    
    back = -1; 
    
    do
    {
        clear_screen();
        printf("---Updating Research Tasks---\n\n");

        //Display task entries
        displayAllTasks(*dex);
        printf("\nWhich task would you like to update? ");
        task = intHandler(1, dex->collection[0].tasks.taskCount);

        //Display all pokemon entries
        displayTaskEntries(*dex);
        printf("\nWhich Pokemon would you like to update? ");
        pokemon = intHandler(1, dex->pokeCount);

        mon = &dex->collection[pokemon - 1];

        //How many times did the user complete the task
        printf("\nHow many times did you complete this task? ");
        complete = intHandler(1, DEFAULT_COMPLETE);

        //Update the task
        mon->tasks.list[task - 1].status += complete;
        updateProgress(mon);

        //Display the updated pokemon
        clear_screen();
        printf("---Update Finished!---\n");
        displayPokemon(*mon);
        printf("-----Research Tasks Progress: %d%%-----\n", mon->tasks.progress);
        displayTaskStatus(*mon);


        printf("\nPress [1] to UPDATE another task or [0] to RETURN: ");
        back = intHandler(0, 1);

    } while (back != 0);
}