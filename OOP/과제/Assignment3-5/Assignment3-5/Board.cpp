#include "Board.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

MyBlock::MyBlock()
{
	this->m_pLeft = nullptr;//delcare and reset
	this->m_pRight = nullptr;//delcare and reset
	this->m_pup = nullptr;//delcare and reset
	this->m_pDown = nullptr;//delcare and reset
	this->m_number = 0;//delcare and reset
	this->m_x = 0;//delcare and reset
	this->m_y = 0;//delcare and reset
}

MyBlock::MyBlock(int num, int x, int y)
{
	this->m_pLeft = nullptr;//delcare and reset
	this->m_pRight = nullptr;//delcare and reset
	this->m_pup = nullptr;//delcare and reset
	this->m_pDown = nullptr;//delcare and reset
	this->m_number = num;//delcare and reset
	this->m_x = x;//delcare and reset
	this->m_y = y;//delcare and reset
}

MyBlock::~MyBlock()
{
}


void MyBlock::SetLeft(MyBlock* Left)
{//set
	this->m_pLeft = Left;
}

void MyBlock::SetRight(MyBlock* Right)
{//set
	this->m_pRight = Right;
}

void MyBlock::SetUp(MyBlock* Up)
{//set
	this->m_pup = Up;
}

void MyBlock::SetDown(MyBlock* Down)
{//set
	this->m_pDown = Down;
}

void MyBlock::SetNum(int num)
{//set
	this->m_number = num;
}

void MyBlock::Set_x(int x)
{//set
	this->m_x = x;
}

void MyBlock::Set_y(int y)
{//set
	this->m_y = y;
}

MyBlock* MyBlock::GetLeft()
{//get
	return this->m_pLeft;
}

MyBlock* MyBlock::GetRight()
{//get
	return this->m_pRight;
}

MyBlock* MyBlock::GetUp()
{//get
	return this->m_pup;
}

MyBlock* MyBlock::GetDown()
{//get
	return this->m_pDown;
}

int MyBlock::GetNum()
{//get
	return this->m_number;
}

int MyBlock::Get_x()
{//get
	return this->m_x;
}

int MyBlock::Get_y()
{//get
	return this->m_y;
}

MyBoard::MyBoard()
{
	this->m_pHead = nullptr;
}

