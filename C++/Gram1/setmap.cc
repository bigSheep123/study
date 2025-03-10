/// C++ 中 set 与 map

/// 1. pair 
#include <utility>
#include <string>
#include<set>
int main()
{
    // int a = 10;
    // std::string str = "apple";
    // auto it = std::make_pair(1,str);

    // map 本身是 key 和 value的一个映射，key 和 value可以选择任意数据类型

    // map会自动对相同键值去重，count 会告诉你这个元素是否出现过
    // 计算元素出现次数可以使用multimap
    // find()，返回指向所查找元素的迭代器，没有就返回map尾部的迭代器

    // map自动按key值从小到大排序
    std::set<int,std::string> set;
}