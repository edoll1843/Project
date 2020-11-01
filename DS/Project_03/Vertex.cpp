#include "Vertex.h"

using namespace std;

Vertex::Vertex()
{
	m_key = 0;
	m_size = 0;
	m_pEHead = NULL;
	m_pNext = NULL;
}
Vertex::Vertex(int key)
{
	m_key = key;
	m_size = 0;
	m_pEHead = NULL;
	m_pNext = NULL;
}
Vertex::~Vertex()
{

}

void Vertex::SetNext(Vertex* pNext)
{//set next vertex
	m_pNext = pNext;
}

int Vertex::GetKey() const
{//return ket of vertex
	return m_key;
}

Vertex* Vertex::GetNext() const
{//return next vertex
	return m_pNext;
}

int Vertex::Size() const
{//return edge size of vertex
	return m_size;
}

void Vertex::AddSize()
{//size  = size + 1
	m_size = m_size + 1;
}

void Vertex::AddEdge(int edgeKey, int weight)
{//add edge in vertex
	Edge* A = m_pEHead;
	if (A == NULL)
	{//if edge is empty
		m_pEHead = new Edge(edgeKey, weight);
		return;
	}
	else {
		while (A->GetNext())
		{//else
			A = A->GetNext();
		}
		Edge * n_p = new Edge(edgeKey, weight);
		A->SetNext(n_p);
	}
	m_size++;
	return;
}

Edge* Vertex::GetHeadOfEdge() const
{//return head edge
	return m_pEHead;
}

void Vertex::Clear()
{//delete all of edge in vertex
	Edge *B = m_pEHead;
	Edge *C;
	while (B)
	{
		C = B;
		B = B->GetNext();
		delete C;
	}
}