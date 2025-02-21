// 形参类型和命名规范
// const &: 输出
// & : 输入输出型参数
// * : 输出型参数
//  task_t task: 回调函数

// 创建一个进程池 
#include "Task.hpp"
#include <sched.h>
#include <sys/wait.h>

#define N 5

class Channel
{
public:
    Channel(std::string name,int wfd,pid_t pid)
    :_name(name) , _wfd(wfd), _pid(pid)
    {}

    std::string GetName() { return _name; }
    int GetWfd() { return _wfd; }
    pid_t GetPid() { return _pid; }

    void Close()
    {
        close(_wfd);
    }
    void Wait()
    {
        pid_t rid = waitpid(_pid, nullptr, 0);
        if (rid > 0)
        {
            std::cout << "wait " << rid << " success" << std::endl;
        }
    }
    void Print()
    {
        std::cout<<GetName()<<" "<<GetWfd()<<" "<<GetPid()<<std::endl;
    }
private:
    std::string _name;
    int _wfd;
    pid_t _pid;
};

// 先描述再组织 先描述我约束一个进程池的一些条件，再通过vector进行组织起来
void CreateChannels(std::vector<Channel>* channels,int n,task_t task)
{
    for(int i = 0; i < n; i++)
    {
        int pipefd[2] = {0};
        pipe(pipefd);
        // 创建子进程
        pid_t id = fork();
        if(id == 0)
        {
            if (!channels->empty())
            {
                //第二次之后，开始创建的管道
                for (auto &channel : *channels)
                    channel.Close();
            }
            // sleep(1000);
            // 子进程需要干的事情
            // 子进程是需要去读，父进程需要去写，来完成整个过程
            close(pipefd[1]);
            // 孩子只需要去执行任务
            dup2(pipefd[0],0); // 将 新的文件描述符关闭0，将旧的文件描述符pipe[0]去代替新的文件描述符0
            task();
            
            close(pipefd[0]);
            exit(0);
        }

        close(pipefd[0]);
        // 给子进程起一个名字
        std::string name = "channel_" + std::to_string(i);

        channels->push_back(Channel(name,pipefd[1],id));
    }
}

int ChoseChannel(int size)
{
    static int num = 0;
    int tmp = num % size;
    num ++;
    return tmp;
}

void SendMeg(Channel& channel,int taskId)
{
    write(channel.GetWfd(),&taskId,sizeof(taskId));
}

void CtrlOnceChannel(std::vector<Channel>& channels)
{
    // 控制做的工作应该是，选择一个任务，选择一个信道，把任务的0，1，2 写进去
    sleep(1);
    int taskId = ChoseTask();
    int size = channels.size();
    int channel_index = ChoseChannel(size);
    SendMeg(channels[channel_index],taskId);
    std::cout << std::endl;
    std::cout << "taskcommand: " << taskId << " channel: "              \
              << channels[channel_index].GetName() << " sub process: "  \
              << channels[channel_index].GetPid() << std::endl;
}


void CtrlChannels(std::vector<Channel>& channels,int n = -1)
{
    // channels[1].GetName(); 
    // (*channels)[1].GetName();
    if(n > 0)
    {
        while(n--)
        {
            CtrlOnceChannel(channels);
        }
    }
    else if( n == -1)
    {
        while(1)
        {
            CtrlOnceChannel(channels);
        }
    }
}

void FreeChannels(std::vector<Channel>& channels)
{
    for(auto& e:channels)
    {
        e.Close();
        e.Wait();

    }
    // for(auto& e :channels)
    // {
    //     e.Wait();
    // }
}

int main(int argc,char* argv[])
{
    if(argc!= 2)
        std::cerr<<"the argc must to be 2!!!"<<std::endl;
    
    // int num = atoi(argv[1]);
    int num = 5;
    // std::cout<<num<<std::endl;
    LoadTask();
    std::vector<Channel> channels;
    // 创建了进程池
    CreateChannels(&channels,num,work);
    // for(auto& e :channels)
    // {
    //     e.Print();
    // }
    // std::cout<<std::endl;
    // channels[0].Print();
    //控制进程池去执行任务
    CtrlChannels(channels,N);

    FreeChannels(channels);
    // Task[1]();
    return 0;
}