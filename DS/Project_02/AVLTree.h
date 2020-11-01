#include "AVLNode.h"
#include <iostream>
#include <fstream>// header file declare
using namespace std;
class AVLTree
{
public:
	AVLNode * root;	// AVLTree Root
	ofstream * flog;

public:
	AVLTree(ofstream * flog); //fucntion declare
	~AVLTree();//fucntion declare
	AVLNode * sa;//fucntion declare
	int num2;//fucntion declare
	AVLNode  *  Getroot();//fucntion declare
	void	 	Setroot(AVLNode * node);//fucntion declare
	bool		Insert(CityData * node);//fucntion declare
	CityData *	Delete(int num);//fucntion declare
	CityData *	Search(int num);//fucntion declare
	bool		Print(AVLNode* root);//fucntion declare

	int height(AVLNode * temp);//fucntion declare
	int diff(AVLNode * temp);//fucntion declare
	AVLNode * rr(AVLNode * parent);//fucntion declare
	AVLNode * ll(AVLNode * parent);//fucntion declare
	AVLNode * lr(AVLNode * parent);//fucntion declare
	AVLNode * rl(AVLNode * parent);//fucntion declare
	AVLNode * balance(AVLNode * temp);//fucntion declare
	AVLNode * inorder_tree(AVLNode * tree);//fucntion declare
};

