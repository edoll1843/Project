#include "pch.h"
#include "Board.h"
#include<iostream>
#include <time.h>
#include <fstream>
#pragma warning (disable:4996)
using namespace std;


Board::Board()
{
	Block* pnew;//declare
	Block* cur = Block_Header;//declare
	Block* pCol = Block_Header;//declare


							
	for (int i = 0; i < 4 * 4; i++)
	{
		//declare
		pnew = new Block();
		pnew->setNum(0);
		pnew->setX(i % 4);
		pnew->setY(i / 4);

		if (Block_Header == NULL)
		{
			Block_Header = pnew;
			cur = Block_Header;
		}
		else
		{
			cur->setRight(pnew);
			pnew->setLeft(cur);

			cur = cur->getRight();
		}
	}

	cur = Block_Header;
	pCol = Block_Header;
	Block* temp = Block_Header;

	for (int j = 0; j < 4; j++)
	{
		cur = cur->getRight();
	}//cur�� ���� ���� ù��° ��带 ����Ŵ

	for (int i = 0; i < 4 - 1; i++)
	{
		//�� ���� ��� ����� �����Ų��.
		for (int j = 0; j < 4; j++)
		{
			cur->setUp(temp);
			temp->setDown(cur);

			temp = temp->getRight();
			cur = cur->getRight();
		}
	}

	cur = Block_Header;
	//������ �迭���� ���� ������ �Ѿ�� ������ ������ ����
	for (int i = 0; i < 4 * 4; i++)
	{
		if (i % 4 == 0 && i != 0)
		{
			cur->getLeft()->setRight(NULL);
			cur->setLeft(NULL);
		}
		cur = cur->getRight();
	}

	//board setting ��, �ʱ� turn change
	Put_random_num2();//turn ���� -> �������� 2 �߰�
	Put_random_num2();
}


Board::~Board()
{
	//(0,0)���� (3,3)����
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 3; j >= 0; j--)
		{
			delete getBlock_x_y(i, j);
		}
	}
}

//�� turn�� �ٲ� ������ ����ִ� ������ block�� number 2�� �Ҵ�
bool Board::Put_random_num2()
{
	if (Check_block() == 0)
		return 0;
	Block* temp = 0;
	int x = 0, y = 0;

	srand((unsigned)time(NULL));

	while (1)
	{
		// random : 0 ~ 3

		y = rand() % 4;
		x = rand() % 4;

		temp = getBlock_x_y(x, y);//��ǥ�� ��带 Ž��
		if (temp != NULL && temp->getNum() == 0)//Ž���� ����� number�� 0�� ����
		{
			//check[x][y] = 1;
			temp->setNum(2);//number�� 2�� ����
			return true;//������ true ��ȯ
		}
	}

}



//����ִ� Block�� ���� ��� return 1 , ��� Block�� ����������� return 0;
bool Board::Check_block()
{
	Block* cur = Block_Header;//������ Ž���ϴ� ���
	Block* pDown = Block_Header;//������ �������� ���
	while (pDown)
	{
		while (cur)//������ Ž��
		{
			//���� ��ǥ�� �ش��ϴ� ���� �ش� ��带 ��ȯ
			if (cur->getNum() == 0)
			{
				return 1;
			}
			cur = cur->getRight();
		}
		pDown = pDown->getDown();//������ ��������.
		cur = pDown;//������ ������ ������ �ٽ� ������ Ž��
	}

	return 0;
}

//(x,y) ��ǥ�� �ش��ϴ� ��带 ��ȯ��.
Block* Board::getBlock_x_y(int x, int y)
{
	Block* pResult = Block_Header;
	for (int i = 0; i < x; i++)//x���̵�
	{
		pResult = pResult->getRight();
	}
	for (int j = 0; j < y; j++)//y���̵�
	{
		pResult = pResult->getDown();
	}
	return pResult;//(x,y)�� �ش��ϴ� ���
}

Block* Board::getHead()
{
	return Block_Header;
}

