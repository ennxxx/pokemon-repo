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