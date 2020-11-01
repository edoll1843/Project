#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <iostream>
using namespace std;
void List::add(Node* newnode) {

	Node* new_node = new Node;
	new_node = newnode;
	if (head->nextNode == nullptr)
	{//if head next is null
		Node* cate_node1 = new Node;//make node
		cate_node1->cate = newnode->cate;//set 
		head->nextNode = cate_node1;//set
		row++;
	}
	Node* tmp = head->nextNode;//set
	if (cate_search(new_node->cate) == true)
	{//if cate is exist
		while (1)
		{
			if (tmp->cate == new_node->cate)
				break;
			tmp = tmp->downNode;
		}

	}
	else
	{
		Node* cate_node = new Node;
		cate_node->cate = newnode->cate;
		while (1)
		{//no cate
			if (tmp->downNode == nullptr)
			{
				break;
			}
			tmp = tmp->downNode;
		}
		tmp->downNode = cate_node;
		row++;
		tmp = tmp->downNode;
	}

	Node* pp = sort_ro(new_node);//sort
	new_node->nextNode = nullptr;
	if (pp->nextNode != nullptr)
	{//if pp-> next is null
		Node* tt;
		tt = pp->nextNode;//tt is pp's next
		pp->nextNode = new_node;
		new_node->nextNode = tt;
		col++;
	}
	else
	{//pp next is not null
		pp->nextNode = new_node;
		col++;
	}
	count++;

}

bool List::cate_search(string cate)
{

	if (head->nextNode->cate == cate)
		return true;//if head next is cate
	else
	{
		Node* tmp = head->nextNode;
		while (tmp->downNode != nullptr)
		{//if tmp is cate
			tmp = tmp->downNode;
			if (tmp->cate == cate)
			{//if tmp is cate
				return true;
			}
		}
	}
	return false;
}

bool List::menu_search(Node* mu)
{
	Node* tmp = head;
	if (tmp->nextNode == nullptr)
		return false;//no cate than false
	tmp = tmp->nextNode;
	while (1)
	{
		if (tmp->cate == mu->cate)
			break;//if tmp cate is find cate break
		if (tmp->downNode == nullptr)
			return false;
		tmp = tmp->downNode;
	}
	while (1)
	{
		if (tmp->menu == mu->menu)
			return true;//is find menu
		if (tmp->nextNode == nullptr)
			return false;
		tmp = tmp->nextNode;
	}
}

void List::remove()
{

	Node* temp;
	Node* rwo = head->nextNode;
	Node* p = rwo->downNode;
	while (1)
	{//delete
		if(rwo->downNode !=nullptr)
			p = rwo->downNode;
		else
		{
			p = nullptr;
		}
		while (rwo!=nullptr)
		{//if row is no null
			temp = rwo;
			rwo = rwo->nextNode;
			temp->nextNode = nullptr;
			temp = nullptr;
			delete temp;//delete
		}
		rwo = p;
		if (rwo == nullptr && p == nullptr)
			break;
	}

	Node* ab = head->nextNode;
	Node* temp1;//temp
	while (ab!=nullptr)
	{//if ab is nu null
		temp1 = ab;
		ab = ab->downNode;
		temp1->nextNode = nullptr;
		temp1 = nullptr;
		delete temp1;//delete
	}
	head->nextNode = nullptr;
	head = nullptr;
	delete head;

}

Node* List::sort_ro(Node* new_node)
{//sort
	Node* temp = head;//set
	Node* new_n = new Node;//set
	new_n = new_node;//set
	int new_price = new_node->price;//set
	if (temp->nextNode == nullptr)
		return nullptr;
	else
		temp = temp->nextNode;//set
	while (1)
	{//if temp cate and new cate is same
		if (temp->cate == new_n->cate)
			break;//find node
		temp = temp->downNode;//set
	}
	while (1)
	{
		if (temp->nextNode == nullptr)
			return temp;
		else
		{
			if (temp->nextNode->price < new_n->price)
			{//if temp price is smaller than new price
				temp = temp->nextNode;
			}
			else if (temp->nextNode->price > new_n->price)
			{//temp is bigger than new price 
				return temp;
			}
			else
			{
				while (1)
				{
					if (temp->nextNode == nullptr)
						return temp;
					const char* a;
					a = temp->nextNode->menu.c_str();
					const char* b;
					b = new_n->menu.c_str();
					if (strcmp(a, b) > 0)
						return temp;
					else if (strcmp(a, b) < 0)
					{//if price is same compare char
						temp = temp->nextNode;
						if (temp->nextNode == nullptr)
							return temp;
						if (temp->nextNode->price > new_n->price)
							return temp;
					}

				}

			}
		}

	}
}

