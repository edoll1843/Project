#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4244)
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Exchange
{//declare super class
public://declare public index
	double before_m = 0;
	double after_m = 0;
	char before_c[50] = {NULL,};
	char after_c[50] = {NULL,};
	char answer = 'Y';
	int KRW = 1;
	int USD = 1200;
	int JPY = 11;
	int EUR = 1300;
	int CNY = 170;
	Exchange()
	{

	}
	~Exchange()
	{
	}
};
class ToKRW : public Exchange
{
public:
	int before_KRW(char a[50],double b)
	{//defore KRW func
		strcpy(after_c, a);
		before_m = b;
		if (strcmp(after_c, "USD") == 0)
		{//if after country is USD 
			after_m = before_m /USD;
		}
		else if (strcmp(after_c, "JPY") == 0)
		{//if after country is JPY 
			after_m = before_m /JPY;
		}
		else if (strcmp(after_c, "EUR") == 0)
		{//if after country is EUR 
			after_m = before_m / EUR;
		}
		else if (strcmp(after_c, "CNY") == 0)
		{//if after country is CNY
			after_m = before_m /CNY;
		}
		return round(after_m);
	}
};

class ToUSD : public Exchange
{
public:
	int before_USD(char a[50], double b)
	{
		strcpy(after_c, a);
		before_m = b;
		if (strcmp(after_c, "KRW") == 0)
		{//if after country is KRW 
			after_m = before_m * 1200;//before_m *(USD/KRW)
		}
		else if (strcmp(after_c, "JPY") == 0)
		{//if after country is JPY 
			after_m = before_m * 109.091;//before_m *(USD/JPY)
		}
		else if (strcmp(after_c, "EUR") == 0)
		{//if after country is EUR 
			after_m = before_m * 0.923;//before_m *(USD/EUR)
		}
		else if (strcmp(after_c, "CNY") == 0)
		{//if after country is CNY 
			after_m = before_m * 7.059;//before_m *(USD/CNY)
		}
		return round(after_m);
	}
};

class ToJPY : public Exchange
{
public:
	int before_JPY(char a[50], double b)
	{
		strcpy(after_c, a);
		before_m = b;
		if (strcmp(after_c, "USD") == 0)
		{//if after country is USD 
			after_m = before_m * 0.009;
		}
		else if (strcmp(after_c, "KRW") == 0)
		{//if after country is KRW 
			after_m = before_m * 11;
		}
		else if (strcmp(after_c, "EUR") == 0)
		{//if after country is EUR 
			after_m = before_m * 0.008;
		}
		else if (strcmp(after_c, "CNY") == 0)
		{//if after country is CNY 
			after_m = before_m / 0.064;
		}
		return round(after_m);
	}
};

class ToEUR : public Exchange
{
public:
	int before_EUR(char a[50], double b)
	{
		strcpy(after_c, a);
		before_m = b;
		if (strcmp(after_c, "USD") == 0)
		{//if after country is USD 
			after_m = before_m * 1.083;
		}
		else if (strcmp(after_c, "JPY") == 0)
		{//if after country is JPY 
			after_m = before_m / 118.182;
		}
		else if (strcmp(after_c, "KRW") == 0)
		{//if after country is KRW 
			after_m = before_m * 1300;
		}
		else if (strcmp(after_c, "CNY") == 0)
		{//if after country is CNY 
			after_m = before_m * 7.647;
		}
		return round(after_m);
	}

};
class ToCNY : public Exchange
{
public:
	int before_CNY(char a[50], double b)
	{
		strcpy(after_c, a);
		before_m = b;
		if (strcmp(after_c, "USD") == 0)
		{//if after country is USD 
			after_m = before_m / 0.142;
		}
		else if (strcmp(after_c, "JPY") == 0)
		{//if after country is JPY 
			after_m = before_m / 15.455;
		}
		else if (strcmp(after_c, "EUR") == 0)
		{//if after country is EUR 
			after_m = before_m / 0.131;
		}
		else if (strcmp(after_c, "KRW") == 0)
		{//if after country is KRW 
			after_m = before_m * 170;
		}
		return round(after_m);
	}
};

int main()
{
	Exchange money;
	ToKRW KRW;
	ToUSD USD;
	ToJPY JPY;
	ToEUR EUR;
	ToCNY CNY;
	int after =0;
	while (money.answer=='Y'|| money.answer == 'y')//while until user input is y
	{
		char want[50];
		char* temp[4] = {NULL,};
		int cnt = 0;
		cout << "¡ÚCurrency Converter¡Ú" << endl;
		cout << "e.g. [Price] KRW to USD" << endl;
		cout << endl;
	
		cin.getline(want, 50);//get input
		char* tmp = strtok(want, " ");
		while (tmp != NULL)
		{//tok price, before country, after country
			temp[cnt] = tmp;
			tmp = strtok(NULL, " ");
			cnt++;
		}
		strcpy(money.after_c,temp[3]);
		money.before_m=atoi(temp[0]);
		if (strcmp(money.after_c, "KRW")==0 || strcmp(money.after_c, "USD") == 0 || strcmp(money.after_c, "JPY") == 0 || strcmp(money.after_c, "EUR") == 0 || strcmp(money.after_c, "CNY") == 0)
		{//if after country is KRW, USD,EUR,CNY,JPY 
			if (strcmp(temp[1], "KRW") == 0)
			{//if before country is KRW
				after = KRW.before_KRW(money.after_c, money.before_m);
			}
			else if (strcmp(temp[1], "USD") == 0)
			{//if before country is USD
				after = USD.before_USD(money.after_c, money.before_m);
			}
			else if (strcmp(temp[1], "JPY") == 0)
			{//if before country is JPY
				after = JPY.before_JPY(money.after_c, money.before_m);
			}
			else if (strcmp(temp[1], "EUR") == 0)
			{//if before country is EUR
				after = EUR.before_EUR(money.after_c, money.before_m);
			}
			else if (strcmp(temp[1], "CNY") == 0)
			{//if before country is CNY
				after = CNY.before_CNY(money.after_c, money.before_m);
			}
			else
			{//no country like that
				cout << "Input error";
				break;
			}
		}
		else
		{//no country like that
			cout << "Input error";
			break;
		}

		cout << after <<" "<<temp[3]<<endl;
		cout << endl;
		cout << "Would you like to continue? (Y/N)" << endl;
		cin >> money.answer;//get answer
		cin.ignore();//reset cin
		if (money.answer == 'N' || money.answer == 'n')
		{//if answer is N or n
			cout << "Bye!";
			break;
		}
	}

	


}