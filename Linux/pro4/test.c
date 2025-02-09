#include<stdio.h>
#include <unistd.h>
#include<sys/types.h>


void RunChild()
{
    while(1)
    {
        sleep(1);
        printf("I am son,pid:%d,ppid:%d\n",getpid(),getppid());
    }
}


int main()
{
    const int num = 5;
    for(int i = 0; i < num; i++)
    {
        pid_t id = fork();
        if(id == 0)
        {
            RunChild();
        }

        sleep(1);
    }

    while(1)
    {
        sleep(1);
        printf("I am parent,pid:%d,ppid:%d\n",getpid(),getppid());
    }

    return 0;
}








// int main()
// {
//     printf("process is running, only me!\n");
//     fork();
//     printf("hello world\n");
//     sleep(1);

//     return 0;
// }