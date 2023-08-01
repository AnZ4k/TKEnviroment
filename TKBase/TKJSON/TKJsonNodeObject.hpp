#ifndef TKJSONNODEOBJECT
#define TKJSONNODEOBJECT
#include "TKJsonIncludes.hpp"
namespace tkv
{   

/**
 * TODO:
 * asBool  asInt asStr asFloat
 * 
 * TODO:
 * operators (= [] v=)
 * 
 * TODO: 
 * setBool setInt setStr setFloat
 */
    class TKJSONObjectNode 
    {
        public:
            TKJSONObjectNode(tkv::tkString pKey, tkv::tkString pValue);
            TKJSONObjectNode(tkv::tkString pKey, tkv::tkString pValue, tkv::TKJSONObjectNode pNode);
            TKJSONObjectNode(tkv::tkString pKey, tkv::tkString pValue, std::deque<tkv::TKJSONObjectNode> pNodeChildren);
            ~TKJSONObjectNode();
            tkv::tkString getKey();
            tkv::tkString getValue();
            std::deque<tkv::TKJSONObjectNode>* getChildren();
            
            void setKey(tkv::tkString pKey);
            void setValue(tkv::tkString pValue);
            void setKey(char* pKey);
            void setValue(char* pValue);
            void setChildren(std::deque<tkv::TKJSONObjectNode> pChildren);
            
            TKJSONObjectNode addNode(tkv::TKJSONObjectNode pNode, bool pAtEnd = true);
            TKJSONObjectNode put(tkv::tkString const key, tkv::tkString const val);
            
            tkv::TKJSONObjectNode *getNode(int pIndex);
            tkv::TKJSONObjectNode *getNode(char* pKey);
            tkv::TKJSONObjectNode *getNode(std::string pKey);

            TKJSONObjectNode& operator = (bool);
            TKJSONObjectNode& operator = (int);
            TKJSONObjectNode& operator = (float);
            TKJSONObjectNode& operator = (double);
            TKJSONObjectNode& operator = (std::string);
            TKJSONObjectNode& operator = (tkv::tkString);
            TKJSONObjectNode& operator = (char*);
            TKJSONObjectNode& operator = (char);

            operator std::string() const;
            
            float asFloat(void);
            int asInt(void);
            bool asBool(void);
            double asDouble(void);
            std::string asstring(void);
            char* asCSTR(void);
            tkv::tkString asTKString(void);

        private:
            tkv::tkString iKey;
            tkv::tkString iValue;
            std::deque<tkv::TKJSONObjectNode> mChildren;      
    };
}
#endif