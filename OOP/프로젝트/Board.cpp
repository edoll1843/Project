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
	}//cur는 다음 행의 첫번째 노드를 가리킴

	for (int i = 0; i < 4 - 1; i++)
	{
		//전 행의 모든 노드들과 연결시킨다.
		for (int j = 0; j < 4; j++)
		{
			cur->setUp(temp);
			temp->setDown(cur);

			temp = temp->getRight();
			cur = cur->getRight();
		}
	}

	cur = Block_Header;
	//일차원 배열에서 다음 행으로 넘어가는 노드들의 연결을 해제
	for (int i = 0; i < 4 * 4; i++)
	{
		if (i % 4 == 0 && i != 0)
		{
			cur->getLeft()->setRight(NULL);
			cur->setLeft(NULL);
		}
		cur = cur->getRight();
	}

	//board setting 시, 초기 turn change
	Put_random_num2();//turn 변경 -> 랜덤으로 2 추가
	Put_random_num2();
}


Board::~Board()
{
	//(0,0)부터 (3,3)까지
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 3; j >= 0; j--)
		{
			delete getBlock_x_y(i, j);
		}
	}
}

//매 turn이 바뀔 때마다 비어있는 랜덤의 block에 number 2를 할당
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

		temp = getBlock_x_y(x, y);//좌표의 노드를 탐색
		if (temp != NULL && temp->getNum() == 0)//탐색한 노드의 number가 0일 때만
		{
			//check[x][y] = 1;
			temp->setNum(2);//number을 2로 설정
			return true;//성공시 true 반환
		}
	}

}



//비어있는 Block이 있을 경우 return 1 , 모든 Block이 꽉차있을경우 return 0;
bool Board::Check_block()
{
	Block* cur = Block_Header;//옆으로 탐색하는 노드
	Block* pDown = Block_Header;//밑으로 내려가는 노드
	while (pDown)
	{
		while (cur)//옆으로 탐색
		{
			//만약 좌표에 해당하는 노드면 해당 노드를 반환
			if (cur->getNum() == 0)
			{
				return 1;
			}
			cur = cur->getRight();
		}
		pDown = pDown->getDown();//밑으로 내려간다.
		cur = pDown;//밑으로 내려간 노드부터 다시 옆으로 탐색
	}

	return 0;
}

//(x,y) 좌표에 해당하는 노드를 반환함.
Block* Board::getBlock_x_y(int x, int y)
{
	Block* pResult = Block_Header;
	for (int i = 0; i < x; i++)//x축이동
	{
		pResult = pResult->getRight();
	}
	for (int j = 0; j < y; j++)//y축이동
	{
		pResult = pResult->getDown();
	}
	return pResult;//(x,y)에 해당하는 노드
}

Block* Board::getHead()
{
	return Block_Header;
}

//시계방향으로 rotation
void Board::rotation_time()
{
	int temp = 0;

	temp = getBlock_x_y(3, 0)->getNum();//(3,0)부터 시작.
	getBlock_x_y(3, 0)->setNum(getBlock_x_y(0, 0)->getNum());
	getBlock_x_y(0, 0)->setNum(getBlock_x_y(0, 3)->getNum());
	getBlock_x_y(0, 3)->setNum(getBlock_x_y(3, 3)->getNum());
	getBlock_x_y(3, 3)->setNum(temp);//한바퀴의 마지막

	temp = getBlock_x_y(3, 1)->getNum();//(3,1)부터 시작.
	getBlock_x_y(3, 1)->setNum(getBlock_x_y(1, 0)->getNum());
	getBlock_x_y(1, 0)->setNum(getBlock_x_y(0, 2)->getNum());
	getBlock_x_y(0, 2)->setNum(getBlock_x_y(2, 3)->getNum());
	getBlock_x_y(2, 3)->setNum(temp); // 한바퀴의 마지막

	temp = getBlock_x_y(3, 2)->getNum();//(3,2)부터 시작.
	getBlock_x_y(3, 2)->setNum(getBlock_x_y(2, 0)->getNum());
	getBlock_x_y(2, 0)->setNum(getBlock_x_y(0, 1)->getNum());
	getBlock_x_y(0, 1)->setNum(getBlock_x_y(1, 3)->getNum());
	getBlock_x_y(1, 3)->setNum(temp); // 한바퀴의 마지막


	temp = getBlock_x_y(2, 1)->getNum();//(2,1)부터 시작.
	getBlock_x_y(2, 1)->setNum(getBlock_x_y(1, 1)->getNum());
	getBlock_x_y(1, 1)->setNum(getBlock_x_y(1, 2)->getNum());
	getBlock_x_y(1, 2)->setNum(getBlock_x_y(2, 2)->getNum());
	getBlock_x_y(2, 2)->setNum(temp);// 한바퀴의 마지막


}

