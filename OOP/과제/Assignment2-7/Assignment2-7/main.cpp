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
	cout << " 0. ���α׷� ����" << endl;
	cout << " 1. ����ũ ��� �����" << endl;
	cout << " 2. ����ũ ���� �����" << endl;
	cout << " 3. ����ũ �����ϱ�" << endl;
	cout << " 4. �� ����ũ ���� Ȯ���ϱ�" << endl;
	cout << " 5. �� ���� Ȯ���ϱ�" << endl;
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
			cout << " ���� ����ũ ����: " << sales.mask << "��" << endl;
			cout << endl; 
		}
		else if (costomer.num == 2)
		{//if num is 2
			cout << " ����ũ ����: " << sales.price << "��" << endl;
			cout << endl;
		}
		else if (costomer.num == 3)
		{//if num is 3
			cout << " �� ���� �����Ͻðڽ��ϱ�?" << endl;
			cin >> costomer.buy_mask_num;//get num of mask
			if (sales.mask - costomer.buy_mask_num < 0 && costomer.money - costomer.buy_mask_num * sales.price < 0)
			{//if number of mask is larger than left mask and not enough money
				cout << " ����ũ ���� �ܾ� ��� �����մϴ�." << endl;
				cout << endl;
			}
			else if (sales.mask - costomer.buy_mask_num < 0)
			{//if mask no mask
				cout << " ����ũ ��� �����մϴ�." << endl;
				cout << endl;
			}
			else if (costomer.money - costomer.buy_mask_num * sales.price < 0)
			{//no money
				cout << " �ܾ��� �����մϴ�." << endl;
				cout << endl;
			}
			else
			{//costomer buy the mask
				cout << " " << costomer.buy_mask_num << "���� ���� �Ϸ�." << endl;
				cout << endl;
				sales.mask = sales.mask - costomer.buy_mask_num;//update mask num
				costomer.money = costomer.money - costomer.buy_mask_num * sales.price;//update money of left
				costomer.mask_num += costomer.buy_mask_num;//update mask num
			}
		}
		else if (costomer.num == 4)
		{//if num is 4
			cout << " �� ����ũ ����: " << costomer.mask_num << "��" << endl;
			cout << endl;
		}
		else if (costomer.num == 5)
		{//if num is 5
			cout << " �� �ܾ�: " << costomer.money << "��" << endl;
			cout << endl;
		}
	}
	return 0;

}
