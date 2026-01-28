#include <stdio.h>
#include <string.h>

float avg(int *, int); 
void cpy(char *, char *, int); 
int len(char *); 

int main()
{
    int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    printf("average of first ten numbers: %f\n", avg(nums, 10)); 
    printf("\n"); 

    char my_str[] = "just a string"; 
    printf("my_str: %s\n", my_str); 
    int my_len = len(my_str); 
    printf("my_len: %d\n", my_len); 
    char my_cpy[my_len]; 
    cpy(my_str, my_cpy, my_len); 
    printf("my_cpy: %s\n", my_cpy); 
    printf("\n"); 

    char one[] = "one"; 
    char two[] = "two"; 
    char tmp[10]; 
    strcpy(tmp, one); 
    printf("strcpy(tmp, one): %s\n", tmp); 
    strcat(tmp, two); 
    printf("strcat(tmp, two): %s\n", tmp);  
    printf("strcmp(one, two): %d\n", strcmp(one, two)); 
    *strchr(tmp, 'o') = 't'; 
    printf("*strchr(tmp, 'o') = 't': %s\n", tmp); 

    return 0; 
}

float avg(int *nums, int size)
{
    int i, sum = 0; 
    for(i = 0; i < size; ++i)
        sum += nums[i]; 
    return sum / size; 
}

void cpy(char *source, char *dest,  int n)
{
    int i; 
    for(i = 0; i < n+1; ++i)
        dest[i] = source[i]; 
}

int len(char *str)
{   
    int len = 0; 
    while(*str)
    {
        len++; 
        str++; 
    }
    printf("\n"); 
    return len; 
}
