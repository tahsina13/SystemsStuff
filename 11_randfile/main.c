#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int in; 
int out; 

int rand(); 

int main()
{
    in = open("/dev/random", O_RDONLY); 
    if(in == -1)
    {
        printf("errno: %d\terror: %s\n", errno, strerror(errno)); 
        return 0; 
    }
    out = open("rand.out", O_CREAT | O_RDWR, 0664); 
    if(out == -1)
    {
        printf("errno: %d\terror: %s\n", errno, strerror(errno)); 
        return 0; 
    }

    printf("Generating random numbers:\n"); 
    int arr[10]; 
    for(int i = 0;  i < 10; ++i)
    {
        arr[i] = rand(); 
        printf("\trandom %d: %d\n", i, arr[i]); 
    }
    printf("\n"); 

    int b; 
    printf("Writing numbers to the file...\n"); 
    b = write(out, arr, sizeof(arr)); 
    printf("write %d bytes\n\n", b); 

    printf("Reading numbers from file...\n"); 
    int arr2[10]; 
    b = pread(out, arr2, sizeof(arr2), 0); 
    printf("read %d bytes\n\n", b); 

    printf("Verification that numbers are same:\n"); 
    for(int i = 0; i < 10; ++i)
        printf("\trandom %d: %d\n", i, arr2[i]); 

    close(in); 
    close(out); 
    return 0; 
}

int rand()
{
    int n; 
    read(in, &n, sizeof(n)); 
    return n; 
}
