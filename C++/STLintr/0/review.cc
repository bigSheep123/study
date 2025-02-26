#include<iostream>
using namespace std;
///// 模板有类模板 和 函数模板

// template<typename T>
// class TestClass{
// public:
// // 静态成员变量 必须类外进行初始化
//     static int _data ;
// };
// // 模板实例化需要 template<>
// template<> int TestClass<int> ::_data = 1;
// template<> int TestClass<char> :: _data = 2;

// int main()
// {
//     cout<<TestClass<int>::_data <<endl;
//     cout<<TestClass<char>::_data <<endl;

//     TestClass<int> obji1, obji2;
//     TestClass<char> objc1, objc2;
//     cout << obji1._data << " " << obji2._data << endl;
//     cout << objc1._data << " " << objc2._data << endl;

//     obji1._data = 3;
//     objc2._data = 4;

//     cout << obji1._data << " " << obji2._data << endl;
//     cout << objc1._data << " " << objc2._data << endl;
// }

// 全特化就是所有的模板都是具体的类
// T* 特化允许用指针类型匹配的模式（但是也只能匹配指针类型）
// const T* 同理
// 偏特化只是一些匹配变的稍微具体了一些，但是本质上任然是templatized


// template<class I,class O>
// struct TestClass
// {
//     TestClass()
//     {
//         cout << "I , O" << endl;
//     }
// };

// // 特殊化设计 偏特化
// template <class T>
// struct TestClass<T*,T*>
// {
//     TestClass()
//     {
//         cout << "T* , T*" << endl;
//     }
// };

// template<class T>
// struct TestClass<const T*, T*>
// {
//     TestClass()
//     {
//         cout << "const T* , T*" << endl;
//     }
// };

// template<class T>
// struct TestClass<T, T>
// {
//     TestClass()
//     {
//         cout<<" T, T" <<endl;
//     }
// };

// int main()
// {
//     TestClass<int,char> obj1;
//     TestClass<int ,int > obj2;
//     TestClass<int*,char*> obj3;
//     TestClass<int*, int*> obj4;
//     TestClass<const int*,int*> obj5;
//     TestClass<const int*,const int*> obj6;
//     return 0;
// }


// class alloc{
// };

// template<class T,class Alloc = alloc>
// class vec{
// public:
//     void swap(vec<T,Alloc>&)
//     {
//         cout<<"swap()" <<endl;
//     } 
// };

// int main() {
//     vec<int> x, y;
//     swap(x, y);
// }


// // new 动态内存分配   static_cast 类型转换
// int main()
// {
//     // int * p = new int(10);
//     // cout<<*p<<endl;
//     // delete p;  // 释放内存

//     // [nodiscard] ::operator new(sizeof(int));
//     // void* raw_mem =::operator new(sizeof(int));
//     // // operator new 允许在分配内存后动手控制对象的构造

//     // //  static_cast类型转换   明确定义类型转换
//     // int* p = static_cast<int*>(raw_mem);
//     // *p = 10;
//     // std::cout<<*p;
//     // ::operator delete(raw_mem);

//     double d = 3.14;
//     int i = static_cast<int>(d);
//     cout<<i<<endl;
// }

// class Base{  
// public:
//     Base()
//     {
//         cout << "Base()" << endl;
//     }

//     virtual void Print() { cout<<"Base Print"<<endl; }
// };
// class Derived :public Base 
// {
// public:
//     Derived()
//     {
//         cout<<"Derived()" <<endl;
//     }

//     void Print() override { cout << " Derived Print"<< endl; }

//     // void Hlleo() override {}
// };

// int main()
// {
//     Derived* d = new Derived;
//     // 类层次的上行转换
//     Base* b = static_cast<Base*> (d);
//     // 多态
//     d->Print();
//     b->Print();

//     return 0;
// }

