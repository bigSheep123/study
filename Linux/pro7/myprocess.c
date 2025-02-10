// #include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include "task.h"
// 轮询状态的代码
typedef void(*func_t) ();

#define N  3
func_t tasks[N] = {NULL};

void LoadTask()
{
    tasks[0] = PrintLog;
    tasks[1] = Download;
    tasks[2] = MysqlDataSync;
}

void HandlerTask()
{
    for(int i = 0; i < N; i++)
    {
        tasks[i]();
    }
}

void ChildRun()
{
    //int *p = NULL;
    int cnt = 5;
    while(cnt)
    {
        printf("I am child process, pid: %d, ppid:%d, cnt: %d\n", getpid(), getppid(), cnt);
        sleep(1);
        cnt--;
        //*p = 100;
    }
}

void DoOtherThing()
{
    HandlerTask();
}

int main()
{
    printf("I am father,pid:%d,ppid:%d\n",getppid(),getppid());
    pid_t id = fork();
    if(id == 0)
    {
        // child
        ChildRun();
        printf("child quit ...\n");
        exit(123);
    }

    LoadTask();

    while(1)
    {
        int status = 0;
        pid_t rid = waitpid(id,&status,WNOHANG); // 非阻塞状态

        if(rid == 0)
        {
            usleep(1000000);
            printf("child is running ,father check next time!\n");
            DoOtherThing();
        }
        else if(rid > 0)
        {
            if(WIFEXITED(status))
            {
                printf("child quit success, child exit code : %d\n", WEXITSTATUS(status));
            }
            else
            {
                printf("child quit unnormal!\n");
            }
            break;
        }
        else
        {
            printf("failed\n");
            break;
        }
    }


    return 0;
}