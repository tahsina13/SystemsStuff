#include "euler.h"

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
