// template 是C++关键字
// void foo(int a);
// 定义模板类，T是模板的精髓，可以通过指定模板实参，将T替换成所需类型

// 通过模板参数替换类型，可以获得很多形式相同的新类型，有效减少代码量
// “泛型”

// 通过类型绑定将模板类变成“普通的类”的过程，称之为模板实例化
// Template Instantiate

/// 模板类的成员函数定义

// template<typename T>
// class vector
// {
// public:
//     void clear();
// private:
//     T* elements;
// };

// // 实现成员函数的时候，必须提供模板参数
// // vector 在语法上类似于特化/偏特化

// template<typename T>
// void vector<T>::clear()
// {

// }

// template function
// 类型被当作了参数，导致代码中可以变化更多的部分了

// 1.函数或者类里，我们用标识符代替变化的地方，就是模板参数
// 2.在需要类型的地方，写上对应的标识符

// 代码的可变，在代码编译好之后就固定下来了，称之为编译期的可变性

// 我的需求能不能用模板来解决
// 怎么解决  把解决方案用代码写出来

// 模板函数的使用

// float data[1024];

// // 编译器没办法去根据返回值推断类型
// template<typename T> T GetValue(int i)
// {
//     return static_cast<T>(data[i]);
// }

// int main()
// {
//     float a = GetValue<float>(0);
// }

// 编译器对模板参数的顺序是有限制的：
// 先写需要指定的模板参数，再把能推导出的模板参数放后面

// template<typename D,typename S> D c_style_cast(S tmp)
// {  return (D)(tmp);   }

// int main()
// {
//     int v = 0;
//     float i = c_style_cast<float> (v);
// }

// 整型也可是Template参数
// 整型

// template<typename T,int Size> struct  Array
// {
//     T data[Size];
// };

// Array<int,16> arr;

// 模板的匹配是在编译时完成的，所以实例化模板的时候使用的参数
// 也必须在编译期确定

// #include <cstdint>
// template<int i> class A
// {
// public:
//     void foo(int)
//     {

//     }
// };

// template <float a> class E{};

// template<uint8_t a, typename b,void* c> class B{};
// template<bool,void (*a)()> class C{};
// template<void (A<3>::*a)(int)> class D{};

// template <int i> int Add(int a)
// {
//     return a + i;
// }

// void foo()
// {
//     A<5> a;
//     B< 7 , A<5>, nullptr > b;  // 模板参数可以时一个无符号八位整数，可以是模板生成的类，可以是一个指针
//     C<false,&foo> c;

//     D<&A<3>::foo>   d;

//     int x = Add<3> (5);
// }

// 模板的匹配规则
// 模板元编程基础

// 答案是 “抽象”，具体手段，无外乎 “求同”， “存异”
// 概括一般规律，处理特殊情况。 软件工程所追求的目标

// 元编程
// 元编程中所有的变化的量（元编程的参数），都是类型，那么这样的
// 编程，我们称之为“泛型”

// 模板会在分析模板时以及实例化模板时进行检查

// 模板可运算

// #include <cassert>
// #include <iostream>
// struct Variant
// {
//     union
//     {
//         int x;
//         float y;
//     } data;
//     uint32 typeId;
// };

// Variant addFloatOrMulInt(Variant const* a, Variant const* b)
// {
//     Variant ret;
//     assert(a->typeId == b->typeId);
//     if (a->typeId == TYPE_INT)
//     {
//         ret.x = a->x * b->x;
//     }
//     else
//     {
//         ret.y = a->y + b->y;
//     }
//     return ret;
// }

// int main()
// {
//     Variant * a,* b;
//     a->typeId = 1;
//     b->typeId = 2;
//     a->data.x = 1;

//     Variant c;
//     c = addFloatOrMulInt(a,b);
//     std::cout << c.typeId <<std::endl;
// }

//         // int/float
// #define BIN_OP(type, a, op, b, result) (*(type *)(result)) \
//  = (*(type const *)(a)) op (*(type const*)(b))

// void doDiv(void* out, void const* data0, void const* data1, DATA_TYPE type)
// {
//     if(type == TYPE_INT)
//     {
//         BIN_OP(int, data0, *, data1, out);
//     }
//     else
//     {
//         BIN_OP(float, data0, +, data1, out);
//     }
// }

// 和typeid 同属于 RTTI 机制的dynamic_cast

// IAnimal* animal = GetAnimalFromSystem();

// IDog* maybeDog = dynamic_cast<IDog*>(animal);
// if(maybeDog)
// {
//     maybeDog->Wangwang();
// }
// ICat* maybeCat = dynamic_cast<ICat*>(animal);
// if(maybeCat)
// {
//     maybeCat->Moemoe();
// }

// 编译器就能确定的东西

