#include "Queue.h"
#include <iostream>



Queue::Queue()
{
	this->Head = nullptr;//head is null
	this->size = 0;//size is 0
}
Queue::~Queue()
{

}
bool Queue::IsEmpty()
{
	if (size == 0)//set
		return true;
}

bool Queue::Push(BSTNode* Node)
{
	if (size == 0)
	{
		this->Head = Node;//set
		size++;
		return true;//set
	}

	BSTNode* parent = nullptr;//set
	BSTNode* current = this->Head;//set

	while (current != nullptr)
	{//current is no null
		parent = current;
		if (Node->GetData() < parent->GetData())
		{//node data is smaller than parent
			current = current->GetLeft();
		}
		else {//else
			current = current->GetRight();
		}
	}

	if (Node->GetData() < parent->GetData())
	{//node data is smaller than paret
		parent->SetLeft(Node);
	}
	else
	{
		parent->SetRight(Node);
	}

	size++;
	return true;
}

void Queue::Pop()
{

}
BSTNode* Queue::Front()
{
	if (size != 0)
	{
		return this->Head;
	}
}

void Queue::Inorder(BSTNode* now)
{
	if (now != nullptr)
	{
		//inorder
		this->Inorder(now->GetLeft());
		std::cout << now->GetData() << " ";
		this->Inorder(now->GetRight());

	}
}
void Queue::Postorder(BSTNode* now)
{
	if (now != nullptr)
	{
		//preorder
		this->Postorder(now->GetLeft());
		this->Postorder(now->GetRight());
		std::cout << now->GetData() << " ";
	}
}
void Queue::Preorder(BSTNode* now)
{
	if (now != nullptr)
	{//preorder
		std::cout << now->GetData() << " ";
		this->Preorder(now->GetLeft());
		this->Preorder(now->GetRight());
	}
}