bool List::print()
{//print

	if (head->nextNode == nullptr)
		return false;
	else
	{
		Node* temp = head->nextNode;//set
		Node* cat = head->nextNode;//set
		while (1)
		{
			cout << endl;
			cout << "========== " << cat->cate << " ==========" << endl << endl;
			while (1)
			{
				if (temp->nextNode == nullptr)
					break;
				temp = temp->nextNode;
				cout << temp->menu << " " << temp->price << endl;//print temp node
			}
			cout << endl;
			if (cat->downNode == nullptr)
				break;
			else
			{
				cat = cat->downNode;
				temp = cat;
			}
		}

	}
	return true;
}

bool List::search_cate(string cate)
{//search cate
	Node* tmp = head;
	char o_temp[100] = { NULL, };//set
	char n_temp[100] = { NULL, };//set
	strcpy(o_temp, cate.c_str());//set
	if (tmp->nextNode == nullptr)
		return false;
	else
	{
		tmp = tmp->nextNode;
		while (1)
		{
			if (_stricmp(strcpy(n_temp, tmp->cate.c_str()), o_temp) == 0)
				break;//cmp temp and n temp
			if (tmp->downNode == nullptr)
				return false;
			tmp = tmp->downNode;
		}
		cout << tmp->cate << endl;//print
		while (1)
		{
			if (tmp->nextNode == nullptr)
				break;
			tmp = tmp->nextNode;
			cout << tmp->menu << " " << tmp->price << endl;//print

		}
	}
	cout << endl;
	return true;
}

bool List::search_menu(string menu)
{
	Node* tmp = head;
	Node* pp = head;
	char o_temp[100] = { NULL, };
	char n_temp[100] = { NULL, };
	strcpy(o_temp, menu.c_str());
	if (tmp->nextNode == nullptr)
		return false;
	else
	{
		tmp = tmp->nextNode;
		pp = head->nextNode;
		while (1)
		{
			while (1)
			{
				if (_stricmp(strcpy(n_temp, tmp->menu.c_str()), o_temp) == 0)
				{//if find menu
					cout << tmp->menu << " " << tmp->price;//print
					cout << endl;
					cout << endl;
					return true;
				}
				if (tmp->nextNode == nullptr)
					break;
				tmp = tmp->nextNode;
			}
			if (pp->downNode == nullptr)
				return false;
			pp = pp->downNode;
			tmp = pp;

		}
	}
	cout << endl;
	return true;
}

bool List::delete_menu(string menu)
{
	Node* tmp = head;//set
	Node* pp = head;//set
	Node* p = head;//set
	char o_temp[100] = { NULL, };//set
	char n_temp[100] = { NULL, };//set
	strcpy(o_temp, menu.c_str());//set
	if (tmp->nextNode == nullptr)
		return false;
	else
	{
		tmp = tmp->nextNode;//set
		pp = head->nextNode;//set
		while (1)
		{
			while (1)
			{
				if (_stricmp(strcpy(n_temp, tmp->menu.c_str()), o_temp) == 0)
				{//if n_temp and 0_temp is same
					if (tmp->nextNode == nullptr)
					{
						p->nextNode = nullptr;
						count--;
						col--;
						delete(tmp);//delete
					}
					else
					{//no same
						p->nextNode = tmp->nextNode;
						count--;
						col--;
						delete tmp;//delete
					}
					cout << "Delete Success!" << endl;
					cout << endl;
					return true;
				}
				if (tmp->nextNode == nullptr)
					break;
				p = tmp;
				tmp = tmp->nextNode;
			}
			if (pp->downNode == nullptr)
				return false;
			pp = pp->downNode;
			tmp = pp;
			p = pp;

		}
	}

	cout << endl;
	return true;
}


