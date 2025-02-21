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

int ChoseTask()
{
    return rand() % NUM;
}


void work()
{
    // int n;
    // read(0,&n,sizeof(n));
    // if(n >=0 && n <=2)
    // {
    //     std::cout<<getpid()<<std::endl;
    //     Task[n]();
    // }

    while(true)
    {
        int command = 0;
        int n = read(0,&command,sizeof(command));
        if( n == sizeof(int))
        {
            std::cout << "pid is :" << getpid() << "handler task" <<std::endl;
        }
        else if(n == 0)  // 读取的时候，当写端关闭的时候，默认会读到 0 
        {
            std::cout<<"sub process :" << getpid() << " quit" <<std::endl;
            break;
        }
    }
}

