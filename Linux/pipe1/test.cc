#include <cstdio>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string>

const int size = 1024;

std::string getOtherMeg()
{
    static int cnt = 0;
    std::string messageid = std::to_string(cnt); // stoi -> string -> int
    cnt++;
    pid_t self_id = getpid();
    std::string stringpid = std::to_string(self_id);

    std::string message = "messageid: ";
    message += messageid;
    message += " my pid is : ";
    message += stringpid;

    return message;
}

void SonWrite(int wfd)
{
    std::string meg = "father,I am your son process!";
    int n = 10;
    // char c = 'A';
    while(n--)
    {
        // sleep(0);
        // std::cerr<<"++++++++++++++++++++++++++++"<<std::endl;
        std::string info = meg + getOtherMeg();
        write(wfd,info.c_str(),info.size());
        // std::cout<<"child quit ..."<<std::endl;

        // std::cerr<<info <<std::endl;
        if (n == 0)
        {
            std::cout << "child quit ..." << std::endl;
            break;
        }
    }


}

void FatherRead(int rfd)
{
    char inbuffer[size];
    while(1)
    {
        sleep(5);
        std::cout << "-------------------------------------------" << std::endl;
        // sleep(500);
        ssize_t n = read(rfd, inbuffer, sizeof(inbuffer) - 1); // sizeof(inbuffer)->strlen(inbuffer);
        if (n > 0)
        {
            inbuffer[n] = 0; // == '\0'
            std::cout  << inbuffer << std::endl;
        }
        else if (n == 0)
        {
            // 如果read的返回值是0，表示写端直接关闭了，我们读到了文件的结尾
            std::cout << "client quit, father get return val: " << n << " father quit too!" << std::endl;
            break;
        }
        else if(n < 0)
        {
            std::cerr << "read error" << std::endl;
            break;
        }

        // std::cout<<"Son , live better, your father gone"<<std::endl;
        // break;
    }
}

int main()
{
    // 1.创建管道   2.创建子进程  3.关闭管道  4.进行通信（测试）
    // 1.创建管道
    int fd[2];
    int n = pipe(fd);
    if(n < 0)
        perror("pipe failed");
    std::cout<<"fd[0]:"<<fd[0]<<" "<<"fd[1]"<<fd[1]<<std::endl;
    sleep(2);

    // 2.创建子进程  子写   父读
    pid_t pid = 0;
    pid = fork();
    // std::cout<<"hello world"<<std::endl;
    // 4.通信的核心逻辑
    if(pid == 0)
    {
        //子进程    关闭读，开始写
        std::cout<<"子进程关闭不需要的fd,准备发消息了"<<std::endl;
        sleep(2);
        close(fd[0]);
        
        // std::string meg = "hello father,I am your son!";
        // // std::cout<<meg.size()<<std::endl;
        // write(fd[1],meg.c_str(),meg.size());
        SonWrite(fd[1]);
        close(fd[1]);
        exit(0);
    }
    else if(pid > 0)
    {
        // 父亲  关闭写，开始读
        std::cout<<"父进程关闭不需要的fd,准备接受消息了"<<std::endl;
        sleep(2);
        close(fd[1]);

        // char recev[27];
        // read(fd[0],recev,27);
        // std::cout<<recev<<std::endl;
        FatherRead(fd[0]);
        std::cout<<"5s,father close rfd"<<std::endl;
        sleep(5);
        close(fd[0]);

        int status = 0;
        pid_t rid = waitpid(pid,&status,0);
        if (rid > 0)
        {
            std::cout << "wait child process done, exit sig: " << (status & 0x7f) << std::endl;
            std::cout << "wait child process done, exit code(ign): " << ((status >> 8) & 0xFF) << std::endl;
        }
    }

    return 0;
}