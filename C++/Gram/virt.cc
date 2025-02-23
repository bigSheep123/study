// #include<iostream>
// 虚函数有默认的实现，子类可以基于基类去实现，也可以不实现
// class Animal {
// public:
//     virtual void speak() { // 虚函数，有默认实现
//         std::cout << "Animal sound" << std::endl;
//     }
// };

// class Dog : public Animal {
// public:
//     void speak() override { // 选择性覆盖
//         std::cout << "Woof!" << std::endl;
//     }
// };

// class Cat : public Animal {
//     // 不覆盖 speak()，直接使用基类的默认实现
// };

// 纯虚函数
// class Shape { // 抽象类
// public:
//     virtual void draw() = 0; // 纯虚函数
// };

// // 纯虚函数可以单独定义实现（但子类仍需覆盖）
// void Shape::draw() {
//     std::cout << "Default draw" << std::endl;
// }

// class Circle : public Shape {
// public:
//     // void draw() override { // 必须实现
//     //     Shape::draw(); // 可调用基类的默认实现
//     //     std::cout << "Drawing a circle" << std::endl;
//     // }

//     void Add() {  return;}
// };

// int main()
// {
//     // Shape shap;
//     // Circle circle;
//     return 0;
// }

// 基类使用 virtual 和 = 0  
// 有纯虚函数，基类就是抽象类，无法实例化
// 子类必须实现所有纯虚函数才能实例化

// class AbstractBase {
// public:
//     virtual void func() = 0;
// };

// void AbstractBase::func() { // 单独定义实现
//     std::cout << "Default implementation" << std::endl;
// }

// class Derived : public AbstractBase {
// public:
//     void func() override {
//         AbstractBase::func(); // 调用基类实现
//         // 扩展逻辑
//     }
// };

// int main()
// {
//     Derived bd;
//     bd.func();
//     return 0;
// }

// 如果抽象类中所有函数都是纯虚函数，称为接口类
// java 的 interface

// #include <iostream>

// class Base {
// public:
//     virtual void foo() { std::cout << "Base::foo()" << std::endl; }  // 虚函数
//     ~Base() { std::cout << "Base destructor" << std::endl; } // ❌ 非虚析构函数
// };

// class Derived : public Base {
// public:
//     int* data; // 派生类独有的资源

//     Derived() { data = new int[100]; } // 分配内存
//     ~Derived() {
//         delete[] data; // 释放内virtual存
//         std::cout << "Derived destructor" << std::endl;
//     }

//     void foo()  { std::cout << "Derived::foo()" << std::endl; }
// };

// int main() {
//     Base* ptr = new Derived(); // 基类指针指向派生类对象
//     ptr->foo();                // 正确调用 Derived::foo()
//     delete ptr;                // 删除指针

//     return 0;
// }

// 触发多态  逐层调用析构函数
// 基类析构函数必须为虚函数

// override 确实是可选择的，但是强烈推荐使用

// 隐藏基类函数
class Base {
public:
    virtual void foo(int x) { /* ... */ }
};

class Derived : public Base {
public:
    void foo(double x) {  // ❌ 参数类型不匹配，未加 override，导致隐藏基类函数
        /* ... */
    }
};