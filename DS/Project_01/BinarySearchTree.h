#include "TreeNode.h"
#include <iostream>
#include <cstring>
#include <string>

class BinarySearchTree
{
	friend class TransferWindowManager;
private:
	TreeNode * m_root; //root
public:
	BinarySearchTree() { m_root = NULL; } //root is NULL
	BinarySearchTree(SoccerPlayerData& data); //funtion declaer
	~BinarySearchTree();//funtion declaer

	void insert(SoccerPlayerData& data);//funtion declaer
	void insert_arr(SoccerPlayerData & data);//funtion declaer
	void deletion(int ability); ////funtion declaer ability = key
	void Clear(TreeNode * root);//funtion declaer
	friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree& tree)//inorder
	{
		while (tree.m_root != NULL)//while root is NULL
		{	// code to print in-order traversal of a binary search tree
			os << tree.m_root;
			return os;
		}
	}
};

