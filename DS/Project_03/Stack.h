//#pragma once
#ifndef STACK_H
#define STACK_H

#ifndef NULL
#define NULL    0
#endif

template <typename T>
class Stack
{
private:
	class StackNode
	{
	public:
		T Data;
		StackNode* pNext;

		StackNode(T data) : Data(data), pNext(NULL) {}
	};

private:
	// the head pointer of the stack
	StackNode * m_pTop;

public:
	Stack();
	~Stack();

	/// <summary>
	/// push the data into this stack
	/// </summary>
	///
	/// <param name="data">
	/// a data to push into this stack
	/// </param>
	void Push(T data);
	/// <summary>
	/// pop(remove) the last-in data from this stack
	/// </summary>
	void Pop();
	/// <summary>
	/// get the last-in data of this stack
	/// </summary>
	/// 
	/// <returns>
	/// the last-in data of this stack
	/// </returns>
	T Top();
	/// <summary>
	/// check whether this stack is empty or not.
	/// </summary>
	///
	/// <returns>
	/// true if this stack is empty.
	/// false otherwise.
	/// </returns>
	bool IsEmpty();
};

#endif

// stack class constructor
template <class T>
Stack<T>::Stack()
{
	m_pTop = NULL;
}

// stack class destructor
template <class T>
Stack<T>::~Stack()
{
	StackNode*cur = NULL;
	StackNode*prev_cur = NULL;
	while (m_pTop) // all stack node memory free
	{
		prev_cur = m_pTop;
		cur = m_pTop;
		while (cur->pNext)
		{
			prev_cur = cur;
			cur = cur->pNext;
		}
		prev_cur->pNext = NULL;
		if (cur == m_pTop)
		{
			delete cur;
			m_pTop = NULL;
			return;
		}
		delete cur;
	}
}

/// push the data into this stack
template <class T>
void Stack<T>::Push(T data)
{
	StackNode*prev_top = m_pTop;
	StackNode*cur = new StackNode(data);

	if (prev_top == NULL) // empty stack
	{
		m_pTop = cur;
		return;
	}
	cur->pNext = m_pTop;
	m_pTop = cur;
}

/// pop(remove) the last-in data from this stack
template <class T>
void Stack<T>::Pop()
{
	StackNode*prev_top = m_pTop;
	if (IsEmpty()) // empty stack
		return;
	if (prev_top->pNext == NULL) // There is only one stack node on the stack
	{
		delete prev_top;
		m_pTop = NULL;
		return;
	}
	m_pTop = prev_top->pNext;
	delete prev_top;
	return;
}

/// check whether this stack is empty or not.
template <class T>
bool Stack<T>::IsEmpty()
{
	if (m_pTop == NULL)
		return true;
	else
		return false;
}

/// get the last-in data of this stack
template <class T>
T Stack<T>::Top()
{
	return m_pTop->Data;
}
