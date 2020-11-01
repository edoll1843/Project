#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <cmath>
using namespace std;
ifstream read;//declare
ofstream write;//declare
int all_char(char a[256])
{//count all char of string
	int count = 0;
	for (int b = 0; b < 256; b++)
	{
		if (a[b] != NULL)
			count++;//if char is not NULL count ++
		else
			break;
	}
	return count;//return count
}
int collec_char(char a[256], char b[256])
{//find collect char
	int count = 0;
	for (int c = 0; c < 256; c++)
	{
		if (a[c] == NULL || b[c] == NULL)
			break;//if string is end break;
		if (a[c] == b[c])
			count++;//if same count++

	}
	return count;//return
}
int main()
{
	time_t start = NULL;//set start time
	time_t end = NULL;//set end time
	read.open("source.txt");//open text
	write.open("result.txt");//open text to write
	char text[256] = { NULL, };
	char arr[256] = { NULL, };
	int text_count = 0;
	double speed = 0;
	double collect = 0;
	int leng = 0;
	write << "KW Typing verification Program" << endl;
	if (read.is_open())
	{//if text is open
		while (!read.eof())
		{   //read while sting is not end
			cout << "KW Typing verification Program" << endl;
			cout << "정확도 : " << collect * 100 << "   ";
			cout << "속도(타자/s) : " << speed << endl << endl;
			write << "정확도 : " << collect * 100 << "   ";
			write << "속도(타자/s) : " << speed << endl << endl;
			read.getline(arr, 256);//get line of string
			cout << "문장 : " << arr << endl;
			write << arr << endl;//write in result.txt
			cout << "입력 : ";
			while (_kbhit())
			{//if input is occr

			}
			start = time(NULL);//start time
			cin.getline(text, 256, '\n');//cin getline
			end = time(NULL);//end time
			system("cls");//make reset od command

			text_count = all_char(text);//count all char of string
			collect = collec_char(text, arr);//find collect char
			leng = all_char(arr);//get length
			collect = collect / (double)leng;

			speed = text_count / ((double)end - (double)start);
			speed = round(speed * 10) / 10.0;
		}
	}
	cout << "KW Typing verification Program" << endl;
	cout << "정확도 : " << collect * 100 << "   " << "속도(타자/s) : " << speed << endl << endl;
	write << "정확도 : " << collect * 100 << "   " << "속도(타자/s) : " << speed << endl << endl;
	read.close();
	write.close();

}