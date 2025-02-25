#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s1("hello world");
    string::reverse_iterator rit = s1.rbegin();
    string::iterator rit1 = s1.begin();
    string::const_iterator rit2 = s1.begin();

    cout << typeid(rit).name()<<endl;
    cout << typeid(rit1).name()<<endl;
    cout << typeid(rit2).name()<<endl;
    string::iterator rit3 = s1.end();

    return 0;
}