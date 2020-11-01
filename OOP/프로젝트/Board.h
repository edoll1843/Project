#pragma once
#include "pch.h"
#include "Block.h"
class Board
{
private:
	Block* Block_Header;
public:
	Board();
	~Board();


	bool Up();
	bool Down();
	bool Left();
	bool Right();

	bool Put_random_num2();//declare
	bool Check_block();//declare

	void printBoard(int count, CFile& outfile, int menu);//declare

	Block* getBlock_x_y(int x, int y);//declare

	void swap(Block* pPivot, char d);//declare

	bool Check_win();//win check
	bool Check_fail();//fail check

	Block* getHead();//��带 ��ȯ


	//rotation - �ð���� �Ǵ� �ݽð����
	void rotation_time();
	void rotation_reverse_time();
};