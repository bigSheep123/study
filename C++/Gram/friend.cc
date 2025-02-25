// #include<iostream>
// class MyClass {
// private:
//     int value;

// public:
//     MyClass(int v) : value(v) {}
//     // 将 operator<< 作为了成员内部函数
//     // std::ostream& operator<<(std::ostream& os) const
//     // {
//     //     os<<"Value:" <<value;
//     //     return os;
//     // }
//     friend std::ostream& operator<< (std::ostream&os, const MyClass& obj);
// };

// std::ostream& operator<< (std::ostream&os, const MyClass& obj)
// {
//     os<<obj.value<<std::endl;
// }

// 友元函数可以直接访问私有成员
// int main() {
//     MyClass obj(43);
//     // obj.operator<<(std::cout);  这个是作为了类内部函数调用
//     // 这个是nb
//     std::cout<<obj;  
//     operator<<(std::cout,obj);

//     return 0;
// }

// operator<< 定义为类的成员函数
// 实现了跨类操作
// class B;
// class A;
// class A {
// private:
//     int dataA;
//     friend int computeSum(const A& a, const B& b); // 声明友元
// };

// class B {
// private:
//     int dataB;
//     friend int computeSum(const A& a, const B& b); // 声明友元
// };

// // 友元函数同时访问 A 和 B 的私有成员
// int computeSum(const A& a, const B& b) {
//     return a.dataA + b.dataB;
// }


// 成员函数适合重载 += -= ，等操作符， 而友元函数适合重载 >> << 对称操作符

// 使用<> 表示友元函数模板的特例化

// template<typename T>
// class MyClass;

// template<typename U>
// void foo(MyClass<U> obj);

// template<typename T>
// class MyClass {
// private:
//     int _data;
// public:
//     // 声明一个依赖类模板参数的友元函数模板
//     MyClass(int n): _data(n) {}
//     template<typename U>
//     friend void foo(MyClass<U> obj); 
// };

// template<typename U>
// void foo(MyClass<U> obj) { std::cout << obj._data << std::endl; }

// int main()
// {
//     MyClass<int> obj(1);
//     foo(obj);
//     return 0;
// }


// template<typename T>
// class MyClass {
//     // template<typename U>
//     friend void bar<>(MyClass<T> obj); // ❌ U 未被使用，与类模板参数无关
// };

// #include <iostream>

// template<typename T>
// class MyClass;

// template<typename U>
// void foo(MyClass<U> obj);

// template<typename T>
// class MyClass {
// public:
//     MyClass(T val): value(val) {}

//     friend void foo<>(MyClass<T> obj);
// private:
//     T value;
// };

// template<typename U>
// void foo(MyClass<U> obj) {
//     std::cout << "Value: " << obj.value << std::endl;
// }

// int main() {
//     MyClass<int> obj(42);
//     foo(obj); // 输出：Value: 42
//     return 0;
// }


