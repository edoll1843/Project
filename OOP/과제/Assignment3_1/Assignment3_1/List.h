#include <iostream>
using namespace std;
class Node {
public:
	string cate;//declare
	string menu;//declare
	int price;//declare
	Node* nextNode;//declare
	Node* downNode;//declare
	
};

class List {
private:
	int count=0;//declare
	int row=0;//declare
	int col=0;//declare
	Node* head = new Node();//declare
public:
	List()
	{
		head->nextNode = nullptr; count = 0;//declare
	}
	~List()
	{
		remove();
	}
	void add(Node * newnode);//declare
	bool cate_search(string cate);//declare
	bool menu_search(Node * mu); //declare
	void remove(); //declare
	Node* sort_ro(Node* new_node);//declare
	bool print();//declare
	bool search_cate(string cate);//declare
	bool search_menu(string menu);//declare
	bool delete_menu(string menu);//declare
};