#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

const char *messg = "gotcha"; 

void rev(char *); 

int main()
{
    char buffer[100]; 
    int s, c;
    int b; 

    while(1)
    {
        mkfifo("sonic", 0644); 
        printf("[sever] waiting for client...\n"); 
        s = open("sonic", O_RDONLY);  

        b = read(s, buffer, sizeof(buffer)-1); 
        buffer[b] = 0; 
        c = open(buffer, O_WRONLY); 
        printf("[sever] received client pipe: %s\n", buffer); 
        remove("sonic"); 
        // server can receive now

        write(c, messg, strlen(messg)); 
        printf("[sever] sent message: %s\n", messg); 
        b = read(s, buffer, sizeof(buffer)-1); 
        buffer[b] = 0; 
        printf("[sever] received message: %s\n", buffer);  
        if(strcmp(buffer, "gotcha"))
        {
            printf("[sever] error in sending\n"); 
            continue; 
        }
        // sever can send now

        while((b = read(s, buffer, sizeof(buffer)-1)))
        {
            buffer[b] = 0; 
            rev(buffer); 
            write(c, buffer, sizeof(buffer)-1); 
        }

        printf("\n"); 
    }
}

void rev(char *str)
{
    int len = strlen(str); 
    char t; 
    for(int i = 0; i < len/2; ++i)
    {
        t = str[i]; 
        str[i] = str[len-1-i]; 
        str[len-1-i] = t; 
    }
}
