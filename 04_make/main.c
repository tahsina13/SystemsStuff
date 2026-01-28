#include <stdio.h>

#include "euler.h"

int main()
{
    printf("%s\t%s\n", "problem", "answer"); 
    printf("--------------------\n"); 
    printf("%d\t%d\n", 1, problem1(1000)); 
    printf("%d\t%d\n", 5, problem5(20)); 
    printf("%d\t%d\n", 6, problem6(100)); 

    return 0; 
}
