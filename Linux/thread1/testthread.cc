#include <cstdlib>
#include <time.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>

int gval = 100;

void *Start(void *args)
{
    while(1) 
    {
        sleep(1);
        std::cout << "new thread running..." << ", pid: " << getpid()
              << ", gval: " << gval << ", &gval: " << &gval << std::endl;
    }
    
}

int main()
{
    srand(time(nullptr));
    
    pthread_t tid1;
    pthread_create(&tid1,nullptr,Start,(void*)"new thread");

    pthread_t tid2;
    pthread_create(&tid2,nullptr,Start,nullptr);

    pthread_t tid3;
    pthread_create(&tid3,nullptr,Start,nullptr);

    while(true) {
        std::cout << "main pthread running" << "  pid:" << getpid() << 
                    ", gval " << gval << " &gval =" << &gval << std::endl;
        gval++;
        sleep(1);
    }

    return 0;
}