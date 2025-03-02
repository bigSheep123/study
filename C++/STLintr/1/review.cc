#include<iostream>
#include <memory>
// #include <stack>
using namespace std;
#include<vector>
#include<algorithm>
///// 模板有类模板 和 函数模板

// template<typename T>
// class TestClass{
// public:
// // 静态成员变量 必须类外进行初始化
//     static int _data ;
// };
// // 模板实例化需要 template<>
// template<> int TestClass<int> ::_data = 1;
// template<> int TestClass<char> :: _data = 2;

// int main()
// {
//     cout<<TestClass<int>::_data <<endl;
//     cout<<TestClass<char>::_data <<endl;

//     TestClass<int> obji1, obji2;
//     TestClass<char> objc1, objc2;
//     cout << obji1._data << " " << obji2._data << endl;
//     cout << objc1._data << " " << objc2._data << endl;

//     obji1._data = 3;
//     objc2._data = 4;

//     cout << obji1._data << " " << obji2._data << endl;
//     cout << objc1._data << " " << objc2._data << endl;
// }

// 全特化就是所有的模板都是具体的类
// T* 特化允许用指针类型匹配的模式（但是也只能匹配指针类型）
// const T* 同理
// 偏特化只是一些匹配变的稍微具体了一些，但是本质上任然是templatized


// template<class I,class O>
// struct TestClass
// {
//     TestClass()
//     {
//         cout << "I , O" << endl;
//     }
// };

// // 特殊化设计 偏特化
// template <class T>
// struct TestClass<T*,T*>
// {
//     TestClass()
//     {
//         cout << "T* , T*" << endl;
//     }
// };

// template<class T>
// struct TestClass<const T*, T*>
// {
//     TestClass()
//     {
//         cout << "const T* , T*" << endl;
//     }
// };

// template<class T>
// struct TestClass<T, T>
// {
//     TestClass()
//     {
//         cout<<" T, T" <<endl;
//     }
// };

// int main()
// {
//     TestClass<int,char> obj1;
//     TestClass<int ,int > obj2;
//     TestClass<int*,char*> obj3;
//     TestClass<int*, int*> obj4;
//     TestClass<const int*,int*> obj5;
//     TestClass<const int*,const int*> obj6;
//     return 0;
// }


// class alloc{
// };

// template<class T,class Alloc = alloc>
// class vec{
// public:
//     void swap(vec<T,Alloc>&)
//     {
//         cout<<"swap()" <<endl;
//     } 
// };

// int main() {
//     vec<int> x, y;
//     swap(x, y);
// }


// // new 动态内存分配   static_cast 类型转换
// int main()
// {
//     // int * p = new int(10);
//     // cout<<*p<<endl;
//     // delete p;  // 释放内存

//     // [nodiscard] ::operator new(sizeof(int));
//     // void* raw_mem =::operator new(sizeof(int));
//     // // operator new 允许在分配内存后动手控制对象的构造

//     // //  static_cast类型转换   明确定义类型转换
//     // int* p = static_cast<int*>(raw_mem);
//     // *p = 10;
//     // std::cout<<*p;
//     // ::operator delete(raw_mem);

//     double d = 3.14;
//     int i = static_cast<int>(d);
//     cout<<i<<endl;
// }

// class Base{  
// public:
//     Base()
//     {
//         cout << "Base()" << endl;
//     }

//     virtual void Print() { cout<<"Base Print"<<endl; }
// };
// class Derived :public Base 
// {
// public:
//     Derived()
//     {
//         cout<<"Derived()" <<endl;
//     }

//     void Print() override { cout << " Derived Print"<< endl; }

//     // void Hlleo() override {}
// };

// int main()
// {
//     Derived* d = new Derived;
//     // 类层次的上行转换
//     Base* b = static_cast<Base*> (d);
//     // 多态
//     d->Print();
//     b->Print();

//     return 0;
// }

// class alloc 
// {
// public:
//     template<class T>
//     T* allocate (size_t n)
//     {
//         return static_cast<T*>(:: operator new(n*sizeof(T)));
//     }

//     template<class T>
//     void deallocate(T*p)
//     {
//         ::operator delete(p);
//     }
// };

// // alloc 类似于函数中缺省参数（默认参数） 
// template<class T,class Alloc=alloc>
// class vec{
// private:
//     T* data;
//     size_t capacity;
//     Alloc allocator;

// public:
//     vec() :data(nullptr),capacity(0) {}

