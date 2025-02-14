
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    close(1);
    int fd = open("myfile", O_WRONLY | O_CREAT, 00644);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    printf("fd: %d\n", fd);
    fflush(stdout);

    close(fd);
    exit(0);
}


// int main()
// {
//     close(2);
//     // close(2);
//     int fd = open("myfile", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return 1;
//     }
//     printf("fd: %d\n", fd);
//     close(fd);
//     return 0;
// }

// // fd 的分配规则
// int main()
// {
//     int fd1 = open("myfile", O_RDONLY | O_CREAT);
//     int fd2 = open("myfile.txt", O_RDONLY | O_CREAT);

//     if (fd1 < 0)
//     {
//         perror("open");
//         return 1;
//     }
//     printf("fd: %d\n", fd1);
//     printf("fd: %d\n", fd2);
//     close(fd1);
//     close(fd2);
//     return 0;
// }

// int main()
// {
//     char buf[1024];
//     ssize_t s = read(0,buf,sizeof(buf));
//     printf("%s",buf);
//     if(s>0)
//     {
//         buf[s] = 0;
//         write(1,buf,strlen(buf));
//         write(2,buf,strlen(buf));
//     }

//     return 0;
// }