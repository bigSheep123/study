// class template explicit specialization
#include <functional>
#include <iostream>
using namespace std;
#include<vector>
// #include<algorithm>


// #define __STL_TEMPLATE_NULL template<>

// template<class Key> 
// struct  hashes{
//     void operator() (){
//         cout<<"hashes<T>"<<endl;
//     }
// };

// // explicit specialization
// template<>
// struct hashes<char>{
//     void operator()(){
//         cout << "hashes<char>" << endl;
//     }
// };

// __STL_TEMPLATE_NULL 
// struct hashes<unsigned char>{
//     void operator()(){
//         cout << "hashes<unsigned char>" << endl;
//     }
// };

// int main()
// {
//     hashes<long> t1;
//     hashes<char> t2;
//     hashes<unsigned char> t3;

//     t1();
//     t2();
//     t3();

//     return 0;
// }


///// 临时对象的产生和运用
// 创建临时对象会造成效率上的负担   刻意制造临时对象，使得程序干净整洁
// 仿函数（functor）与 算法的 搭配

// template<typename T>
// class print{
// public:
//     void operator() (const T& elem)
//     {
//         cout<<elem<<" ";
//     }
// };

// int main()
// {
//     int ia[6] = {0,1,2,3,4,5};
//     vector<int> iv(ia,ia+6);

//     print<int> a;
//     for_each(iv.begin(),iv.end(),a);
// }

// 静态常量整数成员在class 内部直接初始化

// template<typename T>
// class TestClass{
// public:
//     static const int _datai = 5;
//     static const long _datal = 3L;
//     static const char _datac = 'c';
//     static int a;
// };

// template<>
// int TestClass<int>::a = 0;

// template<>
// int TestClass<char>:: a = 20;

// int main()
// {
//     cout<<TestClass<int>::a<<endl;
//     cout<<TestClass<char>::a<<endl;

//     return 0;
// }

// class INT{
//     friend ostream &operator<<(ostream &os,const INT &i);
// public:
//     INT(int i) :m_i(i) {}

//     // 前置++，返回原对象
//     INT& operator++()
//     {
//         ++(this->m_i);
//         return *this;
//     }

//     // 后置++   i++  ++i  
//     INT operator++(int)  //int 这里是占位符
//     {
//         INT tmp = *this;
//         ++(this->m_i);
//         return tmp;
//     }

//     INT& operator--()
//     {
//         --(this->m_i);
//         return *this;
//     }

//     INT operator--(int)
//     {
//         INT tmp = *this;
//         --(this->m_i);
//         return tmp;
//     }

//     // const 后置修饰函数表示为常函数，不能修改成员变量
//     int& operator*() const
//     {
//         return (int&)m_i;
//         // 将 const int 转化为 non-const ivalue 
//         // 如果没有转换的化，会出错
//     }

// private:
//     int m_i;
// };

// ostream &operator<<(ostream &os,const INT &i)
// {
//     os << "[" << i.m_i << "]" <<endl;
//     return os;
// }

// int main()
// {
//     INT I(5);
//     cout<<I++;
//     cout<<I--;
//     cout<<++I;
//     cout <<--I;
//     cout<<(*I);

//     return 0;
// }


//////// 前闭后开区间表示法 （）
/// 泛型指针  first 开始   last - 1

// namespace sil{
//     template<class InputIterator,class T>
//     InputIterator find(InputIterator first,InputIterator last,const T& value)
//     {
//         while(first!=last && *first != value)
//         {
//             ++first;
//         }

//         return first;
//     }

//     template<class InputIterator,class Function>
//     InputIterator for_each(InputIterator first,InputIterator last,Function f)
//     {
//         for(;first !=last;first++)
//         {
//             f(*first);
//         } 

//         return first;
//     }
// }

// template <class T>
// class MyPrint
// {
// public:
//     void operator() (const T& t)
//     {
//         cout << t <<" ";
//     }
// };

// int main()
// {
//     vector<int> ia = {1,2,3,4,5};
//     vector<int>:: iterator it = sil::find(ia.begin(),ia.end(),4);
//     if(it != ia.end())
//     {
//         cout<<"Found value." << endl;
//     }
//     else
//     {
//         cout<<"Not found. "<< endl; 
//     }

//     sil::for_each(ia.begin(),ia.end(),MyPrint<int>());
// }

// 针对某个类class 进行 operator()重载，它就成为了一个仿函数

// namespace sil
// {
//    template<class T>
//    struct plus
//    {
//         T operator() (const T& x, const T& y) const
//         {
//             return x+y;
//         }
//    };

//    template<class T>
//    struct minus
//    {
//         T operator() (const T&x,const T& y) const
//         {
//             return x-y;
//         }
//    };
   
// } // namespace sil


// int main()
// {
//     sil::plus<int> plusobj;
//     sil::minus<int> minusobj;

//     cout <<plusobj(2,3)<<endl;
//     cout<<minusobj(2,3)<<endl;

//     cout<<sil::plus<int>() (3,5) <<endl;
//     cout<<sil::minus<int>() (3,5) <<endl;

//     return 0;
// }