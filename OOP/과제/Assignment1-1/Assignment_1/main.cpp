#include <iostream>
using namespace std;

char map[2500][2500];//declare
int space(int num, int num1, int count)
{
    count++;//count
    if (num1 /3 == num)//if num1/3 is num mean num is 3, no more get small
        return 0;
    else
    {//else
        if (count==1)
        {// if function is first 
            for (int a = 0; a < num; a++)
            {
                for (int b = 0; b < num; b++)
                {
                    if (a % 3 == 1 && b % 3 == 1)
                    {//make hole that 3x3
                        map[a][b] = ' ';
                    }
                }
            }
        }
        else
        {//upto second func
            for (int a = 0; a < num; a++)
            {
                for (int b = 0; b < num; b++)
                {
                    if (a > num1 / 3 - 1 && b > num1 / 3 - 1 && a < num1 - num1 / 3 && b < num1 - num1 / 3)
                    {//make hole in the middle, range to range
                        map[a][b] = ' ';
                    }
                    else
                    {//make nxn
                        map[a][b] = map[a % num1][b % num1];
                    }
                }
            }
        }
        space(num, num1 * 3,count); // call recursion func
    }
}
int main()
{
    int n = 0;//declare
    cout << "Enter the power of 3:";//print
    cin >> n;//input n num
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {//make map which all the map is $
            map[a][b] = '$';
        }
    }
    space(n,3,0);//make hole
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {//print map
            cout << map[a][b];
        }
        cout << endl;
    }

}