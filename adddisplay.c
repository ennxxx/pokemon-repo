#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150

struct pokemon {
    int entry;
    char name[20];
    char type[10];
    char description[50];
} pokemon[MAX];

void addEntry()
{
    int i = 0;
    char ch;

    do
    {
        printf("Please enter the details of your Pokemon.\n");
        
        pokemon[i].entry = i + 1; // Takes note of the entry number
        printf("\nEntry Number %d\n", pokemon[i].entry);
        printf("Input Pokemon Name: ");
        scanf("%s", pokemon[i].name);
        printf("Input Pokemon Type: ");
        scanf("%s", pokemon[i].type);     
        fflush(stdin);  
        printf("Input Pokemon Description: ");
        fgets(pokemon[i].description, 50, stdin);
        i++;
        
        printf("\nPress [A] to add another entry, [B] to return to the main menu: ");
        scanf(" %c", &ch);

    } while (ch != 'B');
}

void displayEntries()
{
    int i;

    for (i = 0; i < 5; i++) // 5 entries per page
    {
        printf("\nDetails for Entry Number %d\n", i + 1);
        printf("Name: %s\n", pokemon[i].name);
        printf("Type: %s\n", pokemon[i].type);
        printf("Description: %s\n", pokemon[i].description);
    }
}

int main()
{
    int ch;
    int index;

    do
    {
        printf("\nManage Data\n");
        printf("[1] Add Entry\n");
        printf("[2] Display All Entries\n");
        printf("[0] Exit\n");

        printf("\nInput: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: addEntry(); break;
            case 2: displayEntries(); break;
            default: break;
        }

    } while (ch != 0);

    return 0;
}