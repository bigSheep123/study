#include <csignal>
#include <iostream>

int main()
{
    // 若 父进程未处理 SIGCHLD，子进程可能成为僵尸进程
    signal(SIGCHLD,SIG_IGN);
    pid_t id = fork();
    if( id == 0)
    {
        int cnt = 5;
        while(cnt) 
        {
            std::cout << "child runing" << std::endl;
            cnt--;
            sleep(1);
        }
        exit(1);
    }

    while(true) 
    {
        std::cout << "father running" << std::endl;
        sleep(1);
    }

    return  0;
}