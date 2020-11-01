#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <vector>
void List::insert_beginning(Node* newNode)
{
	Node* n = new Node;//set
	n = newNode;
	if (head == nullptr)
	{//head is null
		head = n;
		tail = n;

		n->position = 1;
	}
	else if (tail == head)
	{//one node
		Node* temp = head;
		head = n;
		tail = temp;

		head->nextNode = tail;
		head->preNode = tail;
		tail->nextNode = head;
		tail->preNode = head;

		head->position = 1;
		tail->position = 2;

	}
	else
	{//else 
		Node* temp = head;
		head = n;
		n->nextNode = temp;
		n->preNode = tail;
		temp->preNode = n;
		tail->nextNode = n;
		reposition();

	}
}

void List::insert_last(Node* newNode)
{
	Node* n = new Node;//set
	n = newNode;
	if (head == nullptr)
	{//head is null
		head = n;
		tail = n;

		n->position = 1;
	}
	else if (tail == head)
	{//head is tail
		Node* temp = tail;
		head = temp;
		tail = n;

		head->nextNode = tail;
		head->preNode = tail;
		tail->nextNode = head;
		tail->preNode = head;

		head->position = 1;
		tail->position = 2;

	}
	else
	{//head is no null and lot node
		Node* temp = tail;
		tail = n;
		temp->nextNode = n;
		n->nextNode = head;
		n->preNode = temp;
		head->preNode = n;
		reposition();

	}
}

bool List::insert_position(Node* newNode, int posi)
{
	Node* n = new Node;//set
	n = newNode;
	if (head == nullptr && posi == 1)
	{//head is null
		head = n;
		tail = n;

		n->position = 1;
		return true;
	}
	else if (posi == 1)
	{//position is 1 insert begin
		insert_beginning(n);
		return true;
	}
	else if (posi == tail->position + 1)
	{//insert last
		insert_last(n);
		return true;
	}
	else
	{//insert position
		Node* temp = head;

		while (1)
		{
			if (temp == nullptr)
				break;
			else
				temp = temp->nextNode;
			if (temp->position == posi)
				break;
		}
		Node* temp_pre = temp->preNode;
		n->nextNode = temp;
		temp->preNode = n;
		temp_pre->nextNode = n;
		n->preNode = temp_pre;
		reposition();
		return true;
	}


}

void List::Display()
{
	cout << "<Display lecture list>" << endl;
	Node* temp = head;
	if (temp == nullptr)
		return;
	while (1)
	{
		cout << "lecture name: " << temp->name << endl;
		cout << "lecture professor: " << temp->professor << endl;
		cout << "lecture grade: " << temp->grade << endl;
		if (temp->nextNode == nullptr || temp == tail)
			break;
		temp = temp->nextNode;
	}
}


void List::reposition()
{
	if (head == nullptr)
		return;
	if (head->nextNode == nullptr)
	{
		head->position = 1;
		return;
	}
	Node* temp = head;//set
	int p = 2;
	head->position = 1;
	while (1)
	{
		temp = temp->nextNode;
		temp->position = p++;
		if (temp == tail)
			break;
	}
}

int List::maxposition()
{
	if (head == nullptr)
		return 0;
	Node* temp = head;
	while (1)
	{
		if (temp->nextNode == nullptr)
			break;
		temp = temp->nextNode;
		if (temp == tail)
			break;
	}
	return temp->position;
}

