// template<class I,class T>
// void func_impl(I iter,T t)
// {
//     T tmp;  // T是迭代器所指之物型别
// }

// template<class I>
// inline void func(I iter)
// {
//     func_impl(iter,*iter); // func的工作全部转到func_impl
// }

// int main()
// {
//     int i;
//     func(&i);
// }


// Traits编程技法----STL源代码门玥
// tralts所扮演的“特性萃取机” ， 迭代器的相应型别
// 自行以内嵌型别定义的方式定义出相应型别

// template<class I>
// struct iterator_traits{
//     typedef typename I::value_type value_type;
// };

// template<class T>
// struct iterator_traits<T*>
// {
//     typedef T value_type;
// };

// template<class T>
// struct  iterator_traits<const T*> // 偏特化版--当迭代器是个pointer-to-const时
// {                                 // 萃取出来的类型应该是T而非const T
//     typedef T value_type; 
// };


// template<class I>
// typename iterator_traits<I>::value_type 
// func(I ite)
// {return *ite;}

// traits 可以拥有特化版本


template<class I>
struct  iterator_traits{
    typedef typename I::iterator_category iterator_category;
    typedef typename I::value_type value_type;
    typedef typename I::difference_type diffrernce_type;  // 两个迭代器之间的距离
    typedef typename I::pointer pointer;
    typedef typename I::reference reference;
};

template<class I,class T>
typename iterator_traits<I>::diffrernce_type 
count(I first,I last, const T& value){
    typename iterator_traits<I>::diffrernce_type n = 0;
    for(;first != last; ++first)
    {
        ++n;
    }

    return n;
}

// 不可变所指对象之内容，constant iterators  const int* pic
//  可变所指对象之内容，mutable iterators   int *pi

// pointers and refrernces 

//  Item& reference type   Item* pointer type
// Item& operator*() const { return *ptr;}
// Item* operator->() const {return ptr;}


// 针对原生指针而设计的 "偏特化版" 
// const 
template<class T>
struct  iterator_traits<T*>
{
    typedef T* pointer;
    typedef T& reference;
};

// iterator_category 移动特性与施行操作

// Input iterator ： 不允许外界改变 （read only）
// output iterator （write only）
// Forward iterator: 允许 “写入型”算法在此中迭代器所形成的区间上进行读写操作
// Bidirectional iterator: 可双向移动
// Random Access Iterator 

// advance()

template<class InputIterator,class Distance>
void advance_II(InputIterator& i, Distance n)
{
    while(n--)
        ++i;
}

template <class BidirectionalIterator,class Distance>
void advance_BI(BidirectionalIterator& i, Distance n)
{
    if( n >= 0)
        while(n--)  ++i;
    else 
        while(n++)  --i;
}

// 函数重载机制



// traits有能力萃取出迭代器的种类，便可以利用“迭代器类型”相应型别作为advanced()参数

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag {};
struct bidirectional_iterator_tag {};
struct random_access_iterator_tag {};

// classes 用作标记用，不需要任何成员。