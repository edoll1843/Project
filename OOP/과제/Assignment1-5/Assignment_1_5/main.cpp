#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#define MAX_SIZE 16382
using namespace std;

int main()
{
	int row=0,col=0;//decalre
	std::cout << "Enter the row: ";
	cin >> row;//get row
	std::cout << "Enter the column: ";
	cin >> col;//get col
	std::cout << "Origin Matrix >>> ";
	std::cout << endl;
	srand((unsigned int)time(NULL));//to not overlapping
	int** arr;
	arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col];
	int dup[1000];//check dulicate
	for (int i = 0; i < 1000; i++)
		dup[i] = 0;//reset to 0
	dup[0] = -1; // [0] set to -1

	if (1 <= row && col <= 100)
	{//row and col is 1 to 100
		for (int a = 0; a < row; a++)
		{
			for (int b = 0; b < col; b++)
			{
				int num = rand() % (col*row);//get num 0 to col*row -1
				if (dup[num] != num)
				{//if no duplicate
					dup[num] = num;// put num
					arr[a][b] = num;//put num
				}
				else
				{//if duplicate
					while (1)
					{
						num = rand() % (col * row);//get new random number
						if (dup[num] != num)
						{//check duplicate
							dup[num] = num;
							arr[a][b] = num;
							break;//if no dup than break;
						}
					}
				}
			}
		}
		for (int a = 0; a < row; a++)
		{
			for (int b = 0; b < col; b++)
			{//print
				std::cout << arr[a][b];
				std::cout << "	";
			}
			std::cout << endl;
		}
		std::cout << endl;
		std::cout << "Transpose Matrix >>> ";
		std::cout << endl;
		for (int a = 0; a < col; a++)
		{
			for (int b = 0; b < row; b++)
			{//print row is col, col is row
				std::cout << arr[b][a];
				std::cout << "	";
			}
			std::cout << endl;
		}
	}

}