//�ð�������� rotation
void Board::rotation_time()
{
	int temp = 0;

	temp = getBlock_x_y(3, 0)->getNum();//(3,0)���� ����.
	getBlock_x_y(3, 0)->setNum(getBlock_x_y(0, 0)->getNum());
	getBlock_x_y(0, 0)->setNum(getBlock_x_y(0, 3)->getNum());
	getBlock_x_y(0, 3)->setNum(getBlock_x_y(3, 3)->getNum());
	getBlock_x_y(3, 3)->setNum(temp);//�ѹ����� ������

	temp = getBlock_x_y(3, 1)->getNum();//(3,1)���� ����.
	getBlock_x_y(3, 1)->setNum(getBlock_x_y(1, 0)->getNum());
	getBlock_x_y(1, 0)->setNum(getBlock_x_y(0, 2)->getNum());
	getBlock_x_y(0, 2)->setNum(getBlock_x_y(2, 3)->getNum());
	getBlock_x_y(2, 3)->setNum(temp); // �ѹ����� ������

	temp = getBlock_x_y(3, 2)->getNum();//(3,2)���� ����.
	getBlock_x_y(3, 2)->setNum(getBlock_x_y(2, 0)->getNum());
	getBlock_x_y(2, 0)->setNum(getBlock_x_y(0, 1)->getNum());
	getBlock_x_y(0, 1)->setNum(getBlock_x_y(1, 3)->getNum());
	getBlock_x_y(1, 3)->setNum(temp); // �ѹ����� ������


	temp = getBlock_x_y(2, 1)->getNum();//(2,1)���� ����.
	getBlock_x_y(2, 1)->setNum(getBlock_x_y(1, 1)->getNum());
	getBlock_x_y(1, 1)->setNum(getBlock_x_y(1, 2)->getNum());
	getBlock_x_y(1, 2)->setNum(getBlock_x_y(2, 2)->getNum());
	getBlock_x_y(2, 2)->setNum(temp);// �ѹ����� ������


}

//�ݽð���� rotation
void Board::rotation_reverse_time()
{
	int temp = 0;

	temp = getBlock_x_y(3, 0)->getNum();//(3,0)���� ����.
	getBlock_x_y(3, 0)->setNum(getBlock_x_y(3, 3)->getNum());
	getBlock_x_y(3, 3)->setNum(getBlock_x_y(0, 3)->getNum());
	getBlock_x_y(0, 3)->setNum(getBlock_x_y(0, 0)->getNum());
	getBlock_x_y(0, 0)->setNum(temp);//�ѹ����� ������

	temp = getBlock_x_y(3, 1)->getNum();//(3,1)���� ����.
	getBlock_x_y(3, 1)->setNum(getBlock_x_y(2, 3)->getNum());
	getBlock_x_y(2, 3)->setNum(getBlock_x_y(0, 2)->getNum());
	getBlock_x_y(0, 2)->setNum(getBlock_x_y(1, 0)->getNum());
	getBlock_x_y(1, 0)->setNum(temp);//�ѹ����� ������

	temp = getBlock_x_y(3, 2)->getNum();//(3,2)���� ����.
	getBlock_x_y(3, 2)->setNum(getBlock_x_y(1, 3)->getNum());
	getBlock_x_y(1, 3)->setNum(getBlock_x_y(0, 1)->getNum());
	getBlock_x_y(0, 1)->setNum(getBlock_x_y(2, 0)->getNum());
	getBlock_x_y(2, 0)->setNum(temp);//�ѹ����� ������


	temp = getBlock_x_y(2, 1)->getNum();//(2,1)���� ����.
	getBlock_x_y(2, 1)->setNum(getBlock_x_y(2, 2)->getNum());
	getBlock_x_y(2, 2)->setNum(getBlock_x_y(1, 2)->getNum());
	getBlock_x_y(1, 2)->setNum(getBlock_x_y(1, 1)->getNum());
	getBlock_x_y(1, 1)->setNum(temp);//�ѹ����� ������

}

