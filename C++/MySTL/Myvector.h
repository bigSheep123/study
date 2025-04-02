#include <cstring>
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
        vector(size_type n)
            : vectorBase<_Tp>(n)  {}
        vector() = default;

        // this-> 指针明确告诉属于基类
        iterator begin() { return this->_start;}

        iterator end() { return this->_finish;}

        const_iterator begin() const { return this->_start; }
        const_iterator end() const { return this->_finish; }

        size_type size() const 
        {
            return size_type( end() - begin() );
        }

        void push_back(const value_type value)
        {
            if(this->_end_of_storage - this->_finish == 0)
            {
                MLLOCA();
            }
            *this->_finish = value;
            this->_finish++; 
        }

        size_type capacity()
        {
            return (size_type)(this->_end_of_storage - this->begin());
        }

        reference operator[](size_type _n) 
        {
            return *(this->_start + _n);
        }

        vector<_Tp>& operator=(const vector<_Tp>& __x);

        bool is_empty()
        {
            return this->_start == this->_finish;
        }
    private:
        void MLLOCA()
        {
            size_type old_capacity = capacity();
            size_type new_capacity = old_capacity != 0 ? old_capacity * 2 : 2;
            value_type *tmp = new value_type[new_capacity];
            if(this->_start)
                memcpy(tmp, this->_start, old_capacity *sizeof(value_type));
            this->_start = tmp;
            this->_finish = tmp + old_capacity;
            this->_end_of_storage = tmp + new_capacity;
        }
    };

    template <typename _Tp>
    vector<_Tp>& vector<_Tp>::operator=(const vector<_Tp>& x)
    {
        vector<_Tp> vec(x.capacity());
        memcpy(vec->_start, x.begin(), x.size()*sizeof(value_type));
        return vec;
    }

};
