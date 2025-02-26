/// static_cast 是C++ 中最常见的类型转换运算符
#include<iostream>
using namespace std;
#include<memory>
// int main()
// {
//     int a = 42;
//     double b = static_cast<double> (a);
//     char c = static_cast<char> (b);
//     cout << a << " " << b << " " << c << " ";
//     return 0;
// }

// class Base{};
// class Derived: public Base {};

// int main()
// {
//     Derived d;
//     // 向上类型转换  父类----> 子类
//     Base* base_ptr = static_cast<Base*> (&d);
// }

// class MyClass {
// public:
//     explicit MyClass(int x) {  cout<<"hello world"<<endl; }  // explicit 构造函数
// };

// int main()
// {
    // 显示调用构造函数/转换函数
//     int x = 10;
//     MyClass obj = static_cast<MyClass>(x);  // 强制调用 explicit 构造函数
//     // MyClass ob = MyClass(10);
//     // MyClass o = 10;

//     return 0;
// }

// 指针的互转

// int main()
// {
//     int a = 5;
//     void* ptr = static_cast<void*> (&a);
//     int* i_Ptr =static_cast<int*> (ptr);
// }


// 类之间无继承关系
// class PromoteMem2Reg { /* ... */ };
// class Mem2reg { /* ... */ };

// void func(PromoteMem2Reg obj) { /* ... */ }

// int main()
// {
//     Mem2reg m;
//     func(m);  // 错误：Mem2reg 无法转换为 PromoteMem2Reg

//     return 0;
// }

// class Mem2reg;
// class PromoteMem2Reg {
// public:
//   PromoteMem2Reg(const Mem2reg& m);  // 需要定义转换构造函数
// };

// // 或
// class Mem2reg {
// public:
//   operator PromoteMem2Reg() const;  // 需要定义转换运算符
// };

// void func(PromoteMem2Reg obj) { /* ... */ }

// int main()
// {
//     Mem2reg m;
//     //  加载一个 operator () 的重载函数
//     func(m.operator PromoteMem2Reg()); // 错误：Mem2reg 无法转换为 PromoteMem2Reg
// }

// std::unique_ptr 是 C++ 11 引入的智能指针，用于自动管理动态分配的内存
// 确保资源在不再需要时被正确释放

// std::unique_ptr<int> ptr1(new int(42));


// int main()
// {
//     std::unique_ptr<int> ptr1(new int(42));
//     auto ptr2 = std::make_unique<int> (42);

//     *ptr1 = 100;
//     // cout << *ptr1 << endl;
//     //  get方法
//     // int* p = ptr2.get();
//     // int* raw_ptr = ptr1.get();
//     // cout<<*raw_ptr<<endl;
//     // cout<<*ptr1<<endl;

//     std::unique_ptr<int> ptr3 = std::move(ptr1);
//     // cout <<*ptr1 <<endl;
//     int* r = ptr3.release();
//     cout<<*r<<endl;

//     return 0;
// }