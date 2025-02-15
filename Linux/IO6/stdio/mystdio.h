#include<stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//  w   O_CREAT  O_WRONLY  O_TRUNC
//  r   O_RDONLY
//  a+  O_APPEND O_CREAT  O_WRONLY 
#define SIZE 1024
#define FLUSH_NOW 1
#define FLUSH_LINE 2
#define FLUSH_FULL 4

struct _FILE
{
    int flags;
    int _fileno;
    // 缓冲区
    int buf[SIZE];
    // 写入的位置
    int pos;
    int cap;
};

typedef struct _FILE myFILE;

myFILE* my_fopen(const char* path,const char* mode);

size_t my_fwrite(myFILE*fp,const char* buf,size_t n);

int my_fflush(myFILE* fp);

int my_fclose(myFILE* fp);