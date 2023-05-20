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

tkv::tkString &tkv::tkString::operator+=(char c)
{
    this->set(this->get() + std::string(1, c));
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

char tkv::tkString::operator[](int index)  
{
    return this->charAt(index);
}

tkv::tkInternalSearch tkv::tkString::evalueExpression(char *mask)
{
    return this->evalueExpression(std::string(mask));
}

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

int tkv::tkString::length()
{
    return this->_str.length();
}

bool tkv::tkString::startWith(char* mask, bool regexUsed = true)
{
    return this->startWith(std::string(mask), regexUsed);
}

bool tkv::tkString::startWith(std::string mask, bool regexUsed)
{
    if (mask.empty())
    {
        return false;
    }

    if (regexUsed)
    {
        tkv::tkInternalSearch result = this->evalueExpression(mask);
        return (result.founded && result.pos[0][0] == 0);
    }
    else
    {
        if (this->length() < mask.length())
        {
            return false;
        }
        
        return (this->get().find(mask) == 0);
    }
}

bool tkv::tkString::startWith(char mask)
{
    return ((*this)[0] == mask);
}

bool tkv::tkString::endWith(char* mask, bool regexUsed = true)
{
    return this->endWith(std::string(mask), regexUsed);
}

bool tkv::tkString::endWith(std::string mask, bool regexUsed)
{
    if (mask.empty())
    {
        return false;
    }

    if (regexUsed)
    {
        tkv::tkInternalSearch result = this->evalueExpression(mask);
        return (result.founded && result.pos[result.count-1][1] == this->length()-1);
    }
    else
    {
        if (this->length() < mask.length())
        {
            return false;
        }
        
        std::string tmpBuf = this->substring(this->length() -1 -mask.length(), this->length() -1).get();
        return (tmpBuf == mask);
    }
}

bool tkv::tkString::endsWith(char mask)
{
    return (this->get()[this->length() -1] == mask);
}

tkv::tkString tkv::tkString::substring(int pi, int pf)
{
    if (pi < 0)
    {
        pi = 0;
    }

    if (pf < 0)
    {
        pf = 0;
    }
   
    if (pf > this->length() -1)
    {
        pf = this->length() -1;
    }
   
    if (pi > pf)
    {
        return "";           
    }                       
   
    return (tkv::tkString) this->get().substr(pi, pf - pi + 1);
}

tkv::tkString tkv::tkString::substring(int pi)
{
    return this->substring(pi, this->length() -1);
}

tkv::tkString* tkv::tkString::substring(int *pis, int *pfs)
{
    if (pis == nullptr || pfs == nullptr)
    {
        return nullptr;
    }

    if ((sizeof(pis) / sizeof(int)) != (sizeof(pfs) / sizeof(int)))
    {
        return nullptr;
    }
    
    tkString *strs = new tkv::tkString[sizeof(pis) / sizeof(int)];

    for (int i = 0; i < sizeof(pis) / sizeof(int); i)
    {
        strs[i] = this->substring(pis[i], pfs[i]);
    }

    return strs;
}

char tkv::tkString::charAt(int index)
{
    if (index < 0)
    {
        return '\0';
    }

    if (index > this->length() -1)
    {
        return '\0';
    }
    
    return this->_str[index];
}

int tkv::tkString::indexOf(char ch)
{
    for (int i = 0; i < this->length(); i++)
    {
        if ((*this)[i] == ch)
        {
            return i;
        }
    }
    
    return -1;
}

int tkv::tkString::lastIndexOf(char ch)
{
    for (int i = this->length() -1; i >= 0; i--)
    {
        if ((*this)[i] == ch)
        {
            return i;
        }
    }
    
    return -1;
}

int* tkv::tkString::indexOf(std::string str, bool regexUsed = true)
{
    int **mat = this->allIndexOf(str);

    if (mat == nullptr)
    {
        return nullptr;
    }
    else if (mat[0] == nullptr)
    {
        return nullptr;
    }
    
    return mat[0];
}

int* tkv::tkString::indexOf(char *str, bool regexUsed = true)
{
    return this->indexOf(std::string(str), regexUsed);
}

int* tkv::tkString::lastIndexOf(std::string str, bool regexUsed = true)
{
    int **mat = this->allIndexOf(str);

    if (mat == nullptr)
    {
        return nullptr;
    }
    else if (mat[0] == nullptr)
    {
        return nullptr;
    }
    else if (mat[sizeof(mat) / sizeof(mat[0]) -1] == nullptr)
    {
        return nullptr;
    }
    
    return mat[sizeof(mat) / sizeof(mat[0]) -1];
}

int* tkv::tkString::lastIndexOf(char *str, bool regexUsed = true)
{
    return this->lastIndexOf(std::string(str), regexUsed);
}

int** tkv::tkString::allIndexOf(std::string str, bool regexUsed = true)
{
    if (str.empty())
    {
        return nullptr;
    }
    
    if (regexUsed)
    {
        tkv::tkInternalSearch result = this->evalueExpression(str);
    
        if (result.founded)
        {
            return result.pos;
        }
        else
        {
            return nullptr;
        }
    }

    int c = this->occurrencesOf(str, false);

    if (c <= 0)
    {
        return nullptr;
    }

    int **mat = new int*[c];

    for (int i = 0, mi = 0; i < this->length(); i++)
    {
        if ((*this)[i] == str[0] && i + str.length() < this->length())
        {
            if (this->substring(i, i + str.length() -1).get() == str)
            {
                mat[mi] = new int[2];
                mat[mi][0] = i;
                mat[mi][1] = i + str.length() -1;
                mi ++;
            }
        }
    }

    return mat;
}

int** tkv::tkString::allIndexOf(char *str, bool regexUsed = true)
{
    return this->allIndexOf(std::string(str), regexUsed);
}

int tkv::tkString::occurrencesOf(std::string str, bool regexUsed = true)
{
    if (str.empty())
    {
        return 0;
    }
    
    if (regexUsed)
    {
        tkv::tkInternalSearch result = this->evalueExpression(str);
        if (result.founded)
        {
            return result.count;
        }
        else
        {
            return 0;
        }
    }

    int c = 0;

    for (int i = 0; i < this->length(); i++)
    {
        if ((*this)[i] == str[0] && i + str.length() < this->length())
        {
            if (this->substring(i, i + str.length() -1).get() == str)
            {
                c ++;
            }
        }
    }

    return c;
}

int tkv::tkString::occurrencesOf(char *str, bool regexUsed = true)
{
    return this->occurrencesOf(std::string(str), regexUsed);
}

int tkv::tkString::occurrencesOf(char ch)
{
    int c = 0;

    for (int i = 0; i < this->length(); i++)
    {
        if ((*this)[i] == ch)
        {
            c ++;
        }
    }

    return c;
}

bool tkv::tkString::contains(std::string str, bool regexUsed = true)
{
    if (str.empty())
    {
        return false;
    }

    return (this->occurrencesOf(str, regexUsed) > 0);
}

bool tkv::tkString::contains(char *str, bool regexUsed = true)
{
    return this->contains(std::string(str), regexUsed);
}

bool tkv::tkString::contains(char ch)
{
    return ((this->occurrencesOf(ch)) > 0);
}

int* tkv::tkString::getNumbers()
{
    tkv::tkInternalSearch result = this->evalueExpression("\\d+");

    if (! result.founded)
    {
        return nullptr;
    }

    int *res = new int[result.count];

    for (int i = 0; i < result.count; i++)
    {
        res[i] = std::stoi(this->substring(result.pos[i][0], result.pos[i][1]).get());
    }

    return res;
}

bool tkv::tkString::isEmpty()
{
    return (this->length() == 0);
}

bool tkv::tkString::isPalindrome()
{
    return (this->reverse().get() == this->get());
}

bool tkv::tkString::isLowerCase()
{
    for (int i = 0; i < this->length(); i++)
    {
        if (this->charAt(i) >= 'A' && this->charAt(i) <= 'Z')
        {
            return false;
        }
    }

    return true;
}

bool tkv::tkString::isUpperCase()
{
    for (int i = 0; i < this->length(); i++)
    {
        if (this->charAt(i) >= 'a' && this->charAt(i) <= 'z')
        {
            return false;
        }
    }

    return true;
}

bool tkv::tkString::isNumeric()
{
    for (int i = 0; i < this->length(); i++)
    {
        if (this->charAt(i) < '0' || this->charAt(i) > '9')
        {
            return false;
        }
    }

    return true;
}

int tkv::tkString::levenshteinDistance(std::string str)
{
    std::string thisStr = get();
    int m = thisStr.length();
    int n = str.length();
    int** dp = new int*[m + 1];

    for (int i = 0; i <= m; ++i) 
    {
        dp[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; ++i) 
    {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) 
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {
            if (thisStr[i - 1] == str[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else 
            {
                dp[i][j] = 1 + std::min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] });
            }
        }
    }

    int distance = dp[m][n];

    for (int i = 0; i <= m; ++i) {
        delete[] dp[i];
    }

    delete[] dp;
    return distance;
}