// 你运用了模板来实现，当传入两个不同类型的变量，编译器就会报错
// 你没办法根据用户输入或者别的什么在运行期间可能发生的变化的量来决定它的产生
// 或执行什么代码

// #include <iostream>
// template <int i, int j>
// int foo() { return i + j; }
// int main()
// {
//     int x = 1;
//     int y = 10;
//     // std::cin >> x >> y;
//     return foo<x, y>();
// }

// 模板所能做的事情都是编译期完成的，编译期完成的意思是，
// 当你编译一个程序的时候，所有的量就都已经确定了

// int main()
// {
//     int a = 3, b = 5;
//     Variant aVar, bVar;
//     aVar.setInt(a); // 我们新加上的方法，怎么实现的无所谓，大家明白意思就行了。
//     bVar.setInt(b);
//     Variant result = addFloatOrMulInt(aVar, bVar);

//     return 0;
// }

// 在模板代码中，合适的机制就是 “特化” 和 “部分特化（Partial Specialization）”，也就是偏特化

// 对不同的int / float 类型可能执行的代码有区别

//将两个内容不同，但模板参数形式相同的类进行区分  特化 （specialization）

// template<typename T> class AddFloatOrMulInt;

// // class AddFloatOrMulInt<int>

// template<> class AddFloatOrMulInt<int>;

// #include <cstdint>
// #include <iostream>
// template<typename T> class TypeToID
// {
    
// public:
//     static int const ID = -1;
// };

// template<> class TypeToID<uint8_t>
// {
// public:
//     static int const ID = 0;
// };

// template<> class TypeToID<uint16_t>
// {
// public:
//     static int const ID = 1;
// };

// template<> class TypeToID<uint32_t>
// {
// public:
//     static int const ID = 2;
// };

// template<> class TypeToID<uint64_t>
// {
// public:
//     static int const ID = 3;
// };

// template<> class TypeToID<float>
// {
// public:
//     static int const ID = 4;
// };

// template<> class TypeToID<void*>
// {
// public:
//     static int const ID = 5;
// };

// <> 只要里面填入的是一个C++能解析的合法类型，模板都能让我们特化

// 当模板实例化提供的模板参数不能匹配到任何的特化形式的时候
// 就会去匹配类模板 “原型”形式

// 与继承不同，类模板的“原型”和它的特化类在实现上是没用关系的

// 类模板和类模板的特化的作用，

// C++有了模板后，既能匹配任意类型的指针，同时又保留类型信息

// C语言由于没用泛型的概念，它提供了无类型指针 void* 
// 可能有些struct需要深拷贝，所以用到特殊的copy函数

// #include<iostream>
// template<typename T> class TypeToID
// {
    
// public:
//     static int const ID = -1;
// };

// template <typename T> 
// class TypeToID<T*> 
// {
// public:
//     typedef T  SameAsT;
//     static int const ID = 0x00000000;
// };

// void PrintID()
// {
//     std::cout << "ID of float*: " << TypeToID< TypeToID<float*>::SameAsT >::ID <<std:: endl;
// }

// int main()
// {
//     PrintID();
//     return 0;
// }

// #include<iostream>
// template<typename T>
// class RemovePointer 
// {

// };

// template<typename T>
// class RemovePointer<T*>  
// {
// public:
//     typedef T Result;
// };

// void Foo()
// {
//     RemovePointer<float*>::Result x = 5.05f;
//     std::cout << x << std::endl;
// }

// int main()
// {
//     Foo();
// }

// 模板是从最特殊到最一般形式进行匹配的

// 编译器什么时候对模板进行推导，推导到什么程度

// template <typename T> struct X {};

// template <typename T> struct Y
// {
//     typedef X<T> ReboundType;                        // 类型定义1
//     typedef typename X<T>::MemberType MemberType;    // 类型定义2
//     // typedef UnknownType MemberType3;                // 类型定义3

//     void foo()
//     {
//         X<T> instance0;
//         typename X<T>::MemberType instance1;
//         // WTF instance2
//     }
// };


// Two phase name lookup

// 名称查找会在模板定义和实例化各做一次，处理非依赖性名称和依赖性名称的查找
// 两阶段名称查找

// 在语义没用确定之前，连语法都没有分析的价值


// struct A;
// template <typename T> struct X {
//     int v;
//     void convertTo(A& a);
// };
// // 符合标准的写法需要将模板类的定义和模板函数的定义分离开
// struct A { int v; };

// template <typename T> void X<T>::convertTo(A& a) {
//    a.v = v;
// }

// int main() {
//     X<int> x;
//     x.foo(5);
// }

// 如果编译器能在出现的时候知道它的类型，那么就不需要typename，如果必须要
// 到实例化的时候才能知道它是不是合法，定义的时候就把这个名称作为变量而不是类型。 