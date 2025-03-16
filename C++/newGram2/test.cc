// C++ copy constructor
#include<iostream>
using namespace std;
#include <queue>
#include <vector>
#include <functional>

// class People{
// private:
//     int m_age;
// public:
//     People(int age) : m_age(age)
//     {
//         cout << "constructor" << endl;
//     }
//     // 自定义类型的拷贝构造
//     People(People& p)  
//     {
//         cout << "copy constructor" << endl;
//     }
//     ~People()
//     {
//         cout << "destructor" << endl;
//     }
//     int getAge() const{
//         return m_age;
//     }
// };

// //作为一个值从函数中返回
// People getPeople(){
//     People p1(20);
//     return p1;//会调用 copy constructor
// }
// //以值作为参数传入
// void setPeople(People p1){//以值传入会调用 copy constructor
//     //do nothing
// }
 
// // void setPeople(People& p1){//以引用传入不会调用 copy constructor
// //     //do nothing
// // }

// int main()
// {
//     People p1(18);
//     cout << "p1's age " << p1.getAge() << endl;
//     // getPeople();
//     // setPeople(p1);
//     People p2 = p1;
//     // People p2(&p1);
//     // People p2(p1);
//     // cout << "p2's age " << p2.getAge() << endl;
//     return 0;
// }

// = 在初始化的时候会调用 Copy Constructor 
// 两个都已经初始化，再调用 = 就是赋值
// class People{
// private:
//     int m_age;
// public:
//     People(int age):m_age(age){
//         cout << "constructor" << endl;
//     }
 
//     People(const People& p){
//         cout << "copy constructor" << endl;
//     }
 
//     People& operator=(const People& p1){
//         cout << "assignment operator" << endl;
//         m_age = p1.getAge();  
//                 return *this;  
//     }
 
//     ~People(){
//         cout << "destructor" << endl;
//     }
//     int getAge() const{
//         return m_age;
//     }
// };

// int main()
// {
//     People p1(18);
//     cout << "p1's age " << p1.getAge() << endl;
//     People p2 = p1;
//     cout << "p2's age " << p2.getAge() << endl;
//     p2 = p1;   
//     cout << "p2's age " << p2.getAge() << endl;

//     return 0;
// }


// the left value and the right value

// 优先级队列默认是最大堆，传入仿函数



// 假设 NodePair 和 NodeContainer 已定义
// using NodePair = std::pair<int, int>;
// using NodeContainer = std::vector<NodePair>;

// int main()
// {
//     // std::function 是一个通用的函数包装器，可以存储、
//     //复制和调用任意可调用对象（如函数指针、lambda、仿函数等）

//     // function定义一个函数对象 Comp 类型为bool( , )
//     // std::function<bool(const NodePair &a1, const NodePair &a2)> Comp;

//     //                                 // 编译期操作符，用于推导表达式类型
//     //                                 // decltype(Comp)：获取Comp的类型
//     // std::priority_queue<NodePair, NodeContainer, decltype(Comp)> que(
//     //     [](const NodePair &a1, const NodePair &a2) -> bool
//     //     {
//     //         return a1.second < a2.second;
//     //     }); // 装入处理好的DefinBlock

//     // std::function<bool(const NodePair &a1, const NodePair &a2)> Comp;
//     // std::priority_queue<NodePair,NodeContainer,decltype(Comp)> que(
//     //         [](const NodePair &a1, const NodePair &a2) -> bool
//     //         {
//     //             return a1.second < a2.second;
//     //         });

//     auto comp = [](const NodePair &a1, const NodePair &a2) ->bool {
//         return a1.second <a2.second;
//     };

//     std::priority_queue<NodePair,NodeContainer,decltype(comp)> que(comp);

//     return 0;
// }