int tkv::tkString::levenshteinDistance(char *str)
{
    return this->levenshteinDistance(std::string(str));
}

tkv::tkString tkv::tkString::randomString(int length)
{
    if (length <= 0) 
    {
        return tkv::tkString();
    }

    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, alphabet.length() - 1);
    std::string result;

    for (int i = 0; i < length; i++) 
    {
        result += alphabet[dis(gen)];
    }

    return tkv::tkString(result);
}

tkv::tkString tkv::tkString::encodeBase64()
{
    std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";
    std::string ret;
    int i = 0;
    int padding = 0;
    int val = 0;

    for (auto c : this->get()) 
    {
        val = (val<<8) + c;
        padding += 2;

        while (padding >= 0) 
        {
            ret += base64_chars[(val>>padding)&0x3F];
            padding -= 6;
        }
    }

    if (padding == -4) 
    {
        ret += base64_chars[(val&0xF)<<2];
        ret += "==";
    }
    else if (padding == -2) 
    {
        ret += base64_chars[(val&0x3)<<4];
        ret += "=";
    }

    return ret;
}

tkv::tkString tkv::tkString::decodeBase64()
{
    std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";
             
    if (this->get().length() % 4 != 0) 
    {
        return tkv::tkString();
    }

    for (size_t i = 0; i < this->get().length(); ++i) 
    {
        char c = this->get()[i];

        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '+') || (c == '/')) && !((c == '=') && (i >= this->get().length() - 2))) 
        {
            return tkv::tkString();
        }
    }

    std::string ret;
    int val = 0;
    int padding = -8;

    for (auto c : this->get()) 
    {
        if (c == '=')
            break;

        val = (val<<6) + base64_chars.find(c);
        padding += 6;

        if (padding >= 0) 
        {
            ret += (val>>padding)&0xFF;
            padding -= 8;
        }
    }

    return ret;
}

