#include "Manager.h"
#include <cstring>
#include <iostream>
#include<algorithm>
using namespace std;
Manager::~Manager()
{
	if (fout.is_open())
		fout.close();
}

void Manager::Run(const char* filepath)
{
	enum Result result;
	fout.open(RESULT_LOG_PATH);
	// TODO: implement
	ifstream fin;
	fin.open(filepath);
	if (fin.fail())
	{
		fout << "====== SYSTEM ======" << endl;
		fout << "CommandFileNotExist" << endl;
		fout << "=====================" << endl;

		fout << "=====================" << endl;
		PrintError(CommandFileNotExist);
		fout << "=====================" << endl;
		return;
	}
	char * str = new char[200];
	char * token = new char[100];
	while (fin.getline(str, 200))
	{
		token = strtok(str, " ");
		if (!strcmp(token, "LOAD"))
		{
			token = strtok(NULL, " ");
			fout << "===== LOAD =====" << endl;
			if (Load(token) == LoadFileNotExist)
			{
				fout << "LoadFileNotExist" << endl;
				fout << "=================" << endl;
				fout << "=================" << endl;
				PrintError(LoadFileNotExist); //error
				fout << "=================" << endl;
			}
			else
			{
				fout << "Success" << endl;
				fout << "=================" << endl;
				fout << endl;
				fout << "=================" << endl;
				PrintError(Success);
				fout << "=================" << endl;
				fout << endl;

			}

		}
		else if (!strcmp(token, "PRINT"))
		{
			if (Print() == GraphNotExist)//if graph is not exist
				PrintError(GraphNotExist);
			else
			fout << endl;
			fout << "=================" << endl;
			PrintError(Success);
			fout << "=================" << endl;
			fout << endl;

		}
		else if (!strcmp(token, "DIJKSTRAMIN"))
		{//DIJKSTRAMIN
		fout << "===== DIJKSTRAMIN =====" << endl;
		token = strtok(NULL, " ");
		if (token == NULL)
		{//if Vertex inserted is insufficient 
			fout << "VertexKeyNotExist" << endl;
			fout << "=================" << endl;
			fout << endl;
			fout << "=================" << endl;
			PrintError(VertexKeyNotExist);
			fout << "=================" << endl;
			continue;
		}
		int start = atoi(token);
		token = strtok(NULL, "\n");
		if (token == NULL)
		{//if Vertex inserted is insufficient 
			fout << "VertexKeyNotExist" << endl;
			fout << "=================" << endl;
			fout << endl;
			fout << "=================" << endl;
			PrintError(VertexKeyNotExist);
			fout << "=================" << endl;
			continue;
		}
		int end = atoi(token);

		result = FindShortestPathDijkstraUsingMinHeap(start, end);
		//Find Dijkstra using set
		fout << endl << "=================" << endl;
		PrintError(result);
		fout << "=================" << endl;
		fout << endl;
		}

		else if (!strcmp(token, "DIJKSTRA"))
		{//DIJKSTRA
			fout << "===== DIJKSTRA =====" << endl;
			token = strtok(NULL, " ");
			if (token == NULL)
			{//if Vertex inserted is insufficient 
				fout << "VertexKeyNotExist" << endl;
				fout << "=================" << endl;
				fout << endl;
				fout << "=================" << endl;
				PrintError(VertexKeyNotExist);
				fout << "=================" << endl;
				continue;
			}
			int start = atoi(token);
			token = strtok(NULL, "\n");
			if (token == NULL)
			{//if Vertex inserted is insufficient 
				fout << "VertexKeyNotExist" << endl;
				fout << "=================" << endl;
				fout << endl;
				fout << "=================" << endl;
				PrintError(VertexKeyNotExist);
				fout << "=================" << endl;
				continue;
			}
			int end = atoi(token);

			result = FindShortestPathDijkstraUsingSet(start, end);
			//Find Dijkstra using set
			fout << endl << "=================" << endl;

			fout << endl << "=================" << endl;
			PrintError(result);
			fout << "=================" << endl;
			fout << endl;
		}
		else if (!strcmp(token, "BELLMANFORD"))
		{//BELLMANFORD

			fout << "===== BELLMANFORD =====" << endl;
			token = strtok(NULL, " ");
			if (token == NULL)
			{//if Vertex inserted is insufficient 
				fout << "VertexKeyNotExist" << endl;
				fout << "=================" << endl;
				fout << endl;
				fout << "=================" << endl;
				PrintError(VertexKeyNotExist);
				fout << "=================" << endl;
				continue;
			}
			int start = atoi(token);
			token = strtok(NULL, "\n");
			if (token == NULL)
			{//if Vertex inserted is insufficient 
				fout << "VertexKeyNotExist" << endl;
				fout << "=================" << endl;
				fout << endl;
				fout << "=================" << endl;
				PrintError(VertexKeyNotExist);
				fout << "=================" << endl;
				continue;
			}
			int end = atoi(token);

			result = FindShortestPathBellmanFord(start, end);
			//Find BellmanFord
			fout << endl << "=================" << endl;


			PrintError(result);
			fout << "=================" << endl;
			fout << endl;
		}
		else if (!strcmp(token, "FLOYD"))
		{
			fout << "===== FLOYD =====" << endl;
			if (FindShortestPathFloyd() == VertexKeyNotExist)
			{
				fout << "VertexKeyNotExist" << endl;
				fout << "=================" << endl;
				fout << endl;
				fout << "=================" << endl;
				PrintError(VertexKeyNotExist);
				fout << "=================" << endl;
				continue;
			}
			else

			fout << "=================" << endl;
			PrintError(Success);
			fout << "=================" << endl;

		}
		else
		{//NonDefinedCommand
			fout << endl<< "===== " << token << " =====" << endl;
			
			fout << "NonDefinedCommand" << endl;
			fout << "=================" << endl;

			fout << endl << "=================" << endl;
			PrintError(NonDefinedCommand);
			fout << "=================" << endl;
			fout << endl;
		}
	}

}
void Manager::PrintError(Result result)
{
	fout << "Error code: " << result << std::endl;
}

