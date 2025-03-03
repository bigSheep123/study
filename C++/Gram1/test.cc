#include <iostream>

// new operator new    placement new
// new operator/delete operator 就是new 和 delete操作符，而operator new/operator delete 是函数

// C++ 共有三种方式可以分配内存， new operator, operator new, placement new
// new operator

// int main()
// {
//     new int(10);
// }

// #include <iostream>  
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
// private:  
//     int m_x;  
// };  
  
// int main(int argc, char* argv[])  
// {  
//     int* p = new int(10);
//     A *pa = new A(1);  
//     // 1. 调用 void* operator new(size_t size) 分配sizeof(A)大小的内存
//     // 2.在第一步返回的地址上调用A的构造函数;
//     // 3.将第一步返回的地址给pa

//     void* pvoid = pa;
//     delete pvoid;
//     // 这样写虽然是释放了内存，但是由于传过来的是void* 类型，所有，它并不会调用A类的析构函数

//     // delete pa;  
//     // 1.在pa所指的地址上调用A的析构函数
//     // 2.调用void operator delete(void* pUserData) 函数释放pa所指的内存
//     return 0;  
// }  

// #include <iostream>  
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
// private:
//     void* operator new(size_t size)  
//     {  
//         std::cout << "operator new of A" << std::endl;  
//         return ::operator new(size);  
//     }  
//     void operator delete(void* pUserData)  
//     {  
//         std::cout << "operator delete of A" << std::endl;  
//         ::operator delete(pUserData);  
//     }  
//     // 重载的时候一定要保证其能释放内存的能力，重载的时候加不加static ，函数的类型都是static的
// private:  
//     int m_x;  
// };  
  
// int main(int argc, char* argv[])  
// {  
//     //保证一个类不能在堆上创建（性能）
//     //保证一个类对象不能被delete
//     A *pa = new A(1);  
//     delete pa;  
//     return 0;  
// }  

// 1.先 operator new 2. 构造 A对象  3. 析构 A对象  4. 释放内存

// placement new

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
//     A *pa = new (ptr) A(2);                 // placement new
//     // 结果是允许用户把一个对象放到一个特定的地方，达到调用析构函数的效果

//     pa->~A();
// }

// class A  
// {  
// public:  
//     A(int x = 1):m_x(x){}  
//     ~A()  
//     {  
//     }  
// private:  
//     int m_x;  
// };  
  
// int main(int argc, char* argv[])  
// {  
//     const int N = 8;  
//     void *ptr = operator new(sizeof(A) * N);  
//     A *pa = new(ptr)A[N];     
//     return 0;  
// }

