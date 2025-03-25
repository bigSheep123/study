#include "muylist_iter.h"

using namespace std;

// 以上实现看出，为了完成一个针对List而设计的迭代器，我们暴露了太多的List实现细节
// 在 main() 之中为了制作 begin 和 end，我们暴露了 ListItem，在ListIter class
// 中也暴露了 next()操作函数 ，因此将迭代器交给List的设计者
// STL容器中都有专属迭代器的缘故

// 如果不写全局比较函数，则需要更改find函数判定
template <typename T> bool operator!=(const ListItem<T>& item, T n) { 
    return item.value() != n; 
} 

int main() {
    List<int> mylist;
    

    for (int i = 0; i < 5; ++i) {
        mylist.insert_front(i);
        mylist.insert_end(i + 2);
    }

    mylist.display();

    ListIter<ListItem<int>> begin(mylist.front());
    ListIter<ListItem<int>> end;
    ListIter<ListItem<int>> iter;
    iter = find(begin, end, 3);
    if (iter == end)
        cout << "not found" << endl;
    else
        cout << "found. " << iter->value() << endl;

    iter = find(begin, end, 7);
    if (iter == end)
        cout << "not found" << endl;
    else
        cout << "found. " << iter->value() << endl;
}