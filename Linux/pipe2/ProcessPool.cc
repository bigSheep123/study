// 实现一个进程池
#include<iostream>
#include <unistd.h>
#include<vector>
class Channel
{
private:
    int _wfd;
    pid_t _subprocessid;
    std::string _name;
};

// 形参类型和命名规范
// const &：输出
// & ：输入输出型参数
// * 输出型参数
void CreateChannel(int num,std::vector<Channel>*channels)
{
    for(int i = 0;i < num; i++)
    {
        // 创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        if(n < 0)
            exit(1);
        // 创建子进程
        pid_t id = fork();
        if(id == 0)
        {

        }

        // 构建 channel 名称

        // 父进程
        close(pipefd[2]);
        channels->push_back(Channel());
    }
}


int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        std::cerr<<"argv nums must to be 2"<<std::endl;
    }

    std::vector<Channel> channels;

    // 创建信道和子进程
    CreateChannel(num,&channels);
    int n = atoi(argv[1]);
    for(int i = 0; i < n; i++)
    {
        // std::cout<<n<<std::endl;
        channels.push_back(Channel());
    }

    return 0;
}