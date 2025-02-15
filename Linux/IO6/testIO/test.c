#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

const char *filename = "log.txt";


int main()
{
   struct stat st;
   int n = stat(filename, &st);
   if(n<0) return 1;

   printf("file size: %lu\n", st.st_size);

   //int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
   int fd = open(filename, O_RDONLY);
   if(fd < 0)
   {
       perror("open");
       return 2;
   }
   printf("fd: %d\n", fd);

   char *file_buffer = (char*)malloc(st.st_size + 1);

   n = read(fd, file_buffer, st.st_size);
   if(n > 0)
   {
       file_buffer[n] = '\0';
       printf("%s", file_buffer);
   }

   free(file_buffer);


   //const char *message = "hello Linux\n";
   //write(fd, message, strlen(message));
   //write(fd, message, strlen(message));
   //write(fd, message, strlen(message));
   //write(fd, message, strlen(message));

   close(fd);
   return 0;
}

// int main()
// {
//     // // C  用户级别缓冲区的存在，导致，fork()的时候，子进程会拷贝一份父进程的代码和缓冲区的内容
//     // printf("hello printf\n");
//     // fprintf(stdout, "hello fprintf\n");
//     // // system call
//     // const char *msg = "hello write\n";
//     // write(1, msg, strlen(msg));

//     // fork(); //???
//     // umask(0);
//     // int fd1 = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
//     // // int fd2 = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0666);
//     // int fd3 = open("/dev/pts/2", O_CREAT | O_WRONLY | O_TRUNC, 0666);
//     // printf("fd1:%d\n",fd1);
//     // dup2(fd1, 1);
//     // printf("hello world\n");
//     // fprintf(stdout, "hello world\n");
//     // fflush(stdout);
//     // close(0);
//     // close(1);
//     //close(2);
//     int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
//     if(fd < 0)
//     {
//        perror("open");
//        return 1;
//     }
//     // 重定向的函数，将本来要打印在标准输出的内容输入到了文件中
//     dup2(fd,1);
//     printf("printf, fd: %d\n", fd);
//     fprintf(stdout, "fprintf, fd: %d\n", fd);

//     fflush(stdout);


//     close(fd);

//     return 0;
// }







