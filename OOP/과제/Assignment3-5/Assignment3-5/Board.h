#pragma once
class MyBlock
{
private:
	int m_number, m_x, m_y;//declare
	MyBlock* m_pup;//declare
	MyBlock* m_pDown;//declare
	MyBlock* m_pLeft;//declare
	MyBlock* m_pRight;//declare

public:
	MyBlock();//declare
	MyBlock(int num, int x, int y);//declare
	~MyBlock();//declare
	
	void SetLeft(MyBlock *Left);//set
	void SetRight(MyBlock* Right);//set
	void SetUp(MyBlock* Up);//set
	void SetDown(MyBlock* Down);//set

	void SetNum(int num);//set
	void Set_x(int x);//set
	void Set_y(int y);//set

	MyBlock* GetLeft();//get
	MyBlock* GetRight();//get
	MyBlock* GetUp();//get
	MyBlock* GetDown();//get

	int GetNum();//get
	int Get_x();//get
	int Get_y();//get
};

class MyBoard
{
private:
	MyBlock* m_pHead;//declare

public:
	MyBoard();
	~MyBoard();
	
	bool up();//declare
	int up(MyBlock* node);//declare

	bool down();//declare
	int down(MyBlock* node);//declare

	bool left();//declare
	int left(MyBlock * node);//declare

	bool right();//declare
	int right(MyBlock* node);//declare

	void print_board();//declare
	void make_board(MyBlock * node);//declare
	void connect();//declare
	bool putnum();//declare
	bool copy(MyBoard  board,MyBoard temp_board);//declare
	bool check(MyBoard  board, MyBoard temp_board);//declare
	bool win();//declare

};


