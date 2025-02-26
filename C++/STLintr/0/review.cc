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

// class alloc 
// {
// public:
//     template<class T>
//     T* allocate (size_t n)
//     {
//         return static_cast<T*>(:: operator new(n*sizeof(T)));
//     }

//     template<class T>
//     void deallocate(T*p)
//     {
//         ::operator delete(p);
//     }
// };

// // alloc 类似于函数中缺省参数（默认参数） 
// template<class T,class Alloc=alloc>
// class vec{
// private:
//     T* data;
//     size_t capacity;
//     Alloc allocator;

// public:
//     vec() :data(nullptr),capacity(0) {}

//     // 必须显示调用构造函数  禁止隐式类型转换
//     explicit vec(size_t n)
//     {
//         // data = allocator.template allocate<T>(n); // 分配内存
//         // allocate 是模板成员函数，需要通过template 关键字去指明这是一个模板调用
//         data = allocator.template allocate<T>(n);
//         capacity = n;
//         for(size_t i =0; i < n; i++)
//         {
//             new (&data[i]) T();  // placement new 构造对象
//         }
//     }
// };

// void func(const vec<int>& v) { }

// int main()
// {
//     // vec<int> v = 10;  -> 隐式类型转换 vec<int> v (10);
//     // vec<int> v1(10);
//     // vec<int> v2 = vec<int> (10);  // 构造临时变量赋值给  v2
//     // 如果没有 explicit 的话， 发生了隐式类型转换： 将 10 转为 vec<int>
//     // func(10);
//     // func(vec<int> (10));
//     vec<int> v(10);
// }


// #include <iostream>
// using namespace std;

// // 默认分配器 alloc
// class alloc {
// public:
//     void log() { cout << "使用默认分配器" << endl; }
// };

// // 自定义分配器 my_alloc
// class my_alloc {
// public:
//     void log() { cout << "使用自定义分配器" << endl; }
// };

// // 模板类 vec，Alloc 的默认类型是 alloc
// template<class T, class Alloc = alloc>
// class vec {
// private:
//     Alloc allocator; // 成员变量：分配器对象
// public:
//     vec() {
//         allocator.log(); // 调用分配器的日志方法
//     }
// };

// int main() {
//     vec<int> v1;           // 输出：使用默认分配器
//     vec<int, my_alloc> v2; // 输出：使用自定义分配器
//     return 0;
// }

// #define __STL_FUNCTION_TMPL_PARTIAL_ORDER
// class alloc {
// };

// template <class T, class Alloc=alloc>
// class test{
// public:
//     void swap(test<T, Alloc>&) {
//         cout << "swap()" << endl;
//     }
// };

// template <class T, class Alloc=alloc>
// class vec {
// public: 
//     void swap(vec<T, Alloc>&) {
//         cout << "swap()" << endl;
//     }
// };
// #ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
// template <class T, class Alloc>
// inline void swap(vec<T, Alloc>& x, vec<T, Alloc>& y) {
//     x.swap(y);
//     cout << "inline swap" << endl;
// }

// #endif
// int main()
// {
//     vec<int> x, y;
//     swap(x,y);
//     test<char> a,b;
//     swap(a,b);
//     return 0;
// }