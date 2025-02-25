#include<iostream>
using namespace std;
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

#include <iostream>
using namespace std;

class alloc {
public:
    template<class T>
    T* allocate(size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    template<class T>
    void deallocate(T* p, size_t) {
        ::operator delete(p);
    }
};

template<class T, class Alloc = alloc>
class vec {
private:
    T* data;         // 指向动态数组的指针
    size_t capacity; // 当前分配的容量
    Alloc allocator; // 分配器对象

public:
    // 默认构造函数
    vec() : data(nullptr), capacity(0) {}

    // 带初始容量的构造函数
    explicit vec(size_t n) {
        data = allocator.template allocate<T>(n); // 分配内存
        capacity = n;
        // 构造对象（此处简化，假设 T 是默认构造的）
        for (size_t i = 0; i < n; ++i) {
            new (&data[i]) T(); // placement new 构造对象
        }
    }

    // 析构函数
    ~vec() {
        if (data) {
            // 析构所有对象
            for (size_t i = 0; i < capacity; ++i) {
                data[i].~T();
            }
            // 释放内存
            allocator.deallocate(data, capacity);
        }
    }

    // 交换两个 vec 的内容
    void swap(vec<T, Alloc>& other) {
        std::swap(data, other.data);
        std::swap(capacity, other.capacity);
        cout << "swap()" << endl;
    }
};

int main() {
    vec<int> v1(3);  // 创建一个容量为 3 的 vec<int>，使用默认的 alloc
    // vec<int> v2;
    // v1.swap(v2);     // 输出 "swap()"
    return 0;
}