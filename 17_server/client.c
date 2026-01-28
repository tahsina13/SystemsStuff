#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    char pid[100]; 
    char buffer[100]; 
    int s, c; 
    int b; 
    
    s = open("sonic", O_WRONLY); 
    sprintf(pid, "%d", getpid()); 
    mkfifo(pid, 0644); 
    write(s, pid, strlen(pid)); 
    c = open(pid, O_RDONLY); 
    printf("[client] sent client pipe: %s\n", pid);

    b = read(c, buffer, sizeof(buffer)-1); 
    buffer[b] = 0; 
    write(s, buffer, sizeof(buffer)-1); 
    if(strcmp(buffer, "gotcha"))
    {
        printf("[client] error in sending, exiting...\n"); 
        exit(0); 
    }
    remove(pid); 
    // client can send and receive

   
    while(1)
    {
        printf("input: "); 
        scanf("%s", buffer); 
        write(s, buffer, strlen(buffer)); 

        b = read(c, buffer, sizeof(buffer)-1); 
        buffer[b] = 0; 
        printf("output: [%s]\n", buffer); 
    }
}
