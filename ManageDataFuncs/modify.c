#include "pokedex2.c"
// display all entries then then ask the user which one to modify

// function to check if the entry number exists in the pokedex

// this function returns the index of the pokemon's entry if the entry entered exists
// returns -1 otherwise
int entryExists(Pokedex dex, int entry){
    // for all entities in dex
    int i, exists = 0;

    int entryIndex;
    for(i = 0; i < 150; i++){
        if(entry == dex.collection[i].entry){
            exists = 1;
            entryIndex = i;
            i = 150;
        }
    }

    if(exists)
        return entryIndex;

    return -1;
}

void displayPokemon(Pokemon p){
    printf("\nEntry: %d\n", p.entry);
    printf("Name: %s\n", p.name);
    printf("Type: %s\n", p.type);
    printf("Description: %s\n", p.description);
}

void modifyEntry(Pokedex dex){
    displayEntries(dex);

    // ask the user which entry they would like to modify
    int exists, entry, entryIndex;

    // set default value to negative 1 to indicate errors
    exists = entryIndex = entry = -1;

    while(exists == -1){
        printf("\nWhich entry would you like to modify?\n");
        scanf("%d", &entry);
        exists = entryExists(dex, entry);
        if(exists == -1)
            printf("\nThat entry does not exist.\n");
    }

    // guard clause to avoid errors
    // will only set entryIndex to the index of the entry if the entry exists
    if(exists != -1)
        entryIndex = exists;

    // modify the entry located at entryIndex
    Pokemon changeMon = dex.collection[entryIndex];

    char changeOpt;
    changeOpt = ' ';
    do{
        system("clear || cls");
        displayPokemon(changeMon);
        printf("What would you like to change\n");
        printf("[0] Save and Exit\n");
        printf("[1] Name\n");
        printf("[2] Type\n");
        printf("[3] Description\n");
        printf("[4] Cancel\n");
        printf("Input: ");
        scanf("%c", &changeOpt);

        switch(changeOpt){
            case '0':
                printf("\nSaving changes...\n");
                // only assign the new pokemon to the dex if the user enters save
                dex.collection[entryIndex] = changeMon;
                break;
            case '1':
                printf("\nWhat would you like to change the name to?\n");
                scanf("%s", changeMon.name);
                break;
            case '2':
                printf("\nWhat would you like to change the type to?\n");
                scanf("%s", changeMon.type);
                break;
            case '3':
                printf("\nWhat would you like to change the description to?\n");
                scanf("%s", changeMon.description);
                break;
            case '4':
                printf("\nQuitting...\n");
                changeOpt = '0';
                break;
            default:
                printf("\nInvalid input.\n");
                break;
        }
    }while(changeOpt != '0');
}
