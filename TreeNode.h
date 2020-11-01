#include "SoccerPlayerData.h"
#include <iostream>

class TreeNode
{
	friend class BinarySearchTree;
	friend class TransferWindowManager;
private:
	SoccerPlayerData m_data;
	TreeNode* m_left;
	TreeNode* m_right;
public:
	TreeNode() :m_left(NULL), m_right(NULL) {}// function declaer
	~TreeNode() { }// function declaer
	TreeNode(SoccerPlayerData & data, TreeNode* left = NULL, TreeNode* right = NULL)// function declaer
	{ //make player 
		this->m_data = data;
		this->m_left = left;
		this->m_right = right;
	}

	friend std::ostream& operator<<(std::ostream& os, const TreeNode* node)//inorder
	{
		if (node != NULL)
		{//code to print in-order traversal of a binary search tree	
			os << node->m_left;
			os << node->m_data << std::endl;
			os << node->m_right;
		}
		return os;
			
	}
};

