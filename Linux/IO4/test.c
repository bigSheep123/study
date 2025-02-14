#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    // int fd = open("/dev/pts/10", O_WRONLY|O_APPEND);
    // if(fd < 0) return 1;

    // const char *message = "hahaha\n";
    // while(1)
    // {
    //     write(fd, message, strlen(message));
    //     sleep(1);
    // }

    // close(fd);
//    while(1)
//    {
//        printf("pid: %d\n", getpid());
//        sleep(1);
//    }

    // printf("stdin->fd: %d\n", stdin->_fileno);
    // printf("stdout->fd: %d\n", stdout->_fileno);
    // printf("stderr->fd: %d\n", stderr->_fileno);


    // FILE *fp = fopen("log.txt", "w");
    // if(fp == NULL) return 1;
    // printf("fd: %d\n", fp->_fileno); 

    // FILE *fp1 = fopen("log1.txt", "w");
    // if(fp == NULL) return 1;
    // printf("fd: %d\n", fp1->_fileno); 

    // FILE *fp2 = fopen("log2.txt", "w");
    // if(fp == NULL) return 1;
    // printf("fd: %d\n", fp2->_fileno); 

    // fwrite("hello", 5, 1, fp);

    // fclose(fp);

//    const char *message = "hello Linux file!\n";
//    write(1, message, strlen(message));

//     fprintf(stdout, "hello: %d\n", 10);
//     fflush(stdout);

//     int fda = open("loga.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     printf("fda: %d\n", fda);
//     int fdb = open("logb.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     printf("fdb: %d\n", fdb);
//     int fdc = open("logc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     printf("fdc: %d\n", fdc);
//     int fdd = open("logd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     printf("fdd: %d\n", fdd);
//     umask(0);
//     system call
//     int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
//     if(fd < 0)
//     {
//        perror("open");
//        return 1;
//     }

//     const char *message = "hello Linux file!\n";
//     const char *message = "abcdefg\n";
//     const char *message = "123";
//     write(fd, message, strlen(message));

//     close(fd);
//     return 0;
}







// #define ONE   1      // 1 0000 0001
// #define TWO   (1<<1) // 2 0000 0010
// #define THREE (1<<2) // 4 0000 0100
// #define FOUR  (1<<3) // 8 0000 1000

// void print(int flag)
// {
//    if(flag&ONE)
//        printf("one\n"); //替换成其他功能
//    if(flag&TWO)
//        printf("two\n");
//    if(flag&THREE)
//        printf("three\n");
//    if(flag&FOUR)
//        printf("four\n");
// }

// int main()
// {
//    print(ONE);
//    printf("\n");

//    print(TWO);
//    printf("\n");

//    print(ONE|TWO);
//    printf("\n");

//    print(ONE|TWO|THREE);
//    printf("\n");

//    print(ONE|FOUR);
//    printf("\n");

//    print(ONE|TWO|THREE|FOUR);
//    printf("\n");

//    return 0;
// }



// // #include <cstddef>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int main()
// {
//     FILE *fp = fopen("log.txt", "a");
//     if(NULL == fp)
//     {
//         perror("fopen");
//         return 1;
//     }

//     fprintf(stdout, "helloworld, %d, %s, %lf\n", 10, "dh", 3.14);

//     fclose(fp);
//     return 0;
// }


// int main()
// {
//     const char *msg0 = "hello printf\n";
//     const char *msg1 = "hello fwrite\n";
//     const char *msg2 = "hello write\n";
//     printf("%s", msg0);
//     fwrite(msg1, strlen(msg1), 1, stdout);
//     write(1, msg2, strlen(msg2));
//     fork();
//     FILE* fp =NULL;
//     return 0;
// }

// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include<sys/stat.h>
// int main()
// {
//     umask(0);
//     int fd = open("./log", O_CREAT | O_RDWR,777);
//     if (fd < 0)
//     {
//         perror("open");
//         return 1;
//     }
//     close(1);
//     dup2(fd, 1);
//     for (;;)
//     {
//         char buf[1024] = {0};
//         ssize_t read_size = read(0, buf, sizeof(buf) - 1);
//         if (read_size < 0)
//         {
//             perror("read");
//             break;
//         }
//         printf("%s", buf);
//         fflush(stdout);
//     }
//     return 0;
// }
