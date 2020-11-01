#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	int r_num[5] = { -1 ,};//declare
	int temp = 0;//declare
	char my_num[5] = {NULL,};//declare
	int game = 0;//declare
	srand((unsigned int)time(NULL));//get diffrent num each compile 
	for (int a = 0; a < 4; a++)
	{
	again:;
		temp = rand() % 10;//get random num
		for (int b = 0; b < 4; b++)
		{
			if (temp == r_num[b])//if num is same as prior num
				goto again; //get random num again
		}
		r_num[a] = temp;// no duplicate num put num in arr
	}
	cout << "Random numbers: " << endl;

	while (1)
	{
		if (game == 10)
		{//if game is 10 
			cout << "Lose" << endl;
			break;
		}
	
		game++;
		int hit = 0;
		int blow = 0;
		cout << "Your number: ";
		scanf("%s", my_num);//get num
		for (int a = 0; a < 4; a++)
		{
			if (r_num[a] == my_num[a] - '0')//my num is char so -0 to make int
				hit++;//if num is just fit, pluzs hit
			else
			{
				for (int b = 0; b < 4; b++)
				{
					if (r_num[a] == my_num[b]- '0')
					{//if num is fit but no same place
						blow++;//blow ++
					}
				}
			}
			if (hit == 4)
			{//if hit is 4
				cout << ">>" << "HIT: " << hit << "," <<"BLOW: "<<blow<< endl;
				cout << "Win";//win
				break;
			}
		}
		if (hit == 4)
			break;
		cout << ">>" << "HIT: " << hit << "," <<"BLOW: "<<blow<< endl;


	}




}