MyBoard::~MyBoard()
{
}
void MyBoard::print_board()
{
	if (m_pHead == nullptr)
		return;
	MyBlock* cur = m_pHead;
	MyBlock* temp = m_pHead;
	cout << endl;
	cout << "[Board]" << endl;
	for (int a = 0; a < 4; a++)
	{
		cout << "[	";
		for (int b = 0; b < 4; b++)
		{
			if (cur->GetNum() == 0)
			{//if node num is 0
				cout << "-	";
			}
			else
			{//node is none 0
				cout << cur->GetNum() << "	";
			}
			if (cur->GetRight() == nullptr)
				continue;
			cur = cur->GetRight();
		}
		cout << "]" << endl;
		if (temp->GetDown() == nullptr)
			break;
		temp = temp->GetDown();
		cur = temp;
	}

}
void MyBoard::make_board(MyBlock* node)
{
	if (m_pHead == nullptr)
	{//if head is null
		m_pHead = node;
		return;
	}
	MyBlock* cur = m_pHead;
	if (node->Get_y() == 0)
	{//if y is 0
		while (1)
		{
			if (cur->GetDown() == nullptr)
				break;
			cur = cur->GetDown();

		}
		cur->SetDown(node);//set
		node->SetUp(cur);//set
		return;
	}
	else
	{//y is no 0
		while (1)
		{
			if (cur->GetDown() == nullptr)
				break;
			cur = cur->GetDown();
		}
		for (int a = 0; a < 3; a++)
		{
			if (cur->GetRight() == nullptr)
			{
				cur->SetRight(node);//set
				node->SetLeft(cur);//set
				return;
			}
			cur = cur->GetRight();
		}
	}



}
void MyBoard::connect()
{
	MyBlock* cur = m_pHead;//declare
	MyBlock* temp = m_pHead->GetDown();

	int a = 0;
	while (1)
	{

		int b = 0;
		a++;
		while (1)
		{

			b++;
			if (temp->GetUp() == nullptr)
			{//if temp up is null
				temp->SetUp(cur);//set
				cur->SetDown(temp);//set
			}
			if (b == 4)
				break;
			temp = temp->GetRight();//temp go right
			cur = cur->GetRight();//cur go right

		}
		if (a == 3)
			break;
		cur = cur->GetDown()->GetLeft()->GetLeft()->GetLeft();//set
		temp = cur->GetDown();//set
	}
}
bool MyBoard::putnum()
{
	srand((unsigned int)time(NULL));//srand num
	vector<int>arr_x;
	vector<int>arr_y;
	if (m_pHead == nullptr)
		return false;
	MyBlock* cur = m_pHead;//delcare
	MyBlock* temp = m_pHead;//declare
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			if (cur->GetNum() == 0)
			{//if cur num is empty
				arr_x.push_back(cur->Get_x());
				arr_y.push_back(cur->Get_y());
			}
			if (cur->GetRight() == nullptr)
				continue;
			cur = cur->GetRight();
		}
		if (temp->GetDown() == nullptr)
			break;
		temp = temp->GetDown();
		cur = temp;
	}
	if (arr_x.size() == 0)//if no empty place
		return false;
	int v_size = arr_x.size();//node's count
	int num = rand() % v_size;//num is random num to count of node

	cur = m_pHead;
	temp = m_pHead;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			if (cur->Get_x() == arr_x[num] && cur->Get_y() == arr_y[num])
			{//if find num
				cur->SetNum(2);//add 2
				return true;
			}
			if (cur->GetRight() == nullptr)
				continue;
			cur = cur->GetRight();
		}
		if (temp->GetDown() == nullptr)
			break;
		temp = temp->GetDown();
		cur = temp;
	}
	return false;


}
bool MyBoard::copy(MyBoard  board, MyBoard temp_board)
{//copy
	if (m_pHead == nullptr)
		return false;
	MyBlock* cur = board.m_pHead;//declare
	MyBlock* temp = board.m_pHead;//declare
	MyBlock* cur1 = temp_board.m_pHead;//declare
	MyBlock* temp1 = temp_board.m_pHead;//declare

	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			cur1->SetNum(cur->GetNum());//copy
			if (cur->GetRight() == nullptr)
				continue;
			cur = cur->GetRight();
			cur1 = cur1->GetRight();
		}
		if (temp->GetDown() == nullptr)
			break;
		temp = temp->GetDown();
		temp1 = temp1->GetDown();
		cur = temp;
		cur1 = temp1;
	}
		return true;
}
bool MyBoard::check(MyBoard board, MyBoard temp_board)
{
	int a = temp_board.up();//line 1
	copy(board,temp_board);
	int b =	temp_board.down();//line 2
	copy(board, temp_board);
	int c = temp_board.right();//line 3
	copy(board, temp_board);
	int d = temp_board.left();//line 4
	copy(board, temp_board);
	if(a+b+c+d ==0)//if no move
		return false;
}
bool MyBoard::win()
{
	if (m_pHead == nullptr)
		return false;
	MyBlock* cur = m_pHead;
	MyBlock* temp = m_pHead;

	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{

			if (cur->GetNum() == 2048)
				return true;//if node is 2048 return ture
			if (cur->GetRight() == nullptr)
				continue;
			cur = cur->GetRight();

		}
		if (temp->GetDown() == nullptr)
			break;
		temp = temp->GetDown();
		cur = temp;
	}
	return false;//no 2048 node 

}
bool MyBoard::up()
{
	MyBlock* temp = m_pHead;
	int a = up(temp);//line 1
	temp = temp->GetRight();
	int b = up(temp);//line 2
	temp = temp->GetRight();
	int c = up(temp);//line 3
	temp = temp->GetRight();
	int d = up(temp);//line 4
	if (a + b + c + d > 0)//if move
		return true;
	else
		return false;//if no move
}

