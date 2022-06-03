#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int entry;
    char name[20];
    char type[10];
    char description[50];
} Pokemon; 

typedef struct{
    Pokemon collection[150];
    int lastEntry;
} Pokedex;

// Initialization
Pokemon initPokemon();          // This initalizes the Pokemon information
Pokedex initCollection();       // This is a separate struct that contains all 150 Pokemon  

// Menu Pages
void mainMenu();
void manageMenu(Pokedex entry);
void researchMenu();

// Functions
void addEntry(Pokedex entry);

int main()
{   
    mainMenu();            // Opens up the main menu of the Pokedex

    return 0;
}

// Initialization

Pokemon initPokemon()
{
    Pokemon p;

    p.entry = 0;
    strcpy(p.name, "");
    strcpy(p.type, "");
    strcpy(p.description, "");
    
    return p;
}

Pokedex initCollection()
{
    int i;
    Pokedex entry;

    for (i = 0; i < 150; i++)
    {
        entry.collection[i] = initPokemon(); // Access the information of each Pokemon
    }

    entry.lastEntry = 0;

    return entry;
}

// Menu Pages

void mainMenu()
{
    int mainOpt;

    Pokedex entry;
    entry = initCollection();   // Access the entries through this function
    
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
            case 1: manageMenu(entry); break;
            case 2: researchMenu(); break;
            case 3: system("clear || cls");
                    printf("Exiting the Pokédex...\n"); break;
            default: break;
        }

    } while (mainOpt!= 3);
}

void manageMenu(Pokedex entry)
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
            case 0: mainMenu(); break;
            case 1: addEntry(entry); break;
            case 2: 
            case 3: 
            case 4: 
            case 5: 
            case 6: 
            case 7: 
            case 8: 
            default: break;
        }

    } while (manOpt != 0); 
}

void researchMenu()
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
            case 0: mainMenu(); break;
            case 1: 
            case 2: 
            case 3: 
            default: break;
        }        

    } while (resOpt != 0);
}

// Functions

void addEntry(Pokedex entry)
{   
    int back; 
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

