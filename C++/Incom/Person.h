// Person.h
#ifndef PERSON_H
#define PERSON_H

class Person {
public:
    Person(int age)
    {
        m_age = age;
    }
    int getAge() const
    {
        return m_age;
    }
    void setAge(int age)
    {
        m_age = age;
    }

private:
    int m_age;
};

#endif
