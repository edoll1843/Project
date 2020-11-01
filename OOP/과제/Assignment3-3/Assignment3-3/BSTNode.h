#pragma once
class BSTNode {
private:
	BSTNode* pLeft;//set
	BSTNode* pRight;//set
	BSTNode* pNext;//set

	int data;//set

public:
	BSTNode();//set
	BSTNode(int Data);//set
	~BSTNode();//set

	void SetLeft(BSTNode* Left);//set
	void SetRight(BSTNode* Right);//set
	void SetNext(BSTNode* Next);//set
	void SetData(int Data);//set

	BSTNode* GetLeft();//set
	BSTNode* GetRight();//set
	BSTNode* GetNext();//set
	int GetData();//set

};