#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the string : ";
	char str[100] = { NULL, };
	cin.getline(str, 100, '\n');//get string
	for (int a = 0; a<100; a++)
	{
		if (str[a] == NULL)
			continue;//if no text continue;
		else if (str[a] >= 65 && str[a] <= 90)
		{//or if stra[a] is capital letter 
			str[a] += 32; //plus 32 to make small letter
		}
		else if (str[a] >= 97 && str[a] <= 122)
		{//if str[a] is small letter
			str[a] -= 32; //minus 32 to make capital letter
		}
	}
	int a, b;
	char c;
	for (a = 0,b=strlen(str)-1; a<b; a++,b--)
	{
		if (str[a] != NULL)
		{//if str[a] is not a null
			c = str[a];//temp 
			str[a] = str[b];//swap
			str[b] = c;//relocation
		}
	}
	cout << "Result : ";
	cout << str;//print
}