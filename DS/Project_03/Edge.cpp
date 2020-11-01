#include "Edge.h"

Edge::Edge()
{
	m_key = 0;
	m_weight = 0;
	m_pNext = NULL;
}
Edge::Edge(int key, int weight)
{
	m_key = key;
	m_weight = weight;
	m_pNext = NULL;
}
void Edge::SetNext(Edge* pNext)
{//set next edge
	m_pNext = pNext;
}

int Edge::GetKey() const
{//return key of edge
	return m_key;
}

int Edge::GetWeight() const
{//return weight of edge
	return m_weight;
}

Edge* Edge::GetNext() const
{//return next edge
	return m_pNext;
}