struct Pokemon {
    char name[80]; 
    int dex; 
    int level; 
    char moves[4][80]; 

    struct Pokemon *next; 
}; 

struct Pokemon *new_pokemon(char *, int, int, char [4][80]);  
void del_pokemon(struct Pokemon *); 
void show_pokemon(struct Pokemon *); 

void print_list(struct Pokemon *); 
struct Pokemon *insert_front(struct Pokemon *, 
                        char *, int, int, char [4][80]); 
struct Pokemon *free_list(struct Pokemon *); 
struct Pokemon *remove_node(struct Pokemon *, char *);   
