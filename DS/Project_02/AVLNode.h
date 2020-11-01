#include "CityData.h"
#include <iostream>
#include <stack>
using namespace std;
class AVLNode
{
private:

	CityData * pCityData;	// CityData Pointer ���� ����
	AVLNode * pLeft;		// AVL Left Pointer ����
	AVLNode * pRight;		// AVL Right Pointer ������
	int mBF;				// Balance Factor �뷱�� ����

public:
	AVLNode();
	~AVLNode();
	int u;
	int v;
	CityData * data1;
	CityData * data2;
	int wei;
	CityData * GetCityData();	// Get CityData Pointer
	AVLNode * GetLeft();		// Get AVL Left Pointer
	AVLNode * GetRight();		// Get AVL Right Pointer
	int GetmBF();				// Get Balance Factor
		bool operator <(AVLNode &AVLNode) {//operator node
			return this->pCityData->Getname() < AVLNode.GetCityData()->Getname();
		}
	void SetCityData(CityData * node);	// Set CityData Pointer
	void SetLeft(AVLNode * node);		// Set AVL Left Pointer
	void SetRight(AVLNode * node);		// Set AVL Right Pointer
	void SetmBF(int n);					// Set Balance Factor

};
