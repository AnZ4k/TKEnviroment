#ifndef TKFILE
#define TKFILE
#include <iostream>
#include <fstream>
#include "../../TKString/tkString.hpp"

namespace tkv
{
    typedef enum TKFileOpenType 
    {
        tfoWRITE = 0,
        tfoREAD = 1,
        tfoREADWRITE = 2,
        tfoAPPEND = 3,
        tfoREADAPPEND = 4
    } TKFileOpenType;

    typedef enum TKFileOperation 
    {
        toIn = 0,
        toOut = 1
    } TKFileOperation;

    class TKFile
    {
    private:
        std::ifstream fileIn;
        std::ofstream fileOut;
        tkv::tkString path;
        TKFileOpenType openType;
        bool isValidOp(TKFileOperation op);
    public:
        TKFile(void);
        ~TKFile();
        TKFile(tkv::tkString const ppath, tkv::TKFileOpenType const popenType = tfoREAD);
        tkv::tkString readLine(void);
        tkv::tkString readLines(void);
        TKFile* writeLine(tkv::tkString const pbuff);
        TKFile* write(tkv::tkString const pbuff);
        TKFile* fileOpen(tkv::tkString const ppath, tkv::TKFileOpenType const ptype = tfoREAD);
        void close(void);
        TKFile* saveFile(tkv::tkString const ppath = tkv::tkString());
        std::ifstream* getInStream(void);
        std::ofstream* getOutStream(void);
    };
}
#endif