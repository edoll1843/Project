#pragma once
#include "BSTNode.h"

class Queue {
private:
	BSTNode* Head;//set
	int size;//set

public:
	Queue();
	~Queue();

	bool IsEmpty();//set
	bool Push(BSTNode* Node);//set
	void Pop();//set
	BSTNode* Front();//set
	void Inorder(BSTNode* now);//set
	void Postorder(BSTNode* now);//set
	void Preorder(BSTNode* now);//set
};