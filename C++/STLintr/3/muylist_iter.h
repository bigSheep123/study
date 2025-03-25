#include "mylist.h"

template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& value) {
    // 修改*first!=value
    while (first!=last && *first!=value)
    // while (first!=last && (*first).value()!=value)
        ++first;
    return first;
}

template <class InputIterator, class Function>
InputIterator for_each(InputIterator first, InputIterator last, Function f) {
    for (; first != last; ++first)
        f(*first);
    return first;
}


template<class Item>
struct ListIter
{
    Item* ptr;

    ListIter(Item* p = nullptr) : ptr(p) {}

    Item& operator*() const {
        return *ptr;
    }

    Item* operator->() const {
        return ptr;
    }

    ListIter& operator++(){
        ptr = ptr->next();
        return *this;
    }

    ListIter operator++(int){
        ListIter tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator==(const ListIter& i) const {
        return ptr == i.ptr;
    }

    bool operator!=(const ListIter& i) const {
        return ptr != i.ptr;
    }
};