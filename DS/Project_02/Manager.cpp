# define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include "Manager.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Manager::Manager()
{
	flog.open("log.txt", ios::app);
	flog.setf(ios::fixed);

	avl = new AVLTree(&flog);
	gp = new Graph(&flog);
	iter = 0;
	cmd = NULL;
}

Manager::~Manager()
{
	flog.close();
}

void Manager::run(const char * command)
{
	fin.open(command);//open text

	cmd = new char[40];//value declare


	while (!fin.eof())
	{ //whille until read text file is null
		iter = iter + 1; //iter num
		fin.getline(cmd, 40);//get command
		char * one = strtok(cmd, " "); //get one and strto
		two = strtok(NULL, " "); //two strtok
		three = strtok(NULL, " "); 
		four = strtok(NULL, " ");
		if (!strcmp(one, "LOAD")) {
			if (LOAD() == true)
			{ //if LOAD
				printSuccessCode("LOAD");//print success code
			}
			else
			{
				printErrorCode(100, "LOAD");//print error code
			}
		}
		else if (!strcmp(one, "INSERT")) {
			if (INSERT() == true)
			{ //print success code
				printSuccessCode("INSERT");//print success code
			}
			else
			{//print error code
				printErrorCode(200, "INSERT");
			}
		}
		else if (!strcmp(one, "PRINT_AVL")) {
			flog << "==> command " << iter << ") " << "PRINT_AVL" << endl;
			if (PRINT_AVL() == true)//print success code
			{//if command is print AVL
				flog << "Success" << endl;//if command is success print success code
			}
			else
			{
				printErrorCode(300, "PRINT_AVL");
			}
		}
		else if (!strcmp(one, "SEARCH_AVL")) {//if command is SEARCH_AVL
				flog << "==> command " << iter << ") " << "SEARCH_AVL " << two << endl;
			if (SEARCH_AVL() == false) //if fucntion is false
			{
				flog << "==> command " << iter << ") " << "SEARCH_AVL" << endl;
				flog << "Error code: " << "500" << endl;	//print error code
			}
		}
		else if (!strcmp(one, "DELETE_AVL")) {//if command is DELETE_AVL
			flog << "==> command " << iter << ") " << "DELETE_AVL " << two << endl;
			if (DELETE_AVL() == true)
			{ //if delete success print Success
				flog << "Success" << endl;
			}
			else
			{ //false print error code
				printErrorCode(400, "DELETE_AVL");
			}
		}
		else if (!strcmp(one, "BUILD_GP")) {//if command is BUILD_GP
			if (BUILD_GP() == true)
			{//if fucntion success
				printSuccessCode("BUILD_GP"); //print success code
			}
			else
			{ //if print errot code
				printErrorCode(600, "BUILD_GP");
			}
		}
		else if (!strcmp(one, "PRINT_GP")) {//if command is print_GP
			flog << "==> command " << iter << ") " << "PRINT_GP " << endl;
			if (PRINT_GP() == false)//if fucntion is false
			{
				printErrorCode(700, "PRINT_GP"); //print error code
			}
		}
		else if (!strcmp(one, "BUILD_MST")) {
			flog << "==> command " << iter << ") " << "BUILD_MST " << endl;
			if (BUILD_MST() == true)
			{//BUILD_MST() is true
				flog << "Success" << endl;
			}
			else
			{
				printErrorCode(800, "BUILD_MST");
			}
		}
		else if (!strcmp(one, "PRINT_MST")) {
			flog << "==> command " << iter << ") " << "PRINT_MST " << endl;
			if (PRINT_MST() == false)
			{ //print MST 
				printErrorCode(900, "PRINT_MST");
			}
		}
		else if (!strcmp(one, "EXIT")) {
			flog << "==> command " << iter << ") " << "EXIT " << endl;
			flog << "Success" << endl;
			EXIT();
		}
		else {
			printErrorCode(0, "Unknown");
		}
	}
	fin.close();
	return;
}