/// <summary>
/// make a graph
/// </summary>
///
/// <param name="filepath">
/// the filepath to read to make the graph
/// </param>
///
/// <returns>
/// Result::Success if load is successful.
/// Result::LoadFileNotExist if file is not exist.
/// </returns>
Result Manager::Load(const char* filepath)
{
	ifstream fin;
	fin.open(filepath); //file open
	if (fin.fail())
		return LoadFileNotExist;
	char* str = new char[200];
	char*token = NULL;

	fin.getline(str, 200);
	token = strtok(str, " ");
	int size = atoi(token);
	m_graph.SetSize(size);
	for (int a = 0; a < size; a++)
	{
		fin.getline(str, 200);
		token = strtok(str, " ");
		m_graph.AddVertex(a);
		for (int b = 0; b < size; b++)
		{
			if (atoi(token) != 0)
				m_graph.AddEdge(a, b, atoi(token));
			token = strtok(NULL, " ");
		}
	}
	fin.close();
	return Success;
	// TODO: implement
}
/// <summary>
/// print out the graph as matrix form
/// </summary>
///
/// <returns>
/// Result::Success if the printing is successful
/// Result::GraphNotExist if there is no graph
/// </returns>
Result Manager::Print()
{
	if (m_graph.Size() == 0)
		return GraphNotExist;
	else
	{
		m_graph.Print(fout);
		return Success;
	}
	// TODO: implement
}
/// <summary>
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>
/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Dijkstra using std::set
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>
Result Manager::FindShortestPathDijkstraUsingSet(int startVertexKey, int endVertexKey)
{
	if (m_graph.Size() == 0)
	{//if graph is not exist
		fout << "GraphNotExist";
		return GraphNotExist;
	}
	if (m_graph.FindVertex(startVertexKey) == NULL || m_graph.FindVertex(endVertexKey) == NULL)//üũ
	{//if Vertex is not exist
		fout << "InvalidVertexKey";
		return InvalidVertexKey;
	}
	if (m_graph.IsNegativeEdge() == true)
	{//if graph had -Weight
		fout << "InvalidAlgorithm";
		return InvalidAlgorithm;
	}
	vector<int> v;
	v = m_graph.FindShortestPathDijkstraUsingSet(startVertexKey, endVertexKey);
	//Find dijkstra using set
	fout << "shortest path: ";
	for (int i = 1; i < v.size(); i++)
	{//print result vector
		fout << v[v.size()-i] << " ";
	}
	fout << endl;
	fout << "sorted nodes: ";
	int temp = v[0];
	v[0] = v[v.size() - 1];
	v[v.size() - 1] = temp;
	int z = v[v.size() - 1];
	
	v.pop_back();
	sort(v.begin(), v.end());
	for (int b = 0; b < v.size(); b++)
	{//print result vector
		fout << v[b] << " ";
	}
	fout << endl;
	fout << "path length: ";
	fout << z;
	return Success;
	// TODO: implement
}
/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Dijkstra using MinHeap
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>
Result Manager::FindShortestPathDijkstraUsingMinHeap(int startVertexKey, int endVertexKey)
{
	Result result;
	
	if (m_graph.Size() == 0)// graph not exist error
		result = GraphNotExist;
	else if (!m_graph.FindVertex(startVertexKey) || !m_graph.FindVertex(endVertexKey))// vertex having the startvertexkey or vertex having the endvertexkey not exist error
		result = InvalidVertexKey;
	else if (m_graph.IsNegativeEdge() == 1)// Nagative weight in the graph exist error
		result = InvalidAlgorithm;
	else {
		vector<int> v = m_graph.FindShortestPathDijkstraUsingMinHeap(startVertexKey, endVertexKey);// find path MIN algorithm
		fout << "shortest path: ";
		for (int i = 1; i < v.size(); i++)
		{//print result vector
			fout << v[i-1] << " ";
		}
		fout << endl;

		fout << "sorted nodes: ";
		for (int i = 1; i < v.size(); i++)
		{//print result vector
			fout << v[i - 1] << " ";
		}
		int z = v[v.size() - 1];
		fout << endl;
		fout << "path length: ";
		fout << z;
		fout << endl << "=================" << endl;
		result = Success;
		//return result;//success
					   
	}
	return result;
		// TODO: implement
}
	


