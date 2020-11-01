#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class ThreeSixNine
{//declare class
public:
	char TSN[3] = { NULL, };
	int number = 0;
	void print369(int number);//print369 func
};
void ThreeSixNine::print369(int number)
{
	for (int a = 1; a <= number; a++)
	{//1 ~num
		_itoa(a, TSN, 10);//num to char
		int cnt = 0;
		for (int b = 0; b < 3; b++)
		{//if number is 3 or 6 or 9
			if (TSN[b] == '3' || TSN[b] == '6' || TSN[b] == '9')
				cnt++;//get count
		}
		if (cnt == 1)
		{//if count is 1
			cout << '!' << "	";
		}
		else if (cnt == 2)
		{//count is 2
			cout << "!!" << "	";
		}
		else
		{//else print num
			cout << a << "	";
		}
		if (a % 10 == 0)//cout endl each 10
			cout << endl;
	}
}
int main()
{
	int num = 0;
	ThreeSixNine game;

	cout << "input your number" << endl;
	cin >> num;

	game.print369(num);//print
	cout << endl;
	return 0;
}


