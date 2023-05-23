#include <iostream>
#include "tkString.hpp"


int main()
{
    std::cout << "tkString" << std::endl;

    tkv::tkString s1 ="word Word Word popozao Popozao grandao word";
    std::string s2[] = {"[A-Z][a-z]+","g[a-z]+", "w[a-z]+"};
    std::string s3[] = {"reg1", "reg2", "reg3"};
    
    std::cout << s1.replace(s2, s3).get() << '\n';
    std::cout << sizeof(s2) / sizeof(s2[0]) << '\n';
    std::cout << sizeof(s3) / sizeof(s3[0]) << '\n';

    return 0;
}