#include <iostream>
using namespace std;

int main()
{
	int x1 = 0, y1 = 0;//declare
	int x2 = 0, y2 = 0;//declare
	int x3 = 0, y3 = 0;//declare
	
	cout << "P1: ";
	cin >> x1 >> y1;//get P1 point
	cout << "P2: ";
	cin >> x2 >> y2;//get P2 point
	cout << "P3: ";
	cin >> x3 >> y3;//get P3 point
	cout << endl;
	int mul;
	mul = x1 * y2 + x2 * y3 + x3 * y1;//mul is p1x * p2y + p2x * p3y + p3x * p1y 
	mul = mul - x1 * y3 - x2 * y1 - x3 * y2;//if (p1x * p2y + p2x * p3y + p3x * p1y) -reverse mul is new mul
	if (mul < 0 )//if mul is negative 
		cout << "Clockwise";// print clock wise
	else if (mul > 0)//if mul is pisitive 
		cout << "Counter-Clockwise";//print counter clock wise
	else// else mean mul is 0
		cout << "Straight";// print straight
}