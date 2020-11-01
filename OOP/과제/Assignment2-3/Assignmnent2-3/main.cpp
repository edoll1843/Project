#include <iostream>
#pragma warning(disable : 6386)
using namespace std;

int main()
{//declare
	int x, y;
	int arr[10][10] = { 0, };

	cout << "Please input 2D array size: ";
	cin >> x >> y;
	if (x < 1 || x > 10 || y < 1 || y > 10)
		return 0;
	//get x and y

	int i = 1;//declare
	int x1 = 0, y1 = 0;
	int N = x;
	int xx = 0, yy = 0;
	int x_count=x;
	int y_count=y;

	while (N >0)
	{//cycle num is bigger than 0
		for (int a = y-y_count; a < y; a++)
		{//left to right columm 
			arr[yy][xx++] = i++;
		}
		N--;//cycle --
		xx--;
		yy++;
		x_count--;
		if (N == 0)
			break;
		for (int a = x-x_count; a < x; a++)
		{// up to down row
			arr[yy++][xx] = i++;
		}
		yy--;
		xx--;
		y_count--;
		for (int a = y - y_count; a < y; a++)
		{//right to lfet columm
			arr[yy][xx--] = i++;
		}
		xx++;
		N--;
		yy--;
		x_count--;
		if (N == 0)
			break;
		for (int a = x - x_count; a < x; a++)
		{//down to up row
			arr[yy--][xx] = i++;
		}
		xx = ++x1;
		yy = ++y1;
		y_count--;
	}
	for (int a = 0; a < x; a++)
	{//print numbers
		for (int b = 0; b < y; b++)
		{
			cout << arr[a][b] << "	";
		}
		cout << endl;
	}
}