//반시계방향 rotation
void Board::rotation_reverse_time()
{
	int temp = 0;

	temp = getBlock_x_y(3, 0)->getNum();//(3,0)부터 시작.
	getBlock_x_y(3, 0)->setNum(getBlock_x_y(3, 3)->getNum());
	getBlock_x_y(3, 3)->setNum(getBlock_x_y(0, 3)->getNum());
	getBlock_x_y(0, 3)->setNum(getBlock_x_y(0, 0)->getNum());
	getBlock_x_y(0, 0)->setNum(temp);//한바퀴의 마지막

	temp = getBlock_x_y(3, 1)->getNum();//(3,1)부터 시작.
	getBlock_x_y(3, 1)->setNum(getBlock_x_y(2, 3)->getNum());
	getBlock_x_y(2, 3)->setNum(getBlock_x_y(0, 2)->getNum());
	getBlock_x_y(0, 2)->setNum(getBlock_x_y(1, 0)->getNum());
	getBlock_x_y(1, 0)->setNum(temp);//한바퀴의 마지막

	temp = getBlock_x_y(3, 2)->getNum();//(3,2)부터 시작.
	getBlock_x_y(3, 2)->setNum(getBlock_x_y(1, 3)->getNum());
	getBlock_x_y(1, 3)->setNum(getBlock_x_y(0, 1)->getNum());
	getBlock_x_y(0, 1)->setNum(getBlock_x_y(2, 0)->getNum());
	getBlock_x_y(2, 0)->setNum(temp);//한바퀴의 마지막


	temp = getBlock_x_y(2, 1)->getNum();//(2,1)부터 시작.
	getBlock_x_y(2, 1)->setNum(getBlock_x_y(2, 2)->getNum());
	getBlock_x_y(2, 2)->setNum(getBlock_x_y(1, 2)->getNum());
	getBlock_x_y(1, 2)->setNum(getBlock_x_y(1, 1)->getNum());
	getBlock_x_y(1, 1)->setNum(temp);//한바퀴의 마지막

}

//Board를 파일로 출력하는 함수
void Board::printBoard(int count, CFile& outFile, int menu)
{
	Block* cur = Block_Header;
	Block* pDown = Block_Header;


	//temp를 버퍼처럼 사용
	char temp[30] = { 0 };//모든 문자열들을 temp에 저장하여 사용

	//count를 출력
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

	//result를 출력
	strcpy(temp, "[result]\r\n");
	outFile.Write(temp, strlen(temp));
	memset(temp, 0, 30);
	while (pDown)//밑으로 탐색
	{
		while (cur)//옆으로 탐색
		{
			if (cur->getNum() == 0)//0이면 공백을 출력해준다.
			{
				strcpy(temp, "	");
				outFile.Write(temp, strlen(temp));
				memset(temp, 0, 30);
			}
			else//0이 아닌 숫자면 해당숫자를 출력한다.
			{
				itoa(cur->getNum(), temp, 10);
				outFile.Write(temp, strlen(temp));
				memset(temp, 0, 30);

				strcpy(temp, "	");
				outFile.Write(temp, strlen(temp));
				memset(temp, 0, 30);
				memset(temp, 0, 30);
			}
			cur = cur->getRight();//오른쪽으로 넘어간다.
		}
		strcpy(temp, "\r\n");
		outFile.Write(temp, strlen(temp));
		memset(temp, 0, 30);
		pDown = pDown->getDown();//밑으로 내려간다.
		cur = pDown;//밑으로 내려간 노드부터 다시 옆으로 탐색
	}
	strcpy(temp, "\r\n");
	outFile.Write(temp, strlen(temp));
	outFile.Write(temp, strlen(temp));
	memset(temp, 0, 30);
}


