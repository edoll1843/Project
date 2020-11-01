#include "pch.h"
#include "Block.h"



Block::Block()
{

}


Block::~Block()
{
}

int Block::getNum()
{
	return m_number;
}

int Block::getX()
{
	return b_x;
}

int Block::getY()
{
	return b_y;
}

void Block::setNum(int new_num)
{
	m_number = new_num;
}

void Block::setX(int newx)
{
	b_x = newx;
}

void Block::setY(int newy)
{
	b_y = newy;
}



void Block::setUp(Block* NewNode)
{
	p_Up = NewNode;
}

void Block::setDown(Block* NewNode)
{
	p_Down = NewNode;
}

void Block::setRight(Block* NewNode)
{
	p_Right = NewNode;
}

void Block::setLeft(Block* NewNode)
{
	p_Left = NewNode;
}

Block* Block::getUp()
{
	return p_Up;
}

Block* Block::getDown()
{
	return p_Down;
}

Block* Block::getRight()
{
	return p_Right;
}

Block* Block::getLeft()
{
	return p_Left;
}

