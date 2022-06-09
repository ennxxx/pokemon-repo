#include "../include/researchTasks.h"
#include "../include/pokedexTools.h"
#include "../include/manageMenu.h"
#include <stdio.h>
#include <string.h>

void reviewTasksByPokemon(Pokedex dex)
{
    int input, back;
    Pokemon mon;
    
    do
    {
        clear_screen();
        printf("---Reviewing Tasks Per Pokemon---\n\n");
        displayTaskEntries(dex);
        printf("\nWhich Pokemon would you like to review tasks for? ");
        input = intHandler(1, dex.pokeCount);

        mon = dex.collection[input - 1];

        if (input)
        {
            clear_screen();
            displayPokemon(mon);
            printf("-----Research Tasks Progress: %d%%-----\n", mon.tasks.progress);
            displayTaskStatus(mon);
        }

        printf("\nPress [1] to REVIEW other Pokemon or [0] to RETURN: ");
        back = intHandler(0, 1);

    } while (back != 0);
}

void reviewTasksByType(Pokedex dex)
{
    int task, back;
    int namelen, width;
    int i = 0, j;

    Pokemon mon;
    
    do
    {
        clear_screen();
        printf("---Reviewing Task per Task Type---\n\n");

        displayAllTasks(dex);
        printf("\nWhich task would you like to review? ");
        task = intHandler(1, dex.collection[0].tasks.taskCount);
        j = task - 1;
        
        if (task)
        {
            clear_screen();
            printf("---Research Tasks Progress: %s---\n", dex.collection[0].tasks.list[j].type);

            for (i = 0; i < dex.pokeCount; i++)
            {
                mon = dex.collection[i]; // Access entries
                namelen = strlen(mon.name);
                
                switch (task) // For the display to align
                {
                    case 1: width = 27 - namelen; break; // Seen
                    case 2: width = 29 - namelen; break; // Caught
                    case 3: width = 31 - namelen; break; // Defeated
                }

                if (mon.tasks.list[j].status != 0)
                {
                    printf("%s  %s", "⟢", mon.name);
                    printf("%*s", width, " ");
                    printf("%d/%d \n", mon.tasks.list[j].status, mon.tasks.list[j].complete);
                }
            }
        }

        printf("\n< END OF LIST >\n\n"); 

        printf("Press [1] to REVIEW other tasks or [0] to RETURN: ");
        back = intHandler(0, 1);

    } while (back != 0);
    
}