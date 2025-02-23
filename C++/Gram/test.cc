// class Base {
// public:
//     virtual void func() =0; // ❌ 基类函数未声明为 virtual
// };

// class Derived : public Base {
// public:
//     void func() override {} // ❌ 错误：基类 func() 不是虚函数
// };

// class Base {
// public:
//     virtual void func(int x) {}
// };

// class Derived : public Base {
// public:
//     void func(double x) override {} // ❌ 错误：参数类型不匹配
// };

// #include <iostream>

// class Animal {
// public:
//     virtual void speak() const {
//         std::cout << "Animal sound" << std::endl;
//     }
// };

// class Dog : public Animal {
// public:
//     void speak() const override { // ✅ 正确覆盖基类虚函数
//         std::cout << "Woof!" << std::endl;
//     }
// };

// int main() {
//     // Dog dog;
//     // dog.speak(); // 输出 "Woof!"

//     Animal an;
//     an.speak();
//     return 0;
// }