// This adds and checks for duplicate entries in the Pokedex

#include "pokedex.c"

int checkDup(Pokedex entry, Pokemon p)
{
    int i, j;

    for (i = 0; i < entry.lastEntry - 1; i++)
    {
        for (j = i + 1; j < entry.lastEntry; j++)
        {
            if (strcmp(&p.name[i], &p.name[j]) == 0)   
            {
                return 0;   // Returns 0 if the entry has already been entered previously
            }
        }
    }

    return 1;
} 

void addEntry(Pokedex dex)
{   
    int back, redo;
    int i = 0;
    
    Pokemon pokemon;

    do
    {
        system("clear");
        printf("---Adding Entries---\n\n");

        pokemon.entry = dex.lastEntry + 1;
        
        printf("Inputting Entry %d...\n\n", pokemon.entry);

        do
        {
            printf("Name: ");
            scanf("%s", pokemon.name); 

            redo = checkDup(dex, pokemon);  // Must return 1 for the function to continue

            if (redo == 0)
            {
                printf("\nThis entry already exists! Please enter another Pokemon name.\n\n");
            }

        } while (redo != 1);
        
        printf("\nPlease choose from the following:\n");
        printf("[E]lectric\n");
        printf("[F]ire\n");
        printf("[G]rass\n");
        printf("[W]ater\n\n");
        printf("Type: ");
        scanf(" %c", pokemon.type);

        fflush(stdin); 
        printf("\nDescription: ");
        fgets(pokemon.description, 50, stdin);
                
        printf("\n...done inputting!\n\n");

        dex.collection[i] = pokemon;      // Adds Pokemon to database
        dex.lastEntry = pokemon.entry;    // Ensures that new entries will be added based on previous index
        
        i++;

        printf("Press [1] to ADD another entry or [0] to RETURN to the manage menu: ");
        scanf("%d", &back);

        switch(back)
        {
            case 0: manageMenu(dex); break;
            default: break;
        }
        
    } while (back != 0);
}