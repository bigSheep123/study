#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/types.h>

void ChildRun()
{
    int *p = NULL;
    int cnt = 5;
    while(1)
    {
        printf("I am child process, pid: %d, ppid:%d, cnt: %d\n", getpid(), getppid(), cnt);
        sleep(1);
        cnt--;
        *p = 100;
    }
}

int main()
{
    printf("I am father, pid: %d, ppid:%d\n", getpid(), getppid());

    pid_t id = fork();
    if(id == 0)
    {
        // child
        ChildRun();
        printf("child quit ...\n");
        exit(123);
    }
    sleep(7);
    // fahter
    //pid_t rid = wait(NULL);
    int status = 0;
    pid_t rid = waitpid(id, &status,0);
    if(rid > 0)
    {
        printf("wait success, rid: %d\n", rid);
    }
    else
    {
        printf("wait failed !\n");
    }
    sleep(3);
    printf("father quit, status: %d, child quit code : %d, child quit signal: %d\n", status, (status>>8)&0xFF, status & 0x7F);
}




// // 自定义枚举常量
// enum
// {
//     Success = 0,
//     Div_Zero,
//     Mod_Zero,
// };
// // int exit_code = Success;
// int exit_code;
// const char *CodeToErrString(int code)
// {
//     switch(code)
//     {
//         case Success:
//             return "Success";
//         case Div_Zero:
//             return "div zero!";
//         case Mod_Zero:
//             return "mod zero!";
//         default:
//             return "unknow error!";
//     }
// }

// int Div(int x,int y)
// {
//     if(0 == y)
//     {
//         exit_code = Div_Zero;
//         return -1;
//     }
//     else
//     {
//         return x/y;
//         // _exit(31);
//     }
// }

// int main()
// {
// //     for(int errcode = 0; errcode <= 255; errcode++)
// //    {
// //         printf("%d: %s\n", errcode, strerror(errcode));
// //    }

// //     printf("I am process, pid: %d, ppid: %d\n", getpid(), getppid());
// //     sleep(2);
// //     return 0;



//     // Div(1,0);
//     // return 0;
//     // int result = Div(10, 100);
//     // printf("result: %d [%s]\n", result, CodeToErrString(exit_code));
//     // result = Div(10, 0);
//     // printf("result: %d [%s]\n", result, CodeToErrString(exit_code));

//     // return exit_code;
// }






// int main()
// {
//     printf("testexec ... begin\n");
//     execl("/usr/bin/ls","ls","-l","-a",NULL);

//     printf("end\n");
//     return 0;
// }

    // char *const argv[] = {"ps", "-ef", NULL};
    // char *const envp[] = {"PATH=/bin:/usr/bin", "TERM=console", NULL};
    // execl("/bin/ps", "ps", "-ef", NULL);
    // // 带p的，可以使用环境变量PATH，无需写全路径
    // execlp("ps", "ps", "-ef", NULL);
    // // 带e的，需要自己组装环境变量
    // execle("ps", "ps", "-ef", NULL, envp);
    // execv("/bin/ps", argv);

    // // 带p的，可以使用环境变量PATH，无需写全路径
    // execvp("ps", argv);
    // // 带e的，需要自己组装环境变量
    // execve("/bin/ps", argv, envp);
    // exit(0);