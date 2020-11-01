#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <utility>
#include <vector>
using namespace std;

template<typename TKey, typename TValue>
class MinHeap
{
private:
	// array for the elements which should be heap-sorted
	std::vector<std::pair<TKey, TValue>> m_vec;

public:
	MinHeap() { m_vec.push_back(std::make_pair(-1, -1)); }

	/// <summary>
	/// insert key-value pair
	/// </summary>
	///
	/// <param name="key">
	/// the key that is used for sorting
	/// </param>
	///
	/// <param name="value">
	/// the value that is managed in this heap
	/// </param>
	void Push(TKey key, TValue value);
	/// <summary>
	/// remove the minimum element
	/// </summary>
	void Pop();
	/// <summary>
	/// get the minimum element
	/// </summary>
	///
	/// <returns>
	/// the minimum element
	/// </returns>
	std::pair<TKey, TValue> Top();
	/// <summary>
	/// get the key-value pair which the value is the same as the target
	/// </summary>
	///
	/// <returns>
	/// the key-value pair which the value is the same as the target
	/// </returns>
	std::pair<TKey, TValue> Get(TValue target);
	/// <summary>
	/// check whether this heap is empty or not
	/// </summary>
	///
	/// <returns>
	/// true if this heap is empty
	/// </returns>
	bool IsEmpty();
	/// <summary>
	/// change the key of the node which the value is the target.<para/>
	/// In general, the newKey should be smaller than the old key.<para/>
	/// </summary>
	///
	/// <parma name="target">
	/// the target to change the key
	/// </param>
	///
	/// <param name="newKey">
	/// new key for the target
	/// </param>
	void DecKey(TValue target, TKey newKey);

private:
	/// <summary>
	/// heap-sort, heapify.<para/>
	/// this function can be called recursively
	/// </summary>
	void Heapify(int index);
};

#endif

template<typename TKey, typename TValue>
void MinHeap<TKey, TValue>::Push(TKey key, TValue value)
{//insert index
	if (IsEmpty())
	{//if heap is empty
		m_vec.push_back(make_pair(key, value));
		return;
	}
	//else
	m_vec.push_back(make_pair(key, value));
	Heapify(1); //sorting

}

template<typename TKey, typename TValue>
void MinHeap<TKey, TValue>::Pop()
{//delete top index
	if (IsEmpty())
		return;
	Heapify(-1);
}

template<typename TKey, typename TValue>
bool MinHeap<TKey, TValue>::IsEmpty()
{//heap is empty?
	if (m_vec.size() != 1)
		return false;
	else
		return true;
}

template<typename TKey, typename TValue>
std::pair<TKey, TValue> MinHeap<TKey, TValue>::Top()
{//return top index
	return m_vec[1];
}

template<typename TKey, typename TValue>
std::pair<TKey, TValue> MinHeap<TKey, TValue>::Get(TValue target)
{//find index in heap
	for (int i = 0; i < m_vec.size(); i++)
	{
		if (target == m_vec.at(i).second)
		{
			return m_vec[i];
		}
	}
	return m_vec[0]; // not exist = cant found
}

template<typename TKey, typename TValue>
void MinHeap<TKey, TValue>::DecKey(TValue target, TKey newKey)
{
	int i;
	for (i = 0; i < m_vec.size(); i++)
	{
		if (target == m_vec.at(i).second)
		{
			m_vec.at(i).first = newKey; // change distance of select key
		}
	}


	pair<TKey, TValue> p = m_vec[i - 1]; // new key and new value
	int c = i - 1;

	while (c != 1 && m_vec[c / 2].first>m_vec[i - 1].first) // find insertion location
	{
		m_vec[c].first = m_vec[c / 2].first;
		m_vec[c].second = m_vec[c / 2].second;
		c /= 2;
	}

	// insert new key and new value
	m_vec[c].first = p.first;
	m_vec[c].second = p.second;

	return;
}
template<typename TKey, typename TValue>
void MinHeap<TKey, TValue>::Heapify(int index)
{//heap - sorting
	if (index == 1)
	{//Push case
		pair<TKey, TValue> p = m_vec[m_vec.size() - 1];
		int a = m_vec.size() - 1;

		while (a != 1 && m_vec[a / 2].first>m_vec.back().first) // push Sorting 
		{
			m_vec[a].first = m_vec[a / 2].first;
			m_vec[a].second = m_vec[a / 2].second;
			a /= 2;
		}
		m_vec[a].first = p.first;  // push insert
		m_vec[a].second = p.second;
	}
	else if (index == -1)
	{//Pop case
		int a = 1;
		int b = 2;

		pair<TKey, TValue> p = m_vec[m_vec.size() - 1];
		while (b <= m_vec.size() - 1) // pop sorting
		{
			if (b<m_vec.size() - 1 && m_vec[b].first > m_vec[b + 1].first)
				b++;

			if (p.first <= m_vec[b].first)
				break;

			m_vec[a].first = m_vec[b].first;
			m_vec[a].second = m_vec[b].second;
			a = b; b *= 2;
		}
		m_vec[a].first = p.first; // pop insert
		m_vec[a].second = p.second;

		m_vec.resize(m_vec.size() - 1);
	}
}
//#pragma once
