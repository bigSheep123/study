// placement new 是一种C++ 特殊的内存分配和对象构造机制  
// 它允许在已分配好的内存地址上直接构造对象
#include <vector>
using namespace std;
#include<iostream>
#include<string>
// class MyClass {
// // public:
// //     MyClass(int a)
// //     :num(a)
// //     {
// //     }
// public:
//     int num;
// };
// int main()
// {
//     int test[10];
//     // new (address) Type(constructor_arguments)
//     // int buffer[sizeof(MyClass)];
//     void* buffer = new int(10);
//     // int a = 10;
//     MyClass * p = new(buffer) MyClass();

//     // 当 MyClass 类中没有任何类型的适合，它任然有 1 字节的大小
//     // cout << sizeof (MyClass) << endl;
//     // MyClass a;
//     // cout << sizeof (a) << endl;

//     return 0;
// }

// class MyClass
// {
// public:
//     int value;
//     MyClass(int v):value(v){
//         cout << "构造 MyClass(" << value << ") 地址: " << this << endl;
//     }
//     ~MyClass() {
//         cout << "析构 MyClass(" << value << ") 地址: " << this << endl;
//     }
// };

// int main()
// {
//     void* raw_mem =::operator new(sizeof(MyClass));
//     MyClass* p = new (raw_mem) MyClass(42);

//     p->~MyClass();
//     // 使用 operator new 操作时必须要释放内存，否则会存在内存泄露的问题
//     ::operator delete(raw_mem);
//     return 0;
// }

// int main()
// {
//     char buffer[sizeof(MyClass)];

//     // 使用palcement new 在buffer 上构造对象
//     MyClass* p = new(buffer) MyClass(42);

//     // 手动调用析构函数
//     p->~MyClass();
//     return 0;
// }


// 实际应用场景

// 要对编译器可见
// template<class T>
// class Vector;

// template<class T>
// std::ostream& operator<< (std::ostream& os,const Vector<T>& vec);


// template<class T>
// class Vector{
//     T* data;
//     size_t size;
// public:
//     void push_back(const T& value)
//     {
//         new(data + size) T(value);
//         size++;
//     }

//     // template<class T>
//     friend std::ostream& operator<< <T> (std::ostream& os,const Vector<T>& vec);
//     // {   // 1.直接实现在类内部可以  2.直接换成模板参数也可以
//     //     os << vec.size << " " << vec.data << endl;
//     //     return os;
//     // }
// };

// template<class T>
// std::ostream& operator<< (std::ostream& os,const Vector<T>& vec)
// {
//     os << vec.size << " " << vec.data << endl;
//     return os;
// }


// int main()
// {
//     // Vector<std::string> a;
//     // a.push_back(std::string("111"));
//     Vector<int> a;
//     a.push_back(1);
//     cout << a;
//     return 0;
// }
