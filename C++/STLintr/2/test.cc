///// new operator
#include<new>
using namespace std;
#include<iostream>


// int main()
// {
//     int* p = new int(10);
//     std::cout << *p <<std::endl;
//     cout<<p<<endl;
//     delete p;
// }

// class A  
// {  
// public:  
//     A(int x):m_x(x)  
//     {  
//         std::cout << "constructor of A" << std::endl;  
//     }  
//     ~A()  
//     {  
//         std::cout << "destructor of A" << std::endl;  
//     }  
//     void *operator new(size_t size)  
//     {  
//         std::cout << "operator new of A" << std::endl;  
//         return ::operator new(size);  
//     }  
  
//     void* operator new(size_t size, void* p)  
//     {  
//         std::cout << "placement new of A" << std::endl;  
//         return ::operator new(size, p);  
//     }  
//     void operator delete(void* pUserData)  
//     {  
//         std::cout << "operator delete of A" << std::endl;  
//         ::operator delete(pUserData);  
//     }
// private:
//     int m_x;
// };

// int main()
// {
//     void *ptr = operator new(sizeof(A));    //operator new  
//     A *pa = new(ptr)A(2);           //placement new  
//     cout<<ptr<<endl;
//     cout<<pa<<endl;

//     pa->~A();
//     delete pa;
// }


class A  
{  
public:  
    A(int x = 1):m_x(x){}  
    ~A()  
    {  
    }  
private:  
    int m_x;  
};  
  
int main(int argc, char* argv[])  
{  
    const int N = 8;  
    void *ptr = operator new(sizeof(A) * N);  
    A *pa = new(ptr)A[N];     
    return 0;  
}  