//Board�� ���Ϸ� ����ϴ� �Լ�
void Board::printBoard(int count, CFile& outFile, int menu)
{
	Block* cur = Block_Header;
	Block* pDown = Block_Header;


	//temp�� ����ó�� ���
	char temp[30] = { 0 };//��� ���ڿ����� temp�� �����Ͽ� ���

	//count�� ���
	itoa(count, temp, 10);
	outFile.Write(temp, strlen(temp));
	memset(temp, 0, 30);

	if (menu == 1)//Key Left
	{
		strcpy(temp, ". Key Left\r\n");
		outFile.Write(temp, strlen(temp));
		memset(temp, 0, 30);
	}
	else if (menu == 2)//Key Right
	{
		strcpy(temp, ". Key Right\r\n");
		outFile.Write(temp, strlen(temp));
		memset(temp, 0, 30);
	}
	else if (menu == 3)//Key Down
	{
		strcpy(temp, ". Key Down\r\n");
		outFile.Write(temp, strlen(temp));
		memset(temp, 0, 30);
	}
	else if (menu == 4)//Key Up
	{
		strcpy(temp, ". Key Up\r\n");
		outFile.Write(temp, strlen(temp));
		memset(temp, 0, 30);
	}
	else if (menu == 6)//Mouse_Right_to_Left
	{
		strcpy(temp, ". Mouse_Right_to_Left\r\n");
		outFile.Write(temp, strlen(temp));
		memset(temp, 0, 30);
	}
	else if (menu == 5)//Mouse_Left_to_Right
	{
		strcpy(temp, ". Mouse_Left_to_Right\r\n");
		outFile.Write(temp, strlen(temp));
		memset(temp, 0, 30);
	}

	//result�� ���
	strcpy(temp, "[result]\r\n");
	outFile.Write(temp, strlen(temp));
	memset(temp, 0, 30);
	while (pDown)//������ Ž��
	{
		while (cur)//������ Ž��
		{
			if (cur->getNum() == 0)//0�̸� ������ ������ش�.
			{
				strcpy(temp, "	");
				outFile.Write(temp, strlen(temp));
				memset(temp, 0, 30);
			}
			else//0�� �ƴ� ���ڸ� �ش���ڸ� ����Ѵ�.
			{
				itoa(cur->getNum(), temp, 10);
				outFile.Write(temp, strlen(temp));
				memset(temp, 0, 30);

				strcpy(temp, "	");
				outFile.Write(temp, strlen(temp));
				memset(temp, 0, 30);
				memset(temp, 0, 30);
			}
			cur = cur->getRight();//���������� �Ѿ��.
		}
		strcpy(temp, "\r\n");
		outFile.Write(temp, strlen(temp));
		memset(temp, 0, 30);
		pDown = pDown->getDown();//������ ��������.
		cur = pDown;//������ ������ ������ �ٽ� ������ Ž��
	}
	strcpy(temp, "\r\n");
	outFile.Write(temp, strlen(temp));
	outFile.Write(temp, strlen(temp));
	memset(temp, 0, 30);
}


//2048�� ������ return 1;, ������ return 0;, 
bool Board::Check_win()
{
	Block* cur = Block_Header;
	Block* pDown = Block_Header;
	while (pDown)
	{
		while (cur)//������ Ž��
		{
			if (cur->getNum() == 2048)
				return 1;
			cur = cur->getRight();
		}
		pDown = pDown->getDown();//������ ��������.
		cur = pDown;//������ ������ ������ �ٽ� ������ Ž��
	}
	return 0;
}


