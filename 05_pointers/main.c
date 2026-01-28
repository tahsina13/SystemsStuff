#include <stdio.h>

int main()
{
    int i; 

    char c; 
    int n; 
    long l; 

    char *cp; 
    int *np; 
    long *lp; 

    unsigned int u; 
    int *u_ip; 
    char *u_cp; 

    // addresses
    printf("&c (hex): %p\n", &c); 
    printf("&c (dec): %lu\n", &c); 
    printf("&n (hex): %p\n", &n); 
    printf("&n (dec): %lu\n", &n); 
    printf("&l (hex): %p\n", &l); 
    printf("&l (dec): %lu\n", &l); 
    printf("\n"); 

    // pointers 
    cp = &c; 
    np = &n; 
    lp = &l; 

    printf("cp: %p\n", cp); 
    printf("np: %p\n", np); 
    printf("lp: %p\n", lp); 
    printf("\n"); 

    // changing values with pointers
    *cp = 't'; 
    *np = 7; 
    *lp = 2020; 

    printf("c: %c\n", c); 
    printf("n: %d\n", n); 
    printf("l: %ld\n", l); 
    printf("\n"); 

    // pointers of different types
    u = 602214076; 
    u_ip = (int *) &u; 
    u_cp = (char *) &u; 
    printf("u_ip: %p points to *u_ip: %d\n", u_ip, *u_ip); 
    printf("u_cp: %p points to *u_cp: %d\n", u_cp, *u_cp); 
    printf("u (hex): %x\n", u); 
    printf("u (dec): %u\n", u); 
    printf("\n"); 

    // bytes shenanigans
    printf("bytes of u\n"); 
    for(i = 0; i < sizeof(u); ++i)
        printf("%hhu ", u_cp[i]); 
    printf("\n"); 
    for(i = 0; i < sizeof(u); ++i)
        printf("%hhx ", u_cp[i]); 
    printf("\n\n"); 

    for(i = 0; i < sizeof(u); ++i)
        ++u_cp[i]; 
    /* if the hex is split into pairs (one byte)
     * each pair will be incremented by 1
     */
    printf("u (+1 bytes) (hex): %x\n", u); 
    /* adds the sum of 2^x where x is a multiples of 8
     * 2^0 + 2^8 + 2^16 + 2^24
     */
    printf("u (+1 bytes) (dec): %u\n", u); 

    for(i = 0; i < sizeof(u); ++i)
        u_cp[i] += 16; 
    /* same but first digit of pair incremented */
    printf("u (+16 bytes) (hex): %x\n", u); 
    /* same but multiples of 8 - 1 */ 
    printf("u (+16 bytes) (dec): %u\n", u); 

    return 0; 
}
