#include "../include/pokedexTools.h"

// Changes all inputs to uppercase
char 
toUpper(char c) 
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    
    return c;
}