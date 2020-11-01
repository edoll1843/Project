#include <iostream>
using namespace std;

class Pharmacist
{//declare class
public:
	int mask = 5;
	int price = 1000;
};
class Buyer
{//declare class
public:
	int num = 0;
	int money = 3000;
	int mask_num = 0;
	int buy_mask_num = 0;
};
void menu()
{//print menu
	cout << " 0. 프로그램 종료" << endl;
	cout << " 1. 마스크 재고 물어보기" << endl;
	cout << " 2. 마스크 가격 물어보기" << endl;
	cout << " 3. 마스크 구매하기" << endl;
	cout << " 4. 내 마스크 갯수 확인하기" << endl;
	cout << " 5. 내 지갑 확인하기" << endl;
}
int main()
{
	Buyer costomer;
	Pharmacist sales;
	while (1)
	{
		menu();//print menu
		cin >> costomer.num;//get num of menu
		if (costomer.num == 0)
			break;
		else if (costomer.num == 1)
		{//if num is 1
			cout << " 남은 마스크 갯수: " << sales.mask << "개" << endl;
			cout << endl; 
		}
		else if (costomer.num == 2)
		{//if num is 2
			cout << " 마스크 가격: " << sales.price << "원" << endl;
			cout << endl;
		}
		else if (costomer.num == 3)
		{//if num is 3
			cout << " 몇 개를 구매하시겠습니까?" << endl;
			cin >> costomer.buy_mask_num;//get num of mask
			if (sales.mask - costomer.buy_mask_num < 0 && costomer.money - costomer.buy_mask_num * sales.price < 0)
			{//if number of mask is larger than left mask and not enough money
				cout << " 마스크 재고와 잔액 모두 부족합니다." << endl;
				cout << endl;
			}
			else if (sales.mask - costomer.buy_mask_num < 0)
			{//if mask no mask
				cout << " 마스크 재고가 부족합니다." << endl;
				cout << endl;
			}
			else if (costomer.money - costomer.buy_mask_num * sales.price < 0)
			{//no money
				cout << " 잔액이 부족합니다." << endl;
				cout << endl;
			}
			else
			{//costomer buy the mask
				cout << " " << costomer.buy_mask_num << "개를 구매 완료." << endl;
				cout << endl;
				sales.mask = sales.mask - costomer.buy_mask_num;//update mask num
				costomer.money = costomer.money - costomer.buy_mask_num * sales.price;//update money of left
				costomer.mask_num += costomer.buy_mask_num;//update mask num
			}
		}
		else if (costomer.num == 4)
		{//if num is 4
			cout << " 내 마스크 갯수: " << costomer.mask_num << "개" << endl;
			cout << endl;
		}
		else if (costomer.num == 5)
		{//if num is 5
			cout << " 내 잔액: " << costomer.money << "원" << endl;
			cout << endl;
		}
	}
	return 0;

}