bool List::delete_lecture(string u_name)
{
	if (head == nullptr)//head is null
		return false;
	Node* temp = head;
	string temp_name;
	int temp_posi;
	while (1)
	{
		if (temp->name == u_name)
		{//name is umane
			temp_name = temp->name;
			temp_posi = temp->position;
			break;
		}
		if (temp->nextNode == nullptr)
			return false;
		if (temp == tail)
			return false;
		temp = temp->nextNode;

	}
	if (temp == head && temp->nextNode == nullptr)
	{//temp is head and next is null
		free(head);
		head = nullptr;
		delete head;
	}
	else if (temp == head)
	{//temp is head
		if (temp->nextNode == tail)
		{//next is tial
			head = tail;
			tail->nextNode = nullptr;
			tail->preNode = nullptr;
			head->nextNode = nullptr;
			head->preNode = nullptr;
			free(temp);
			temp = nullptr;
			delete temp;

		}
		else
		{//esles
			head = temp->nextNode;
			tail->nextNode = head;
			head->preNode = tail;
			free(temp);
			temp = nullptr;
			delete temp;

		}
	}
	else if (temp == tail)
	{//temp is tail
		if (temp->preNode == head)
		{//pre is head
			tail = head;
			tail->nextNode = nullptr;
			tail->preNode = nullptr;
			head->nextNode = nullptr;
			head->preNode = nullptr;
			free(temp);
			temp = nullptr;
			delete temp;//delete

		}
		else
		{//esle
			tail = temp->preNode;
			tail->nextNode = head;
			head->preNode = tail;
			free(temp);
			temp = nullptr;
			delete temp;
		}
	}
	else
	{//else
		temp->preNode->nextNode = temp->nextNode;
		temp->nextNode->preNode = temp->preNode;
		free(temp);
		temp = nullptr;
		delete temp;
	}
	reposition();
	cout << "**" << temp_name << " has been deleted from position " << temp_posi << "**" << endl;
	cout << "------------------------------------------" << endl;
	return true;

}

bool List::search_lecture(string u_name)
{
	if (head == nullptr)
		return false;
	Node* temp = head;
	while (1)
	{
		if (temp->name == u_name)
			return true;
		if (temp->nextNode == nullptr)
			break;
		if (temp == tail)
			break;
		temp = temp->nextNode;
	}
	return false;
}

void List::update_lecture(Node* newNode, string u_name)
{
	if (head == nullptr)
		return;
	Node* temp = head;
	while (1)
	{
		if (temp->name == u_name)
			break;
		temp = temp->nextNode;
	}
	temp->name = newNode->name;
	temp->professor = newNode->professor;
	temp->grade = newNode->grade;
}

bool List::serch_lec(string u_name)
{//serch
	if (head == nullptr)//head is null
		return false;
	Node* temp = head;
	while (1)
	{
		if (temp->name == u_name)
			break;
		if (temp->nextNode == nullptr)
			return false;
		if (temp == tail)
			return false;
		temp = temp->nextNode;
	}
	cout << "*At position " << temp->position << "*" << endl;
	cout << "lecture name: " << temp->name << endl;
	cout << "lecture professor: " << temp->professor << endl;
	cout << "lecture grade: " << temp->grade << endl;
	cout << "-----------------------------------" << endl << endl;
	return true;
}

bool List::search_pro(string u_name)
{
	if (head == nullptr)//head is null
		return false;
	Node* temp = head;//set
	int count = 0;
	while (1)
	{
		if (temp->professor == u_name)
		{
			cout << "*At position " << temp->position << "*" << endl;
			cout << "lecture name: " << temp->name << endl;
			cout << "lecture professor: " << temp->professor << endl;
			cout << "lecture grade: " << temp->grade << endl << endl;
			count++;
		}
		if (temp->nextNode == nullptr && count == 0)
			return false;
		else if (temp->nextNode == nullptr)
			break;
		if (temp == tail && count == 0)
			return false;
		else if (temp == tail)
			break;
		temp = temp->nextNode;
	}
	return true;
}

bool List::search_grade(int g)
{
	if (head == nullptr)
		return false;//head is null
	Node* temp = head;
	int count = 0;
	while (1)
	{
		if (temp->grade == g)
		{
			cout << "*At position " << temp->position << "*" << endl;
			cout << "lecture name: " << temp->name << endl;
			cout << "lecture professor: " << temp->professor << endl;
			cout << "lecture grade: " << temp->grade << endl << endl;
			count++;
		}
		if (temp->nextNode == nullptr && count == 0)
			return false;
		else if (temp->nextNode == nullptr)
			break;
		if (temp == tail && count == 0)
			return false;
		else if (temp == tail)
			break;
		temp = temp->nextNode;
	}
	return true;
}

