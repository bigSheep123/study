#include <memory>
namespace Myvector{

    template<typename _Tp>
    class vectorBase
    {
    public:
        vectorBase()
        :_start(0),_end_of_storage(0),_finish(0) {}

        vectorBase(size_t n)
        { 
            _Tp* tmp = new _Tp[n];
            _start = tmp;
            _finish = tmp + n;
            _end_of_storage = _finish;
        }  

        ~vectorBase()
        {
            delete[] _start;
        }
    // protected:
        _Tp* _start;
        _Tp* _finish;
        _Tp* _end_of_storage;
    };

    template<typename _Tp>
    class vector:public vectorBase<_Tp>
    {
    public:
        typedef _Tp value_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef value_type* iterator;
        typedef const value_type* const_iterator;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef size_t size_type;

    public:
        iterator begin() { return _start;}

        iterator end() { return _finish;}
        size_type size() const 
        {
            return size_type(end()-begin());
        }

        vector(size_type n)
            :vectorBase(n)
            {} 
        vector() = default;
    };
};