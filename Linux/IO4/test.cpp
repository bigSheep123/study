#include <iostream>
#include <string>
#include <fstream>

#define FILENAME "log.txt"

int main()
{
    std::ofstream out(FILENAME);
    if (!out.is_open())
        return 1;

    std::string mesg = "hello Cplusplus";
    out.write(mesg.c_str(), mesg.size());
    std::cout << mesg.size() << std::endl;
    out.close();

    return 0;
}