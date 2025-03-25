#include <iostream>

// release()释放指针的所有权但不销毁对象
// reset()释放当前管理的对象并销毁它
template <class T>
class auto_ptr
{
public:
    explicit auto_ptr(T *p = 0) : pointer(p) {}

    template <class U>
    auto_ptr(auto_ptr<U> &rhs) : pointer(rhs.release()) {}

    ~auto_ptr()
    {
        delete pointer;
    }

    template <class U>
    auto_ptr<T> &operator=(auto_ptr<U> &rhs)
    {
        if (this != &rhs)
            // release()：仅放弃当前指针所有权，返回该指针供其他指针接管
            this->reset(rhs.release());
        return *this;
    }

    T &operator*() const
    {
        return *pointer;
    }
    T *operator->() const
    {
        return pointer;
    }
    T *get() const
    {
        return pointer;
    }

private:
    T *pointer;
};

int main()
{
    auto_ptr<int> p(new int(10));
    std::cout << *p << std::endl;
    std::cout << p.get() << std::endl;
    std::cout << p.operator->() << std::endl;

    return 0;
}