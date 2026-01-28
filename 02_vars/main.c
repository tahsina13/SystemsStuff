#include <stdio.h>

int main()
{
    printf("no initialization\n"); 
    char x; 
    printf("x is %d\n", x); 
    printf("\n"); 
    
    printf("x is...\n"); 
    x = 47; 
    printf("in decimal: %d\n", x); 
    printf("in octal: %o\n", x); 
    printf("in hex: %x\n", x); 
    printf("\n"); 

    printf("when x goes out of bounds:\n"); 
    // wraps back to -128; 
    x = 128; 
    printf("x is %d\n", x); 
    printf("\n"); 

    printf("how many digits of pi can we store?\n"); 
    // answer: 7 digits
    float pi = 3.141592; 
    printf("7 digits of pi are %f\n", pi); 
    pi = 3.1415926; 
    printf("8 digits of pi are %f\n", pi); 
    printf("\n"); 

    printf("can C store the monster number?\n"); 
    // monster = 80801742479451287588645990496171075700575436800000000
    // answer: only 19 digits, 35 short
    unsigned long long monster = 8080174247945128758; 
    printf("the monster: %lld\n", monster); 
    printf("\n"); 

    return 0; 
}