tkv::tkString tkv::tkString::replace(std::string mask, std::string newText, bool regexUsed = true)
{
    if (regexUsed)
    {
        return tkv::tkString(std::regex_replace(this->get(), std::regex(mask), newText));
    }

    return tkv::tkString(this->get().replace(this->get().find(mask), mask.length(), newText));
}

tkv::tkString tkv::tkString::replace(std::string mask, char c, bool regexUsed = true)
{
    if (regexUsed)
    {
        return tkv::tkString(std::regex_replace(this->get(), std::regex(mask), std::string(1, c)));
    }

    return tkv::tkString(this->get().replace(this->get().find(mask), mask.length(), std::string(1, c)));
}

tkv::tkString tkv::tkString::replace(std::string mask, char* newText, bool regexUsed = true)
{
    return this->replace(mask, std::string(newText), regexUsed); 
}

tkv::tkString tkv::tkString::replace(std::string *mask, std::string* newText, bool regexUsed = true)
{
    tkv::tkString ret = "";
    tkv::tkString tmBuf = "";

    if (mask == nullptr || newText == nullptr)
    {
        return tkv::tkString();
    }
    else if (sizeof(mask) / sizeof(mask[0]) != sizeof(newText) / sizeof(newText[0]))
    {
        return tkv::tkString();
    }

    for (int i = 0; i < sizeof(mask) / sizeof(mask[0]); i++)
    {
        tmBuf = this->replace(mask[i], newText[i], regexUsed);
        ret = tmBuf;
    }
    
    return ret;
}

tkv::tkString tkv::tkString::replace(std::string *mask, std::string newText, bool regexUsed = true)
{
    tkv::tkString ret = "";
    tkv::tkString tmBuf = "";

    if (mask == nullptr || newText.empty())
    {
        return tkv::tkString();
    }

    for (int i = 0; i < sizeof(mask) / sizeof(mask[0]); i++)
    {
        tkv::tkString tmBuf = this->replace(mask[i], newText, regexUsed);
        ret = tmBuf;
    }   

    return ret;
}

