// 
#include <pthread.h>
#include <iostream>
#include <unistd.h>

// void * Test(void * args)
// {
//     const char* name = static_cast<char*>(args);
//     std::cout << name <<  "  "<<getpid() <<std::endl;
//     std::cout << pthread_self() << std::endl;


//     // {
//     //     int a = 10;
//     //     int b = a/ 0;
//     // }
//     return nullptr;
// }

// int main()
// {
//     pthread_t t1;
//     pthread_create(&t1,nullptr,Test,(void*)("new Thread"));

//     void ** ret;
//     pthread_join(t1,ret);
//     std::cout << t1 << " "<<getpid() << std::endl;
//     std::cout << pthread_self() << std::endl;

//     pthread_exit(nullptr);

//     while(1)
//     {

//     }

//     return 0;
// }

// 进程史资源分配的基本单位，线程是调度的基本单位
// 线程共享进程数据，但也拥有自己的一部分数据


// pthread_t 类型的线程ID，本质上就是一个进程地址空间上的一个地址

// void *thread1(void *arg)
// {
//     printf("thread 1 returning ... \n");
//     int *p = (int *)malloc(sizeof(int));
//     *p = 1;
//     return (void *)p;
// }

// void *thread2(void *arg)
// {
//     printf("thread 2 exiting ...\n");
//     int *p = (int *)malloc(sizeof(int));
//     *p = 2;
//     pthread_exit((void *)p);
// }

// void *thread3(void *arg)
// {
//     while (1)
//     { //
//         printf("thread 3 is running ...\n");
//         sleep(1);
//     }
//     return NULL;
// }

// int main(void)
// {
//     pthread_t tid;
//     void *ret;
//     // thread 1 return
//     pthread_create(&tid, NULL, thread1, NULL);
//     pthread_join(tid, &ret);
//     printf("thread return, thread id %lX, return code:%d\n", tid, *(int *)ret);
//     free(ret);

//     // thread 2 exit
//     pthread_create(&tid, NULL, thread2, NULL);
//     pthread_join(tid, &ret);
//     printf("thread return, thread id %lX, return code:%d\n", tid, *(int *)ret);
//     free(ret);

//     // thread 3 cancel by other
//     pthread_create(&tid, NULL, thread3, NULL);
//     sleep(3);
//     printf("thread return, thread id %lX\n", tid);
//     pthread_cancel(tid);
//     pthread_join(tid, &ret);
//     if (ret == PTHREAD_CANCELED)
//         printf("thread return, thread id %lX, return code:PTHREAD_CANCELED\n", tid);
//     else
//         printf("thread return, thread id %lX, return code:NULL\n", tid);

//     return 0;
// }

// 新建的线程是 joinable 的，线程退出后，需要对其进行 pthread_join 操作，否则无法释放资源，从而造成系统泄露

// 关心线程的返回值，join 是一种负担，我们可以告诉系统，当线程退出时，自动释放线程资源

// pthread_detach （pthread_t thread）;
// joinable 和分离是冲突的，一个线程不能即是 joinable 又是分离的

// void *thread_run(void *arg)
// {
//     pthread_detach(pthread_self());
//     printf("%s\n", (char *)arg);
//     return NULL;
// }
// // 线程 pthread_detach （pthread_self()）之后的话，就不可以 join 了

// int main(void)
// {
//     pthread_t tid;
//     if (pthread_create(&tid, NULL, thread_run, (void*)"thread1 run...") != 0)
//     {
//         printf("create thread error\n");
//         return 1;
//     }

//     int ret = 0;
//     sleep(1); // 很重要，要让线程先分离，再等待

//     if (pthread_join(tid, NULL) == 0)
//     {
//         printf("pthread wait success\n");
//         ret = 0;
//     }
//     else
//     {
//         printf("pthread wait failed\n");
//         ret = 1;
//     }
//     return ret;
// }


// Linux 线程的互斥
// 互斥：任何时刻，互斥保证有且只有一个执行流进入临界区访问临界资源，通常对临界资源起保护作用
// 互斥量 mutex 

// 买票系统

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <pthread.h>
// int ticket = 100;
// void *route(void *arg)
// {
//     char *id = static_cast<char *> (arg);
//     while (1)
//     {
//         if (ticket > 0)
//         {
//             usleep(1000);
//             printf("%s sells ticket:%d\n", id, ticket);
//             ticket--;
//         }
//         else
//         {
//             break;
//         }
//     }

//     return nullptr;
// }

// int main(void)
// {
//     pthread_t t1, t2, t3, t4;
//     pthread_create(&t1, NULL, route, (void*) "thread 1");
//     pthread_create(&t2, NULL, route, (void*)"thread 2");
//     pthread_create(&t3, NULL, route, (void*) "thread 3");
//     pthread_create(&t4, NULL, route, (void*) "thread 4");

//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);
//     pthread_join(t3, NULL);
//     pthread_join(t4, NULL);
// }

// if 语句判断条件为真以后，代码可以并发的切换到其他线程
// --ticket 并不是一个原子操作

// 代码必须要有互斥行为：当代码进入临界区执行时，不允许其他线程进入该临界区
// 如果多个线程同时要求执行临界区的代码，并且灵界去没有线程的执行，那么只允许一个线程进入该临界区
//  本质上就是一把锁，Linux 上提供的这把锁叫互斥量

// 互斥量的接口
// 初始化互斥量

// 1. 静态分配
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// 2. 动态分配

// int main()
// {
//     pthread_mutex_t mut;
//     pthread_mutex_init(mut,nullptr);

// }


// 销毁互斥量
// 使用 PTHREAD_ MUTEX_ INITIALIZER 初始化的互斥量不需要销毁
// 不用销毁一个已经加锁的互斥量 
// 已经销毁的互斥量，确保后面不会有线程再尝试加锁

// 互斥量处于未锁状态，该函数会将互斥量锁定，同时返回成功
// 发起函数调用时，其他线程已经锁定互斥量，或者存在其他线程同时申请互斥量，但没有竞争到互斥量

// int ticket = 100;
// pthread_mutex_t mutex;
// void *route(void *arg)
// {
//     char *id = (char *)arg;
//     while (1)
//     {
//         pthread_mutex_lock(&mutex);
//         if (ticket > 0)
//         {
//             usleep(1000);
//             printf("%s sells ticket:%d\n", id, ticket);
//             ticket--;
//             pthread_mutex_unlock(&mutex);
//             // sched_yield(); 放弃CPU
//         }
//         else
//         {
//             pthread_mutex_unlock(&mutex);
//             break;
//         }
//     }
// }
// int main(void)
// {
//     pthread_t t1, t2, t3, t4;
//     pthread_mutex_init(&mutex, NULL);
//     pthread_create(&t1, NULL, route, (void*)"thread 1");
//     pthread_create(&t2, NULL, route, (void*)"thread 2");
//     pthread_create(&t3, NULL, route, (void*)"thread 3");
//     pthread_create(&t4, NULL, route, (void*)"thread 4");
//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);
//     pthread_join(t3, NULL);
//     pthread_join(t4, NULL);
//     pthread_mutex_destroy(&mutex);

//     return 0;
// }



pthread_cond_t cond;
pthread_mutex_t mutex;

void *r1(void *arg)
{
    while (1)
    {
        pthread_cond_wait(&cond, &mutex);
        printf("活动\n");
    }
}
void *r2(void *arg)
{
    while (1)
    {
        pthread_cond_signal(&cond);
        sleep(1);
    }
}

int main(void)
{
    pthread_t t1, t2;
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, r1, NULL);
    pthread_create(&t2, NULL, r2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}