//���н� return 1, ���а� �ƴϰ� �� ���డ���ϸ� return 0;
bool Board::Check_fail()
{
	Block* cur = Block_Header;
	Block* pDown = Block_Header;
	while (pDown)//������ Ž��
	{
		while (cur)//������ Ž��
		{
			if (cur->getNum() == 0)//���� ���ڰ� 0�̸� �� ���డ�� : ���а� �ƴ� -> return 0
			{
				return 0;
			}
			else//���� ���� ���� ���ڵ��� �ִ��� Ȯ�� : �ϳ��� ������ ���а� �ƴϴ�. -> return 0
			{
				if (cur->getUp())
				{
					if (cur->getNum() == cur->getUp()->getNum())
						return 0;
				}
				if (cur->getDown())
				{
					if (cur->getNum() == cur->getDown()->getNum())
						return 0;
				}
				if (cur->getRight())
				{
					if (cur->getNum() == cur->getRight()->getNum())
						return 0;
				}
				if (cur->getLeft())
				{
					if (cur->getNum() == cur->getLeft()->getNum())
						return 0;
				}
			}
			cur = cur->getRight();
		}
		pDown = pDown->getDown();//������ ��������.
		cur = pDown;//������ ������ ������ �ٽ� ������ Ž��
	}
	return 1;//�� ������ ��ġ�� ���� 0�� ��ȯ�� �ȵȴٸ� ���а� �´ٰ� �Ǵ� -> return 1
}


//���ڵ��� �ϳ��� ���� ���� ��� return 0; �ϳ��� �а�� return 1;
//Up() �̿ܿ� Down(), Right(), Left() �Լ��鵵 ��� ���� ���.
bool Board::Up()
{

	Block* cur = 0;
	bool perform = 0;


	//STAGE 1 :0�̻��� ���ڵ��� �������� ���Ƴֱ�
	for (int x = 0; x <= 3; x++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				cur = getBlock_x_y(x, y);//��ǥ�� �ش��ϴ� ���� ��´�.
				if (cur->getNum() == 0)//number�� 0�� ���̸�
				{
					swap(cur, 'd');//cur�� �Ʒ��� ���� swap
					if (cur->getUp()->getNum() != 0)//swap�� ����� number�� 0�� �ƴѼ� �̸�
						perform = 1;//���� ����(�ѹ��̶� ��ȿ�� ������ �� ��� 1�� ����)
									//��ȿ�� �����̶� 0�̾ƴѰ��� ��� swap�Ǵ� ���
				}
			}
		}
	}


	//STAGE 2 : �������� ���ϱ�
	for (int x = 0; x <= 3; x++)
	{
		for (int y = 0; y < 3; y++)//���ʿ��� �������� ����
		{
			cur = getBlock_x_y(x, y);

			//cur�� �Ʒ��� ���� �����ϰ� cur�� cur�� �Ʒ��� ���� ���ڰ� ���� ��
			if (cur->getDown() && cur->getNum() == cur->getDown()->getNum() && cur->getNum() != 0)
			{
				//cur�� ������ ���ڸ� ������
				cur->setNum(cur->getNum() + cur->getDown()->getNum());
				cur->getDown()->setNum(0);
				perform = 1;
			}
			else
				continue;
		}
	}


	//STAGE 3 : �ٽ� �������� ���Ƴֱ�
	for (int x = 0; x <= 3; x++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				cur = getBlock_x_y(x, y);//��ǥ�� �ش��ϴ� ���� ��´�.
				if (cur->getNum() == 0)//number�� 0�� ���̸�
				{
					swap(cur, 'd');//�Ʒ��� ���� swap
					if (cur->getUp()->getNum() != 0)
						perform = 1;
				}
			}
		}
	}

	return perform;
}

bool Board::Down()
{

	Block* cur = 0;
	bool perform = 0;


	//Stage 1
	for (int x = 3; x >= 0; x--)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int y = 3; y > 0; y--)//���ʿ��� �������� ����
			{

				cur = getBlock_x_y(x, y);
				if (cur->getNum() == 0)
				{
					swap(cur, 'u');//���� ���� swap
					if (cur->getDown()->getNum() != 0)
						perform = 1;
				}
			}
		}
	}


	//Stage 2
	for (int x = 0; x <= 3; x++)
	{
		for (int y = 3; y > 0; y--)
		{
			cur = getBlock_x_y(x, y);

			//cur�� ���� ���� �����ϰ� cur�� cur�� ���� ���� ���ڰ� ���� ��
			if (cur->getUp() && cur->getNum() == cur->getUp()->getNum() && cur->getNum() != 0)
			{
				//cur�� ������ ���ڸ� ������
				cur->setNum(cur->getNum() + cur->getUp()->getNum());
				cur->getUp()->setNum(0);
				perform = 1;
			}
			else
				continue;
		}
	}



	//Stage 3
	for (int x = 3; x >= 0; x--)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int y = 3; y > 0; y--)
			{

				cur = getBlock_x_y(x, y);
				if (cur->getNum() == 0)
				{
					swap(cur, 'u');//���� ���� swap
					if (cur->getDown()->getNum() != 0)
						perform = 1;
				}
			}
		}
	}



	return perform;
}

