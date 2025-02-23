#include<iostream>
using namespace std;
// // 类模板
// template<typename T>
// struct MyClass {
//     void foo() {}
// };

// // 错误的特化写法（缺少 template<>）
// // 模板的特化 显示特化，告诉编译器这是一个针对特定类型的特化版本
// template<>
// struct MyClass<int> {  // ❌ 编译器会报错
//     void foo() {}
// };

// // 函数模板
// template<typename T>
// void myFunction(T value) { /* 通用实现 */ }

// // 正确写法：显式特化也需要 template<>
// template<>  // ✅
// void myFunction<int>(int value) { 
//     // 针对 int 类型的特化实现
// }



// // 部分特化
// template<typename T, typename U>
// struct MyPair { /* 通用实现 */ };

// // 部分特化（第二个类型固定为 int）
// template<typename T>  // ✅ 注意这里不是 template<>
// struct MyPair<T, int> { 
//     // 当第二个类型是 int 时的特化实现
// };

// template<typename T>
// class TestClass{
// public:
//     static int _data;
// };
// // 静态变量的初始化，配置内存
// template<> int TestClass<int>::_data = 1;

// int main()
// {
//     TestClass<int> obj1;
//     obj1._data = 2;
//     cout<<obj1._data << " " <<endl;

//     return 0;
// }
//// typename 和 class 是等效的，一般情况下没啥子区别

// // 全特化 一般化设计
// template<typename I,class O>
// struct TestClass{
//     TestClass(){
//         cout<<"I O"<<endl;
//     }
// };
 
// // 特殊化设计  T* 特化允许用指针类型匹配的模式，也只能如此匹配
// template<class T>
// struct TestClass<T*, T*>
// {
//     TestClass(){
//         cout<<"T* T*"<<endl;
//     }
// };

// // 特殊化设计  const T* 允许指向const 指针类型的匹配
// template<class T>
// struct TestClass<const T*,T*>
// {
//     TestClass()
//     {
//         cout<<"const T* T*"<<endl;
//     }
// };

// int main()
// {
//     TestClass<int,char> ob1;
//     TestClass<int*,int*> ob2;
//     TestClass<const int*,int*> ob3;

//     return 0;
// }


// inline 内联函数，解决一些频繁调用小函数大量消耗栈空间的问题
// class alloc{
// };

// template<class T,class Alloc = alloc>
// class Vec{
//     public:
//     void swap(Vec<T,Alloc>&){
//         cout<<"swap() "<<endl;
//     }
// };

// int main(){
//     Vec<int> x,y;
//     x.swap(y);
//     swap(x,y);
// }