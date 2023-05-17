#include <string>
#include <regex>

#ifndef TKSTRING
#define TKSTRING

namespace tkv {
    typedef struct tkAny {
        int* ivals;
        std::string* svals;
        float* fvals;
        bool* bvals;
        bool intUsed = false;
        bool stringUsed = false;
        bool floatUsed = false;
        bool boolUsed = false;
    } tkAny;

    typedef struct tkInternalSearch {
        int** pos = nullptr;
        bool founded = false;
        int count = 0;
    } tkInternalSearch;

    class tkString {
    public:
        // Construtores
        tkString();
        tkString(char* str);
        tkString(std::string str);
        tkString(std::string* str);
        tkString(tkString* str);
        tkString &operator=(char* str);
        tkString &operator=(std::string str);
        tkString &operator=(tkString);
        tkString &operator+=(char* str);
        tkString &operator+=(std::string str);
        tkString &operator+=(tkString);
        ~tkString();

        // Manipulacao de strings
        tkString *split(std::string mask, bool regexUsed = true);
        tkString *split(char *mask, bool regexUsed = true);
        tkString **split(std::string *mask, bool regexUsed = true);
        tkString **split(char **mask, bool regexUsed = true);
        tkString replace(std::string mask, std::string newText, bool regexUsed = true);
        tkString replace(std::string mask, char c, bool regexUsed = true);
        tkString replace(std::string mask, char* newText, bool regexUsed = true);
        tkString replace(std::string *mask, std::string* newText, bool regexUsed = true);
        tkString replace(std::string *mask, std::string newText, bool regexUsed = true);
        tkString replace(std::string *mask, char** newText, bool regexUsed = true);
        tkString replace(std::string *mask, char* newText, bool regexUsed = true);
        tkString replace(char *mask, std::string newText, bool regexUsed = true);
        tkString replace(char *mask, char *newText, bool regexUsed = true);
        tkString replace(char *mask, char c, bool regexUsed = true);
        tkString replace(char **mask, char** newText, bool regexUsed = true);
        tkString replace(char **mask, std::string* newText, bool regexUsed = true);
        tkString replace(char **mask, std::string newText, bool regexUsed = true);
        tkString trim();
        tkString trimLeft();
        tkString trimRight();
        tkString upper(std::string mask = "", bool regexUsed = true);
        tkString upper(char *str, bool regexUsed = true);
        tkString lower(std::string mask = "", bool regexUsed = true);
        tkString lower(char *str, bool regexUsed = true);
        tkString camel(std::string mask = "", bool regexUsed = true);
        tkString camel(char *str, bool regexUsed = true);
        tkString reverse();
        tkString mirror();
        tkString substring(int pi, int pf);
        tkString substring(int pi);
        tkString* substring(int* pis, int* pfs);
        tkString leftJoin(std::string str);
        tkString leftJoin(char *str);
        tkString leftJoin(std::string* s);
        tkString leftJoin(char** strs);
        tkString leftJoin(tkString s);
        tkString leftJoin(tkString* s);
        tkString leftJoin(char s);
        tkString rightJoin(std::string s);
        tkString rightJoin(char* s);
        tkString rightJoin(std::string* s);
        tkString rightJoin(char** s);
        tkString rightJoin(tkString s);
        tkString rightJoin(tkString* s);
        tkString rightJoin(char s);
        tkString truncate(int size);
        tkString truncateFromFinal(int size);
        tkString truncateFrom(int pi);
        tkString truncateFrom(int pi, int pf);
        tkString shuffle(int rounds = 1);
        tkString urlFriendly();
        tkString format(std::string dlim, std::string data, bool regexUsed = false); //str str
        tkString format(char* dlim, std::string data, bool regexUsed = false);              //char str
        tkString format(char* dlim, char* data, bool regexUsed = false);                    //char char
        tkString format(std::string dlim, char* data, bool regexUsed = false);       //str char
        tkString format(std::string dlim, tkString data, bool regexUsed = false);    //str tstr
        tkString format(std::string dlim, tkString* data, bool regexUsed = false);   //str tstr*
        tkString format(char* dlim, tkString* data, bool regexUsed = false);                //char tstr*
        tkString format(char* dlim, tkString data, bool regexUsed = false);                 //char tstr
        tkString format(std::string dlim, std::string* data, bool regexUsed = false);//str str*
        tkString format(char *dlim, std::string* data, bool regexUsed = false);             //char str*
        tkString format(std::string dlim, tkAny data, bool regexUsed = false);       //str tany
        tkString format(char  *dlim, tkAny data, bool regexUsed = false);                   //char tany
        tkString format(std::string dlim, tkAny* data, bool regexUsed = false);      //str tany*
        tkString format(char *dlim, tkAny* data, bool regexUsed = false);                   //char tany*
        tkString decodeUrl();
        tkString normalize();
        tkString randomCase(int rounds = 1);
        tkString removeNotFriendly();

        // Busca e verificacao
        bool startWith(std::string mask, bool regexUsed = true);
        bool startWith(char* mask, bool regexUsed = true);
        bool endWith(std::string mask, bool regexUsed = true);
        bool endWith(char* mask, bool regexUsed = true);
        bool startsWith(char mask, bool regexUsed = true);
        bool endsWith(char mask, bool regexUsed = true);
        char charAt(int p);
        int length();
        int indexOf(char ch);
        int* indexOf(std::string mask, bool regexUsed = true);
        int* indexOf(char *mask, bool regexUsed = true);
        int** allIndexOf(std::string mask, bool regexUsed = true);
        int** allIndexOf(char *mask, bool regexUsed = true);
        int* lastIndexOf(std::string mask, bool regexUsed = true);
        int* lastIndexOf(char *mask, bool regexUsed = true);
        int lastIndexOf(char ch);
        int* allIndexOf(char ch);
        bool contains(std::string mask, bool regexUsed = true);
        bool contains(char* mask, bool regexUsed = true);
        int** oCurrencesOf(std::string mask, bool regexUsed = true);
        int** oCurrencesOf(char *mask, bool regexUsed = true);
        int** oCurrencesOf(char ch);
        int** oCurrencesOf(tkString s, bool regexUsed = true);
        
        // Getter e Setter
        std::string get();
        void set(std::string);
        void set(tkString);
        void set(char *str);

        // Auxiliares
        int* getNumbers();
        tkString toBase64();
        tkString fromBase64();
        tkString randomString(int rounds = 1);
        bool isEmpty();
        bool isPalindrome();
        bool isLowerCase();
        bool isUpperCase();
        bool isNumeric();
        int levenshteinDistance();

    private:
        std::string _str = "";
        tkInternalSearch evalueExpression(std::string mask);
        tkInternalSearch evalueExpression(char *mask);
    };
} // tkv
#endif