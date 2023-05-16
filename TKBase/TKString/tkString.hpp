#include <string>
using std::string;

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

namespace tkv {

    class tkString {
    public:
        // Construtores
        tkString();
        tkString(const char* str);
        tkString(const std::string& str);
        tkString(const tkString& str);
        ~tkString();

        // Manipulacao de strings
        tkString* split(const std::string mask, const bool regexUsed = true);
        tkString** split(const std::string* mask, const bool regexUsed = true);
        tkString replace(const std::string mask, const std::string newText, const bool regexUsed = true);
        tkString replace(const std::string* mask, const std::string* newText, const bool regexUsed = true);
        tkString replace(const std::string* mask, const std::string newText, const bool regexUsed = true);
        tkString replace(const std::string mask, const char c, const bool regexUsed = true);
        tkString trim();
        tkString trimLeft();
        tkString trimRight();
        tkString upper(const std::string mask = "", const bool regexUsed = true);
        tkString lower(const std::string mask = "", const bool regexUsed = true);
        tkString camel(const std::string mask = "", const bool regexUsed = true);
        tkString reverse();
        tkString mirror();
        tkString substring(int pi, int pf);
        tkString substring(int pi);
        tkString* substring(int* pis, int* pfs);
        tkString leftJoin(const std::string s);
        tkString leftJoin(const std::string* s);
        tkString leftJoin(const tkString s);
        tkString leftJoin(const tkString* s);
        tkString leftJoin(const char s);
        tkString rightJoin(const std::string s);
        tkString rightJoin(const std::string* s);
        tkString rightJoin(const tkString s);
        tkString rightJoin(const tkString* s);
        tkString rightJoin(const char s);
        tkString truncate(const int size);
        tkString truncateFromFinal(const int size);
        tkString truncateFrom(const int pi);
        tkString truncateFrom(const int pi, const int pf);
        tkString shuffle(const int rounds = 1);
        tkString urlFriendly();
        tkString format(const std::string dlim = "{}", const std::string* data, const bool regexUsed = false);
        tkString format(const std::string dlim = "{}", const tkString* data, const bool regexUsed = false);
        tkString format(const std::string dlim = "{}", const std::string* data, const bool regexUsed = false);
        tkString format(const std::string dlim = "{}", const tkAny data, const bool regexUsed = false);
        tkString format(const std::string dlim = "{}", const tkAny* data, const bool regexUsed = false);
        tkString decodeUrl();
        tkString normalize();
        tkString randomCase(const int rounds = 1);
        tkString removeNotFriendly();

        // Busca e verificacao
        bool startWith(const std::string mask, const bool regexUsed = true);
        bool endWith(const std::string mask, const bool regexUsed = true);
        bool startsWith(const char mask, const bool regexUsed = true);
        bool endsWith(const char mask, const bool regexUsed = true);
        char charAt(int p);
        int length();
        int indexOf(const char ch);
        int* indexOf(const std::string mask, const bool regexUsed = true);
        int** allIndexOf(const std::string mask, const bool regexUsed = true);
        int* lastIndexOf(const std::string mask, const bool regexUsed = true);
        int lastIndexOf(const char ch);
        int* allIndexOf(const char ch);
        bool contains(const std::string* mask, const bool regexUsed = true);
        int oCurrencesOf(const std::string mask, const bool regexUsed = true);
        int oCurrencesOf(const char ch);
        int oCurrencesOf(const tkString s);
        int* oCurrencesOf(const std::string* mask, const bool regexUsed = true);
        int* oCurrencesOf(const char* ch);
        int* oCurrencesOf(const tkString* s);
        
        // Getter e Setter
        std::string get();
        void set(const std::string);
        void set(const tkString);

        // Auxiliares
        int* getNumbers();
        tkString toBase64();
        tkString fromBase64();
        tkString randomString(const int rounds = 1);
        bool isEmpty();
        bool isPalindrome();
        bool isLowerCase();
        bool isUpperCase();
        bool isNumeric();
        int levenshteinDistance();

    private:
        typedef struct tkInternalSearch {
            int** pos;
            bool founded;
        } tkInternalSearch;

        std::string _str = "";
        tkInternalSearch evalueExpression(std::string mask);
    };
} // tkv