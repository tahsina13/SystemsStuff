#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int i; 
    srand(time(0)); 

    int foo[10]; 
    printf("foo:\n"); 
    for(i = 0; i < 9; ++i)
    {
        foo[i] = rand() % 100; 
        printf("%d ", foo[i]); 
    }
    foo[9] = 0; 
    printf("%d\n", foo[9]); 
    printf("\n"); 

    int rfoo[10]; 
    int *p, *r; 
    p = foo + 9, r = rfoo; 
    printf("rfoo:\n");  
    for(i = 0; i < 10; ++i)
    {
        *(r + i) = *(p - i); 
        printf("%d ", *(r + i)); 
    }
    printf("\n\n"); 

    // let's try to randomize the values of foo 
    // i have way too much free time 
    
    int bar[10]; 
    for(i = 0; i < 10; ++i)
        bar[i] = foo[i]; 
    printf("bar:\n"); 
    for(i = 0; i < 10; ++i)
    {
        int n = rand() % (10 - i) + i; 
        int tmp = bar[i]; 
        bar[i] = bar[n]; 
        bar[n] = tmp; 
        printf("%d ", bar[i]); 
    }
    printf("\n"); 

    return 0; 
}