int MyBoard::up(MyBlock* node)
{
	MyBlock* cur = node->GetDown();
	MyBlock* cur_pre = node;
	int a = 0;
	int count = 0;
	while (1)
	{
		int move = 0;
		while (1)
		{
			if (cur->GetNum() != 0)
			{//there is num not 0
				if (cur->GetNum() == cur_pre->GetNum())
				{//same with pre node
					if (move >= 2 && count >=3)
					{//if move more 2 and count 3
						move = 0;
						break;
					}
					cur_pre->SetNum(cur_pre->GetNum() * 2);//merge
					cur->SetNum(0);//set
					count++;
					break;
				}
				else if (cur_pre->GetNum() == 0)
				{//pre node is 0
					cur_pre->SetNum(cur->GetNum());
					cur->SetNum(0);
					count++;
				}
				else if (cur_pre->GetNum() != cur->GetNum())
				{//no same pre
					break;
				}
			}
			else
			{//cur node is 0
				break;
			}
			if (cur_pre == node)
			{
				break;
			}
			else
			{
				if (move >= 2)
				{
					move = 0;
					break;
				}
				cur = cur->GetUp();
				cur_pre = cur_pre->GetUp();
				move++;
			}
		}
		a++;
		cur = node->GetDown();
		cur_pre = node;
		if (a == 1)
		{//if roof is 1
			cur_pre = cur;
			cur = cur->GetDown();
		}
		else if (a == 2)
		{//if roof is 2
			cur_pre = cur_pre->GetDown()->GetDown();
			cur = cur->GetDown()->GetDown();
		}
		else
			break;

	}
	return count;

}

bool MyBoard::down()
{
	MyBlock* temp = m_pHead->GetDown()->GetDown()->GetDown();
	int a = down(temp);//line 1
	temp = temp->GetRight();
	int b = down(temp);//line 2
	temp = temp->GetRight();
	int c = down(temp);//line 3
	temp = temp->GetRight();
	int d = down(temp);//line 4
	if (a + b + c + d > 0)
		return true;
	else
		return false;
}

int MyBoard::down(MyBlock* node)
{
	MyBlock* cur = node->GetUp();
	MyBlock* cur_pre = node;
	int a = 0;
	int count = 0;

	while (1)
	{
		int move = 0;
		while (1)
		{
			if (cur->GetNum() != 0)
			{//if cur is no 0
				if (cur->GetNum() == cur_pre->GetNum())
				{//same with prenode
					if (move >= 2 && count >= 3)
					{
						move = 0;
						break;
					}
					cur_pre->SetNum(cur_pre->GetNum() * 2);
					cur->SetNum(0);
					count++;
					break;
				}
				else if (cur_pre->GetNum() == 0)
				{//pre is 0
					cur_pre->SetNum(cur->GetNum());
					cur->SetNum(0);
					count++;
				}
				else if (cur_pre->GetNum() != cur->GetNum())
				{//no same with pre node
					break;
				}
			}
			else
			{//cur is 0
				break;
			}
			if (cur_pre == node)
			{
				break;
			}
			else
			{
				if (move >= 2)
				{
					move = 0;
					break;
				}
				cur = cur->GetDown();
				cur_pre = cur_pre->GetDown();
				move++;
			}
		}
		a++;
		cur = node->GetUp();
		cur_pre = node;
		if (a == 1)
		{//roof is 1
			cur_pre = cur;
			cur = cur->GetUp();
		}
		else if (a == 2)
		{//roof is 2
			cur_pre = cur_pre->GetUp()->GetUp();
			cur = cur->GetUp()->GetUp();
		}
		else//else break;
			break;

	}
	return count;
}

