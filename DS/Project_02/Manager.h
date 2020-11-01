#include "Graph.h"
#include<utility>
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class Manager
{
public:
	AVLTree * avl;//value declare
	Graph * gp;//value declare
	char * cmd;//value declare
	int iter;//value declare
	char * two;//value declare
	char * three;//value declare
	char * four;//value declare
	int num;//value declare
	int zzzz;//value declare
	
	AVLNode * prin;//value declare

public:
	Manager();
	~Manager();

	ofstream flog;//value declare
	ifstream fin;//value declare

	void run(const char * command);//fucntion declare
	bool LOAD();//fucntion declare
	bool INSERT();//fucntion declare
	bool PRINT_AVL();//fucntion declare
	bool SEARCH_AVL();//fucntion declare
	bool DELETE_AVL();//fucntion declare
	bool BUILD_GP();//fucntion declare
	bool PRINT_GP();//fucntion declare
	bool BUILD_MST();//fucntion declare
	bool PRINT_MST();//fucntion declare
	void EXIT();//fucntion declare

	AVLNode * si;//value declare
	AVLNode * inorder_s(AVLNode * a);//fucntion declare

	void printErrorCode(int n, const char * cmdname);//fucntion declare
	void printSuccessCode(const char * cmdname);//fucntion declare

};
