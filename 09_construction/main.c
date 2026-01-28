#include <stdlib.h>
#include <time.h>

#include "pokemon.h"

int main()
{
    srand(time(0)); 
    int level = rand() % 100 + 1; 
    char moves[4][80] = {
        "Tackle", 
        "Tail Whip", 
        "Water Gun", 
        "Bite", 
    }; 
    struct Pokemon *squirtle = new_pokemon("Squirtle", 7, level, moves); 
    show_pokemon(squirtle); 
    del_pokemon(squirtle); 
    return 0; 
}
