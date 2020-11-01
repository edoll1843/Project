#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;
vector <int> v;
vector <int> v1;

int N = 0;

void input()
{//get input
	cout << "Enter the n: ";
	cin >> N;
}
void map(vector<int>& v)
{// make map that 1to n
	for (int a = 1; a <= N; a++)
	{
		v.push_back(a);
	}
}
void find(vector<int>& v)
{
	for (int a = 2; a < N; a++)
	{//1is not prime
		for (int b = 2; b <= a; b++)
		{//1is not prime
			if (a % b == 0)
			{ //if a division b no remainder 
				if (a / b != 1)
				{//if a division b no remainder and a/b is not a 1 means no prime
					break;
				}
				v1.push_back(a);//else push primes
			}
		}
	}
}

int main()
{
	input();//get input
	map(v);//mapping
	find(v);//find primes
	int count = 0;
	for (int a = 0; a < v1.size(); a++)
	{//print primes
		cout << v1[a] << " ";
		count++;		
	}
	cout << endl;
	cout <<"The number of Prime numbers:" <<count;

	return 0;
}

