#include <iostream>
#include <memory>
#include <string>

class TypeDescriptor {
public:
    virtual ~TypeDescriptor() = default;
    virtual std::string name() const = 0;
};

template<typename T>
class TypeDescriptorImpl : public TypeDescriptor {
public:
    std::string name() const override {
        return typeid(T).name();
    }
};

class Any {
    std::shared_ptr<TypeDescriptor> desc;
    void* data;

public:
    template<typename T>
    Any(T&& value) : 
        desc(std::make_shared<TypeDescriptorImpl<T>>()),
        data(new T(std::forward<T>(value))) {}

    std::string type() const {
        return desc->name();
    }
};

int main() {
    Any a = 42;
    Any b = std::string("Hello");
    std::cout<< typeid(int).name()<<std::endl;
    std::cout<< typeid(std::string).name()<<std::endl;

    std::cout << "a's type: " << a.type() << std::endl;  // 输出 int 的 typeid 名称
    std::cout << "b's type: " << b.type() << std::endl;  // 输出 std::string 的 typeid 名称
    return 0;
}