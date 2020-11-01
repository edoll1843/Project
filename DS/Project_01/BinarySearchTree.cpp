#define _CRT_SECURE_NO_WARNINGS
#include "BinarySearchTree.h"
//#include "SoccerPlayerData.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(SoccerPlayerData & data)
{
}

BinarySearchTree::~BinarySearchTree()
{
	Clear(m_root);//delete memoty
}
void BinarySearchTree::insert_arr(SoccerPlayerData & data)
{// insert arr
	TreeNode * player_arr = new TreeNode(data, NULL, NULL);//make node
	TreeNode * p_arr = m_root; //m_root
	TreeNode * pp_arr = NULL; // reset
	if (p_arr == NULL)  //if p_arr is NULL
	{
		m_root = player_arr; //root is node
		return; 
	}
	else
	{
		while (p_arr) //while until p_arr is not NULL
		{
			pp_arr = p_arr; 
			p_arr = p_arr->m_right; //p_arr is p_arr right
		}
		pp_arr->m_right = player_arr; //insert pp_arr right is plyer_arr
	}
}

void BinarySearchTree::insert(SoccerPlayerData & data)
{//insert Binary search Tree
	TreeNode * player = new TreeNode(data, NULL, NULL);// make new Node
	TreeNode * p = m_root; //reset
	TreeNode * pp = NULL;  //reset
	if (p == NULL)
	{// if root is NULL return
		m_root = player;
		return;
	}
	else //else
	{
		while (p) //while until p is Not NULL
		{
			pp = p; 
			if (data.m_ability < p->m_data.m_ability)
				p = p->m_left;//if new data abli is smaller than predata go left
			else if (data.m_ability > p->m_data.m_ability) //or big go right
				p = p->m_right; 
		}
		if (data.m_ability < pp->m_data.m_ability)
			pp->m_left = player;  //make line with tree
		else
			pp->m_right = player; //make contact with tree
	}
}

void BinarySearchTree::deletion(int ability)
{// delete
	TreeNode * p = m_root, *pp = NULL;
	while (p  && ability != p->m_data.m_ability)//find delete node
	{
		pp = p;
		if (ability < p->m_data.m_ability)
			p = p->m_left;  //if node is small go left
		else
			p = p->m_right; //else go right
	}
	if (p == NULL)//if p is NULL
		return;  //return
	if (p == m_root && p->m_left == NULL && p->m_right == NULL)//if only root
	{
		m_root = NULL;
		delete p;
	}
	else if (p->m_left == NULL && p->m_right == NULL)//if Node is leaf
	{
		if (pp == NULL)
			return; // if no node return
		else if (pp->m_left == p)
		{ //if node's parent's left child
			pp->m_left = NULL;
			delete p;
		}
		else
		{
			pp->m_right = NULL; //if right child
			delete p;
		}
	}
	else if (p->m_left == NULL && p->m_right!=NULL)//if only 1 child (right)
	{
		if (pp == NULL)//pp is NULL
			m_root = p->m_right; // root go right
		else if (pp->m_left == p) //else go left
		{
			pp->m_left = p->m_right; // parent's left is node's right
		}
		else
			pp->m_right = p->m_right; //else
		delete p;
	}
	else if (p->m_left != NULL && p->m_right == NULL)//if only 1child(left)
	{
		if (pp == NULL) // pp is NULL
			m_root = p->m_left; // root go left
		else if (pp->m_left == p) //else go left
			pp->m_left = p->m_left;
		else
			pp->m_right = p->m_left; // else
		delete p;   // delete
	}
	else//node has two child
	{
		TreeNode *prevprev = p;//maximum node's parent node
		TreeNode * prev = prevprev->m_left;//maximum node
		while (prev->m_right != NULL)
		{//find biggest node in left child
			prevprev = prev; //prevprev is pp
			prev = prev->m_right; //
		}
		if (prev->m_left != NULL)
		{//if there are bigegst node in left child 
			//if delete node is maximum node
			if (prevprev->m_left == prev) 
				prevprev->m_left = prev->m_left; 
			else
				prevprev->m_right = prev->m_left;
		}
		else
		{// if delete node is root
			if (prevprev->m_left == prev)
				prevprev->m_left = NULL;
			else//else
				prevprev->m_right = NULL;//put node
		}
		if(p==m_root)
		{
			m_root = prev;
		}
		p->m_data = prev->m_data; //put data
		p = prev; //p is prev
		delete p; // delete
		p = NULL; // p is NULL
	}
}

void BinarySearchTree::Clear(TreeNode * root)
{// delete memory by inorder function
	TreeNode * cur = root;
	if (cur)
	{
		Clear(cur->m_left);
		Clear(cur->m_right);
		delete cur; //delete it
	}
}


