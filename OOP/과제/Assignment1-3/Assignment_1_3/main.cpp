#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N = 0;
unsigned int cnt = 0;
vector <char> v; 
void input_bit();
void func_g();
void input_N()//get input
{
	cout << "Input N:";
	cin >> N;
	input_bit();//get bit input
}
void input_bit()
{//get bit input
	string bit;
	cout << "Input Bitstream:";
	cin >> bit;
	int bitsize = bit.size();
	for (int a = 0; a < bitsize; a++)
	{//input the bit
		v.push_back(bit.back());
		bit.pop_back();
	}
	func_g();//reverse
}
void func_f()
{//reversal 
	for (vector<int>::size_type a = 0; a < v.size(); a++)
	{//for 0 to  maxbit
		if (v[a] == '0')
		{//if 0 change to 1
			v[a] = '1';
		}
		else if(v[a] == '1')
		{//if 1 change to 0
			v[a] = '0';
		}
	}
}
void func_g()
{//reverse the bit
	int c, i, j;
	for (i = 0, j = v.size() - 1; i < j; i++, j--)
	{
		c = v[i];//c is temp
		v[i] = v[j]; //swap
		v[j] = c;//relocation
	}
}
void add_bit(int a)
{
	if (a % 2 == 0)
	{// if a is even 
		v.push_back('0'); //add 0
	}
	else if (a == 1 || a % 2 == 1)
	{//if a is odd num
		v.push_back('1');//add 1
	}
}
void count()
{//demical num
	cnt = 0;
	vector<int>::size_type num = 0;
	int mul = 1;
	while (num <v.size())
	{
		if (num == 33)
			break;
		if (v[v.size()-1-num] == '1')
		{//if bit is 1
			cnt += mul; //add
		}
		mul *= 2;//squared num
		num++;
	}
}
int main()
{
	input_N();//get input
	string output;
	for (int a = 1; a <= N; a++)
	{
		func_g();//reverse func g
		func_f();// reversal func func f
		add_bit(a);//add bit 1
		cout << a << ": ";
		for (vector<int>::size_type b = 0; b < v.size(); b++)
		{//print bit
			cout << v[b];
		}
		cout << endl;
		count();
		cout << cnt;//print demical num
		cout << endl;
	}

}