#include<stdio.h>

int main(int argc,char* argv[],char *env[])
{
    // int i = 0;
    // for(;env[i];i++)
    // {
    //     printf("%s\n",env[i]);
    // }

    for(int i = 0; i < argc;i++)
    {
        printf("%s\n",argv[i]);
    }
    return 0;
}