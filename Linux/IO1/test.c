#include<stdio.h>
#include<string.h>
#include <sys/types.h>

#include <stdio.h>
// #include <string.h>
int main()
{
    // const char *msg = "hello fwrite\n";
    FILE* fp =fopen("log","w");
    fclose(fp);
    return 0;
}


    // fwrite(msg, strlen(msg), 1, stdout);
    // printf("hello printf\n");
    // fprintf(stdout, "hello fprintf\n");

// int main()
// {
//     FILE *fp = fopen("myfile", "r");
//     if (!fp)
//     {
//         printf("fopen error!\n");
//     }
//     char buf[1024];
//     const char *msg = "hello world!\n";
//     //strlen 算上了'\0'
//     // printf("%d,%d\n",strlen(msg),sizeof(msg)/sizeof(char));
//     // printf("%lu\n",sizeof(ssize_t));
//     // printf("%lu\n",sizeof(int));
//     while (1)
//     {
//         clearerr(fp);
//         // 注意返回值和参数，此处有坑，仔细查看man手册关于该函数的说明
//         ssize_t s = fread(buf, 1, 30, fp);
//         // fread 犹点意思
//         // printf("%lu\n",sizeof(ssize_t));
//         if (s > 0)
//         {
//             // printf("%lu\n",s)
//             buf[s] = 0;
//             printf("%s\n", buf);
//         }
//         if (feof(fp))
//         {
//             break;
//         }
//     }
//     fclose(fp);
//     return 0;
// }

// int main()
// {
//     FILE* fp = fopen("myfile","w");
//     if(!fp)
//     {
//         printf("fopen error\n");
//     }
//     printf("%d\n",fp->_fileno);


//     const char* mesg = "hello world\n";
//     int count = 5;
//     while(count--)
//     {
//         int a = fwrite(mesg,strlen(mesg),1,fp);
//         printf("%d\n",a);
//     }

//     fclose(fp);

//     return 0;
// }