// #include<stdlib.h>
// #include<stdio.h>
// #include<string.h>
// #include <unistd.h>
// #include <sys/types.h>

// #define clear() printf("\033[H\033[J")

// char* extract_after_last_slash(const char* str) {
//     // 查找最后一个反斜杠
//     char* last_slash = strrchr(str, '/');
//     if (last_slash != NULL) {
//         // 返回'\'后的子字符串
//         return strdup(last_slash + 1);
//     } else {
//         // 未找到'\'，返回整个字符串的拷贝
//         return strdup(str);
//     }
// }

// const char* getName()
// {
//     const char* str = getenv("HOME");
//     const char* name = extract_after_last_slash(str);
//     return name;
// }

// void Init()
// {
//     clear();
//     const char* name = getName();
//     printf("%s",name);
// }

// void Create()
// {
//     pid_t id = fork();
//     if(id < 0)
//     {
//         perror("fork failed");
//     }

//     if(id == 0)
//     {

//     }
//     else
//     {

//     }

// }

// int main()
// {
//     Init();
//     Create();
//     return 0;
// }



// // int main()
// // {
// //     clear();    
// //     const char* str = getenv("HOME");
// //     printf("%s\n",str);
// //     printf("dh@helloworld:~\n");
// //     return 0;
// // }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 512
#define ZERO '\0'
#define SEP " "
#define NUM 32
#define SkipPath(p) do{ p += (strlen(p)-1); while(*p != '/') p--; }while(0)

// 为了方便，我就直接定义了
char cwd[SIZE*2];
char *gArgv[NUM];
int lastcode = 0;

void Die()
{
    exit(1);
}

const char *GetHome()
{
    const char *home = getenv("HOME");
    if(home == NULL) return "/";
    return home;
}

const char *GetUserName()
{
    const char *name = getenv("USER");
    if(name == NULL) return "None";
    return name;
}
const char *GetHostName()
{
    const char *hostname = getenv("HOSTNAME");
    if(hostname == NULL) return "None";
    return hostname;
}
// 临时
const char *GetCwd()
{
    const char *cwd = getenv("PWD");
    if(cwd == NULL) return "None";
    return cwd;
}

// commandline : output
void MakeCommandLineAndPrint()
{
    char line[SIZE];
    const char *username = GetUserName();
    const char *hostname = GetHostName();
    const char *cwd = GetCwd();

    SkipPath(cwd);
    snprintf(line, sizeof(line), "[%s@%s %s]> ", username, hostname, strlen(cwd) == 1 ? "/" : cwd+1);
    printf("%s", line);
    fflush(stdout);
}

int GetUserCommand(char command[], size_t n)
{
    char *s = fgets(command, n, stdin);
    if(s == NULL) return -1;
    command[strlen(command)-1] = ZERO;
    return strlen(command); 
}


void SplitCommand(char command[], size_t n)
{
    (void)n;
    // "ls -a -l -n" -> "ls" "-a" "-l" "-n"
    gArgv[0] = strtok(command, SEP);
    int index = 1;
    while((gArgv[index++] = strtok(NULL, SEP))); // done, 故意写成=,表示先赋值，在判断. 分割之后，strtok会返回NULL，刚好让gArgv最后一个元素是NULL, 并且while判断结束
}

void ExecuteCommand()
{
    pid_t id = fork();
    if(id < 0) Die();
    else if(id == 0)
    {
        // child
        execvp(gArgv[0], gArgv);
        exit(errno);
    }
    else
    {
        // fahter
        int status = 0;
        pid_t rid = waitpid(id, &status, 0);
        if(rid > 0)
        {
            lastcode = WEXITSTATUS(status);
            if(lastcode != 0) printf("%s:%s:%d\n", gArgv[0], strerror(lastcode), lastcode);
        }
    }
}

void Cd()
{
    const char *path = gArgv[1];
    if(path == NULL) path = GetHome();
    // path 一定存在
    chdir(path);

    // 刷新环境变量
    char temp[SIZE*2];
    getcwd(temp, sizeof(temp));
    snprintf(cwd, sizeof(cwd), "PWD=%s", temp);
    putenv(cwd); // OK
}

int CheckBuildin()
{
    int yes = 0;
    const char *enter_cmd = gArgv[0];
    if(strcmp(enter_cmd, "cd") == 0)
    {
        yes = 1;
        Cd();
    }
    else if(strcmp(enter_cmd, "echo") == 0 && strcmp(gArgv[1], "$?") == 0)
    {
        yes = 1;
        printf("%d\n", lastcode);
        lastcode = 0;
    }
    return yes;
}

int main()
{
    int quit = 0;
    while(!quit)
    {
        // 1. 我们需要自己输出一个命令行
        MakeCommandLineAndPrint();

        // 2. 获取用户命令字符串
        char usercommand[SIZE];
        int n = GetUserCommand(usercommand, sizeof(usercommand));
        if(n <= 0) return 1;

        // 3. 命令行字符串分割. 
        SplitCommand(usercommand, sizeof(usercommand));

        // 4. 检测命令是否是内建命令
        n = CheckBuildin();
        if(n) continue;
        // 5. 执行命令
        ExecuteCommand();
    }
    return 0;
}





