tkv::tkString tkv::tkString::replace(std::string *mask, char** newText, bool regexUsed = true)
{
    tkv::tkString ret = "";
    tkv::tkString tmBuf = "";

    if (mask == nullptr || newText == nullptr)
    {
        return tkv::tkString();
    }
    else if (sizeof(mask) / sizeof(mask[0])!= sizeof(newText) / sizeof(newText[0]))
    {
        return tkv::tkString();
    }

    for (int i = 0; i < sizeof(mask) / sizeof(mask[0]); i++)
    {
        tmBuf = this->replace(mask[i], newText[i], regexUsed);
        ret = tmBuf;
    }

    return ret;
}

tkv::tkString tkv::tkString::replace(std::string *mask, char* newText, bool regexUsed = true)
{
    tkv::tkString ret = "";
    tkv::tkString tmBuf = "";

    if (mask == nullptr || newText == nullptr)
    {
        return tkv::tkString();
    }

    for (int i = 0; i < sizeof(mask) / sizeof(mask[0]); i++)
    {
        tmBuf = this->replace(mask[i], newText, regexUsed);
        ret = tmBuf;
    }

    return ret;
}

tkv::tkString tkv::tkString::replace(char *mask, std::string newText, bool regexUsed = true)
{
    return this->replace(std::string(mask), newText, regexUsed);
}

tkv::tkString tkv::tkString::replace(char *mask, char *newText, bool regexUsed = true)
{
    return this->replace(std::string(mask), std::string(newText), regexUsed);
}

tkv::tkString tkv::tkString::replace(char *mask, char c, bool regexUsed = true)
{
    return this->replace(std::string(mask), c, regexUsed);
}

tkv::tkString tkv::tkString::replace(char **mask, char** newText, bool regexUsed = true)
{
    tkv::tkString ret = "";
    tkv::tkString tmBuf = "";

    if (mask == nullptr || newText == nullptr)
    {
        return tkv::tkString();
    }
    else if (sizeof(mask) / sizeof(mask[0])!= sizeof(newText) / sizeof(newText[0]))
    {
        return tkv::tkString();
    }

    for (int i = 0; i < sizeof(mask) / sizeof(mask[0]); i++)
    {
        tmBuf = this->replace(mask[i], newText[i], regexUsed);
        ret = tmBuf;
    }

    return ret;
}

tkv::tkString tkv::tkString::replace(char **mask, std::string* newText, bool regexUsed = true)
{
    tkv::tkString ret = "";
    tkv::tkString tmBuf = "";

    if (mask == nullptr || newText == nullptr)
    {
        return tkv::tkString();
    }
    else if (sizeof(mask) / sizeof(mask[0])!= sizeof(newText) / sizeof(newText[0]))
    {
        return tkv::tkString();
    }

    for (int i = 0; i < sizeof(mask) / sizeof(mask[0]); i++)
    {
        tmBuf = this->replace(mask[i], newText[i], regexUsed);
        ret = tmBuf;
    }

    return ret;
}

tkv::tkString tkv::tkString::replace(char **mask, std::string newText, bool regexUsed = true)
{
    tkv::tkString ret = "";
    tkv::tkString tmBuf = "";

    if (mask == nullptr || newText.empty())
    {
        return tkv::tkString();
    }

    for (int i = 0; i < sizeof(mask) / sizeof(mask[0]); i++)
    {
        tmBuf = this->replace(mask[i], newText, regexUsed);
        ret = tmBuf;
    }
    
    return ret;
}

tkv::tkString tkv::tkString::trimLeft()
{
    int pi = 0;

    for (int i = 0; i < this->length(); i++)
    {
        if ((*this)[i] != ' ')
        {
            pi = i;
            break;
        }
    }

    return this->substring(pi);
}

tkv::tkString tkv::tkString::trimRight()
{
    int pf = 0;
    
    for (int i = this->length() - 1; i >= 0; i--)
    {
        if ((*this)[i] != ' ')
        {
            pf = i;
            break;
        }
    }

    return this->substring(0, pf);
}

tkv::tkString tkv::tkString::trim()
{
    return this->trimLeft().trimRight(); 
}

tkv::tkString tkv::tkString::upper(char* str, bool regexUsed = true)
{
    return this->upper(std::string(str), regexUsed);
}

tkv::tkString tkv::tkString::lower(char *str, bool regexUsed = true)
{
    return this->lower(std::string(str), regexUsed);
}

tkv::tkString tkv::tkString::reverse()
{
    tkv::tkString ret = "";

    for (int i = this->length() - 1; i >= 0; i--)
    {
        ret += (*this)[i];
    }

    return ret;
}

