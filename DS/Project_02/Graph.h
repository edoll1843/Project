#include "AVLTree.h"
#include <iostream>
#include <fstream>// header file declare
#include <map>
#include <vector>
using namespace std;
class Graph
{
public:
	map<int,CityData*> * mList;	// mList[from vetex] = map<to vertex, weigth>
	CityData * * vertex;			// vetex[index] = CityData * 
	int size;					// AVLTree size
	int  mstMatrix;			// MST
	AVLNode * gp_arry[30];//value declare
	AVLNode * MST_arry[30];//value declare
	ofstream * flog;//value declare
	int swei;//value declare
	int arr[100];//value declare
	int parent[100];//value declare
	int num[100];//value declare
	int cc;//value declare

	struct edge//struct edge
	{
	public:
		int u; //(u,v)
		int v;//(u,v)
		CityData * data1;//value declare
		CityData * data2;//value declare
		int wei;
		bool operator <(edge &edge) { //set operation to use sort
			return this->wei < edge.wei;//if wei is smaller than edge's wei return edge.we 
		}
	};

	vector<edge> kru_tree;//value declare
	vector<edge> R_tree;//value declare
public:
	Graph(ofstream * flog);//value declare
	~Graph();//value declare

	bool	Build(AVLTree * root);
	void 	Print_GP();
	void	Print_MST();

	bool	Kruskal();
	int 	make_set(int parent[],int a);
	int union_set(int parent[],int x, int y);
	int find(int parent[],int x,int y);
	void insert_gp(AVLNode * tree,int zzzz);


};


