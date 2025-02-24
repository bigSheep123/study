// CRTP (奇异递归模板模式)
// #include<functional>
// class Module{};
// template <typename Derived, typename Module>
// class _PassManagerBase {
//     // 基类中可能使用Derived的方法
// };

// class MyPass : public _PassManagerBase<MyPass, Module> {
//     // 实现具体逻辑
// };
//                                        // condition 为true，name类型为void，模板正常实例化   // Module 必须继承自 Pass
// template <typename Pass, typename = std::enable_if_t<std::is_base_of_v<_PassManagerBase<Pass, Module>, Pass>>>
// class PassManager {
//     // 使用Pass类的方法
// };

// NOLINTNEXTLINE
// #define CMMC_TRANSFORM_PASS(CLASS)                                   \
//     static const int __pass_##CLASS = [] {                           \
//         PassRegistry::get().registerPass(std::make_shared<CLASS>()); \
//         return 0;                                                    \
//     }()

// class Mem2reg{
// public:
//     Mem2reg() = default;
//     ~Mem2reg() = default;
//     bool run()  {return true;}
// };

// CMMC_TRANSFORM_PASS(Mem2reg);
// 注册，编译器的优化注册


#include <any>
#include <iterator>
#include<queue>
#include<string>
#include<iostream>
#include <bits/unique_ptr.h>
using namespace std;
// template<typename name>
// class A 
// {
// public:
//     std::queue<name> q;
// };

// template<typename Pass>
// class PassManager:public _PassManagerBase
// {   
// private:
//     std::queue<Pass> Passque;
// public:
//     void addPass(Pass& pass) {}
// };

// int main()
// {
//     // std::queue<std::string> q;
//     A<int> a;
//     for(int i = 0; i< 10; i++)
//     {
//         // a.q.push(i);
//         a.q.emplace(i);
//     }

//     // a.q.push(1);
//     while(!a.q.empty())
//     {

//         cout << a.q.front()<<endl;
//         a.q.pop();
//     }

//     return 0;
// }


// // C++ 14 是一个非常重要的智能指针工厂函数，用来创建 std::unique_ptr 对象
// class MyClass {
// public:
//     MyClass(int a,int b) {
//         std::cout << "MyClass constructor with value: " << a << std::endl;
//     }
//     void say_hello() {
//         std::cout << "Hello from MyClass!" << std::endl;
//     }
// };

// int main() {
//     // 使用 std::make_unique 创建 unique_ptr
//     auto ptr = std::make_unique<MyClass>(10,20);
//     ptr->say_hello();

//     return 0;
// }

// template<typename T>
// class MyClass;

// template<typename U>
// void foo(MyClass<U> obj);

// template<typename T>
// class MyClass {
// public:
//     // 声明一个依赖类模板参数的友元函数模板
//     template<typename U>
//     friend void foo(MyClass<U> obj); // ❌ 错误触发点
// };

// // template<typename U>
// // void foo(MyClass<U> obj) { return;}

// int main()
// {
//     MyClass<int> MC;
//     return 0;
// }

// // 先声明类模板
// template<typename T>
// class MyClass;

// //先声明友元函数模板
// template<typename U>
// void foo(MyClass<U> obj);


// template<typename T>
// class MyClass {
// public:
//     // 声明一个依赖类模板参数的友元函数模板
//     template<typename U>
//     friend void foo(MyClass<U> obj); // ❌ 错误触发点
// };

// template<typename U>
// void foo(MyClass<U> obj)
// {

// }

// template<typename T>
// class MyClass {
// public:
//     // 声明一个依赖类模板参数的友元函数模板
//     friend void foo(MyClass<T> obj)
//     {

//     }// ❌ 错误触发点
// };

// int main()
// {
//     MyClass<int> mc;
//     // mc.foo();
// }

// template<typename T>
// class MyClass {
// public:
//     // 声明一个依赖类模板参数的友元函数模板

//     friend void foo(MyClass<T>& obj)
//     {
//         int i = 0;
//         i++;
//     }// ❌ 错误触发点
// };

// int main()
// {
//     MyClass<int> mc;
//     foo(mc);
//     // mc.foo();
// }

// template<typename T>
// class MyClass {
// public:
//     // 声明一个依赖类模板参数的友元函数模板
//     template<typename U>
//     friend void foo(MyClass<U>& obj)
//     {
//         int i = 0;
//         i++;
//     }// ❌ 错误触发点
// };

// int main()
// {
//     MyClass<int> mc;
//     foo(mc);
//     // mc.foo();
// }

// 定义在类中的友元函数，friend ，本质上还是一个全局函数  ，而非类的成员函数
// 友元函数在类内定义（隐式全局函数）
// 友元函数在类内声明，类外定义
// #include <iostream>

// class MyClass
// {
// private:
//     int value;

// public:
//     MyClass(int val) : value(val) {}

//     //友元函数定义在类内部（隐式全局函数）
//     friend void printValue(const MyClass &obj);
// };

// void printValue(const MyClass &obj)
// {
//     std::cout << "Value: " << obj.value << std::endl;
// }

// int main()
// {
//     MyClass obj(42);
//     printValue(obj);
//     return 0;
// }

// #include <iostream>

// template<typename T>
// class MyTemplateClass {
// private:
//     T value;

// public:
//     MyTemplateClass(T val) : value(val) {}

//     // 友元函数声明（需模板参数）
//     friend void printTemplateValue(const MyTemplateClass<T>& obj)
//     {
//         std::cout << "Template Value: " << obj.value << std::endl;
//     }
// };

// // // 类外定义友元函数（需显式模板参数）
// // template<typename T>
// // void printTemplateValue(const MyTemplateClass<T>& obj) {
// //     std::cout << "Template Value: " << obj.value << std::endl;
// // }

// int main() {
//     MyTemplateClass<int> obj(42);
//     printTemplateValue(obj);  // ✔️ 直接调用
//     return 0;
// }

// 友元函数必须在类外声明否则无法使用
// class MyClass {
//     friend void hiddenFriend(); // 类内定义的友元函数，但未在全局声明
// };

// void hiddenFriend() {}

// int main() {
//     hiddenFriend(); // ❌ 错误：编译器找不到该函数
//     return 0;
// }

// 友元函数，突破封装，保持可控

// 支持操作符重载（尤其是非成员操作符）

// class MyClass
// {
// private:
//     int value;

// public:
//     MyClass(int v) : value(v) {}
//     //friend std::ostream &operator<<(std::ostream &os, const MyClass &obj);
//     std::ostream &operator<<(std::ostream &os, const MyClass &obj)
//     {
//         os << "Value:" << obj.value;
//         return os;
//     }
// };

// int main()
// {
//     MyClass obj(43);
//     std::cout<<obj;
// }

#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    std::ostream& operator<<(std::ostream& os) const
    {
        os<<"Value:" <<value;
        return os;
    }
};

int main() {
    MyClass obj(43);
    obj.operator<<(std::cout);
    return 0;
}
