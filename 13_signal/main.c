#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

char messg[100]; 

void sighandler(int signo)
{
    if(signo == SIGINT)
    {
        int f = open("messg.txt", O_RDWR | O_APPEND | O_CREAT, 0644); 
        write(f, messg, strlen(messg)); 
        close(f); 
        exit(0); 
    }
    else if(signo == SIGUSR1)
        printf("parent: %d\n", getppid()); 
}

int main(int argc, char *argv[])
{
    snprintf(messg, sizeof(messg)-1, "%s %d exited on SIGINT\n", argv[0], getpid());  
    signal(SIGINT, sighandler); 
    signal(SIGUSR1, sighandler); 
    while(1)
    {
        printf("process: %d\n", getpid()); 
        sleep(1); 
    }
}
