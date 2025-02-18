

//形参类型和命名规范
// const &：输出
//  &：输入输出型参数
//  *： 输出型参数
//  task_t task：回调函数

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Task.hpp"

// void work(int rfd)
// {
//     while (true)
//     {
//         int command = 0;
//         int n = read(rfd, &command, sizeof(command));
//         if (n == sizeof(int))
//         {
//             std::cout << "pid is : " << getpid() << " handler task" << std::endl;
//             ExcuteTask(command);
//         }
//         else if (n == 0)
//         {
//             std::cout << "sub process : " << getpid() << " quit" << std::endl;
//             break;
//         }
//     }
// }

// master
class Channel
{
public:
    Channel(int wfd, pid_t id, const std::string &name)
        : _wfd(wfd), _subprocessid(id), _name(name)
    {
    }
    int GetWfd() { return _wfd; }
    pid_t GetProcessId() { return _subprocessid; }
    std::string GetName() { return _name; }
    void CloseChannel()
    {
        close(_wfd);
    }
    void Wait()
    {
        pid_t rid = waitpid(_subprocessid, nullptr, 0);
        if (rid > 0)
        {
            std::cout << "wait " << rid << " success" << std::endl;
        }
    }
    ~Channel()
    {
    }

private:
    int _wfd;
    pid_t _subprocessid;
    std::string _name;
};

// 形参类型和命名规范
// const &: 输出
// & : 输入输出型参数
// * : 输出型参数
//  task_t task: 回调函数
void CreateChannelAndSub(int num, std::vector<Channel> *channels, task_t task)
{
    // BUG? --> fix bug
    for (int i = 0; i < num; i++)
    {
        // 1. 创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        if (n < 0)
            exit(1);

        // 2. 创建子进程
        pid_t id = fork();
        if (id == 0)
        {
            if (!channels->empty())
            {
                // 第二次之后，开始创建的管道
                for(auto &channel : *channels) channel.CloseChannel();
            }
            // child - read
            close(pipefd[1]);
            dup2(pipefd[0], 0); // 将管道的读端，重定向到标准输入
            task();
            close(pipefd[0]);
            exit(0);
        }

        // 3.构建一个channel名称
        std::string channel_name = "Channel-" + std::to_string(i);
        // 父进程
        close(pipefd[0]);
        // a. 子进程的pid b. 父进程关心的管道的w端
        channels->push_back(Channel(pipefd[1], id, channel_name));
    }
}

// 0 1 2 3 4 channelnum
int NextChannel(int channelnum)
{
    static int next = 0;
    int channel = next;
    next++;
    next %= channelnum;
    return channel;
}

void SendTaskCommand(Channel &channel, int taskcommand)
{
    write(channel.GetWfd(), &taskcommand, sizeof(taskcommand));
}
void ctrlProcessOnce(std::vector<Channel> &channels)
{
    sleep(1);
    // a. 选择一个任务
    int taskcommand = SelectTask();
    // b. 选择一个信道和进程
    int channel_index = NextChannel(channels.size());
    // c. 发送任务
    SendTaskCommand(channels[channel_index], taskcommand);
    std::cout << std::endl;
    std::cout << "taskcommand: " << taskcommand << " channel: "
              << channels[channel_index].GetName() << " sub process: " << channels[channel_index].GetProcessId() << std::endl;
}
void ctrlProcess(std::vector<Channel> &channels, int times = -1)
{
    if (times > 0)
    {
        while (times--)
        {
            ctrlProcessOnce(channels);
        }
    }
    else
    {
        while (true)
        {
            ctrlProcessOnce(channels);
        }
    }
}

void CleanUpChannel(std::vector<Channel> &channels)
{
    // int num = channels.size() -1;
    // while(num >= 0)
    // {
    //     channels[num].CloseChannel();
    //     channels[num--].Wait();
    // }

    for (auto &channel : channels)
    {
        channel.CloseChannel();
        channel.Wait();
    }
    // // 注意
    // for (auto &channel : channels)
    // {
    //     channel.Wait();
    // }
}

// ./processpool 5
int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     std::cerr << "Usage: " << argv[0] << " processnum" << std::endl;
    //     return 1;
    // }
    // int num = std::stoi(argv[1]);
    int num = 5;
    LoadTask();

    std::vector<Channel> channels;
    // 1. 创建信道和子进程
    CreateChannelAndSub(num, &channels, work1);

    // 2. 通过channel控制子进程
    ctrlProcess(channels, 5);

    // 3. 回收管道和子进程. a. 关闭所有的写端 b. 回收子进程
    CleanUpChannel(channels);

    // sleep(100);
    return 0;
}
