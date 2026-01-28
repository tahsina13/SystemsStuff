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
    printf("---------------\n"); 
    for(int i = 0; i < 4; ++i)
        printf("%s\n", pkm->moves[i]); 
}

void print_list(struct Pokemon *node)
{
    while(node)
    {
        show_pokemon(node); 
        printf("\n"); 
        node = node->next; 
    }
}

struct Pokemon *insert_front(struct Pokemon *node, 
                        char *name, int dex, int level, char moves[4][80])
{
    printf("Catching %s\n", name); 
    struct Pokemon *tmp = new_pokemon(name, dex, level, moves); 
    tmp->next = node; 
    return tmp;  
}

struct Pokemon *free_list(struct Pokemon *node)
{
    while(node)
    {
        printf("Releasing %s\n", node->name); 
        struct Pokemon *next = node->next; 
        del_pokemon(node);  
        node = next; 
    }
}

struct Pokemon *remove_node(struct Pokemon *node, char *name)  
{
    printf("Releasing %s\n", name); 

    char dumb_moves[4][80] = {{""}}; 
    struct Pokemon *dummy = new_pokemon("", 0, 0, dumb_moves); 
    dummy->next = node; 
    struct Pokemon *last = dummy; 
    
    while(node)
    {
        if(!strcmp(node->name, name))
        {
            last->next = node->next; 
            del_pokemon(node); 
            break; 
        }
        last = node; 
        node = node->next; 
    }
    
    struct Pokemon *head = dummy->next; 
    del_pokemon(dummy); 
    return head; 
}

