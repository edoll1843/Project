#pragma once
#include <iostream>
using namespace std;
class Node {
public:

	Node* nextNode;//declare
	Node* preNode;//declare
	string name;//declare
	string professor;//declare
	int grade=0;//declare
	int position = 0;//declare


};

class List {
private:

	Node* head = new Node();//declare
	Node* tail = new Node();//declare

	
public:
	List()
	{
		head = nullptr;//declare
		tail = nullptr;//declare
	}
	~List()
	{

	}
	void insert_beginning(Node* newNode);//declare
	void insert_last(Node* newNode);//declare
	bool insert_position(Node* newNode,int posi);//declare
	void Display();//declare
	void reposition();//declare
	int maxposition();//declare
	bool delete_lecture(string u_name);//declare
	bool search_lecture(string u_name);//declare
	void update_lecture(Node* newNode,string u_name);//declare
	bool serch_lec(string u_name);//declare
	bool search_pro(string u_name);//declare
	bool search_grade(int g);//declare
	void sort_ascending();//declare
	void reverse();//declare
	void delete_lecture2(string u_name);//declare
};