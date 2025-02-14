#include<stdio.h>

#define SkipPath(p) do{ p+=(strlen(p) - 1); while(*p != '/') p--}while(0)


// #define N  5

// char arr[N];
// int main()
// {
//     arr[0] = ' ';
//     arr[1] = 'a';
//     arr[2] = '\0';
//     return 0;
// }