void List::sort_ascending()
{
	vector<string> v1;
	vector<string> v2;
	vector<int> v3;
	if (head == nullptr)
		return;
	Node* temp = head;

	if (temp->nextNode == nullptr)
		return;
	else
	{
		while (1)
		{
			if (temp == tail)
				break;
			Node* temp1 = temp->nextNode;
			while (1)
			{
				if (temp->grade > temp1->grade)
				{
					temp = temp1;
				}
				else if (temp->grade == temp1->grade)
				{
					char a[100];//set
					char b[100];//set
					strcpy(a, temp->name.c_str());//set
					strcpy(b, temp1->name.c_str());//set
					if (strcmp(a, b) > 0)
					{//a is bigger than b
						temp = temp1;
					}
				}
				if (temp1 == tail)
				{//set
					v1.push_back(temp->name);//set
					v2.push_back(temp->professor);//set
					v3.push_back(temp->grade);//set
					delete_lecture2(temp->name);//delete ndde
					break;
				}
				temp1 = temp1->nextNode;
			}
			temp = head;
			if (temp == tail)
			{//temp is tail
				v1.push_back(temp->name);//set
				v2.push_back(temp->professor);//set
				v3.push_back(temp->grade);//set
				delete_lecture2(temp->name);//delete
				break;
			}
		}

		for (int a = 0; a < v1.size(); a++)
		{
			Node* N = new Node;
			N->name = v1[a];//set
			N->professor = v2[a];//set
			N->grade = v3[a];//set
			insert_last(N);//set insert last
		}
	}
}

void List::reverse()
{
	if (head == nullptr)//head is null
		return;
	if (head->nextNode == nullptr)
		return;
	int count = maxposition();
	Node* temp = head;
	int a = 1;
	while ( a<count)
	{// a < coutn
		temp = temp->nextNode;
		a++;
	}
	Node* cur;
	while (1)
	{//temp is head break
		cur = temp->preNode;
		temp->preNode->nextNode = nullptr;
		temp->preNode = nullptr;
		temp->nextNode = cur;
		temp = cur;
		if (temp == head)
			break;
	}
	tail->preNode = head;
	head->nextNode = tail;
	Node* swap = head;
	head = tail;
	tail = swap;
	Node* z = head;
	while (1)
	{//z is tail
		z->nextNode->preNode = z;
		z = z->nextNode;
		if (z == tail)
			break;
	}
	reposition();
}

void List::delete_lecture2(string u_name)
{//delelete with no print
	if (head == nullptr)
		return;
	Node* temp = head;
	string temp_name;
	int temp_posi;
	while (1)
	{
		if (temp->name == u_name)
		{
			temp_name = temp->name;
			temp_posi = temp->position;
			break;
		}
		if (temp->nextNode == nullptr)
			return;
		if (temp == tail)
			return;
		temp = temp->nextNode;

	}
	if (temp == head && temp->nextNode == nullptr)
	{
		free(head);
		head = nullptr;
		delete head;
	}
	else if (temp == head)
	{
		if (temp->nextNode == tail)
		{
			head = tail;
			tail->nextNode = nullptr;
			tail->preNode = nullptr;
			head->nextNode = nullptr;
			head->preNode = nullptr;
			free(temp);
			temp = nullptr;
			delete temp;

		}
		else
		{
			head = temp->nextNode;
			tail->nextNode = head;
			head->preNode = tail;
			free(temp);
			temp = nullptr;
			delete temp;

		}
	}
	else if (temp == tail)
	{
		if (temp->preNode == head)
		{
			tail = head;
			tail->nextNode = nullptr;
			tail->preNode = nullptr;
			head->nextNode = nullptr;
			head->preNode = nullptr;
			free(temp);
			temp = nullptr;
			delete temp;

		}
		else
		{
			tail = temp->preNode;
			tail->nextNode = head;
			head->preNode = tail;
			free(temp);
			temp = nullptr;
			delete temp;
		}
	}
	else
	{
		temp->preNode->nextNode = temp->nextNode;
		temp->nextNode->preNode = temp->preNode;
		free(temp);
		temp = nullptr;
		delete temp;
	}
	reposition();

}