bool MyBoard::left()
{
	MyBlock* temp = m_pHead;
	int a =left(temp);//line 1
	temp = temp->GetDown();
	int b =left(temp);//line 2
	temp = temp->GetDown();
	int c =left(temp);//line 3
	temp = temp->GetDown();
	int d =left(temp);//line 4
	if (a + b + c + d > 0)
		return true;
	else
		return false;
}
int MyBoard::left(MyBlock* node)
{
	MyBlock* cur = node->GetRight();
	MyBlock* cur_pre = cur->GetLeft();
	MyBlock* temp = node;
	int a = 0;
	int count = 0;

	while (1)
	{
		int move = 0;
		while (1)
		{
			if (cur->GetNum() != 0)
			{//cur is no 0

				if (cur_pre->GetNum() == cur->GetNum())
				{//same with pre node
					if (move >= 2 && count >= 3)
					{
						move = 0;
						break;
					}
					cur_pre->SetNum(cur_pre->GetNum() * 2);
					cur->SetNum(0);
					count++;
					break;
				}
				else if (cur_pre->GetNum() == 0)
				{//if pre node is 0
					cur_pre->SetNum(cur->GetNum());
					cur->SetNum(0);
					count++;
				}
				else if (cur_pre->GetNum() != cur->GetNum())
				{//no same with pre node
					break;
				}
			}
			else
			{
				break;
			}
			if (cur_pre == node)
			{
				break;
			}
			else
			{

				if (move >= 2)
				{
					move = 0;
					break;
				}
				cur = cur->GetLeft();
				cur_pre = cur_pre->GetLeft();
				move++;
			}
		}
		a++;
		cur = node->GetRight();
		cur_pre = node;
		if (a == 1)
		{//roof is 1
			if (cur->GetRight() == nullptr)
				break;
			cur_pre = cur;
			cur = cur->GetRight();
		}
		else if (a == 2)
		{//roof is 2
			if (cur->GetRight() == nullptr)
				break;
			cur_pre = cur_pre->GetRight()->GetRight();
			cur = cur->GetRight()->GetRight();
		}
		else
			break;
	}
	return count;
}
bool MyBoard::right()
{

	MyBlock* temp = m_pHead->GetRight()->GetRight()->GetRight();
	int a = right(temp);//line 1
	temp = temp->GetDown();
	int b = right(temp);//line 2
	temp = temp->GetDown();
	int c = right(temp);//line 3
	temp = temp->GetDown();
	int d = right(temp);//line 4
	if (a + b + c + d > 0)
		return true;
	else
		return false;
}

int MyBoard::right(MyBlock* node)
{
	MyBlock* cur = node->GetLeft();
	MyBlock* cur_pre = cur->GetRight();
	MyBlock* temp = node;
	int a = 0;
	int count = 0;

	while (1)
	{
		int move = 0;
		while (1)
		{
			if (cur->GetNum() != 0)
			{//cur is no 0

				if (cur_pre->GetNum() == cur->GetNum())
				{//same with pre node
					if (move >= 2 && count >= 3)
					{
						move = 0;
						break;
					}
					cur_pre->SetNum(cur_pre->GetNum() * 2);
					cur->SetNum(0);
					count++;
					break;
				}
				else if (cur_pre->GetNum() == 0)
				{//pre node is 0
					cur_pre->SetNum(cur->GetNum());
					cur->SetNum(0);
					count++;

				}
				else if (cur_pre->GetNum() != cur->GetNum())
				{//no same with pre node
					break;
				}
			}
			else
			{//cur is 0
				break;
			}
			if (cur_pre == node)
			{
				break;
			}
			else
			{

				if (move >= 2)
				{
					move = 0;
					break;
				}
				cur = cur->GetRight();
				cur_pre = cur_pre->GetRight();
				move++;
			}
		}
		a++;
		cur = node->GetLeft();
		cur_pre = node;
		if (a == 1)
		{//roof is 1
			if (cur->GetLeft() == nullptr)
				break;
			cur_pre = cur;
			cur = cur->GetLeft();
		}
		else if (a == 2)
		{//roof is 2
			if (cur->GetLeft() == nullptr)
				break;
			cur_pre = cur_pre->GetLeft()->GetLeft();
			cur = cur->GetLeft()->GetLeft();
		}
		else
			break;
	}
	return count;
}
