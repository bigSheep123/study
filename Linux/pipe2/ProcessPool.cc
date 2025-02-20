// 形参类型和命名规范
// const &: 输出
// & : 输入输出型参数
// * : 输出型参数
//  task_t task: 回调函数

// 创建一个进程池 
#include"Task.hpp"

class Channel
{

};

// 先描述再组织 先描述我约束一个进程池的一些条件，再通过vector进行组织起来
void CreateChannels(std::vector<Channel>* channels,int n)
{
    for(int i = 0; i < n; i++)
    {
        int pipefd[2] = {0};
        pipe(pipefd);
        // 创建子进程
        pid_t id = fork();
        if(id < 0)
        {
            // 子进程需要干的事情
            // 子进程是需要去读，父进程需要去写，来完成整个过程

        }

        close(pipefd[0]);
    }
}

int main(int argc,char* argv[])
{
    if(argc!= 2)
        std::cerr<<"the argc must to be 2!!!"<<std::endl;
    
    int num = atoi(argv[1]);
    // std::cout<<num<<std::endl;
    std::vector<Channel> channels;
    
    CreateChannels(&channels,num);
}