//     // 必须显示调用构造函数  禁止隐式类型转换
//     explicit vec(size_t n)
//     {
//         // data = allocator.template allocate<T>(n); // 分配内存
//         // allocate 是模板成员函数，需要通过template 关键字去指明这是一个模板调用
//         data = allocator.template allocate<T>(n);
//         capacity = n;
//         for(size_t i =0; i < n; i++)
//         {
//             new (&data[i]) T();  // placement new 构造对象
//         }
//     }
// };

// void func(const vec<int>& v) { }

// int main()
// {
//     // vec<int> v = 10;  -> 隐式类型转换 vec<int> v (10);
//     // vec<int> v1(10);
//     // vec<int> v2 = vec<int> (10);  // 构造临时变量赋值给  v2
//     // 如果没有 explicit 的话， 发生了隐式类型转换： 将 10 转为 vec<int>
//     // func(10);
//     // func(vec<int> (10));
//     vec<int> v(10);
// }


// #include <iostream>
// using namespace std;

// // 默认分配器 alloc
// class alloc {
// public:
//     void log() { cout << "使用默认分配器" << endl; }
// };

// // 自定义分配器 my_alloc
// class my_alloc {
// public:
//     void log() { cout << "使用自定义分配器" << endl; }
// };

// // 模板类 vec，Alloc 的默认类型是 alloc
// template<class T, class Alloc = alloc>
// class vec {
// private:
//     Alloc allocator; // 成员变量：分配器对象
// public:
//     vec() {
//         allocator.log(); // 调用分配器的日志方法
//     }
// };

// int main() {
//     vec<int> v1;           // 输出：使用默认分配器
//     vec<int, my_alloc> v2; // 输出：使用自定义分配器
//     return 0;
// }

// #define __STL_FUNCTION_TMPL_PARTIAL_ORDER
// class alloc {
// };

// template <class T, class Alloc=alloc>
// class test{
// public:
//     void swap(test<T, Alloc>&) {
//         cout << "swap()" << endl;
//     }
// };

// template <class T, class Alloc=alloc>
// class vec {
// public: 
//     void swap(vec<T, Alloc>&) {
//         cout << "swap()" << endl;
//     }
// };
// #ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
// template <class T, class Alloc>
// inline void swap(vec<T, Alloc>& x, vec<T, Alloc>& y) {
//     x.swap(y);
//     cout << "inline swap" << endl;
// }

// #endif
// int main()
// {
//     vec<int> x, y;
//     swap(x,y);
//     test<char> a,b;
//     swap(a,b);
//     return 0;
// }

// template members of classes

// class alloc{
// };

// template<class T,class Alloc=alloc>
// class vec{
// public:
//     typedef T value_type;
//     typedef value_type* iterator;

//     template<class U>
//     void Insert(iterator pos,U f,U l)
//     {
//         cout << "Insert" << endl;
//     }
// };

// int main()
// {
//     int ia[5] = {0,1,2,3,4};
//     vec<int> x;
//     vec<int>::iterator it;
//     x.Insert(it,ia, ia+5);
//     return 0;
// }

// 编译器支持一个 template 参数 可以根据前一个 template的参数设置

// class alloc {
// };

// template <class T, class Alloc=alloc, size_t BufSiz=0>
// class deque {
// public:
//     deque() {
//         cout << "deque()" << endl;
//     }
// };

// template <class T,class Sequence = deque<T>>
// class stack
// {
// public:
//     stack() {
//         cout << "stack" << endl;
//     }
// private:
//     Sequence c;
// };

// int main()
// {
//     stack<int> x;
//     return 0;
// }

// class alloc {
// };

// inline size_t __deque_buf_size(size_t n, size_t sz) {
//     return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
// }

// template<class T,class Ref, class Ptr, size_t BufSiz>
// struct __deque_iterator
// {
//     typedef __deque_iterator<T,T&,T*,BufSiz> iterator;
//     typedef __deque_iterator<T,const T&,const T*,BufSiz> const_iterator;
//     static size_t buffer_size()
//     {
//         return __deque_buf_size(BufSiz,sizeof(T));
//     }
// };
// // BufSiz 为非类型参数
// // float class-type 内部链接对象 不可以作为非类型模板参数
// template<class T,class Alloc=alloc,size_t Buf>
// class deque{
// public:
//     // typedef __deque_iterator<T, T &, T *, BufSiz> iterator;
// };

// 匿名函数对象

// template <typename T>
// class print {
// public:
//     void operator() (const T& elem) {
//         cout << elem << ' ';
//     }
// };

// int main() {
//     int ia[6] = {0, 1, 2, 3, 4, 5};
//     vector<int> iv(ia, ia + 6);
    
//     // print<int> a;
//     // print<int>() 是一个匿名对象，不是函数调用

