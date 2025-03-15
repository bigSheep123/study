// C++ copy constructor
#include<iostream>
using namespace std;
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

