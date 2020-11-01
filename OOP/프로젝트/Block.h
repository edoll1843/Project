#pragma once
#include "pch.h"
class Block
{
private:
	int m_number, b_x, b_y;//각 블럭의 숫자와 좌표x,y

	//Block의 사방의 블락을 가리키는 포인터
	Block* p_Up;
	Block* p_Down;
	Block* p_Left;
	Block* p_Right;

public:
	Block();
	~Block();

	//data handle
	int getNum();
	int getX();
	int getY();
	void setNum(int new_num);
	void setX(int newx);
	void setY(int newy);


	//link handle
	void setUp(Block* NewNode);
	void setDown(Block* NewNode);
	void setRight(Block* NewNode);
	void setLeft(Block* NewNode);
	Block* getUp();
	Block* getDown();
	Block* getRight();
	Block* getLeft();


};

