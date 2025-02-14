#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define clear() printf("\033[H\033[J")
#define SIZE 512
#define NUM 32
#define ZERO '\0'
#define SPACE " "

char* Argv[NUM];

int code = 0;
char tmp[SIZE];
char fileName[SIZE];
char command[SIZE];
int redir_type;

#define None_Redir 0
#define In_Redir   1
#define Out_Redir  2
#define App_Redir  3

// 支持处理 ls -al > file.txt 类型的命令   >>  <

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

const char* getHostName()
{
    const char* host = getenv("HOSTNAME");
    if(host == NULL) return NULL;
    return host;
}

const char* getName()
{
    const char* name = getenv("USER");
    if(name == NULL) return NULL;
    // const char* name = extract_after_last_slash(str);
    return name;
}

const char* getPath()
{
    const char* path = getenv("PWD");
    if(path == NULL) return  NULL;
    return  path;
}

void Init()
{
    const char* name = getName();
    const char* host = getHostName();
    const char* path = getPath();
    if(tmp[0])
    {
        path = tmp;
    }
    printf("[%s@%s:%s]$ ",name,host,path);
    fflush(stdout);
}

void GetCommand(char* commond)
{
    char* s = fgets(commond,SIZE,stdin);
    if(s == NULL) return;
    int n = strlen(s) - 1;
    commond[n] = ZERO;
    // printf("%s",commond);
    // fflush(stdout);
}

void SplitCommand(char *command)
{
    Argv[0] = strtok(command,SPACE);
    int index = 1;
    while((Argv[index++] = strtok(NULL,SPACE)));
    // for(int i = 0;i < index-1; i++)
    // {
    //     printf("%s\n",Argv[i]);
    // }
}

void Cd()
{
    const char *path = Argv[1];
    // path 一定存在
    chdir(path);
    getcwd(tmp,sizeof(tmp));
    // printf("%s",tmp);
    // snprintf(cwd, sizeof(cwd), "PWD=%s", tmp);
    // putenv(tmp);
}

int IsBuildCommand()
{   
    int flag = 0;
    const char* enter_cmd = Argv[0];
    if(strcmp(enter_cmd,"cd") == 0)
    {
        flag = 1;
        Cd();
    }
    else if(strcmp(enter_cmd,"echo") == 0 && strcmp(Argv[1],"$?") == 0)
    {
        flag = 1;
        printf("%d\n",code);
        code = 0;
    }

    return flag;
}

void Execute()
{
    pid_t id = fork();
    if(id < 0)
    {
        perror("fork failed");
    }

    if(id == 0)
    {
        if(redir_type != None_Redir)
        {
            if(redir_type == In_Redir)
            {
                int fd = open(fileName, O_RDONLY);
                dup2(fd, 0);
            }
            else if(redir_type == Out_Redir)
            {
                int fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                dup2(fd, 1);
            }
            else if(redir_type == App_Redir)
            {
                int fd = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0666);
                dup2(fd, 1);
            }
            else
            {}
        }

        execvp(Argv[0],Argv);
    }
    else
    {
        int status = 0;
        waitpid(id,&status,0);
    }

}

void SkipSpace(char* command,size_t i)
{
    while(command[i] == ' ')
    {
        i++;
    }
    int n = i;
    while(command[i] != '\0')
    {
        fileName[i-n] = command[i];
        // command[i] = ' ';
        i++;
    }
    command[n] = '\0';
    // while(command[i] != ' ')
    // {
    //     command[i] = ' ';
    //     i++;
    // }
}

void GetfileName(char* command)
{
    // 处理 ls -al > file.txt  // 17个字节
    size_t len = strlen(command);
    // printf("%lu",len);

    for(int i = 0; i < len; i++)
    {
        if(command[i] == '>')
        {
            command[i] = ' ';
            i++;
            redir_type = Out_Redir;
            if(command[i] == '>')
            {
                command[i] = ' ';
                i++;
                redir_type = App_Redir;
            }
            SkipSpace(command,i);
            // printf("%s\n",fileName);
            break;
        }
        else if(command[i] == '<')
        {
            redir_type = In_Redir;
            command[i] = ' ';
            i++;
            SkipSpace(command,i);
            // printf("%s\n",fileName);
            break;
        }
        else {}
    }
}


int main()
{
    clear();
    while (1)
    {
        redir_type = None_Redir;
        Init();
        GetCommand(command);

        // ls -al > file.txt
        GetfileName(command);

        SplitCommand(command);

        // printf("%s\n",Argv[0]);
        if((Argv[0][0] == 'd')&& (Argv[0][1] == 'h'))
        {
            exit(0);
        }

        int flag = IsBuildCommand();
        
        if(!flag)
            Execute();
    }

    return 0;
}

// int main()
// {
//     clear();    
//     const char* str = getenv("HOME");
//     printf("%s\n",str);
//     printf("dh@helloworld:~\n");
//     return 0;
// }


