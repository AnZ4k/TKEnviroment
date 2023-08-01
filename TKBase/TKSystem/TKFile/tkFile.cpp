#include "tkFile.hpp"

tkv::TKFile::TKFile()
{
    this->path = "";
    this->fileIn = std::ifstream();
    this->fileOut = std::ofstream();
}

tkv::TKFile::~TKFile()
{   
    this->close();
}

tkv::TKFile::TKFile(tkv::tkString ppath, tkv::TKFileOpenType popenType)
{
    this->fileOpen(ppath, popenType);
}

tkv::tkString tkv::TKFile::readLine()
{   
    if (!this->isValidOp(toIn))
        return tkString();

    this->fileIn.seekg(0);
    std::string buf;
    if (this->fileIn.is_open())
    {
        std::getline(this->fileIn, buf);
        this->fileIn.seekg(0);
        return tkv::tkString(buf);
    }
    return tkv::tkString();
}

tkv::tkString tkv::TKFile::readLines()
{
    if (!this->isValidOp(toIn))
        return tkString();

    std::string line = "";
    std::string buffer = "";

    this->fileIn.seekg(0);

    while (this->fileIn.good())
    {
        getline(this->fileIn, line);
        buffer += (line + '\n');
    }
    this->fileIn.seekg(0);

    return tkv::tkString(buffer);
}

tkv::TKFile* tkv::TKFile::writeLine(tkv::tkString pbuff)
{
    return this->write(pbuff.rightJoin('\n'));
}

tkv::TKFile* tkv::TKFile::write(tkv::tkString pbuff)
{
    if (isValidOp(toOut))
        this->fileOut << pbuff.get();

    return this;
}

tkv::TKFile* tkv::TKFile::fileOpen(tkv::tkString ppath, tkv::TKFileOpenType ptype)
{    
    this->path = ppath;
    this->openType = ptype;

    if (isValidOp(toIn))
    {
        this->fileIn = std::ifstream(ppath.get(), std::ios::in);
    }

    if (isValidOp(toOut))
    {
        if (this->openType == tfoAPPEND || this->openType == tfoREADAPPEND)
            this->fileOut = std::ofstream(this->path.get(), std::ios::app);
        else if (this->openType == tfoWRITE || this->openType == tfoREADWRITE)
            this->fileOut = std::ofstream(this->path.get(), std::ios::trunc);
    }

    return this;
}

void tkv::TKFile::close()
{
    if(isValidOp(toIn))
        this->fileIn.close();
    if(isValidOp(toOut))
        this->fileOut.close();
}
bool tkv::TKFile::isValidOp(tkv::TKFileOperation op)
{
    switch (op)
    {
        case toIn: {
            if (this->openType == tfoREAD || this->openType == tfoREADAPPEND || this->openType == tfoREADWRITE)
                return true;
            return false;
            break;
        }
        case toOut: {
            if (this->openType == tfoWRITE || this->openType == tfoREADAPPEND || this->openType == tfoREADWRITE || this->openType == tfoAPPEND)
                return true;
            return false;
        }
        default : {
            return false;
        }
    }
}

tkv::TKFile* tkv::TKFile::saveFile(tkv::tkString ppath)
{
    this->close();

    if (isValidOp(toOut) && isValidOp(toIn))
        this->fileOpen(this->path, tfoREADAPPEND);
    else if (isValidOp(toOut))
        this->fileOpen(this->path, tfoAPPEND);
    else
        this->fileOpen(this->path, tfoREAD);

    return this;
}

std::ifstream* tkv::TKFile::getInStream()
{
    return &(this->fileIn);
}

std::ofstream* tkv::TKFile::getOutStream()
{
    return &(this->fileOut);
}