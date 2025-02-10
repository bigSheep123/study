#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("testexec ... begin!\n");
    pid_t id = fork();
    if(id == 0)
    {
        // putenv("HHHH=111111111111111111");
        // // 我的父进程本身就有一批环境变量！！！, 从bash来
        char *const argv[] = 
        {
            "-a",
            "-l",
            NULL
        };
        // extern char**environ;
        // printf("child pid: %d\n", getpid());
        // sleep(2);
        // // execvp("./mypragma", argv, environ);
        // execvpe("./myprogma", argv, environ);
        // exit(1);

        // execl("/usr/bin/top", "top", NULL);
        // execlp("top", "top", NULL);
        // execv("/usr/bin/ls", argv);
        execvp("ls",argv);
    }

    // fahter
    int status = 0;
    pid_t rid = waitpid(id, &status, 0);
    if(rid > 0)
    {
        printf("father wait success, child exit code: %d\n", WEXITSTATUS(status));
    }
    printf("testexec ... end!\n");
    return 0;
}
