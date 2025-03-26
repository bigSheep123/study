#include"Person.h"
#include "PersonWrapper.h"
#include <iostream>

extern "C";

int main()
{
    int age = 18;
    auto a = Person_create(age);
    std::cout<< Person_getAge(a) <<std::endl;
    Person_setAge(a,20);
    std::cout << Person_getAge(a) <<std::endl;
    Person_destroy(a);

    return 0;
}