bool Manager::LOAD()
{
	string line; //string line
	ifstream in("city_list.txt"); //open citylist
	if (in.fail())
		return false;
	if (avl->Getroot() != NULL)//if avl is NULL
		return false;
	while (getline(in, line))
	{
		char buff[100] = { 0 };//vlaue
		int num1 = 0;
		CityData * data;
		memset(buff, 0, sizeof(buff));//make reset
		strncpy(buff, line.c_str(),sizeof(buff)-1);//copy in to arry
		if (strlen(buff) == 0) break;
		char * city_num = strtok(buff, "\t");//strtok num
		char * city_name = strtok(NULL, "\t");//strtok name
		char * coun_name = strtok(NULL, "\t");//strtok name
		num1 = atoi(city_num);
		data = new CityData;
		data->SetLocationId(num1);//set data
		data->Setname(city_name);//set data
		data->Setcountry(coun_name);//set data
		AVLNode * gp_node = new AVLNode();//make node
		gp_node->SetCityData(data); //set data
		avl->Insert(data); //insert data
		gp->insert_gp(gp_node, zzzz);//insert data
		zzzz++;


	}
	in.close();

	return true;
}

bool Manager::INSERT()
{//insert fucntion
	int num2 = atoi(two);
	CityData * data = new CityData;
	data->SetLocationId(num2);
	data->Setname(three);
	data->Setcountry(four);
	AVLNode * gp_node = new AVLNode();
	gp_node->SetCityData(data);
	avl->Insert(data);
	gp->insert_gp(gp_node, zzzz);
	zzzz++;
	return true;
}
bool Manager::PRINT_AVL()
{//print_avl
	AVLNode * node = avl->Getroot();
	if (node)
	{
		avl->Print(node); //call fucntion
		return true;
	}
	else	
	{
		return false;
	}
}
bool Manager::SEARCH_AVL()
{
	num = atoi(two);
	if (num == 0)
		return false;
	AVLNode * ml = avl->Getroot();//get root
	AVLNode * temp = inorder_s(ml);
	if (temp == NULL)
	{
		return false;
	}
	else
	{
		flog << "(";
		flog << temp->GetCityData()->GetLocationId();
		flog << ", ";
		flog << temp->GetCityData()->Getname();
		flog << ", ";
		flog << temp->GetCityData()->Getcountry();
		flog << ")";
		flog << endl;
	}
	return true;
}

bool Manager::DELETE_AVL()
{//delete AVL
	num = atoi(two);
	avl->Delete(num);
	return true;
}

bool Manager::BUILD_GP()
{//build gp
	if (gp->Build(avl) == true)
		return true;
	else
		return false;
}

bool Manager::PRINT_GP()
{//print gp
	if (gp == NULL)
		return false;
	gp->Print_GP();
	return true;
}

bool Manager::BUILD_MST()
{ //build mst
	gp->Kruskal();
	return true;
}

bool Manager::PRINT_MST()
{//print mst
	gp->Print_MST();
	return true;
}

void Manager::EXIT()
{
	exit(1);
}
AVLNode * Manager::inorder_s(AVLNode * a)
{//inorder
	if(a!=NULL)
	{
		if(a->GetLeft())
		{
			inorder_s(a->GetLeft());
		}
		if (a->GetCityData()->GetLocationId() == num)
		{
			si = a;
			
		}
		if(a->GetRight())
		{
			inorder_s(a->GetRight());
		}
	}
	else
		return NULL;
	return si;
}

void Manager::printErrorCode(int n, const char * cmdname) {//ERROR CODE PRINNT FUNCTION
	flog << "==> command " << iter << ") " << cmdname << endl;
	flog << "Error code: " << n << endl;
}

void Manager::printSuccessCode(const char * cmdname) {//SUCCESS CODE PRINNT FUNCTION
	flog << "==> command " << iter << ") " << cmdname << endl;
	flog << "Success" << endl;
}
