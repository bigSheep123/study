#include <stdio.h>
#include <unistd.h>

int main()
{
    int cnt = 10;
    // \r 回车进行覆盖
    // 内存缓存区
    while(cnt>=0)
    {
        printf("倒计时: %2d\r", cnt);
        // fflush(stdout);
        cnt--;
        sleep(1);
    }
    printf("\n");

    //printf("hello bit,hello world...");
    //fflush(stdout);
    //sleep(3);

    return 0;
}
