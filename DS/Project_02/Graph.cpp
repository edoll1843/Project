#include "Graph.h"
#include <map>
#include <cstdlib>
#include <iostream>
#include <algorithm>
Graph::Graph(ofstream * flog)
{
	this->flog=flog; //get flog
}

Graph::~Graph()
{
}

bool Graph::Build(AVLTree * root)
{

	int a = 0; //value declare
	int weight = 0;//value declare
	while (gp_arry[size] != NULL)
	{ //while gp arry is null
		a++; //count 
		size++; //count
	}
	this->vertex = new CityData*[size + 1]; //reset
	this->mList = new map<int, CityData*>[size + 1]; //reset
	AVLNode * temp = new AVLNode(); //make new node
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (strncmp(gp_arry[i]->GetCityData()->Getname(), gp_arry[j]->GetCityData()->Getname(),sizeof(gp_arry[i]->GetCityData()->Getname())) > 0)
			{ //if index i 's name si bigger than gp_arry's name
				temp = gp_arry[i]; //swap
				gp_arry[i] = gp_arry[j]; //swap
				gp_arry[j] = temp; //swap
			}
		}
	}
	for (int x = 0; x < a; x++)
	{
		{
			vertex[x] = gp_arry[x]->GetCityData(); //insert  data into vertex
		}
	}
	for (int v = 0; v < size; v++)
	{
		for (int x = 0; x < a; x++)
		{
			mList[v].insert(make_pair(x, vertex[x])); //insert into mList
		}
	}
	return true;
}
void Graph::Print_GP()
{ //print gp
	int weight = 0;//value declare
	for (int a = 0; a < size; a++)
	{
		for (int b = 0; b < size; b++)
		{//weight is mlist's local- next local 's abs
			weight = abs(mList[a][a]->GetLocationId() - mList[a][b]->GetLocationId());
			*flog << weight << "	";
		}
		*flog << endl;
	}
}

void Graph::Print_MST()
{
	for (int a = 0; a < R_tree.size(); a++)
	{//print r_tree's data
		*flog<< "("<<R_tree[a].data1->Getname()<<", ";
		*flog << R_tree[a].data2->Getname()<<"), ";
		*flog<< R_tree[a].wei << endl;
	}
	*flog << "Total: " << mstMatrix << endl;
}

bool Graph::Kruskal()
{
	edge ege[30][30] = { 0 };//edge's ege[30][30] value declare
	for (int a = 0; a < size; a++)
		for (int b = 0; b < size; b++)
		{

			ege[a][b].u = a;//insert value
			ege[a][b].v = b; //insert value
			ege[a][b].data1 = mList[a][a]; //insert data1
			ege[a][b].data2 = mList[a][b]; //insert data2
			ege[a][b].wei = abs(mList[a][a]->GetLocationId() - mList[a][b]->GetLocationId()); //insert weight
			if (ege[a][b].wei == 0)
			{ //if wei is 0 break;
				break;
			}
			kru_tree.push_back((edge(ege[a][b])));//insert edge node into vector 
		}
	sort(kru_tree.begin(), kru_tree.end());//sort it
	int parent[60];//value declare
	for (int i = 0; i < 60; i++)
		parent[i] = i; //set root value
	for (int i = 0; i < kru_tree.size(); i++)
		if (!find(parent, kru_tree[i].u, kru_tree[i].v))
		{ //if find union 
			mstMatrix += kru_tree[i].wei; //get weight of kru_tree
			R_tree.push_back((edge(kru_tree[i]))); //insert in vector too
			union_set(parent, kru_tree[i].u, kru_tree[i].v);//union_set 

		}
	return true;
}

int Graph::make_set(int parent[], int a)
{//make ser
	if (parent[a] == a) //if parent [] is a return
		return a;
	return make_set(parent, parent[a]);//recursivly call fucntion
}

int Graph::union_set(int parent[],int x, int y)
{ //union_set
	x = make_set(parent, x);//make set parent and x
	y = make_set(parent, y);//make set parent and y
	if (x < y)
	{
		parent[y] = x;
		return x;
	}
	else
	{
		parent[x] = y;
		return y;
	}
}

int Graph::find(int parent[],int x,int y)
{
	x = make_set(parent, x);//call make_set fucntion
	y = make_set(parent, y);
	if (x == y)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void Graph::insert_gp(AVLNode * tree,int zzzz)
{ //insert gp arry
		if (gp_arry[0] == NULL)
		{ //if arry is null  
			gp_arry[0] = tree;//set root
		}
		else
		{
			gp_arry[zzzz] = tree;
		}

	return;
}