bool Board::Left()
{

	Block* cur = 0;
	bool perform = 0;


	//Stage 1
	for (int y = 0; y <= 3; y++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int x = 0; x < 3; x++)//���ʿ��� ���������� ����
			{

				cur = getBlock_x_y(x, y);//��ǥ�� �ش��ϴ� ���� ��´�.
				if (cur->getNum() == 0)//number�� 0�� ���̸�
				{
					swap(cur, 'r');//������ ���� swap
					if (cur->getLeft()->getNum() != 0)
						perform = 1;
				}
			}
		}
	}


	//Stage 2
	for (int y = 0; y <= 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cur = getBlock_x_y(x, y);

			//cur�� ������ ���� �����ϰ� cur�� cur�� ������ ���� ���ڰ� ���� ��
			if (cur->getRight() && cur->getNum() == cur->getRight()->getNum() && cur->getNum() != 0)
			{
				//cur�� ������ ���ڸ� ������
				cur->setNum(cur->getNum() + cur->getRight()->getNum());
				cur->getRight()->setNum(0);
				perform = 1;
			}
			else
				continue;
		}
	}

	//Stage 3
	for (int y = 0; y <= 3; y++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int x = 0; x < 3; x++)
			{
				cur = getBlock_x_y(x, y);
				if (cur->getNum() == 0)
				{
					swap(cur, 'r');//������ ���� swap
					if (cur->getLeft()->getNum() != 0)
						perform = 1;
				}
			}
		}
	}
	return perform;
}

bool Board::Right()
{

	Block* cur = 0;
	bool perform = 0;

	//Stage 1
	for (int y = 0; y <= 3; y++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int x = 3; x > 0; x--)//�����ʿ��� �������� ����
			{

				cur = getBlock_x_y(x, y);//��ǥ�� �ش��ϴ� ���� ��´�.
				if (cur->getNum() == 0)//number�� 0�� ���̸�
				{
					swap(cur, 'l');//���� ���� swap
					if (cur->getRight()->getNum() != 0)
						perform = 1;
				}
			}
		}
	}


	//Stage 2
	for (int y = 0; y <= 3; y++)
	{
		for (int x = 3; x > 0; x--)
		{
			cur = getBlock_x_y(x, y);

			//cur�� ���� ���� �����ϰ� cur�� cur�� ���� ���� ���ڰ� ���� ��
			if (cur->getLeft() && cur->getNum() == cur->getLeft()->getNum() && cur->getNum() != 0)
			{
				//cur�� ���� ������ ���ڸ� ������
				cur->setNum(cur->getNum() + cur->getLeft()->getNum());
				cur->getLeft()->setNum(0);
				perform = 1;
			}
			else
				continue;
		}
	}



	//Stage 3
	for (int y = 0; y <= 3; y++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int x = 3; x > 0; x--)//�����ʿ��� �������� ����
			{
				cur = getBlock_x_y(x, y);
				if (cur->getNum() == 0)
				{
					swap(cur, 'l');//�Ʒ��� ���� swap
					if (cur->getRight()->getNum() != 0)
						perform = 1;
				}
			}
		}
	}


	return perform;
}







