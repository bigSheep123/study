#ifndef __JJALLOC
#define __JJALLOC

#include <climits>
#include<iostream>
#include <new>
using namespace std;

namespace JJ{
    // void handler(){}

    template<class T>
    inline T* _allocate(ptrdiff_t size,T* )
    {
        set_new_handler(0);
                  //调用全局的 operator new函数      //size_t 是标准的内存分配函数的参数类型   //  size * sizeof(T)计算需要分配的内存总字节数
        T* tmp =(T*)(::operator new((size_t)(size* sizeof(T))));
        if(tmp == nullptr){
            cerr << "out of memory" << endl;
            exit(1);
        }

        return tmp;
    }

    // 归还内存先前配置的空间
    template<class T>
    inline void _deallocate(T* buffer)
    {
        ::operator delete(buffer);
    }
    
    // 等同于 new(const void*) p  
    template<class T1, class T2>
    inline void _construct(T1* p,const T2& value){
        new (p) T1(value);
    }

    template<class T>
    inline void _destroy(T* ptr){
        ptr->~T();
    }    

    template<class T>
    class allocator{
    public:
        typedef T  value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;  //ptrdiff_t 用于表示指针之间的差值，指针相减的结果

        // 重新绑定分配器，使其能够为类型U分配内存
        template <class U>
        struct rebind{
            typedef allocator<U> other;
        };

        pointer allocate(size_type n, const void* hint=0){
            return _allocate((difference_type)n,(pointer)(0));
        }

        void deallocate(pointer p,size_type n){
            _deallocate(p);
        }

        void construct(pointer p,const T& value){
            _construct(p,value);
        }

        void destroy(pointer p){
            _destroy(p);
        }

        // 传回某个对象的地址。 a.address(x)  ==  &x
        pointer address(reference x){
            return (pointer)&x;
        }

        const_pointer const_adress(const_reference x){
            return (const_pointer)&x;
        }

        size_type max_size() const{
            return size_type(UINT_MAX /sizeof(T));
        }
    };
}


#endif