tkv::tkString tkv::tkString::mirror()
{
    return this->get() + this->reverse().get();
}

tkv::tkString tkv::tkString::upper(std::string mask = "", bool regexUsed = true)
{
    tkString ret;
    
    if (mask.empty())
    {
        for (int i = 0; i < this->length(); i++)
        {
            if ((*this)[i] >= 'a' && (*this)[i] <= 'z')
            {
                ret += (*this)[i] - 32;
            }
        }

        return ret;
    }

    if (regexUsed)
    {
        tkInternalSearch _res = evalueExpression(mask);

        if (! _res.founded)
            return tkv::tkString();

        for (int i = 0; i < _res.count; i++)
        {
            std::string oldStr, newStr;
            oldStr = this->substring(_res.pos[i][0], _res.pos[i][1]).get();
            
            for (int j = 0; j < oldStr.length(); j++)
            {
                newStr += oldStr[j] - 32;
            }

            ret = this->replace(oldStr, newStr, false);
        }

        return ret;
    }
    
    int count = this->occurrencesOf(mask, false);

    if (count <= 0)
        return tkv::tkString();

    int **matPos = this->allIndexOf(mask, false);
   
    if (matPos == nullptr)
        return tkv::tkString();
    
    for (int i = 0; i < count; i++)
    {
        std::string oldStr, newStr;
        oldStr = this->substring(matPos[i][0], matPos[i][1]).get();
        
        for (int j = 0; j < oldStr.length(); j++)
        {
            newStr += oldStr[j] - 32;
        }

        ret = this->replace(oldStr, newStr, false);
    }
    
    return ret;
}

tkv::tkString tkv::tkString::lower(std::string mask = "", bool regexUsed = true)
{
    tkString ret;
    
    if (mask.empty())
    {
        for (int i = 0; i < this->length(); i++)
        {
            if ((*this)[i] >= 'A' && (*this)[i] <= 'Z')
            {
                ret += (*this)[i] + 32;
            }
        }

        return ret;
    }

    if (regexUsed)
    {
        tkInternalSearch _res = evalueExpression(mask);

        if (! _res.founded)
            return tkv::tkString();

        for (int i = 0; i < _res.count; i++)
        {
            std::string oldStr, newStr;
            oldStr = this->substring(_res.pos[i][0], _res.pos[i][1]).get();
            
            for (int j = 0; j < oldStr.length(); j++)
            {
                newStr += oldStr[j] + 32;
            }

            ret = this->replace(oldStr, newStr, false);
        }

        return ret;
    }
    
    int count = this->occurrencesOf(mask, false);

    if (count <= 0)
        return tkv::tkString();

    int **matPos = this->allIndexOf(mask, false);
   
    if (matPos == nullptr)
        return tkv::tkString();
    
    for (int i = 0; i < count; i++)
    {
        std::string oldStr, newStr;
        oldStr = this->substring(matPos[i][0], matPos[i][1]).get();
        
        for (int j = 0; j < oldStr.length(); j++)
        {
            newStr += oldStr[j] + 32;
        }

        ret = this->replace(oldStr, newStr, false);
    }
    
    return ret;
}

tkv::tkString* tkv::tkString::split(char* mask, bool regexUsed = true)
{
    return this->split(std::string(mask), regexUsed);
}

tkv::tkString* tkv::tkString::split(std::string mask, bool regexUsed = true)
{
    int count = this->occurrencesOf(mask, regexUsed);
    int **matPos = this->allIndexOf(mask, regexUsed);
    tkString *ret = new tkv::tkString[count];

    if (matPos == nullptr)
        return nullptr;

    for (int i = 0, strI = 0, strF = 0; i < count; i++)
    {
        if (matPos[i] == nullptr)
            return nullptr;

        (matPos[i][1] >= this->length())? strI = (this->length() -1): strI = matPos[i][1];
        (count <= (i + 1))? strF = (this->length() -1): strF = (matPos[i + i][0] -1);
        ret[i] = this->substring(strI, strF);
    }

    return ret;
}

tkv::tkString tkv::tkString::leftJoin(std::string str)
{
    tkv::tkString ret = str;
    ret += this->get();
    
    return ret;
}

tkv::tkString tkv::tkString::rightJoin(std::string str)
{
    tkv::tkString ret = this->get();
    ret += str;
    
    return ret;
}

