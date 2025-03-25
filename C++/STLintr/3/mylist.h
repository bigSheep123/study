#include<iostream>

template<typename T>
class ListItem;

template<typename T>
class List{
public:
    void insert_front(T value);
    void insert_end(T value);
    void display(std::ostream& os = std::cout) const;
    ListItem<T> * front(){
        return _front;
    }

    List(); 
private:
    ListItem<T> *_front;
    ListItem<T> *_end;
    int size;
};

template<typename T>
void List<T>::display(std::ostream& os) const 
{
    ListItem<T>* tmp = _front;
    while(tmp != _end->next())
    {
        std::cout << tmp->value() <<" ";
        tmp = tmp->next();
    }
    std::cout << std::endl;
}

template<typename T>
void List<T>::insert_front(T value)
{
    ListItem<T>* tmp = new ListItem<T>(value);
    tmp->set_next(_front);
    if (nullptr == _front)
        _end = _front = tmp;
    else 
        _front = tmp;
    size++;
}


template<typename T>
void List<T>::insert_end(T value)
{
    ListItem<T>* tmp = new ListItem<T>(value);
    if(nullptr == _front)
        insert_front(value);
    _end->set_next(tmp);
    _end = tmp;
    size++;
}

template<typename T>
List<T>::List()
{
    _front = _end = nullptr;
    size = 0;
}

template<typename T>
class ListItem{
public:
    ListItem(T value):_value(value){
        _next = nullptr;
    }

    T value() const
    {
        return _value;
    }

    ListItem* next() const{
        return _next;
    }

    void set_next(ListItem* i)
    {
        _next = i;
    } 
private:
    T _value;
    ListItem *_next;
};