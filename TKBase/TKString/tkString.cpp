#include "tkString.hpp"

tkv::tkString::tkString() {
    this->set("");
}

tkv::tkString::tkString(char *str) 
{
    if (str == nullptr)
    {
        this->set("");
        return;
    }
    this->set(std::string(str));
}

tkv::tkString::tkString(std::string *str) 
{
    if (str == nullptr)
    {
        this->set("");
        return;
    }
    this->set(*str);
}

tkv::tkString::tkString(tkString *str)
{
    if (str == nullptr)
    {
        this->set("");
        return;
    }
    this->set(str->get());
}

tkv::tkString::tkString(std::string str)
{
    this->set(str);
}

tkv::tkString& tkv::tkString::operator=(char *str)
{
    this->set(std::string(str));
    return *this;
}

tkv::tkString& tkv::tkString::operator=(std::string str)
{
    this->set(str);
    return *this;
}

tkv::tkString& tkv::tkString::operator=(tkString str)
{
    this->set(str.get());
    return *this;
}

tkv::tkString &tkv::tkString::operator+=(char *str)
{
    if (str == nullptr)
    {
        return *this;
    }
    this->set(this->get() + std::string(str));
    return *this;
}

tkv::tkString &tkv::tkString::operator+=(std::string str)
{
    this->set(this->get() + str);
    return *this;
}

tkv::tkString &tkv::tkString::operator+=(tkString str)
{
    this->set(this->get() + str.get());
    return *this;
}

tkv::tkInternalSearch tkv::tkString::evalueExpression(char *mask)
{
    return this->evalueExpression(std::string(mask));
}

/*
        std::string get();
        void set(std::string);
        void set(tkString);
        void set(char *str);
*/

std::string tkv::tkString::get()
{
    return this->_str;
}

void tkv::tkString::set(std::string str)
{
    this->_str = str;
}

void tkv::tkString::set(tkString str)
{
    this->set(str.get());
}

void tkv::tkString::set(char *str)
{
    this->set(std::string(str));
}

tkv::tkInternalSearch tkv::tkString::evalueExpression(std::string mask)
{
    tkv::tkInternalSearch result;
    std::regex pattern(mask);

    if (std::regex_search(this->get(), pattern))
    {
        result.founded = true;
    }
    else 
    {
        return result;
    }

    std::sregex_iterator it (this->get().begin(), this->get().end(), pattern);
    std::sregex_iterator end;

    for (; it!= end; ++it)
    {
        result.count++;
    }
    
    result.pos = new int*[result.count];
    it = std::sregex_iterator(this->get().begin(), this->get().end(), pattern);

    for (int i = 0; it!= end; ++it, i++)
    {
        std::smatch match = *it;
        result.pos[i] = new int(i);
        result.pos[i][0] = match.position();
        result.pos[i][1] = match.position() + match.length() -1;
    }
    return result;
}

tkv::tkString::~tkString()
{
    this->_str = "";
}
