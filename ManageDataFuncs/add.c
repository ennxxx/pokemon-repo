// This adds and checks for duplicate entries in the Pokedex

#include "pokedex.c"

void addEntry(Pokedex entry)
{   
    int back, redo = 0;
    int i = 0;
    
    Pokemon pokemon;

    do
    {
        system("clear");
        printf("---Adding Entries---\n\n");

        pokemon.entry = entry.lastEntry + 1;
        
        printf("Inputting Entry %d...\n\n", pokemon.entry);

        printf("Name: ");
        scanf("%s", pokemon.name); 
        
        // Function to check for duplicates
        
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

        entry.collection[i] = pokemon;      // Adds Pokemon to database
        entry.lastEntry = pokemon.entry;    // Ensures that new entries will be added based on previous index
        
        i++;

        printf("Press [1] to ADD another entry or [0] to RETURN to the manage menu: ");
        scanf("%d", &back);

        switch(back)
        {
            case 0: manageMenu(entry); break;
            default: break;
        }
        
    } while (back != 0);
}