/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Bellman-Ford
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::NegativeCycleDetected if exception has occurred.
/// Result::Success otherwise.
/// </returns>
Result Manager::FindShortestPathBellmanFord(int startVertexKey, int endVertexKey)
{
	vector<int> vt;
	if (m_graph.Size() == 0)// graph not exist error
		return GraphNotExist;
	if (m_graph.FindVertex(startVertexKey) == NULL || m_graph.FindVertex(endVertexKey) == NULL)// vertex having the startvertexkey or vertex having the endvertexkey not exist error
		return InvalidVertexKey;
	vt = m_graph.FindShortestPathBellmanFord(startVertexKey, endVertexKey);// find path BELLMAN algorithm


	if (vt.size() == 0) // Size of vector means to exist negative weight in the graph
		return NegativeCycleDetected;
	fout << "shortest path: ";
	for (int a = 1; a < vt.size(); a++)// print out path
	{
		fout << vt[vt.size() - a ] << " ";
	}
	int temp = vt[0];
	vt[0] = vt[vt.size() - 1];
	vt[vt.size() - 1] = temp;
	int z = vt[vt.size() - 1];
	fout << endl;
	fout << "sorted nodes: ";
	vt.pop_back();
	sort(vt.begin(), vt.end());
	for (int b = 0; b < vt.size(); b++)
	{//print result vector
		fout << vt[b] << " ";
	}
	fout << endl;
	fout << "path length: ";
	fout << z;
	fout << endl << "================" << endl;
	return Success;
	// TODO: implement
}

Result Manager::FindShortestPathFloyd()
{
	vector<vector<int>> mv;

	if (m_graph.GetpVHead() == NULL) // if m_graph is not exist
	{
		return GraphNotExist; // return error
	}

	mv = m_graph.FindShortestPathFloyd(); // call PRINT function in m_graph

	if (mv.size() == 0)
		return NegativeCycleDetected;

	for (int i = 0; i < mv.size(); i++)
	{
		for (int j = 0; j < mv.size(); j++)
		{
			fout << mv[i][j] << " ";
		}

		fout << endl;
	}
	fout << "================" << endl;
	fout << endl;
	return Success; // return success
}
