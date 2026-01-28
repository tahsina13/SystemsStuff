struct Pokemon {
    char name[80]; 
    int dex; 
    int level; 
    char moves[4][80]; 
}; 

struct Pokemon *new_pokemon(char *, int, int, char [4][80]);  
void del_pokemon(struct Pokemon *); 
void show_pokemon(struct Pokemon *); 
