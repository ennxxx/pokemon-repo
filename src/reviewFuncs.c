#include "../include/researchTasks.h"
#include <stdio.h>

void reviewTasksByPokemon(Pokemon pokemon)
{
    int i;
    
    for (i = 0; i < tasks.taskCount; i++)
    {
        printf("%s\n", tasks.pokemon.name);
        printf("%s\n", tasks.collection[i].type);
    }
}