tkv::tkString tkv::tkString::leftJoin(char *str)
{
    return this->leftJoin(std::string(str));
}

tkv::tkString tkv::tkString::rightJoin(char *str)
{
    return this->rightJoin(std::string(str));
}

tkv::tkString tkv::tkString::leftJoin(tkString str)
{
    return this->leftJoin(str.get());
}

tkv::tkString tkv::tkString::rightJoin(tkString str)
{
    return this->rightJoin(str.get());
}

tkv::tkString tkv::tkString::leftJoin(std::string *strs)
{
    tkString ret = this->get();

    if (strs == nullptr)
        return tkv::tkString();

    for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
    {
        tkString tmBuf = ret;
        ret = tmBuf.leftJoin(strs[i]);
    }

    return ret;
}

tkv::tkString tkv::tkString::rightJoin(std::string *strs)
{
    tkString ret = this->get();

    if (strs == nullptr)
        return tkv::tkString();

    for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
    {
        tkString tmBuf = ret;
        ret = tmBuf.rightJoin(strs[i]);
    }

    return ret;
}

tkv::tkString tkv::tkString::leftJoin(tkString *strs)
{
    tkString ret = this->get();

    if (strs == nullptr)
        return tkv::tkString();

    for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
    {
        tkString tmBuf = ret;
        ret = tmBuf.leftJoin(strs[i]);
    }

    return ret;
}

tkv::tkString tkv::tkString::rightJoin(tkString *strs)
{
    tkString ret = this->get();

    if (strs == nullptr)
        return tkv::tkString();

    for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
    {
        tkString tmBuf = ret;
        ret = tmBuf.rightJoin(strs[i]);
    }

    return ret;
}

tkv::tkString tkv::tkString::leftJoin(char **strs)
{
    tkString ret = this->get();

    if (strs == nullptr)
        return tkv::tkString();

    for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
    {
        tkString tmBuf = ret;
        ret = tmBuf.leftJoin(strs[i]);
    }

    return ret;   
}

tkv::tkString tkv::tkString::rightJoin(char **strs)
{
    tkString ret = this->get();

    if (strs == nullptr)
        return tkv::tkString();

    for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
    {
        tkString tmBuf = ret;
        ret = tmBuf.rightJoin(strs[i]);
    }

    return ret;
}

tkv::tkString tkv::tkString::leftJoin(char c)
{
    return this->leftJoin(std::string(1, c));
}

tkv::tkString tkv::tkString::rightJoin(char c)
{
    return this->rightJoin(std::string(1, c));
}

tkv::tkString tkv::tkString::truncate(int len)
{
    if (this->length() <= len)
        return this->get();

    return this->substring(0, len);
}

tkv::tkString tkv::tkString::truncateFrom(int pi, int len)
{
    if (this->length() <= len && pi >= 0 && pi < this->length())
        return this->substring(pi, this->length() -1);
    else if (this->length() <= len && pi < 0)
        return tkv::tkString();
    else if (this->length() <= len && pi >= this->length())
        return tkv::tkString();
    
    return this->substring(pi, len);
}

tkv::tkString tkv::tkString::truncateFromFinal(int len)
{
    if (this->length() <= len)
        return this->get();

    return this->reverse().substring(0, len).reverse();
}

tkv::tkString tkv::tkString::shuffle()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(this->get().begin(), this->get().end(), gen);

    return this->get();
}

tkv::tkString tkv::tkString::urlFriendly()
{
    tkv::tkString ret = this->get();
    // 33 - 47
    // 58 - 64
    // 91 - 96
    // 123 - 126
    // 128
    // 130 - 140 
    // 142
    // 145 - 156
    // 158 255

    for (int i = 0; i < ret.length(); i++)
    {
        tkString ret = this->get();
        tkString buff;

        if (((*this)[i] >= 21 && (*this)[i] <= 47) || 
            ((*this)[i] >= 58 && (*this)[i] <= 64) || 
            ((*this)[i] >= 91 && (*this)[i] <= 96) || 
            ((*this)[i] >= 123 && (*this)[i] <= 126) || 
            ((*this)[i] >= 128 && (*this)[i] <= 140) || 
            ((*this)[i] >= 142 && (*this)[i] <= 156) || 
            ((*this)[i] >= 158 && (*this)[i] <= 255))
        {
            buff = ret.replace(ret[i], "%" + std::to_string(static_cast<int>((*this)[i])));
        }
    }
}