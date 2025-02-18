#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

#define TaskNum 3

typedef void (*task_t)(); // task_t 函数指针类型

void Print()
{
    std::cout << "I am print task" << std::endl;
}
void DownLoad()
{
    std::cout << "I am a download task" << std::endl;
}
void Flush()
{
    std::cout << "I am a flush task" << std::endl;
}

task_t tasks[TaskNum];

void LoadTask()
{
    srand(time(nullptr) ^ getpid() ^ 17777);
    tasks[0] = Print;
    tasks[1] = DownLoad;
    tasks[2] = Flush;
}

void ExcuteTask(int number)
{
    if (number < 0 || number > 2)
        return;
    tasks[number]();
}

int SelectTask()
{
    return rand() % TaskNum;
}

void work()
{
    while (true)
    {
        int command = 0;
        int n = read(0, &command, sizeof(command));
        if (n == sizeof(int))
        {
            std::cout << "pid is : " << getpid() << " handler task" << std::endl;
            ExcuteTask(command);
        }
        else if (n == 0)
        {
            std::cout << "sub process : " << getpid() << " quit" << std::endl;
            break;
        }
    }
}

void work1()
{
    while (true)
    {
        int command = 0;
        int n = read(0, &command, sizeof(command));
        if (n == sizeof(int))
        {
            std::cout << "pid is : " << getpid() << " handler task" << std::endl;
            ExcuteTask(command);
        }
        else if (n == 0)
        {
            std::cout << "sub process : " << getpid() << " quit" << std::endl;
            break;
        }
    }
}

void work2()
{
    while (true)
    {
        int command = 0;
        int n = read(0, &command, sizeof(command));
        if (n == sizeof(int))
        {
            std::cout << "pid is : " << getpid() << " handler task" << std::endl;
            ExcuteTask(command);
        }
        else if (n == 0)
        {
            std::cout << "sub process : " << getpid() << " quit" << std::endl;
            break;
        }
    }
}