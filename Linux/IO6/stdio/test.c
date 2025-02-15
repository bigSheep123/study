#include "mystdio.h"

#define FILE_NAME "log.txt"

int main()
{
    myFILE *fp = my_fopen(FILE_NAME, "w");
    if (fp == NULL)
        perror("fp failed");

    const char *str = "hello bit";
    int cnt = 5;
    printf("%lu",strlen(str));
    char buffer[128];
    while (cnt)
    {
        sprintf(buffer, "%s - %d\n", str, cnt);
        my_fwrite(fp, buffer, strlen(buffer)); // strlen()+1不需要
        cnt--;
        sleep(1);
        my_fflush(fp);
    }

    my_fclose(fp);

    return 0;
}