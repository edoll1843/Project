#include <iostream>

using namespace std;

int main()
{
	char type;//declare
	int text=0;//declare
	int call=0;//declare
	int extra_text=0;//declare
	int extra_call=0;//declare
	int fee = 0;//declare
	cout << "Which type: ";
	cin >> type;//get type
	cout << "Text: ";
	cin >> text;//get text
	cout << "CALL : ";
	cin >> call;// get call
	cout << "=========" << endl;;
	cout << "Result" << endl;;
	
	if (type == 'A')
	{//if type is A
		if (text - 100 > 0)
		{//if used text is more than 100
			extra_text = (text - 100) * 20;//count extra text fee
		}
		else
		{//smaller than 100
			extra_text = 0;//no extra fee of text
		}
		if (call - 60 > 0)
		{//if used call is more than 60
			extra_call = (call - 60) * 180;//count textra call fee
		}
		else
		{//smaller than 60
			extra_call = 0;//no extra fee of call
		}
		fee = 10000;//basic fee is 10000
	}
	else if (type == 'B')
	{//if type is B
		if (text - 150 > 0)
		{//if used text is more than 150
			extra_text = (text - 150) * 15;//count extra text fee
		}
		else
		{
			extra_text = 0;//no extra fee of text
		}
		if (call - 90 > 0)
		{//if used call is more than 90
			extra_call = (call - 90) * 150;//count textra call fee
		}
		else
		{
			extra_call = 0;//no extra fee of call
		}
		fee = 15000;//basic fee is 15000
	}
	else if (type == 'C')
	{
		if (text - 200 > 0)
		{//if used text is more than 100
			extra_text = (text - 200) * 10;//count extra text fee
		}
		else
		{
			extra_text = 0;//no extra fee of text
		}
		if (call - 120 > 0)
		{//if used call is more than 120
			extra_call = (call - 120) * 60;//count textra call fee
		}
		else
		{
			extra_call = 0;//no extra fee of call
		}
		fee = 20000;//basic fee is 20000
	}
	else if (type == 'D')
	{
		if (text - 250 > 0)
		{//if used text is more than 100
			extra_text = (text - 250) * 5;//count extra text fee
		}
		else
		{
			extra_text = 0;//no extra fee of text
		}
		if (call - 150 > 0)
		{//if used call is more than 150
			extra_call = (call - 150) * 30;//no extra fee of call
		}
		else
		{
			extra_call = 0;//no extra fee of call
		}
		fee = 25000;//basic fee is 25000
	}
	cout << "Extra text: " << extra_text << endl;
	cout << "Extra call: " << extra_call << endl;
	cout << "Total: " << extra_text + extra_call+fee;//get total fee extra call,text and basic fee


}