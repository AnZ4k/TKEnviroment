#ifndef TKJSONNODEOBJECT
#define TKJSONNODEOBJECT
#include "TKJsonIncludes.hpp"
namespace tkv
{
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
            
            void addNode(tkv::TKJSONObjectNode pNode, bool pAtEnd = true);
            
            tkv::TKJSONObjectNode *getNode(int pIndex);
            tkv::TKJSONObjectNode *getNode(char* pKey);
            tkv::TKJSONObjectNode *getNode(std::string pKey);
        private:
            tkv::tkString iKey;
            tkv::tkString iValue;
            std::deque<tkv::TKJSONObjectNode> mChildren;      
    };
}
#endif