void Board::swap(Block* pTB, char d)
{

	Block* s = 0;//(switch_Block)  ����ġ �� ���

	int temp_x = 0, temp_y = 0;

	//���⿡ ���� ��� ������ ����
	if (d == 'u')
	{
		s = pTB->getUp();

	}
	else if (d == 'd')
	{

		s = pTB->getDown();

	}
	else if (d == 'l')
	{
		s = pTB->getLeft();
	}
	else if (d == 'r')
	{
		s = pTB->getRight();
	}
	else
	{
		cout << "\ncheck_move_able() : error unknown value '" << d << "'" << endl;//�߸��� �����Է� ��. ���α׷� ����
		exit(2);
	}
	//��ǥ�� �ٲٱ�
	temp_x = s->getX();
	temp_y = s->getY();

	s->setX(pTB->getX());
	s->setY(pTB->getY());
	pTB->setX(temp_x);
	pTB->setY(temp_y);
	if (pTB->getX() == 0 && pTB->getY() == 0)
		Block_Header = pTB;
	else if (s->getX() == 0 && s->getY() == 0)
		Block_Header = s;
	//��ǥ ���� �Ϸ�///



	//switch �� ���� Zero����� ���� ����.
	Block* s_Left = s->getLeft();
	Block* s_Right = s->getRight();
	Block* s_Up = s->getUp();
	Block* s_Down = s->getDown();

	Block* z_Left = pTB->getLeft();
	Block* z_Right = pTB->getRight();
	Block* z_Down = pTB->getDown();
	Block* z_Up = pTB->getUp();



	// u , d , l , r ���⿡ ���� ��� swap 
	if (d == 'u')
	{
		//���� ��쿡 ���� swap
		if (s_Up == NULL && z_Down == NULL)//�� �Ʒ��� ������ ��
		{
			s->setUp(pTB);
			pTB->setDown(s);

			s->setDown(NULL);
			pTB->setUp(NULL);
		}
		else if (s_Up == NULL)//���� ������ ��
		{
			pTB->setDown(s);
			s->setUp(pTB);

			s->setDown(z_Down);
			z_Down->setUp(s);

			pTB->setUp(NULL);
		}
		else if (z_Down == NULL)//���� ������ ��
		{
			pTB->setDown(s);
			s->setUp(pTB);

			pTB->setUp(s_Up);
			s_Up->setDown(pTB);

			s->setDown(NULL);
		}
		else//�߰��� ������ ��
		{
			pTB->setDown(s);
			s->setUp(pTB);

			s_Up->setDown(pTB);
			pTB->setUp(s_Up);

			s->setDown(z_Down);
			z_Down->setUp(s);
		}



		//�¿� ������� ��ũ ����
		//s�� �����ѳ�� ����
		if (s_Right)
		{
			s_Right->setLeft(pTB);
			pTB->setRight(s_Right);
		}
		if (s_Left)
		{
			s_Left->setRight(pTB);
			pTB->setLeft(s_Left);
		}

		//zero ��忡 ������ ��� ����
		if (z_Right)
		{
			z_Right->setLeft(s);
			s->setRight(z_Right);
		}
		if (z_Left)
		{
			z_Left->setRight(s);
			s->setLeft(z_Left);
		}



	}
	else if (d == 'd')
	{
		//���� ��쿡 ���� swap
		if (s_Down == NULL && z_Up == NULL)//���Ʒ��� �� NULL�� ��
		{
			s->setDown(pTB);
			pTB->setUp(s);

			s->setUp(NULL);
			pTB->setDown(NULL);
		}
		else if (z_Up == NULL)//zero�� ���� NULL�� ��
		{
			pTB->setUp(s);
			s->setDown(pTB);

			pTB->setDown(s_Down);
			s_Down->setUp(pTB);

			s->setUp(NULL);
		}
		else if (s_Down == NULL)//switch ����� ���� NULL�� ��
		{
			pTB->setUp(s);
			s->setDown(pTB);

			s->setUp(z_Up);
			z_Up->setDown(s);

			pTB->setDown(NULL);
		}
		else//�߰��� ������ ��
		{
			pTB->setUp(s);
			s->setDown(pTB);

			z_Up->setDown(s);
			s->setUp(z_Up);

			pTB->setDown(s_Down);
			s_Down->setUp(pTB);
		}

		//�¿� ������� ��ũ ����
		//s�� �����ѳ�� ����
		if (s_Right)
		{
			s_Right->setLeft(pTB);
			pTB->setRight(s_Right);
		}
		if (s_Left)
		{
			s_Left->setRight(pTB);
			pTB->setLeft(s_Left);
		}

		//zero ��忡 ������ ��� ����
		if (z_Right)
		{
			z_Right->setLeft(s);
			s->setRight(z_Right);
		}
		if (z_Left)
		{
			z_Left->setRight(s);
			s->setLeft(z_Left);
		}
	}
	else if (d == 'l')
	{
		//�¿� ��쿡 ���� swap
		if (s_Left == NULL && z_Right == NULL)
		{
			s->setLeft(pTB);
			pTB->setRight(s);

			s->setRight(NULL);
			pTB->setLeft(NULL);
		}
		else if (z_Right == NULL)//zero ����� �������� NULL�� ��
		{
			pTB->setRight(s);
			s->setLeft(pTB);

			pTB->setLeft(s_Left);
			s_Left->setRight(pTB);

			s->setRight(NULL);
		}
		else if (s_Left == NULL)//switch ����� ������ NULL�� ��
		{
			pTB->setRight(s);
			s->setLeft(pTB);

			s->setRight(z_Right);
			z_Right->setLeft(s);

			pTB->setLeft(NULL);
		}
		else//�߰��� ������ ��
		{
			pTB->setRight(s);
			s->setLeft(pTB);

			s->setRight(z_Right);
			z_Right->setLeft(s);

			pTB->setLeft(s_Left);
			s_Left->setRight(pTB);

		}



		//�¿� ������� ��ũ ����
		//s�� �����ѳ�� ����
		if (s_Down)
		{
			s_Down->setUp(pTB);
			pTB->setDown(s_Down);
		}
		if (s_Up)
		{
			s_Up->setDown(pTB);
			pTB->setUp(s_Up);
		}

		//zero ��忡 ������ ��� ����
		if (z_Down)
		{
			z_Down->setUp(s);
			s->setDown(z_Down);
		}
		if (z_Up)
		{
			z_Up->setDown(s);
			s->setUp(z_Up);
		}


	}
	else if (d == 'r')
	{
		//�¿� ��쿡 ���� swap
		if (s_Right == NULL && z_Left == NULL)
		{
			s->setRight(pTB);
			pTB->setLeft(s);

			s->setLeft(NULL);
			pTB->setRight(NULL);
		}
		else if (s_Right == NULL)//s ����� �������� NULL�� ��
		{
			pTB->setLeft(s);
			s->setRight(pTB);

			z_Left->setRight(s);
			s->setLeft(z_Left);

			pTB->setRight(NULL);
		}
		else if (z_Left == NULL)//switch ����� ������ NULL�� ��
		{
			pTB->setLeft(s);
			s->setRight(pTB);

			s_Right->setLeft(pTB);
			pTB->setRight(s_Right);

			s->setLeft(NULL);
		}
		else//�߰��� ������ ��
		{
			pTB->setLeft(s);
			s->setRight(pTB);

			z_Left->setRight(s);
			s->setLeft(z_Left);

			pTB->setRight(s_Right);
			s_Right->setLeft(pTB);
		}



		//�¿� ������� ��ũ ����
		//s�� �����ѳ�� ����
		if (s_Down)
		{
			s_Down->setUp(pTB);
			pTB->setDown(s_Down);
		}
		if (s_Up)
		{
			s_Up->setDown(pTB);
			pTB->setUp(s_Up);
		}

		//zero ��忡 ������ ��� ����
		if (z_Down)
		{
			z_Down->setUp(s);
			s->setDown(z_Down);
		}
		if (z_Up)
		{
			z_Up->setDown(s);
			s->setUp(z_Up);
		}
	}
	else
	{
		cout << "check_move_able() : error unknown value " << d << endl;
	}
}

