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
	cout << "**********************************" << endl;
	cout << "S T A R T" << endl;
	cout << "**********************************" << endl;
	while (user_input != 12)
	{
		user_input = 0;
		print_menu();
		cin >> user_input;
		cout << endl;
		if (user_input == 1)
		{//insert begin
			cout << "<Insert lecture at beginning>" << endl;
			string user_name;//set
			string user_professor;//set
			string user_grade;//set
			char grade_temp[10];
			cout << "->Enter the lecture name: ";
			cin.ignore(100, '\n');
			getline(cin, user_name);

			cout << "->Enter the lecture professor: ";
			getline(cin, user_professor);

			cout << "->Enter the lecture grade: ";
			getline(cin, user_grade);
			cout << "----------------------------------------" << endl << endl;
			strcpy(grade_temp, user_grade.c_str());
			Node* newnode = new Node;
			newnode->name = user_name;//set
			newnode->professor = user_professor;//set
			newnode->grade = atoi(grade_temp);//set
			list.insert_beginning(newnode);//insert
		}
		else if (user_input == 2)
		{//insert last
			cout << "<Insert lecture at last>" << endl;
			string user_name;//set
			string user_professor;//set
			string user_grade;//set
			char grade_temp[10];//set
			cout << "->Enter the lecture name: ";
			cin.ignore(100, '\n');
			getline(cin, user_name);
			cout << "->Enter the lecture professor: ";
			getline(cin, user_professor);
			cout << "->Enter the lecture grade: ";
			getline(cin, user_grade);
			cout << "----------------------------------------" << endl << endl;
			strcpy(grade_temp, user_grade.c_str());
			Node* newnode = new Node;//make node
			newnode->name = user_name;//set
			newnode->professor = user_professor;//set
			newnode->grade = atoi(grade_temp);//set
			list.insert_last(newnode);//insert last
		}
		else if (user_input == 3)
		{//insert position
tryAgain:
			int user_po = 0;
			cout << "<Insert lecture at position>" << endl;
			cout << "->Enter the position of lecture insert :";
			cin >> user_po;//set
			if (user_po <= 0 || user_po > list.maxposition() + 1)
				goto tryAgain;//if position is wrong goto again
			string user_name;//set
			string user_professor;//set
			string user_grade;//set
			char grade_temp[10];
			cout << "->Enter the lecture name: ";
			cin.ignore(100, '\n');
			getline(cin, user_name);
			cout << "->Enter the lecture professor: ";
			getline(cin, user_professor);
			cout << "->Enter the lecture grade: ";
			getline(cin, user_grade);
			cout << "----------------------------------------" << endl << endl;
			strcpy(grade_temp, user_grade.c_str());
			Node* newnode = new Node;//set
			newnode->name = user_name;//set
			newnode->professor = user_professor;//set
			newnode->grade = atoi(grade_temp);//set
			if (list.insert_position(newnode, user_po) == false)//insert
				continue;
		}
		else if (user_input == 4)
		{
			string user_name;//set
			cout << "<Delete lecture>" << endl;
			cout << "Enter the lecture of Delete: ";
			cin.ignore(100, '\n');
			getline(cin, user_name);//set
			if (list.delete_lecture(user_name) == false)
			{//delete 
				cout << "No lecture to delete" << endl;
				continue;
			}
		}
		else if (user_input == 5)
		{
			string user_name;//set
			cout << "<Update lecture>" << endl;
			cout << "->Enter the lecture name: ";
			cin.ignore(100, '\n');//set
			getline(cin, user_name);//set
			if (list.search_lecture(user_name) == false)
			{//serch lecture
				cout << "No information to update" << endl;
				cout << "--------------------------------" << endl;
			}
			else
			{
				string user_name1;//set
				string user_professor;//set
				string user_grade;//set
				char grade_temp[10];
				cout << "->Enter the new lecture name: ";
				getline(cin, user_name1);
				cout << "->Enter the new lecture professor: ";
				getline(cin, user_professor);
				cout << "->Enter the new lecture grade: ";
				getline(cin, user_grade);
				cout << "----------------------------------------" << endl << endl;
				strcpy(grade_temp, user_grade.c_str());//set
				Node* newnode = new Node;//set
				newnode->name = user_name1;//set
				newnode->professor = user_professor;//set
				newnode->grade = atoi(grade_temp);//set
				list.update_lecture(newnode, user_name);//update 
			}
		}
		else if (user_input == 6)
		{
			string user_name;
			cout << "<Search lecture>" << endl;
			cout << "->Enter the lecture name you want to search: ";
			cin.ignore(100, '\n');
			getline(cin, user_name);
			if (list.serch_lec(user_name) == false)
			{//search lecture
				cout << "No lecture you found" << endl << endl;
				cout << "-----------------------------------" << endl;
			}
		}
		else if (user_input == 7)
		{
			string user_name;
			cout << "<Search professor>" << endl;
			cout << "->Enter the professor name you want to search: ";
			cin.ignore(100, '\n');
			getline(cin, user_name);
			if (list.search_pro(user_name) == false)
			{//search professor
				cout << "No professor you find" << endl;
				cout << "-----------------------------------" << endl;
			}
			else
				cout << "-----------------------------------" << endl;
		}
		else if (user_input == 8)
		{
			string user_name;
			char grade_temp[10];
			cout << "<Search grade>" << endl;
			cout << "->Enter the grade you want to search: ";
			cin.ignore(100, '\n');
			getline(cin, user_name);
			strcpy(grade_temp, user_name.c_str());
			int user_grade = atoi(grade_temp);
			if (list.search_grade(user_grade) == false)
			{//search grade
				cout << "No grade you find" << endl;
				cout << "-----------------------------------" << endl;
			}
			else
			{
				cout << "-----------------------------------" << endl;
			}
		}
		else if (user_input == 9)
		{//sort ascending
			cout << "<Sort by grade in ascending order>" << endl;
			cout << "-----------------------------------" << endl;
			list.sort_ascending();
		}
		else if (user_input == 10)
		{//print
			list.Display();
			cout << "-------------------------------------" << endl;
		}
		else if (user_input == 11)
		{//reverse
			list.reverse();
			cout << "<Reverse lecture list>" << endl;
			cout << "**The product list has been reversed**" << endl;
			cout << "-----------------------------------" << endl;
		}
		else if (user_input == 12)
		{//exit
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
	cout << "1.Insert lecture at beginning" << endl;
	cout << "2.Insert lecture at last" << endl;
	cout << "3.Insert lecture at position" << endl;
	cout << "4.Delete lecture" << endl;
	cout << "5.Update lecture " << endl;
	cout << "6.Search lecture" << endl;
	cout << "7.Search professor" << endl;
	cout << "8.Search grade " << endl;
	cout << "9.Sort by grade In ascending order " << endl;
	cout << "10.Display lecture list " << endl;
	cout << "11.Reverse lecture list" << endl;
	cout << "12.Exit" << endl;
	cout << "Input Number : ";
}
