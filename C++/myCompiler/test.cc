#include <cassert>
#include<iostream>
// class A 
// {
// public:
//     virtual void run() = 0;
// };

// class B :public A 
// {
// public:
//     void run() override { std::cout<<"hello " <<std::endl; }
// };

// int main()
// {
//     // A a;
//     B a;
//     a.run()
// }

// int main()
// {
//     int* p = nullptr;
//     // 断言是在检查，检查它是不是
//     assert(p != nullptr);
//     return 0;
// }

// dynamic_cast  和 static_cast 的区别
// static  编译时检查    dynamic 运行时检查
//  需要编译者自己知道      基类指针--->  派生类指针

// class User {};

// class Instruction : public User {
// public:
// //   virtual ~Instruction() = default; // 添加虚析构函数
//   // ... 其他成员
// };

// class StoreInst :public Instruction
// {

// };

// void Test(Instruction* inst) {}

// int main()
// {   
//     // Instruction* it =
//     StoreInst* sT;
//     Instruction* it = static_cast<Instruction*> (sT);
//     Test(sT);
// }

// virtual 关键字 声明的函数叫 虚函数
// 存在虚函数的类都存在一个一维的虚函数表叫做虚表，类的对象有一个指向虚表开始的虚指针 虚表与类对应，虚指针与对象对应

// #include "stdafx.h"
// #include <iostream>
// #include <stdlib.h>
// using namespace std;

// class Father
// {
// public:
//     void Face()
//     {
//         cout << "Father's face" << endl;
//     }

//     virtual void Say()
//     {
//         cout << "Father say hello" << endl;
//     }
// };


// class Son:public Father
// {
// public:
//     void Say()
//     {
//         cout << "Son say hello" << endl;
//     }
// };

// class SonSon :public Son
// {
// public:
//     void Say()
//     {
//         cout<<"sONSON say hello" <<endl;
//     }
// };

// int main()
// {
//     // Son son;
//     // Father *pFather=&son; // 隐式类型转换
//     // // 我们构造son类的对象时，先调用 father类的构造函数去构造father类的对象，然后才调用son类的构造函数完成自身部分的构造
//     // pFather->Say();
//     SonSon sonson;
//     Father* pFather = &sonson;
//     pFather->Say();
// }

/// 前面输出的结果是因为编译器在编译的时候，就已经确定了对象调用的函数地址
/// 晚绑定， virtual，虚函数
/// 一旦某个函数在基类中声明为virtual ，那么所有的派生类中该函数都是birtual，而不需要显式地声明virtual

// 编译器在编译时，发现father类中有虚函数，此时编译器会为每个包含虚函数的类创建一个虚表（vtable）

/// 虚表指针 vptr ，这个指针指向对象所属类的虚表
/// 虚函数放在虚表里面，   虚表指针可以用来索引虚函数
/// 虚表的创建和虚表指针的初始化   在构造子类对象时，要先调用父类的构造函数，此时编译器只知道了父类，并不知道后面的继承者，初始化
/// 父类对象的虚表指针，该虚表指针指向父类的虚表，当执行子类的构造函数时，子类对象的虚表指针被初始化，指向自身的虚表


// #include <iostream>
// #include <stdlib.h>
// using namespace std;

// class CA
// {
// public:
//     void f()
//     {
//         cout << "CA f()" << endl;
//     }
//     virtual void ff()
//     {
//         cout << "CA ff()" << endl;
//         f();
//     }
// };

// class CB : public CA
// {
// public :
//     virtual void f()
//     {
//         cout << "CB f()" << endl;
//     }
//     void ff()
//     {
//         cout << "CB ff()" << endl;
//         f();
//         CA::ff();
//     }
// };
// class CC : public CB
// {
// public:
//     virtual void f()
//     {
//         cout << "C f()" << endl;
//     }
// };

// int main()
// {
//     CB b;
//     CA *ap = &b;
//     CC c;
//     CB &br = c;
//     CB *bp = &c;

//     ap->f();
//     cout << endl;

//     b.f();
//     cout << endl;

//     br.f();
//     cout << endl;

//     bp->f();
//     cout << endl;

//     ap->ff();
//     cout << endl;

//     bp->ff();
//     cout << endl;

//     return 0;
// }

// class A
// {
// public:
//     virtual void print() {};
// };
// class B :public A
// {
// public:
//     // void print() {};
// };

// int main()
// {
// 	A * b = new B;
// 	B * c = dynamic_cast<B*>(b);
// 	return 0;
// }
// dynamic_cast 要求操作数必须是多态类型的，即实现中必须带有virtual函数
// 这个太tmd关键了

// s -> d  如果没有父子关系，返回结果就是null
// 子类到父类，这是必然成功的
// 父类到子类，依赖于父类指针是否真实的指向了对象的子类型，标示这是不是一个真实的子类对象

//对象的type_info被存在了虚表的首部，所以要使用dynamic_cast，对象必须有多态，然后运行时期比对要转换的类型是否和type_info中记录的类型相同即可。


#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['z']=50;
  mymap['d']=200;
  mymap['b']=100;
  mymap['c']=150;

  it = mymap.find('b');
  if (it != mymap.end())
    std::cout <<it->second << std::endl;

//   // print content:
//   std::cout << "elements in mymap:" << '\n';
//   std::cout << "a => " << mymap.find('a')->second << '\n';
//   std::cout << "c => " << mymap.find('c')->second << '\n';
//   std::cout << "d => " << mymap.find('d')->second << '\n';

// 自动排序的  按照key值进行排序  first -> key   second -> value
	for(auto e:mymap)
	{
		std::cout <<e.first<<' '<<e.second <<std::endl;
	}

  return 0;
}