//     // print<int> a;
//     for_each(iv.begin(), iv.end(), print<int>());
// }

// template<class T>
// class Test{
// public:
//     static const int con_value = 10;
//     // static int value = 10;
//     // 需要类外初始化
//     static int value; 
// };

// class INT 
// {
//     friend ostream& operator<<(ostream& os,const INT& i);
// public:
//     INT(int value) :_value(value) {}

//     // 前置++
//     INT& operator++ ()
//     {
//         this->_value++;
//         return *this;
//     }

//     INT operator++(int) 
//     {
//         INT temp = *this;
//         ++(*this);
//         return temp;
//     }
// private:
//     int _value = 4;
// };

// ostream& operator<<(ostream& os,const INT& i)
// {
//     os << i._value << endl;
//     return os;
// }

// int main()
// {
//     INT a (10);
//     cout<< ++a;
//     cout<< a++;
//     cout<< a;

//     return 0;
// }

//// for_each 与 find

/// for_each 与 find

// namespace sil
// {
//     template<class InputIterator,class T>
//     InputIterator find(InputIterator first,InputIterator last,const T& value)
//     {
//         while(first!=last && *first!=value)
//             ++first;
//         return first;
//     }

//     template<class InputIterator, class Function>
//     InputIterator for_each(InputIterator first, InputIterator last, Function f)
//     {
//         while(first!=last)
//         {
//             f(*first);
//             first++;
//         }
//         return first;
//     }
// }

// template<class T>
// class MyPrint
// {
// public:
//     void operator() (const T& t)
//     {
//         cout<<t <<" ";
//     }
// };

// int main()
// {
//     vector<int> ia = {0, 1, 2, 3, 4};
//     vector<int>::iterator it = sil::find(ia.begin(), ia.end(), 4);
//     if (it!= ia.end()) {
//         cout << "Found value." << endl;
//     }
//     else {
//         cout << "Not found." << endl;
//     }

//     sil::for_each(ia.begin(), ia.end(), MyPrint<int>());
//     return 0;
// }

/// 啥是仿函数 ： 重载了函数调用符()的类或结构体，为仿函数



// #include <iostream>
// using namespace std;

// #define __STL_TEMPLATE_NULL   /* blank */

// template <class Key> struct hashes {
//     void operator() () {
//         cout << "hashes<T>" << endl;
//     }
// };

// // 以下注释编译不通过，必须遵守c++标准规格，即写出template<>
// // error: an explicit specialization must be preceded by 'template <>'

// // explicit specialization
//  template<> struct hashes<char>{
//     void operator()(){
//         cout << "hashes<char>" << endl;
//     }
// };
// // 特化类  
// template<> struct hashes<unsigned char>{
//     void operator()(){
//         cout << "hashes<char>" << endl;
//     }
// };

// int main() {
//     hashes<long> t1;
//     hashes<char> t2;
//     hashes<unsigned char> t3;

//     t1();
//     t2();
//     t3();
// }

// 编译器允许约束模板友元  则定义为 <>  
// 友元类型取决于类被初始化的时的类型，但程序必须在类外为友元提供模板定义

// class alloc {};

// template <class T, class Alloc=alloc, size_t BufSiz=0>
// class deque {
// public:
//     deque() {
//         cout << "deque" << " ";
//     }
// };

// template <class T, class Sequence>
// class stack;

// template <class T, class Sequence>
// bool operator==(const stack<T, Sequence> &x,
//                 const stack<T, Sequence> &y);

// template <class T, class Sequence>
// bool operator<(const stack<T, Sequence> &x,
//                const stack<T, Sequence> &y);

// template <class T, class Sequence = deque<T>>
// class stack 
// {
//     friend bool operator== <T> (const stack<T> &, const stack<T>&);
//     friend bool operator< <T> (const stack<T> &, const stack<T> &);

//     friend bool operator== <T> (const stack &, const stack &);
//     friend bool operator< <T> (const stack &, const stack &);

//     friend bool operator== <> (const stack &, const stack &);
//     friend bool operator< <> (const stack &, const stack &);
    
// };

// template <class T, class Sequence>
// bool operator==(const stack<T, Sequence> &x, 
//                 const stack<T, Sequence> &y) {
//     // error: cannot convert 'std::basic_ostream<char>' to 'bool' in return
//     // return cout << "operator==" << '\t';
//     cout << "operator==" << '\t';
//     return true;
// }

// template <class T, class Sequence>
// bool operator<(const stack<T, Sequence> &x, 
//                 const stack<T, Sequence> &y) {
//     // return cout << "operator<" << '\t';
//     cout << "operator<" << '\t';
//     return true;
// }

