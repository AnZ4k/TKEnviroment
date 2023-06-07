#include <string>
#include <regex>
#include <random>
#include <iostream>
#include <vector>

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
        tkString &operator=(const char* str);                                                        
        tkString &operator=(std::string str);                                                   
        tkString &operator=(tkString);                                                          
        tkString &operator+=(char* str);
        tkString &operator+=(const char* str);                                                        
        tkString &operator+=(std::string str);                                                  
        tkString &operator+=(char);                                                             
        tkString &operator+=(tkString);                                                         
        ~tkString();                                                                            
        char operator[](int index);                                                             

        // Manipulacao de strings
        std::vector<tkString> split(std::string mask, bool regexUsed = true);                                
        std::vector<tkString> split(char *mask, bool regexUsed = true);                                      
        tkString replace(std::string mask, std::string newText, bool regexUsed = true);            
        tkString replace(std::string mask, char c, bool regexUsed = true);                         
        tkString replace(std::string mask, char* newText, bool regexUsed = true);                  
        tkString replace(std::vector<std::string> mask, std::vector<std::string> newText, bool regexUsed = true);        
        tkString replace(std::vector<std::string> mask, std::string newText, bool regexUsed = true);  
        tkString replace(char c, std::string newText);                                           
        tkString replace(char c, char* newText);                                                 
        tkString replace(char *mask, std::string newText, bool regexUsed = true);                
        tkString replace(char *mask, char *newText, bool regexUsed = true);                      
        tkString replace(char *mask, char c, bool regexUsed = true);                             
        tkString trim();                                                                                 
        tkString trimLeft();                                                                        
        tkString trimRight();                                                                       
        tkString upper(std::string mask = "", bool regexUsed = true);                               
        tkString upper(char *str, bool regexUsed = true);                                              
        tkString lower(std::string mask = "", bool regexUsed = true);                                  
        tkString lower(char *str, bool regexUsed = true);                                              
        tkString reverse();                                                                         
        tkString mirror();                                                                          
        tkString substring(int pi, int pf);                                                                  
        tkString substring(int pi);                                                                          
        tkString* substring(int* pis, int* pfs);                                                             
        tkString leftJoin(std::string str);                                                                   
        tkString leftJoin(char *str);                                                                        
        tkString leftJoin(tkString s);                                                                        
        tkString leftJoin(char s);                                                                            
        tkString leftJoin(std::vector<std::string> s);                                                        
        tkString rightJoin(std::string s);                                                                        
        tkString rightJoin(char* s);                                                                             
        tkString rightJoin(tkString s);                                                                       
        tkString rightJoin(std::vector<std::string> s);                                                          
        tkString rightJoin(char s);                                                                               
        tkString truncate(int size);                                                                                
        tkString truncateFromFinal(int size);                                                                   
        tkString truncateFrom(int pi, int pf);                                                                  
        tkString shuffle();                                                                                    
        tkString randomCase();                                                                               

        // Busca e verificacao
        bool startWith(std::string mask, bool regexUsed = true);                                
        bool startWith(char* mask, bool regexUsed = true);                                      
        bool startWith(char mask);                                                              
        bool endWith(std::string mask, bool regexUsed = true);                                  
        bool endWith(char* mask, bool regexUsed = true);                                        
        bool endsWith(char mask);                                                               
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
        bool contains(char mask);                                                               
        int occurrencesOf(std::string mask, bool regexUsed = true);                             
        int occurrencesOf(char *mask, bool regexUsed = true);                                   
        int occurrencesOf(char ch);                                                             
        
        // Getter e Setter
        std::string get();                                                                      
        void set(std::string);                                                                  
        void set(tkString);                                                                     
        void set(char *str);   
        void set(const char* str);                                                                 

        // Auxiliares
        int* getNumbers();                                                                      
        tkString encodeBase64();                                                                
        tkString decodeBase64();                                                                
        tkString randomString(int length);                                                      
        bool isEmpty();                                                                         
        bool isPalindrome();                                                                    
        bool isLowerCase();                                                                     
        bool isUpperCase();                                                                     
        bool isNumeric();                                                                       
        int levenshteinDistance(std::string str);                                               
        int levenshteinDistance(char* str);                                                     

    private:
        std::string _str = "";
        tkInternalSearch evalueExpression(std::string mask);                                
        tkInternalSearch evalueExpression(char *mask);                                      
    };

} // tkv
#endif