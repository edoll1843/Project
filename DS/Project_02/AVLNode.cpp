#include "AVLNode.h"

AVLNode::AVLNode()
{
}

AVLNode::~AVLNode()
{
}

CityData * AVLNode::GetCityData()
{
	return pCityData; //return city data
}

AVLNode * AVLNode::GetLeft()
{
	if(pLeft ==NULL) 
	{ //if left is NULL
		return 0; //return 0
	}
	else
	{ //else
	return pLeft; //return left
	}
}

AVLNode * AVLNode::GetRight()
{
	if(pRight == NULL)
	{
		return 0;
	}
	else
	{
		return pRight;//rerturn right
	}
}

int AVLNode::GetmBF()
{
	return mBF;
}

void AVLNode::SetCityData(CityData * node)
{
	pCityData = node; //city data is node
}

void AVLNode::SetLeft(AVLNode * node)
{
	pLeft = node; //left is node
}

void AVLNode::SetRight(AVLNode * node)
{
	pRight = node; //right is node
}

void AVLNode::SetmBF(int n)
{
	mBF = n;
}
