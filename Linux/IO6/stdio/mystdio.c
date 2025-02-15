#include "mystdio.h"
#include <assert.h>
myFILE* my_fopen(const char* path,const char* mode)
{
    int flag = 0;
    int isCreate = 0;
    mode_t denf = 0666;
    if(strcmp("r",mode) == 0)
    {
        flag = (O_RDONLY);
    }
    else if(strcmp("w",mode) == 0)
    {
        flag = (O_CREAT|O_WRONLY|O_TRUNC);
        isCreate = 1;
    }
    else if(strcmp("a",mode) == 0)
    {   
        flag = (O_APPEND|O_CREAT|O_WRONLY);
        isCreate = 1;
    }
    else {}
    // printf("%s,%d,%d\n",path,flag,denf);
    int fd = 0;
    if(isCreate)
        fd = open(path,flag,0666);
    else   
        fd = open(path,flag);

    // printf("%d\n",fd);
    if(fd < 0) return NULL;

    myFILE* fp = (myFILE*)malloc(sizeof(myFILE));
    // assert(fp !=NULL);
    if(fp == NULL)
        perror("malloc failed");
    fp->_fileno = fd;
    fp->cap = SIZE;
    fp->flags =FLUSH_LINE;

    fp->pos = 0;
    // int fileno = open(path,flag);
    // myFILE* fp;
    // fp->_fileno = fileno;
    return fp;
}

size_t my_fwrite(myFILE*fp,const char* buf,size_t n)
{
    memcpy(fp->buf +fp->pos,buf,n);
    fp->pos += n;

    if((fp->flags&FLUSH_LINE)&& fp->buf[fp->pos-1] == '\n')
    {
        my_fflush(fp);
    }

    return n;
    // size_t num = write(fp->_fileno,buf,n);
    // if(num < 0)
    //     perror("write failed");
    
    // return num;
}

int my_fflush(myFILE* fp)
{
    write(fp->_fileno,fp->buf,fp->pos);
    fp->pos = 0;
}

int my_fclose(myFILE* fp)
{
    my_fflush(fp);
    close(fp->_fileno);
    free(fp);
}