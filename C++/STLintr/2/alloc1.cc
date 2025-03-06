// allocator 里面有各种 type
// SGI-STL 的配置器

#include<vector>
using namespace std;
#include<iostream>

// int main()
// {
//     // gcc
//     // vector<int,std::alloca> iv; 
// }

class Foo {};

int main()
{
    Foo* pf = new Foo;
    // new 实际操作是， ::operator new 配置内存 
    // Foo::Foo() 构造对象内容
    delete pf;
}

// 