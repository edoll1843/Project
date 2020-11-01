#include "BSTNode.h"

BSTNode::BSTNode()
{
	this->pLeft = nullptr;//set
	this->pRight = nullptr;//set
	this->pNext = nullptr;//set
	this->data = 0;//set
}
BSTNode::BSTNode(int Data)
{
	this->pLeft = nullptr;//set
	this->pRight = nullptr;//set
	this->pNext = nullptr;//set
	this->data = Data;//set
}
BSTNode::~BSTNode()
{

}

void BSTNode::SetLeft(BSTNode* Left)
{
	this->pLeft = Left;//set
}
void BSTNode::SetRight(BSTNode* Right)
{
	this->pRight = Right;//set
}
void BSTNode::SetNext(BSTNode* Next)
{
	this->pNext = Next;
}//set
void BSTNode::SetData(int Data)
{
	this->data = Data;//set
}

BSTNode* BSTNode::GetLeft()
{
	return this->pLeft;//set
}
BSTNode* BSTNode::GetRight()
{//set
	return this->pRight;
}
BSTNode* BSTNode::GetNext()
{//set
	return this->pNext;
}
int BSTNode::GetData()
{//set
	return this->data;
}