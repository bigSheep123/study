#include<iostream>
#include<unistd.h>
#include<vector>

#define NUM 3
typedef void (*task_t)();

task_t Task[NUM];
void Print()
{
    std::cout<<"I am Print Task"<<std::endl;
}

void Flush()
{
    std::cout<<"I am Flush Task"<<std::endl;
}

void Download()
{
    std::cout<<"I am Download Task"<<std::endl;
}

void LoadTask()
{
    srand(time(nullptr) ^ getpid() ^ 17777);
    Task[0] = Print;
    Task[1] = Flush;
    Task[2] = Download;
}

