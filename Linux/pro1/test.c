// #include <cinttypes>
#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
    printf("hello world");

    return 0;
}

// int main()
// {
//     int ret = fork();
//     if(ret == -1)
//     {
//         perror("fork failed");
//         exit(-1);
//     }
//     else if(ret == 0){
//         // 子
//         sleep(2);
//         printf("I am son : %d    %d\n",getpid(),getppid());
//         return 0;
//     }

//     // 父亲
//     sleep(3);
//     printf("I am father: %d   %d\n",getpid(), getppid());
//     return 0;

// }

//  fork()
// int main()
// {
//     int ret = fork();
//     printf("hello proc: %d, ret: %d \n",getpid(),ret);
//     sleep(5);

//     return 0;
// }


// getpid()  getppid()
// int main()
// {
//     printf("pid:%d\n",getpid());
//     printf("ppid:%d\n",getppid());
//     return 0;
// }



//
// 查看 进程 
// ps aux | grep test | grep -v grep
// int main()
// {
//     while(1)
//     {
//         sleep(1);
//     }
//     return 0;
// }