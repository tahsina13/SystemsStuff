#include "mystring.h"

int mystrlen(char *s)
{
    int i = 0; 
    while(*s)
    {
        ++s; 
        ++i; 
    }
    return i; 
}

char *mystrcpy(char *s1, char *s2)
{
    char *foo = s1; 
    while(*s2)
    {
        *s1 = *s2; 
        ++s1; 
        ++s2; 
    }
    return foo; 
}

char *mystrncpy(char *s1, char *s2, int size)
{
    char *foo = s1; 
    for(int i = 0; i < size && *s2; ++i)
    {
        *s1 = *s2; 
        ++s1; 
        ++s2; 
    }
    return foo; 
}

char *mystrcat(char *s1, char *s2)
{
    char *foo = s1; 
    s1 += mystrlen(s1); 
    while(*s2)
    {
        *s1 = *s2; 
        ++s1; 
        ++s2; 
    }
    return foo; 
}

char *mystrncat(char *s1, char *s2, int size)
{
    char *foo = s1; 
    s1 += mystrlen(s1); 
    for(int i = 0; i < size && *s2; ++i)
    {
        *s1 = *s2; 
        ++s1; 
        ++s2; 
    }
    return foo; 
}

char *mystrchr(char *s, int c)
{
    while(*s && *s != c) ++s; 
    return *s || !c ? s : 0; 
}

int mystrcmp(char *s1, char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1 > *s2)       return 1; 
        else if(*s1 < *s2)  return -1; 
        ++s1; 
        ++s2; 
    }
    if(!*s1 && !*s2)    return 0; 
    else if(!*s2)       return 1; 
    else                return -1; 
}
