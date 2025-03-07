// 智能指针
// 内存泄露， new 没有 delete释放内存
// unique_ptr
    // std::unique_ptr<A> a(new A());
    // a->do_something();

    // if(open)
    // {
    //     // 不再需要手动释放内存
    //     return;
    // }

    // // 不再需要手动释放内存
    // return;

    // std::unique_ptr<A> a1(new A());
    // // std::unique_ptr的拷贝构造函数被删除，不允许进行拷贝操作
    // // 智能指针有一个通用的规则，-> 表示用于调用指针原有的方法
    // // . 表示调用智能指针本身的方法
    // std::unique_ptr<A> a2 = std::move(a1);
    // a1->do_something();
    // a2->do_something();
    // std::cout<<a1.operator bool()<<std::endl;
    // std::cout<<a2.operator bool()<<std::endl;

    // release()释放所管理的指针的所有权，返回原生指针，但并不销毁原生指针
    // reset()释放并且销毁原生指针，要是有一个参数，那么参数将管理这个新指针
    // return 0;

    // std::unique_ptr<A> a1(new A());
    // get()尽量不要使用

// shared_ptr
    // //shared_ptr 强调的是共享所有权
    // // 也就是说多个share_ptr可以拥有同一个原生指针的所有权

    // std::shared_ptr<A> a1(new(A));
    // std::shared_ptr<A> a2 = a1;
    // // shared_ptr 强调共享所有权，引用计数的方式管理指针
    // //当引用计数为0时，会销毁拥有的原生对象
    // std::cout << a2.use_count() << std::endl;


#include <memory>
#include<iostream>
// class A
// {
// public:
//     void do_something() {
//         std::cout<<"do some things"<<std::endl;
//     }
// };

// void test_unique_ptr(bool open)
// {   
//     // weak_ptr存在的意义是为了解决shared_ptr通过引用计数来管理原生指针的
//     // 引用循环的一方改成弱引用
//     std::shared_ptr<A> a1(new A());
//     std::weak_ptr<A> weak_a1 = a1;//不增加引用计数
//     std::cout<<weak_a1.use_count()<<std::endl;
// }

// int main()
// {
//     test_unique_ptr(true);
//     return 0;
// }

// unique_ptr 所持有对象智能通过转移语义将所有权转移到另一个unique_ptr


// unique_ptr 使用场景
// 不需要多个指向同一个对象的指针时使用
// 对象内部或方法内部优先使用 unique_ptr

class A
{
public:
    void do_something() {
        std::cout<<"do some things"<<std::endl;
    }
};

// class TestUnique
// {
// private:
//     std::unique_ptr<A> a_ = std::unique_ptr<A>(new A());
// public:
//     void process1()
//     {
//         a_->do_something();
//     }

//     void process2()
//     {
//         a_->do_something();
//     }

//     ~TestUnique()
//     {
//         //此处不再需要手动删除a_
//     }
// };

// shared_ptr 需要多个执行同一个对象的指针使用
// 这个对象需要被多个Class同时使用的时候

// make_shared（）可以避免new的时候导致出现两次内存申请

// 在B，C中定义了A，而在A中如果定义B,C则会导致循环引用

// 如果想要A内部将当前对象的指针共享给其他对象
// 采用this指针不行，重新创建的shared_ptr与当前对象的shared_ptr无关
// shared_from_this()

// 1.使用了智能指针，尽量不再使用原生指针
// 2.不要把一个原生指针交给多个指针指针管理
// 3.不要get
// 4.不要 this构造指针
// 5.指针指针时管理堆对象的




