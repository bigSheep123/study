#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



// int main()
// {
//     int fd = open("myfile", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return 1;
//     }
//     const char *msg = "hello world!\n";
//     char buf[1024];
//     while (1)
//     {
//         // 13 * 5 = 65
//         ssize_t s = read(fd, buf, strlen(msg)); // 类比write
//         if (s > 0)
//         {
//             printf("%lu\n",s);
//             printf("%s", buf);
//         }
//         else
//         {
//             break;
//         }
//     }
//     close(fd);
//     return 0;
// }



// int main()
//  {
//      // umask(0);
//      int fd = open("myfile", O_WRONLY | O_CREAT, 0644);
//      if (fd < 0)
//      {
//          perror("open");
//          return 1;
//      }
//      int count = 5;
//      const char *msg = "hello world!\n";
//      // printf("%d",len);
//      int len = strlen(msg);
//      printf("%d\n",len);

//     while (count--)
//     {
//         int n = write(fd, msg, len); // fd: 后面讲， msg：缓冲区首地址， len: 本次读取，期望写入多少个字节的数
//         // 据。 返回值：实际写了多少字节数据
//         printf("%d\n",n);
//     }
//     close(fd);
//     return 0;
// }