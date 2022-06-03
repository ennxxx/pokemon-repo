// Display function still in progress 

#include "pokedex.c"

void displayEntries(Pokedex dex)
{   
    int i, back;

    Pokemon pokemon;

    do
    {
        system("clear || cls");

        for (i = 0; i < 3; i++)     // Garbage values are displayed rip
        {
            pokemon = dex.collection[i];
            printf("Details for Entry Number %d\n", pokemon.entry);
            printf("Name: %s\n", pokemon.name);
            printf("Type: %s\n", pokemon.type);
            printf("Description: %s\n", pokemon.description);
        }
        
        printf("Press [1] for the next page, [0] to RETURN to the manage menu: ");
        scanf("%d", &back);

        switch(back)    // Previous and next pages have not been implemented
        {
            case 0: manageMenu(dex);
            case 1: break;
            default: printf("Invalid option! Please try again.\n\n"); break;
        }

    } while (back != 0);
}