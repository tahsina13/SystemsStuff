#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

struct Pokemon *new_pokemon(char *name, int dex, int level, char moves[4][80])
{
    struct Pokemon *pkm = (struct Pokemon *) malloc(sizeof(struct Pokemon)); 
    strcpy(pkm->name, name);  
    pkm->dex = dex; 
    pkm->level = level;  
    for(int i = 0; i < 4; ++i)
        strcpy(pkm->moves[i], moves[i]); 
    return pkm; 
}

void del_pokemon(struct Pokemon *pkm)
{
    free(pkm); 
}

void show_pokemon(struct Pokemon *pkm)
{
    printf("%s #%03d\n", pkm->name, pkm->dex); 
    printf("lv. %d\n", pkm->level); 
    for(int i = 0; i < 4; ++i)
        printf("%s\n", pkm->moves[i]); 
}
