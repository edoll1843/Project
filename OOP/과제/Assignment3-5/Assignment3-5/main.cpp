#include "Board.h"
#include <iostream>

using namespace std;

void print_menu();
int main()
{
	MyBoard m_Board;//declare
	MyBoard temp_board;//declare

	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{//make map and insert node
			MyBlock* newNode = new MyBlock(0, a, b);
			m_Board.make_board(newNode);
		}
	}
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{//make map and insert node
			MyBlock* newNode = new MyBlock(0, a, b);
			temp_board.make_board(newNode);
		}
	}
	m_Board.connect();//connect node
	temp_board.connect();//connect node
	int user_input = 0;
	m_Board.putnum();//put random num
	cout << "[Start]" << endl;
	while (1)
	{

		m_Board.print_board();//print
		temp_board.copy(m_Board,temp_board);//copy board to temp
		if (temp_board.check(m_Board, temp_board) == false)
		{//check rose
			cout << "Lose!!" << endl;
			cout << "[program exit]" << endl;
			return 0;
		}
		if (m_Board.win() == true)
		{//check win
			cout << "Win!!" << endl;
			cout << "[program exit]" << endl;
			return 0;
		}
		cout << endl;
		print_menu();//print menu
		cin >> user_input;
		if (user_input == 1)
		{//if 1 up
			if (m_Board.up() == true)
			{
				m_Board.putnum();//put random num
			}
			else
			{
				continue;
			}

		}
		else if (user_input == 2)
		{
			if (m_Board.down() == true)
			{//if 2 down
				m_Board.putnum();
			}
			else
			{
				continue;
			}


		}
		else if (user_input == 3)
		{
			if (m_Board.left() == true)
			{//if 3 left
				 m_Board.putnum();
			}
			else
			{	
				continue;
			}

		}
		else if (user_input == 4)
		{//if 4 right
			if (m_Board.right() == true)
			{
				m_Board.putnum();
			}
			else
			{			
				continue;
			}

		}	
		else if (user_input == -1)
		{//if -1 return
			cout << endl;
			cout << "[program exit]";
			return 0;
		}
		user_input = 0;
	}
}
void print_menu()
{
	cout << "[Menu]" << endl;
	cout << "1.Up	2,Down	3.Left	4.Right" << endl;
	cout << "Input >> ";
}
