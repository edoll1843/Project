#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <fstream>
#include "List.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void print_menu();
int main()
{
	int user_input = 0;

	List list;
	while (user_input != 7)
	{
		//while until input is 7
		print_menu();//print menu
		cin >> user_input;
		cout << endl;
		if (user_input == 1)
		{//LOAD
			string dir = "input.txt";
			ifstream in(dir);
			string line;
			char buf[100];
			string cate2;
			string menu2;
			while (getline(in, line))
			{
				strcpy(buf, line.c_str());
				char* cate1 = strtok(buf, "\t");//get cate
				char* menu1 = strtok(NULL,"\t");//get menu
				char* price = strtok(NULL, "\t");//get price
				if (strcmp(cate1,"CATEGORY")==0)
				{
					continue;
				}
				if (cate1 == NULL)
				{//is cate is null error
					cout <<menu1<< " invalid input!" << endl<<endl;
					continue;
				}
				else if (menu1 == NULL)
				{//menu and price is null
					cout << cate1<< " invalid input!" << endl << endl;
					continue;
				}
				else if (price == NULL)
				{//price is null
					cout << menu1 << " invalid input!" << endl << endl;
					continue;
				}
				cate2 = string(cate1);//set
				menu2 = string(menu1);//set
				int pri = atoi(price);//set
				Node* n_node = new Node;//make node
				n_node->cate = cate2;//set
				n_node->menu = menu2;//set
				n_node->price = pri;//set
				if (list.menu_search(n_node) == true)
				{//if menu is exist
					cout << menu2 << " already exists!" << endl << endl;
					continue;
				}
				list.add(n_node);//insert
				
			}
			cout << "LOAD Success!" << endl << endl;
		}
		else if (user_input == 2)
		{//PRINT
			if (list.print() == false)
			{//if print is false
				cout << "The data does not exist!" << endl;
				cout << endl;
				user_input = 0;
				continue;
			}
		}
		else if (user_input == 3)
		{//INSERT
			string user_txt;
			cout << "Enter Category, Menu and Price : " ;
			cin.ignore(100, '\n');
			getline(cin, user_txt);
			char buf[100];//declare
			string cate2;//declare
			string menu2;//declare
			strcpy(buf, user_txt.c_str());//set
			char* cate1 = strtok(buf, " ");//get cate
			char* menu1 = strtok(NULL, " ");//get menu
			char* price = strtok(NULL, " ");//get price
			if (cate1 == NULL || price == NULL)
			{//cate and price is null
				cout << cate1 << " invalid input!" << endl << endl;
				continue;
			}
			cate2 = string(cate1);//set
			menu2 = string(menu1);//set
			int pri = atoi(price);//set
			Node* n_node = new Node;//set
			n_node->cate = cate2;//set
			n_node->menu = menu2;//set
			n_node->price = pri;//set
			if (list.menu_search(n_node) == true)
			{//exist
				cout << menu2 << " already exists!" << endl << endl;
				continue;
			}
			list.add(n_node);
			cout << "Insert Success!" << endl << endl;
			user_input = 0;
		}
		else if (user_input == 4)
		{//Category SEARCH
			string user_txt;
			cout << "Enter Category which you want to find : ";
			cin.ignore(100, '\n');
			getline(cin, user_txt);
			if (list.search_cate(user_txt) == false)
			{//if search is false
				cout << "No search data" << endl << endl;
				continue;
			}
		}
		else if (user_input == 5)
		{//Menu SEARCH
			string user_txt;
			cout << "Enter Menu which you want to find : ";
			cin.ignore(100, '\n');
			getline(cin, user_txt);
			if (list.search_menu(user_txt) == false)
			{//if search is false
				cout << "No search data" << endl << endl;
				continue;
			}
		}
		else if (user_input == 6)
		{//DELETE
			string user_txt;
			cout << "Enter Menu which you want to delete : ";
			cin.ignore(100, '\n');
			getline(cin, user_txt);
			if (list.delete_menu(user_txt) == false)
			{//if search is false
				cout << "No search data" << endl << endl;
				continue;
			}
		}
		else if (user_input == 7)
		{//End of Program!
			cout << endl << "End of Program." << endl;
			exit(0);
		}
		else
		{
			exit(0);
		}
		user_input = 0;
	}

}
void print_menu()
{
	cout << "1.LOAD" << endl;
	cout << "2.PRINT" << endl;
	cout << "3.INSERT" << endl;
	cout << "4.Category SEARCH" << endl;
	cout << "5.Menu SEARCH" << endl;
	cout << "6.DELETE" << endl;
	cout << "7.End of Program!" << endl;
	cout << "Select Number : ";
}
