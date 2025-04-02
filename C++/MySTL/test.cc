#include "Myvector.h"
#include <iostream>
using namespace Myvector;

int main()
{
    vector<int> v;
    v.push_back(10);
    // std::cout << v.size() << std::endl;
    // std::cout << v.capacity() << std::endl;
    v.push_back(20);
    // std::cout << v.size() << std::endl;
    // std::cout << v.capacity() << std::endl;
    v.push_back(30);
    // std::cout << v.size() << std::endl;
    // std::cout << v.capacity() << std::endl;
    vector<int> v2 = v;
    // v2.operator=(v);
    std::cout << &v2 <<std::endl;
    std::cout << &v <<std::endl;
    for(auto& e : v2)
    {
        std::cout << e << std::endl;
    }

    return 0;
}