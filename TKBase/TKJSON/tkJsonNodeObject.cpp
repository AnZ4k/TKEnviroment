#include "TKJsonNodeObject.hpp"

tkv::TKJSONObjectNode::TKJSONObjectNode(tkv::tkString pKey, tkv::tkString pValue)
{
    this->setKey(pKey);
    this->setValue(pValue);
}

tkv::TKJSONObjectNode::TKJSONObjectNode(tkv::tkString pKey, tkv::tkString pValue, tkv::TKJSONObjectNode pNode)
{
    this->setKey(pKey);
    this->setValue(pValue);
    this->addNode(pNode);
}

tkv::TKJSONObjectNode::TKJSONObjectNode(tkv::tkString pKey, tkv::tkString pValue, std::deque<tkv::TKJSONObjectNode> pNodeChildren)
{
    this->setKey(pKey);
    this->setValue(pValue);
    this->setChildren(pNodeChildren);
}

tkv::TKJSONObjectNode::~TKJSONObjectNode()
{
    this->mChildren.~deque();
}

tkv::tkString tkv::TKJSONObjectNode::getKey()
{
    return this->iKey.get();
}

tkv::tkString tkv::TKJSONObjectNode::getValue()
{
    return this->iValue.get();
}

std::deque<tkv::TKJSONObjectNode>* tkv::TKJSONObjectNode::getChildren()
{
    return &this->mChildren;
}

void tkv::TKJSONObjectNode::setKey(tkv::tkString pKey)
{
    this->iKey.set(pKey);
}

void tkv::TKJSONObjectNode::setValue(tkv::tkString pValue)
{
    this->iValue.set(pValue);
}

void tkv::TKJSONObjectNode::setKey(char* pKey)
{
    this->iKey.set(pKey);
}

void tkv::TKJSONObjectNode::setValue(char* pValue)
{
    this->iValue.set(pValue);
}

void tkv::TKJSONObjectNode::setChildren(std::deque<tkv::TKJSONObjectNode> pChildren)
{
    if (pChildren.empty())
        return;
    
    this->mChildren = pChildren;
}

tkv::TKJSONObjectNode tkv::TKJSONObjectNode::addNode(tkv::TKJSONObjectNode pNode, bool pAtEnd)
{
    if (pAtEnd)
    {
        this->mChildren.push_back(pNode);
        return;
    }

    this->mChildren.push_front(pNode);

    return *this;
}

tkv::TKJSONObjectNode* tkv::TKJSONObjectNode::getNode(int pIndex)
{
    if (pIndex >= this->getChildren()->size())
    {
        return this->getNode(this->getChildren()->size() -1);
    }
    else if (pIndex < 0)
    {
        return this->getNode(0);
    }

    return &this->getChildren()->at(pIndex);
}

tkv::TKJSONObjectNode* tkv::TKJSONObjectNode::getNode(char *pKey)
{
    return this->getNode(static_cast<std::string>(pKey));
}

tkv::TKJSONObjectNode* tkv::TKJSONObjectNode::getNode(std::string pKey)
{
    for (int i = 0; i < this->getChildren()->size(); i++)
    {
        if (this->getChildren()->at(i).getKey().get() == pKey)
        {
            return &this->getChildren()->at(i);
        }
    }
    return nullptr;
}