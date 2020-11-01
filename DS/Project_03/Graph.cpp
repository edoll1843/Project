#include "Graph.h"
#include "Stack.h"
#include "MinHeap.h"
#include <set>
#include <algorithm>
#include <string.h>
Graph::Graph()
{
	m_pVHead = NULL;
	m_vSize = 0;
	// TODO: implement
}
Graph::~Graph()
{
	// TODO: implement
}

void Graph::AddVertex(int vertexKey)
{//add vertex 
	Vertex* A = m_pVHead;
	Vertex* vx = new Vertex(vertexKey);
	if (A == NULL)
	{//if head vertex is empty
		m_pVHead = vx;
		return;
	}
	while (A->GetNext())
	{//else
		A = A->GetNext();
	}
	A->SetNext(vx);
	return;
}
	void Graph::AddEdge(int startVertexKey, int endVertexKey, int weight) // Add Edge in Graph Linked List
	{
		Vertex*pCur = m_pVHead;

		if (m_pVHead == NULL) // Head not exist
			return;

		while (pCur)
		{
			if (startVertexKey == pCur->GetKey())
			{
				pCur->AddEdge(endVertexKey, weight); // Add Edge in Vertex class
				return;
			}
			pCur = pCur->GetNext();
		}
	}

	Vertex* Graph::FindVertex(int key)
	{
		Vertex*pCur = m_pVHead;

		while (pCur)
		{
			if (pCur->GetKey() == key)
				return pCur;
			pCur = pCur->GetNext();
		}
		return NULL;
	}
	void Graph::SetSize(int size)
	{
		m_vSize = size;
	}
	int Graph::Size() const // return Size function
	{
		return m_vSize;
	}
	void Graph::Clear()
	{//delete all of graph
		Vertex* A = m_pVHead;
		Vertex* B;

		while (A)
		{
			B = A;
			A = A->GetNext();
			B->Clear();
			delete B; //delete vertex
		}
	}
	void Graph::Print(std::ofstream& fout)
	{//print graph
		ifstream fin;
		fin.open("mapdata.txt");
		char* Z = new char[100];
		fin.getline(Z, 100);
		fout << "===== PRINT ===== " << endl;
		while (fin.getline(Z, 100))
		{//print all of graph
			fout << Z << endl;
		}
		fout << "=================" << endl;
		delete[] Z;
	}
	bool Graph::IsNegativeEdge()
	{//check -Weight of all of Edge
		Vertex* A = m_pVHead;
		Edge* B = NULL;
		while (A)
		{
			B = A->GetHeadOfEdge();
			while (B)
			{
				if (B->GetWeight() < 0)
					return true; //exist -Weight
				B = B->GetNext();
			}
			A = A->GetNext();
		}
		return false; //Not exist -Weight
	}
	std::vector<int> Graph::FindShortestPathDijkstraUsingSet(int startVertexKey, int endVertexKey)
	{//Find Shortest Path using Dijkstra wite Set
		vector<int> v;
		set<int, less<int>> s; //declare set
		Vertex* P = FindVertex(startVertexKey); //find start vertex
		Vertex* Q;
		Edge* E;
		int a;
		int* dis = new int[m_vSize];
		int* visit = new int[m_vSize];
		int* path = new int[m_vSize]; //make table
		for (a = 0; a < m_vSize; a++)
		{
			dis[a] = 11111111;
			visit[a] = 0;
			path[a] = -1; //initializing
		}
		dis[startVertexKey] = 0;
		while (1)
		{
			E = P->GetHeadOfEdge();
			visit[P->GetKey()] = 1;
			while (E)
			{
				if (dis[E->GetKey()] > E->GetWeight() + dis[P->GetKey()])
				{//if need update distance
					if (s.find(dis[E->GetKey()]) != s.end())
					{//if exist distance in set
						s.erase(dis[E->GetKey()]); //erase index in set
						v.push_back(dis[P->GetKey()] + E->GetWeight());//push new distance
					}

					dis[E->GetKey()] = E->GetWeight() + dis[P->GetKey()];//update
					path[E->GetKey()] = P->GetKey();
					if (visit[E->GetKey()] == 0)
						v.push_back(dis[E->GetKey()]);
				}
				E = E->GetNext();
			}
			s.insert(v.begin(), v.end()); //insert vector in set
			int g = 0;
			if (s.size() != 0)
				g = *s.begin(); //find shortest path
			for (a = 0; a < m_vSize; a++)
			{
				if (dis[a] == g)
				{
					s.erase(g); //erase
					break;
				}
			}
			P = FindVertex(a);
			v.clear();
			if (checkvisittable(visit) == true || (s.size() == 0 && visit[endVertexKey] == 1))
				break; //if visit table is all true or set size = 0 and visited endvertex
		}
		v.push_back(dis[endVertexKey]); //push total distance in vector
		v.push_back(endVertexKey); //push path
		while (endVertexKey != startVertexKey)
		{//push path
			P = FindVertex(path[endVertexKey]);
			endVertexKey = P->GetKey();
			v.push_back(endVertexKey);
		}
		delete[] dis, visit, path;
		return v;

	}
	std::vector<int> Graph::FindShortestPathDijkstraUsingMinHeap(int startVertexKey, int endVertexKey)
	{
		MinHeap<int, int>* mh = new MinHeap<int, int>;//distance, vertex
		int *dist = new int[m_vSize];
		memset(dist, 127, m_vSize * sizeof(int));
		int *path = new int[m_vSize];
		memset(path, -1, m_vSize * sizeof(int));
		vector<int> route;

		mh->Push(0, startVertexKey);//insert distance and vertex
		dist[startVertexKey] = 0;//change distance

		while (mh->IsEmpty() != 1)//until mh is empty
		{
			pair<int, int> pick = mh->Top();//pull mh's begin
			Edge * e = FindVertex(pick.second)->GetHeadOfEdge();

			while (e)
			{
				if (dist[e->GetKey()] > e->GetWeight() + pick.first)//appear shorter path
				{
					dist[e->GetKey()] = e->GetWeight() + pick.first;//change distance
					if (mh->Get(e->GetKey()).second != -1)//find vertex in mh
						mh->DecKey(e->GetKey(), dist[e->GetKey()]);//change distance in mh
					else
						mh->Push(dist[e->GetKey()], e->GetKey());//insert new distance and vertex
					path[e->GetKey()] = pick.second;//update path
				}
				e = e->GetNext();
			}
			mh->Pop();
		}

		int prev = endVertexKey;
		while (1)//find path to the end vertex from the start vertex
		{
			route.push_back(prev);
			if (prev == startVertexKey)
				break;
			prev = path[prev];
		}
		reverse(route.begin(), route.end());//reverse route
		route.push_back(dist[endVertexKey]);//insert distance
		return route;
	}
	std::vector<int> Graph::FindShortestPathBellmanFord(int startVertexKey, int endVertexKey)
	{
		vector<int> v;
		Vertex* pCur = m_pVHead;
		Edge* E;
		int a;
		int* dis = new int[m_vSize];
		int* dis2 = new int[m_vSize];
		int* path = new int[m_vSize];//make table
		for (a = 0; a < m_vSize; a++)
		{
			dis[a] = 11111111;
			dis2[a] = 11111111;
			path[a] = -1; //initialing
		}
		dis[startVertexKey] = 0;
		dis2[startVertexKey] = 0; //it will use find -weight
		int count = 0; int count2 = 0;
		while (count != m_vSize - 1)
		{//doing size*size-1
			while (count2 != m_vSize)
			{//doing size
				if (dis[pCur->GetKey()] != 11111111)
				{//if distance is infinity, dont need visit
					E = pCur->GetHeadOfEdge();
					while (E)
					{
						if (dis[E->GetKey()] > dis[pCur->GetKey()] + E->GetWeight())
						{//if need update
							dis[E->GetKey()] = dis[pCur->GetKey()] + E->GetWeight();
							dis2[E->GetKey()] = dis2[pCur->GetKey()] + E->GetWeight();
							path[E->GetKey()] = pCur->GetKey();
						}
						E = E->GetNext();
					}
				}
				count2++;//count2 += 1
				pCur = pCur->GetNext();
			}
			count2 = 0;
			count++; //count += 1
			pCur = m_pVHead;
		}
		pCur = m_pVHead;
		count = 0; count2 = 0;
		//find -weight, use only distance table 2
		//same process
		while (count != m_vSize - 1)
		{
			while (count2 != m_vSize)
			{
				if (dis2[pCur->GetKey()] != 11111111)
				{
					E = pCur->GetHeadOfEdge();
					while (E)
					{
						if (dis2[E->GetKey()] > dis2[pCur->GetKey()] + E->GetWeight())
						{
							dis2[E->GetKey()] = dis2[pCur->GetKey()] + E->GetWeight();
							path[E->GetKey()] = pCur->GetKey();
						}
						E = E->GetNext();
					}
				}
				count2++;
				pCur = pCur->GetNext();
			}
			count2 = 0;
			count++;
			pCur = m_pVHead;
		}
		//find -weight, if dis != dis2 (update more), graph have - weight
		for (int j = 0; j < m_vSize; j++)
		{
			if (dis[j] != dis2[j])
			{
				v.clear();//clear vector
				return v; //if exist -weight return 0 vector
			}
		}
		v.push_back(dis[endVertexKey]); //push total distance
		while (endVertexKey != -1)
		{//push path
			v.push_back(endVertexKey);
			endVertexKey = path[endVertexKey];
		}
		return v;

		delete[] dis, dis2, path;
	}
	Vertex*Graph::GetpVHead()
	{
		return m_pVHead;
	}


	vector<vector<int>> Graph::FindShortestPathFloyd()
	{
		Vertex* walker = m_pVHead;   // set Vwalker is first vertex
		vector<vector<int>> dist;

		for (int i = 0; i < m_vSize; i++)      // i -> Vertex key
		{
			vector<int> v;
			Edge*pCur = walker->GetHeadOfEdge();

			for (int j = 0; j < m_vSize; j++)
			{
				if (pCur != NULL)
				{
					if (pCur->GetKey() == j)
					{
						v.push_back(pCur->GetWeight());
						pCur = pCur->GetNext();
					}
					else
						v.push_back(1000);
				}
				else
					v.push_back(1000);
			}
			dist.push_back(v);
			walker = walker->GetNext();
		}
		for (int k = 0; k < m_vSize; k++)
		{
			for (int i = 0; i < m_vSize; i++)
			{
				for (int j = 0; j < m_vSize; j++)
				{
					if (dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
		for (int i = 0; i < m_vSize; i++)
			dist[i][i] = 0;

		return dist;
	}
