#include <iostream>
#include "tkString.hpp"


int main()
{
    std::cout << "Testing tkString" << std::endl;

    tkv::tkString s1("Hello");
    std::cout << s1.get() << std::endl;

    tkv::tkString s2("World");
    std::cout << s2.get() << std::endl;

    tkv::tkString s3 = s1.get() + s2.get();
    std::cout << s3.get() << std::endl;
    
    return 0;
}