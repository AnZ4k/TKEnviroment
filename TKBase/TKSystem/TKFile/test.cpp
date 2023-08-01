#include "tkFile.hpp"
#include <iostream>

int main()
{
    tkv::TKFile myFile;

    std::cout << myFile.fileOpen("teste.txt", tkv::tfoREADAPPEND)->writeLine("se leu isso esta fungando")->saveFile()->readLines().get() << '\n';

    return 0;
}