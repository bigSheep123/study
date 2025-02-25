#include<string>
#include<iostream>
// 左值 和 右值 lvalue  rvalue
// 左值 是有明确存储位置（内存地址）的对象，可以取地址，生命周期独立于表达式
// 左值可以出现在赋值符号 = 的左侧或者右侧

// 右值 是临时对象或字面量，没有持久的内存地址，生命周期仅存在于当前表达式中
// 右值 只能出现在 = 右侧

// C++ 11 出现纯右值 和 将亡值 prvalue xvalue

// prvalue
// int func() { return 10; }  // 返回值是纯右值
// int d = func();            // func() 是纯右值


    // std::string s1 = "hello world";
    // std::cout << s1 << std::endl;
    // std::string s2 = std::move(s1);
    // std::cout << s1 << std::endl;

// void Test(int&& x) { return;}

// int main()
// {
//     int a = 10;
//     Test(10);
//     // Test(a);
//     Test(std::move(a));

//     // && std::move()  是现代C++ 实现高效资源管理的关键
// }

// 问题
// class PassName { /* ... */ };

// void modifyPass(PassName &pass) {  // 参数是非 const 左值引用
//     修改 pass 的内容
// }

// int main() {
//     PassName a;
//     modifyPass(PassName());  // 传递临时对象（右值）触发错误
//     return 0;
// }

// 修改 1
// class PassName { /* ... */ };

// void modifyPass(const PassName &pass) {  // const 左值引用，允许传递临时对象 ，但是不能修改了
//     // 修改 pass 的内容
// }

// int main() {
//     PassName a;
//     modifyPass(PassName());  // 传递临时对象（右值）触发错误
//     return 0;
// }

// class PassName { /* ... */ };

// void modifyPass(PassName &&pass) {  // 参数是非 const 左值引用
//     // 修改 pass 的内容
// }

// int main()
// {
//     // PassName pass;
//     modifyPass(PassName());
//     return 0;
// }


// const T& 可以接受右值：因为临时对象的生命周期被延长，且const 保证不会修改它
