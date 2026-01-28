#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **parse_args(char *); 

int main()
{   
    char cmd[] = "ls -a -l"; 
    char **args = parse_args(cmd); 
    execvp(args[0], args); 
    return 0; 
}

char **parse_args(char *cmd)
{
    char **argsv = (char **) malloc(5 * sizeof(char *)); 
    char *next = cmd; 
    int i = 0; 
    while(next)
    {
        argsv[i] = strsep(&next, " "); 
        ++i; 
    }
    return argsv; 
}