//2048이 있으면 return 1;, 없으면 return 0;, 
bool Board::Check_win()
{
	Block* cur = Block_Header;
	Block* pDown = Block_Header;
	while (pDown)
	{
		while (cur)//옆으로 탐색
		{
			if (cur->getNum() == 2048)
				return 1;
			cur = cur->getRight();
		}
		pDown = pDown->getDown();//밑으로 내려간다.
		cur = pDown;//밑으로 내려간 노드부터 다시 옆으로 탐색
	}
	return 0;
}


//실패시 return 1, 실패가 아니고 더 진행가능하면 return 0;
bool Board::Check_fail()
{
	Block* cur = Block_Header;
	Block* pDown = Block_Header;
	while (pDown)//밑으로 탐색
	{
		while (cur)//옆으로 탐색
		{
			if (cur->getNum() == 0)//블럭의 숫자가 0이면 더 진행가능 : 실패가 아님 -> return 0
			{
				return 0;
			}
			else//인접 블럭에 같은 숫자들이 있는지 확인 : 하나라도 있으면 실패가 아니다. -> return 0
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
		pDown = pDown->getDown();//밑으로 내려간다.
		cur = pDown;//밑으로 내려간 노드부터 다시 옆으로 탐색
	}
	return 1;//위 과정을 거치는 동안 0이 반환이 안된다면 실패가 맞다고 판단 -> return 1
}


//숫자들을 하나도 밀지 않을 경우 return 0; 하나라도 밀경우 return 1;
//Up() 이외에 Down(), Right(), Left() 함수들도 모두 같은 방식.
bool Board::Up()
{

	Block* cur = 0;
	bool perform = 0;


	//STAGE 1 :0이상의 숫자들을 위쪽으로 몰아넣기
	for (int x = 0; x <= 3; x++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				cur = getBlock_x_y(x, y);//좌표에 해당하는 블럭을 얻는다.
				if (cur->getNum() == 0)//number가 0인 블럭이면
				{
					swap(cur, 'd');//cur을 아래쪽 블럭과 swap
					if (cur->getUp()->getNum() != 0)//swap한 노드의 number가 0이 아닌수 이면
						perform = 1;//수행 여부(한번이라도 유효한 수행이 된 경우 1을 저장)
									//유효한 수행이란 0이아닌값과 노드 swap되는 경우
				}
			}
		}
	}


	//STAGE 2 : 같은숫자 더하기
	for (int x = 0; x <= 3; x++)
	{
		for (int y = 0; y < 3; y++)//위쪽에서 밑쪽으로 진행
		{
			cur = getBlock_x_y(x, y);

			//cur의 아래쪽 블럭이 존재하고 cur과 cur의 아래쪽 블럭의 숫자가 같을 때
			if (cur->getDown() && cur->getNum() == cur->getDown()->getNum() && cur->getNum() != 0)
			{
				//cur의 블럭으로 숫자를 더해줌
				cur->setNum(cur->getNum() + cur->getDown()->getNum());
				cur->getDown()->setNum(0);
				perform = 1;
			}
			else
				continue;
		}
	}


	//STAGE 3 : 다시 위쪽으로 몰아넣기
	for (int x = 0; x <= 3; x++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				cur = getBlock_x_y(x, y);//좌표에 해당하는 블럭을 얻는다.
				if (cur->getNum() == 0)//number가 0인 블럭이면
				{
					swap(cur, 'd');//아래쪽 블럭과 swap
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
			for (int y = 3; y > 0; y--)//밑쪽에서 위쪽으로 진행
			{

				cur = getBlock_x_y(x, y);
				if (cur->getNum() == 0)
				{
					swap(cur, 'u');//위쪽 블럭과 swap
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

			//cur의 위쪽 블럭이 존재하고 cur과 cur의 위쪽 블럭의 숫자가 같을 때
			if (cur->getUp() && cur->getNum() == cur->getUp()->getNum() && cur->getNum() != 0)
			{
				//cur의 블럭으로 숫자를 더해줌
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
					swap(cur, 'u');//위쪽 블럭과 swap
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
			for (int x = 0; x < 3; x++)//왼쪽에서 오른쪽으로 진행
			{

				cur = getBlock_x_y(x, y);//좌표에 해당하는 블럭을 얻는다.
				if (cur->getNum() == 0)//number가 0인 블럭이면
				{
					swap(cur, 'r');//오른쪽 블럭과 swap
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

			//cur의 오른쪽 블럭이 존재하고 cur과 cur의 오른쪽 블럭의 숫자가 같을 때
			if (cur->getRight() && cur->getNum() == cur->getRight()->getNum() && cur->getNum() != 0)
			{
				//cur의 블럭으로 숫자를 더해줌
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
					swap(cur, 'r');//오른쪽 블럭과 swap
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
			for (int x = 3; x > 0; x--)//오른쪽에서 왼쪽으로 진행
			{

				cur = getBlock_x_y(x, y);//좌표에 해당하는 블럭을 얻는다.
				if (cur->getNum() == 0)//number가 0인 블럭이면
				{
					swap(cur, 'l');//왼쪽 노드와 swap
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

			//cur의 왼쪽 블럭이 존재하고 cur과 cur의 왼쪽 블럭의 숫자가 같을 때
			if (cur->getLeft() && cur->getNum() == cur->getLeft()->getNum() && cur->getNum() != 0)
			{
				//cur의 왼쪽 블럭으로 숫자를 더해줌
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
			for (int x = 3; x > 0; x--)//오른쪽에서 왼쪽으로 진행
			{
				cur = getBlock_x_y(x, y);
				if (cur->getNum() == 0)
				{
					swap(cur, 'l');//아래쪽 블럭과 swap
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

	Block* s = 0;//(switch_Block)  스위치 될 노드

	int temp_x = 0, temp_y = 0;

	//방향에 따른 노드 포인터 설정
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
		cout << "\ncheck_move_able() : error unknown value '" << d << "'" << endl;//잘못된 방향입력 시. 프로그램 종료
		exit(2);
	}
	//좌표값 바꾸기
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
	//좌표 설정 완료///



	//switch 될 노드와 Zero노드의 인접 노드들.
	Block* s_Left = s->getLeft();
	Block* s_Right = s->getRight();
	Block* s_Up = s->getUp();
	Block* s_Down = s->getDown();

	Block* z_Left = pTB->getLeft();
	Block* z_Right = pTB->getRight();
	Block* z_Down = pTB->getDown();
	Block* z_Up = pTB->getUp();



	// u , d , l , r 방향에 따른 노드 swap 
	if (d == 'u')
	{
		//상하 경우에 따른 swap
		if (s_Up == NULL && z_Down == NULL)//위 아래가 막혔을 때
		{
			s->setUp(pTB);
			pTB->setDown(s);

			s->setDown(NULL);
			pTB->setUp(NULL);
		}
		else if (s_Up == NULL)//위가 막혔을 때
		{
			pTB->setDown(s);
			s->setUp(pTB);

			s->setDown(z_Down);
			z_Down->setUp(s);

			pTB->setUp(NULL);
		}
		else if (z_Down == NULL)//밑이 막혔을 때
		{
			pTB->setDown(s);
			s->setUp(pTB);

			pTB->setUp(s_Up);
			s_Up->setDown(pTB);

			s->setDown(NULL);
		}
		else//중간에 껴있을 때
		{
			pTB->setDown(s);
			s->setUp(pTB);

			s_Up->setDown(pTB);
			pTB->setUp(s_Up);

			s->setDown(z_Down);
			z_Down->setUp(s);
		}



		//좌우 인접노드 링크 갱신
		//s에 인접한노드 갱신
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

		//zero 노드에 인접한 노드 갱신
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
		//상하 경우에 따른 swap
		if (s_Down == NULL && z_Up == NULL)//위아래가 다 NULL일 때
		{
			s->setDown(pTB);
			pTB->setUp(s);

			s->setUp(NULL);
			pTB->setDown(NULL);
		}
		else if (z_Up == NULL)//zero의 위가 NULL일 때
		{
			pTB->setUp(s);
			s->setDown(pTB);

			pTB->setDown(s_Down);
			s_Down->setUp(pTB);

			s->setUp(NULL);
		}
		else if (s_Down == NULL)//switch 노드의 밑이 NULL일 때
		{
			pTB->setUp(s);
			s->setDown(pTB);

			s->setUp(z_Up);
			z_Up->setDown(s);

			pTB->setDown(NULL);
		}
		else//중간에 껴있을 때
		{
			pTB->setUp(s);
			s->setDown(pTB);

			z_Up->setDown(s);
			s->setUp(z_Up);

			pTB->setDown(s_Down);
			s_Down->setUp(pTB);
		}

		//좌우 인접노드 링크 갱신
		//s에 인접한노드 갱신
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

		//zero 노드에 인접한 노드 갱신
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
		//좌우 경우에 따른 swap
		if (s_Left == NULL && z_Right == NULL)
		{
			s->setLeft(pTB);
			pTB->setRight(s);

			s->setRight(NULL);
			pTB->setLeft(NULL);
		}
		else if (z_Right == NULL)//zero 노드의 오른쪽이 NULL일 때
		{
			pTB->setRight(s);
			s->setLeft(pTB);

			pTB->setLeft(s_Left);
			s_Left->setRight(pTB);

			s->setRight(NULL);
		}
		else if (s_Left == NULL)//switch 노드의 왼쪽이 NULL일 떄
		{
			pTB->setRight(s);
			s->setLeft(pTB);

			s->setRight(z_Right);
			z_Right->setLeft(s);

			pTB->setLeft(NULL);
		}
		else//중간에 껴있을 때
		{
			pTB->setRight(s);
			s->setLeft(pTB);

			s->setRight(z_Right);
			z_Right->setLeft(s);

			pTB->setLeft(s_Left);
			s_Left->setRight(pTB);

		}



		//좌우 인접노드 링크 갱신
		//s에 인접한노드 갱신
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

		//zero 노드에 인접한 노드 갱신
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
		//좌우 경우에 따른 swap
		if (s_Right == NULL && z_Left == NULL)
		{
			s->setRight(pTB);
			pTB->setLeft(s);

			s->setLeft(NULL);
			pTB->setRight(NULL);
		}
		else if (s_Right == NULL)//s 노드의 오른쪽이 NULL일 때
		{
			pTB->setLeft(s);
			s->setRight(pTB);

			z_Left->setRight(s);
			s->setLeft(z_Left);

			pTB->setRight(NULL);
		}
		else if (z_Left == NULL)//switch 노드의 왼쪽이 NULL일 떄
		{
			pTB->setLeft(s);
			s->setRight(pTB);

			s_Right->setLeft(pTB);
			pTB->setRight(s_Right);

			s->setLeft(NULL);
		}
		else//중간에 껴있을 때
		{
			pTB->setLeft(s);
			s->setRight(pTB);

			z_Left->setRight(s);
			s->setLeft(z_Left);

			pTB->setRight(s_Right);
			s_Right->setLeft(pTB);
		}



		//좌우 인접노드 링크 갱신
		//s에 인접한노드 갱신
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

		//zero 노드에 인접한 노드 갱신
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

