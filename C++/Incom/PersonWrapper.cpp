// PersonWrapper.cpp
#include "PersonWrapper.h"
#include "Person.h"

extern "C" {
    PersonHandle Person_create(int age) {
        return reinterpret_cast<PersonHandle>(new Person(age));
    }

    void Person_destroy(PersonHandle handle) {
        delete reinterpret_cast<Person*>(handle);
    }

    int Person_getAge(PersonHandle handle) {
        return reinterpret_cast<Person*>(handle)->getAge();
    }

    void Person_setAge(PersonHandle handle, int age) {
        return reinterpret_cast<Person*>(handle)->setAge(age);
    }
}
