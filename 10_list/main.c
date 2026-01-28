#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "pokemon.h"
#include "moveset.h"

char my_team[3][80] = {
    "Articuno", 
    "Zapdos", 
    "Moltres", 
}; 

int main()
{
    srand(time(0)); 
    struct Pokemon *team = NULL; 
     
    team = insert_front(team, 
        my_team[0], 144, rand()%100+1, articuno); 
    team = insert_front(team, 
        my_team[1], 145, rand()%100+1, zapdos); 
    team = insert_front(team, 
        my_team[2], 146, rand()%100+1, moltres); 
    printf("\n"); 

    printf("Current Team:\n"); 
    print_list(team); 

    team = remove_node(team, my_team[rand()%3]); 
    team = remove_node(team, "Mewtwo"); 
    printf("\n"); 
    printf("New Team:\n"); 
    print_list(team); 

    free_list(team);

    return 0; 
}
