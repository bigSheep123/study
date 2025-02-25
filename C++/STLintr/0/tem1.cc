// bound friend templates
#include<iostream>
#include<cstddef>
using namespace std;

class alloc{
};

template<class T,class Alloc=alloc,size_t BufSiz = 0>
class deque{
public:
    deque(){
        cout<<"deque"<<" ";
    }
};

template <class T,class Sequence>
class stack;

template<class T,class Sequence>
bool operator==(const stack<T,Sequence> &x,const stack<T,Sequence> &y);

template<class T,class Sequence>
bool operator<(const stack<T,Sequence> &x,const stack<T,Sequence> &y);

// template<class T>
// bool operator==(const stack<T>&, const stack<T>&);

template<class T,class Sequence = deque<T>>
class stack
{
    // friend bool operator==<T> (const stack<T,deque<T>>&, const stack<T,deque<T>>&);
    // friend bool operator< <T> (const stack<T,deque<T>>& , const stack<T,deque<T>>&);

    // friend bool operator== <T>(const stack&,const stack &);
    // friend bool operator< <T> (const stack&,const stack &);

    friend bool operator==<>(const stack &, const stack& );
    friend bool operator< <>(const stack &, const stack& );

    // friend bool operator< (const stack&,const stack&);
    // friend bool operator== (const stack&,const stack&);

public:
    stack(){
        cout<<"stack"<<endl;
    }
private:
    Sequence c;
};

template <class T, class Sequence>
bool operator==(const stack<T, Sequence> &x, 
                const stack<T, Sequence> &y) {
    // error: cannot convert 'std::basic_ostream<char>' to 'bool' in return
    // return cout << "operator==" << '\t';
    cout << "operator==" << '\t';
    return true;
}

template <class T, class Sequence>
bool operator<(const stack<T, Sequence> &x, 
                const stack<T, Sequence> &y) {
    // return cout << "operator<" << '\t';
    cout << "operator<" << '\t';
    return true;
}

int main() {
    stack<int> x;
    stack<int> y;

    cout << (x == y) << endl;
    cout << (x < y) << endl;

    stack<char> y1;
    // error: no match for 'operator==' (operand types are 'stack<int>' and 'stack<char>')
    // cout << (x == y1) << endl; 
}