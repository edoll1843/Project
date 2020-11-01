#pragma once
#include "pch.h"
class Block
{
private:
	int m_number, b_x, b_y;//�� ���� ���ڿ� ��ǥx,y

	//Block�� ����� ����� ����Ű�� ������
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

