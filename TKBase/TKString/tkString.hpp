#include <string>
#include <regex>
#include <random>

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
        tkString();                                                                             //ok
        tkString(char* str);                                                                    //ok
        tkString(std::string str);                                                              //ok
        tkString(std::string* str);                                                             //ok                                                                          
        tkString(tkString* str);                                                                //ok
        tkString &operator=(char* str);                                                         //ok
        tkString &operator=(std::string str);                                                   //ok
        tkString &operator=(tkString);                                                          //ok
        tkString &operator+=(char* str);                                                        //ok
        tkString &operator+=(std::string str);                                                  //ok
        tkString &operator+=(char);                                                             //ok
        tkString &operator+=(tkString);                                                         //ok
        ~tkString();                                                                            //ok

        char operator[](int index);                                                             //ok

        // Manipulacao de strings
        tkString *split(std::string mask, bool regexUsed = true);
        tkString *split(char *mask, bool regexUsed = true);
        tkString **split(std::string *mask, bool regexUsed = true);
        tkString **split(char **mask, bool regexUsed = true);
        tkString replace(std::string mask, std::string newText, bool regexUsed = true);         //ok
        tkString replace(std::string mask, char c, bool regexUsed = true);                      //ok
        tkString replace(std::string mask, char* newText, bool regexUsed = true);               //ok
        tkString replace(std::string *mask, std::string* newText, bool regexUsed = true);       //ok
        tkString replace(std::string *mask, std::string newText, bool regexUsed = true);        //ok
        tkString replace(std::string *mask, char** newText, bool regexUsed = true);             //ok
        tkString replace(std::string *mask, char* newText, bool regexUsed = true);              //ok
        tkString replace(char *mask, std::string newText, bool regexUsed = true);               //ok
        tkString replace(char *mask, char *newText, bool regexUsed = true);                     //ok
        tkString replace(char *mask, char c, bool regexUsed = true);                            //ok
        tkString replace(char **mask, char** newText, bool regexUsed = true);                   //ok
        tkString replace(char **mask, std::string* newText, bool regexUsed = true);             //ok
        tkString replace(char **mask, std::string newText, bool regexUsed = true);              //ok
        tkString trim();                                                                        //ok    
        tkString trimLeft();                                                                    //ok
        tkString trimRight();                                                                   //ok
        tkString upper(std::string mask = "", bool regexUsed = true);
        tkString upper(char *str, bool regexUsed = true);                                       //ok
        tkString lower(std::string mask = "", bool regexUsed = true);
        tkString lower(char *str, bool regexUsed = true);                                       //ok
        tkString camel(std::string mask = "", bool regexUsed = true);
        tkString camel(char *str, bool regexUsed = true);                                       //ok
        tkString reverse();
        tkString mirror();
        tkString substring(int pi, int pf);                                                                 //ok
        tkString substring(int pi);                                                                         //ok
        tkString* substring(int* pis, int* pfs);                                                            //ok
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
        tkString format(std::string dlim, std::string data, bool regexUsed = false); 
        tkString format(char* dlim, std::string data, bool regexUsed = false);       
        tkString format(char* dlim, char* data, bool regexUsed = false);             
        tkString format(std::string dlim, char* data, bool regexUsed = false);       
        tkString format(std::string dlim, tkString data, bool regexUsed = false);    
        tkString format(std::string dlim, tkString* data, bool regexUsed = false);   
        tkString format(char* dlim, tkString* data, bool regexUsed = false);         
        tkString format(char* dlim, tkString data, bool regexUsed = false);          
        tkString format(std::string dlim, std::string* data, bool regexUsed = false);
        tkString format(char *dlim, std::string* data, bool regexUsed = false);      
        tkString format(std::string dlim, tkAny data, bool regexUsed = false);       
        tkString format(char  *dlim, tkAny data, bool regexUsed = false);            
        tkString format(std::string dlim, tkAny* data, bool regexUsed = false);      
        tkString format(char *dlim, tkAny* data, bool regexUsed = false);            
        tkString decodeUrl();
        tkString normalize();
        tkString randomCase(int rounds = 1);
        tkString removeNotFriendly();

        // Busca e verificacao
        bool startWith(std::string mask, bool regexUsed = true);                            //ok
        bool startWith(char* mask, bool regexUsed = true);                                  //ok
        bool startWith(char mask);                                                          //ok
        bool endWith(std::string mask, bool regexUsed = true);                              //ok
        bool endWith(char* mask, bool regexUsed = true);                                    //ok
        bool endsWith(char mask);                                                           //ok
        char charAt(int p);                                                                 //ok
        int length();                                                                       //ok
        int indexOf(char ch);                                                               //ok
        int* indexOf(std::string mask, bool regexUsed = true);                              //ok
        int* indexOf(char *mask, bool regexUsed = true);                                    //ok
        int** allIndexOf(std::string mask, bool regexUsed = true);                          //ok
        int** allIndexOf(char *mask, bool regexUsed = true);                                //ok
        int* lastIndexOf(std::string mask, bool regexUsed = true);                          //ok
        int* lastIndexOf(char *mask, bool regexUsed = true);                                //ok
        int lastIndexOf(char ch);                                                           //ok
        int* allIndexOf(char ch);                                                           //ok
        bool contains(std::string mask, bool regexUsed = true);                             //ok
        bool contains(char* mask, bool regexUsed = true);                                   //ok
        bool contains(char mask);                                                           //ok
        int occurrencesOf(std::string mask, bool regexUsed = true);                         //ok
        int occurrencesOf(char *mask, bool regexUsed = true);                               //ok
        int occurrencesOf(char ch);                                                         //ok
        
        // Getter e Setter
        std::string get();                                                                  //ok
        void set(std::string);                                                              //ok
        void set(tkString);                                                                 //ok
        void set(char *str);                                                                //ok

        // Auxiliares
        int* getNumbers();                                                                  //ok
        tkString encodeBase64();                                                            //ok    
        tkString decodeBase64();                                                            //ok
        tkString randomString(int length);                                                  //ok
        bool isEmpty();                                                                     //ok
        bool isPalindrome();                                                                //ok
        bool isLowerCase();                                                                 //ok
        bool isUpperCase();                                                                 //ok
        bool isNumeric();                                                                   //ok
        int levenshteinDistance(std::string str);                                           //ok
        int levenshteinDistance(char* str);                                                 //ok

    private:
        std::string _str = "";
        tkInternalSearch evalueExpression(std::string mask);                                //ok
        tkInternalSearch evalueExpression(char *mask);                                      //ok
    };
} // tkv
#endif