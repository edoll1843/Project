#include <iostream>
using namespace std;

char map[3][3];//declare
int x = 0, y = 0;//declare
char end()
{
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			if (map[a][b] == map[a][b + 1] && b == 0)
			{//if row same char than make winner
				if (map[a][b + 1] == map[a][b + 2])
				{//row winner
					return map[a][b];//return winner
				}
			}
			if (map[a][b] == map[a + 1][b] && a == 0)
			{//if col same char(O or X) then return winner
				if (map[a + 1][b] == map[a + 2][b])
				{//col winner
					return map[a][b];//return winner
				}
			}
			if (map[a][b] == map[a + 1][b + 1] && a == 0 && b == 0)
			{//if Hanoi same char(O or X) then return winnier
				if (map[a + 1][b + 1] == map[a + 2][b + 2])
				{//Hanoi winner(left ro right)
					return map[a][b];//return winner
				}
			}
			if (a == 0 && b == 2 && map[a][b] == map[a + 1][b - 1])
			{//if Hanoi same char(O or X) then return winnier
				if (map[a + 1][b - 1] == map[a + 2][b - 2])
				{//Hanoi winner (right to left)
					return map[a][b];//return winner
				}
			}
			else
				continue;
		}
	}
}
void player1()
{//player 1 func
	cout << "[Play 1] Enter your location [x y] : ";
	cin >> x >> y;//get x y
	map[y][x] = 'O';//map [y][x] to 0
	x = 0; y = 0;//reset
}
void player2()
{
	cout << "[Play 2] Enter your location [x y] : ";
	cin >> x >> y;
	map[y][x] = 'X';
	x = 0; y = 0;
}
void print()
{
	cout << "  X 0   1   2";
	cout << endl;//print
	cout << "Y  --- --- ---";
	cout << endl;
}
void print_0()
{
	for (int a = 0; a < 3; a++)
	{
		cout << a << " ";
		for (int b = 0; b < 3; b++)
		{//print map
			cout << "|";
			if (map[a][b] != NULL)
			{//if map[a][b] is not null
				cout << " " << map[a][b] << " ";//print
			}
			else
			{//else
				cout << "   ";//print hole
			}
			if (b == 2)
			{//print edge
				cout << "|";
				cout << endl;
				cout << "   --- --- ---";
			}
		}
		cout << endl;
	}
}
int main()
{

	bool cnt = true;
	while (1)
	{//while until occur winner or there is no space to put O or X
		char winner;
		int count = 0;
		print();//print
		print_0();//print O or X
		if (cnt == true)
		{//if cnt is true 
			player1();//player1's turn
			cnt = false;//player 1 is done, cnt turn false
		}
		else if (cnt == false)
		{//if cnt is false
			player2();//turn to player 2
			cnt = true;//turn to true player1
		}
		winner = end();
		if (winner == 'O')
		{//is winner is player 1 
			print();
			print_0();
			cout << "Winner is [Player 1] " << endl;
			break;
		}
		else if (winner == 'X')
		{//winner is player2
			print();
			print_0();
			cout << "Winner is [Player 2]" << endl;
			break;
		}
		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{//check count
				if (map[a][b] != NULL)
					count++;
			}
		}
		if (count == 9)
		{//if count is 9 there is no space to put O or X
			print();
			print_0();
			cout << "Draw";//print Draw
			break;
		}
	}
}