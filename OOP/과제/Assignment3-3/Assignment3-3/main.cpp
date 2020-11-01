#include <iostream>
#include "BSTNode.h"
#include "Queue.h"
#include <vector>

using namespace std;
void print_menu()
{
	cout << "1. Preorder" << endl;
	cout << "2. Inorder" << endl;
	cout << "3. Postorder" << endl;
	cout << "4. Exit" << endl;
	cout << "Select Number : ";
}
int main(void)
{
	vector<int> input;//set
	Queue* q = new Queue;//set

	int size = 0;//set
	int n_input = 0;//set

	cout << "Enter Input Size: ";
	cin >> size;

	cout << "Enter a number: ";
	for (int i = 0; i < size; i++)
	{
		cin >> n_input;
		input.push_back(n_input);//insert
	}


	for (int i = 0; i < input.size(); i++)
	{
		BSTNode* newNode = new BSTNode(input[i]);//set

		q->Push(newNode);//push
	}

	while (1)
	{
		int user_input = 0;
		print_menu();
		cin >> user_input;
		cout << endl;

		if (user_input == 1)
		{
			cout << "Preorder : ";
			q->Preorder(q->Front());//preorder
			cout << endl<<endl;
		}
		else if (user_input == 2)
		{
			cout << "Inorder : ";
			q->Inorder(q->Front());//inorder
			cout << endl<<endl;
		}
		else if (user_input == 3)
		{
			cout << "Postorder : ";
			q->Postorder(q->Front());//front
			cout << endl<<endl;
		}
		else if (user_input == 4)
		{
			cout << endl;
			cout << "End of Program." << endl;
			break;
		}

	}
	return 0;
}