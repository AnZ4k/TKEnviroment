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
        tkString *split(std::string mask, bool regexUsed = true);                               //ok
        tkString *split(char *mask, bool regexUsed = true);                                     //ok
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
        tkString upper(std::string mask = "", bool regexUsed = true);                           //ok
        tkString upper(char *str, bool regexUsed = true);                                       //ok
        tkString lower(std::string mask = "", bool regexUsed = true);                           //ok
        tkString lower(char *str, bool regexUsed = true);                                       //ok
        tkString reverse();                                                                     //ok
        tkString mirror();                                                                      //ok
        tkString substring(int pi, int pf);                                                                 //ok
        tkString substring(int pi);                                                                         //ok
        tkString* substring(int* pis, int* pfs);                                                            //ok
        tkString leftJoin(std::string str);                                                                 //ok 
        tkString leftJoin(char *str);                                                                       //ok 
        tkString leftJoin(std::string* s);                                                                  //ok 
        tkString leftJoin(char** strs);                                                                     //ok 
        tkString leftJoin(tkString s);                                                                      //ok 
        tkString leftJoin(tkString* s);                                                                     //ok 
        tkString leftJoin(char s);                                                                          //ok 
        tkString rightJoin(std::string s);                                                                  //ok     
        tkString rightJoin(char* s);                                                                        //ok 
        tkString rightJoin(std::string* s);                                                                 //ok     
        tkString rightJoin(char** s);                                                                       //ok     
        tkString rightJoin(tkString s);                                                                     //ok     
        tkString rightJoin(tkString* s);                                                                    //ok     
        tkString rightJoin(char s);                                                                         //ok     
        tkString truncate(int size);                                                                        //ok        
        tkString truncateFromFinal(int size);                                                               //ok    
        tkString truncateFrom(int pi, int pf);                                                              //ok    
        tkString shuffle();                                                                                 //ok   
        tkString urlFriendly();           
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