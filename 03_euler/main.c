#include <stdio.h>

int problem1(int); 
int problem5(int); 
int problem6(int); 

int main()
{
    printf("%s\t%s\n", "problem", "answer"); 
    printf("--------------------\n"); 
    printf("%d\t%d\n", 1, problem1(1000)); 
    printf("%d\t%d\n", 5, problem5(20)); 
    printf("%d\t%d\n", 6, problem6(100)); 

    return 0; 
}

int problem1(int n)
{
    int s = 0; 
    int i; 
    for(i = 1; i < n; ++i)
        s += i * (i % 3 == 0 || i % 5 == 0); 
    return s; 
}

int problem5(int n)
{
    // start with 1
    int ans = 1; 
    int i; 
    for(i = 1; i <= n; ++i)
    {
        int r = ans % i; 
        if(r != 0)
        {
            // next multiple of i is i - r away
            ans += (i - r); 
            // recheck with all preceding values
            i = 0;  
        }
    }
    return ans; 
}

int problem6(int n)
{
    int i; 
    int sum_sq = 0; 
    int sq_sum = 0; 
    for(i = 1; i <= n; ++i)
    {
        sum_sq += i*i; 
        sq_sum += i; 
    }
    sq_sum *= sq_sum; 
    return sq_sum - sum_sq; 
}
