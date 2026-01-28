#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    srand(time(NULL)); 
    printf("Going to fork\n"); 
    int f = fork(); 
    if(f) f = fork(); 
    if(f)
    {
        // parent
        int status; 
        int p = wait(&status); 
        printf("Child Finished!\tPID: %d\tTime: %d\n", p, WEXITSTATUS(status)); 
        return 0; 
    }
    else 
    {
        // child
        printf("Child: %d\n", getpid()); 
        int s = rand() % 8 + 2; 
        sleep(s); 
        return s; 
    }
}
