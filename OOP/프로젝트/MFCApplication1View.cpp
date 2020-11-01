
// MFCApplication1View.cpp : CMFCApplication1View 클래스의 구현
//

#include "pch.h"
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"


#pragma warning (disable:4996)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// print commmand
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(Print_Clr, &CMFCApplication1View::OnClr)
	ON_COMMAND(Print_CLR_NUM, &CMFCApplication1View::OnClrNum)


	ON_COMMAND(ID_32789, &CMFCApplication1View::Log_On)
	ON_COMMAND(ID_32790, &CMFCApplication1View::Log_Off)
END_MESSAGE_MAP()




Board m_board;

CMFCApplication1View::CMFCApplication1View()
{
	
	this->m_bDragFlag_toR = 0;
	this->m_bDragFlag_toL = 0;

	Color_On_flag = 1;//0: color off , 1: color on
	Save_rotation_flag = 0;//if 1 save move
	Save_move_flag = 0;//if 1 save move
	Turn_count = 0;//if 1 save move


	outFile.Open(_T("log.txt"), CFile::modeCreate | CFile::modeWrite);//write file open
}

CMFCApplication1View::~CMFCApplication1View()
{
	outFile.Close();//file close
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	//

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 그리기

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{

	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.


}


// CMFCApplication1View 인쇄
BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비

	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication1View 진단

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{

	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 메시지 처리기




void CMFCApplication1View::OnPaint()
{

	Invalidate(FALSE);//수정된 부분을 다시 그려준다.

	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	CPen NewPen(PS_SOLID, 1, RGB(0, 0, 0));//펜 - 기본두께 2 , 기본 색상 검정
	CPen* pOldPen = dc.SelectObject(&NewPen);//다른팬을 들고 원래팬은 저장한다.
											 //CBrush NewBrush(RGB(0, 0, 0));
											 //CBrush* pOldBrush = dc.SelectObject(&NewBrush);

	Block* pCur;
	int size = 64;//하나의 사각형의 size

	//기본 시작점 (10,10)으로부터 변의 길이가 64인 정사각형
	int init_coordinate_x_1 = 10;
	int init_coordinate_y_1 = 10;
	int init_coordinate_x_2 = 10 + size;
	int init_coordinate_y_2 = 10 + size;


	CBrush NewBrush(RGB(255, 255, 255));//초기 Brush

	//각 색깔 정의
	CBrush Yellow_2(RGB(255, 255, 0));
	CBrush Orange_4(RGB(255, 127, 0));
	CBrush Green_8(RGB(0, 255, 0));
	CBrush Blue_16(RGB(0, 0, 255));
	CBrush Gray_32(RGB(166, 166, 166));
	CBrush Pink_64(RGB(255, 0, 255));
	CBrush Cyan_128(RGB(0, 255, 255));
	CBrush Purple_256(RGB(128, 0, 128));
	CBrush Violet_512(RGB(112, 48, 160));
	CBrush Brown_1024(RGB(207, 110, 54));
	CBrush Red_2048(RGB(255, 0, 0));

	CBrush* pOldBrush = dc.SelectObject(&NewBrush);//기존 pen은 저장


	//(0,0)부터 (3,3)까지
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			pCur = m_board.getBlock_x_y(i, j);

			if (Color_On_flag == 1)//색상 출력시
			{
				//숫자에 따라 사각형의 내부에 색을 할당한다.
				switch (pCur->getNum())
				{
				case 0:
					dc.SelectObject(&NewBrush);
					break;
				case 2:
					dc.SelectObject(&Yellow_2);
					break;
				case 4:
					dc.SelectObject(&Orange_4);
					break;
				case 8:
					dc.SelectObject(&Green_8);
					break;
				case 16:
					dc.SelectObject(&Blue_16);
					break;
				case 32:
					dc.SelectObject(&Gray_32);
					break;
				case 64:
					dc.SelectObject(&Pink_64);
					break;
				case 128:
					dc.SelectObject(&Cyan_128);
					break;
				case 256:
					dc.SelectObject(&Purple_256);
					break;
				case 512:
					dc.SelectObject(&Violet_512);
					break;
				case 1024:
					dc.SelectObject(&Brown_1024);
					break;
				case 2048:
					dc.SelectObject(&Red_2048);
					break;
				}
			}

			//사각형 board를 출력해준다.
			dc.Rectangle(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size));


			//dc.SetBkColor(TRANSPARENT);//배경 투명으로


				//사각형 내부에 숫자를 출력한다.
			if (pCur->getNum() == 0);//0이면 출력을 안한다.
			else if (pCur->getNum() == 2)
				dc.DrawText(_T("2"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 4)
				dc.DrawText(_T("4"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 8)
				dc.DrawText(_T("8"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 16)
				dc.DrawText(_T("16"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 32)
				dc.DrawText(_T("32"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 64)
				dc.DrawText(_T("64"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 128)
				dc.DrawText(_T("128"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 256)
				dc.DrawText(_T("256"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 512)
				dc.DrawText(_T("512"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 1024)
				dc.DrawText(_T("1024"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			else if (pCur->getNum() == 2048)
				dc.DrawText(_T("2048"), CRect(init_coordinate_x_1 + i * size, init_coordinate_y_1 + (j * size), init_coordinate_x_2 + (i * size), init_coordinate_y_2 + (j * size)), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		}

	}

	//로그파일 기록상태를 표시
	if (Save_rotation_flag == 1 && Save_move_flag == 1)
	{
		dc.DrawText(_T("log file (0)"), CRect(10, 290, 250, 400), 0);
	}
	else if (Save_rotation_flag == 0 && Save_move_flag == 0)
	{
		dc.DrawText(_T("log file (x)"), CRect(10, 290, 250, 400), 0);
	}

	//색상 출력 상태를 표시
	if (Color_On_flag == 0)
	{
		dc.DrawText(_T("no color"), CRect(10, 330, 250, 400), 0);
	}
	else if (Color_On_flag == 1)
	{
		dc.DrawText(_T("yes color"), CRect(10, 330, 250, 400), 0);
	}

	//다시 옛날 팬으로 되돌려놓는다.
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldPen);
}


void CMFCApplication1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	int input_err = 0;
	switch (nChar)//키 입력
	{
	case VK_LEFT://왼쪽방향 입력시
		if (m_board.Left() != 0)//왼쪽으로 갈수 있는지 검사 -> 왼쪽에 블럭이 있다면
		{
			m_board.Put_random_num2();//턴을 바꾼다.
			Turn_count++;//턴의 count를 1 증가시킨다.
			if (Save_move_flag == 1)//log파일저장 flag가 On이면
				m_board.printBoard(Turn_count, outFile, 1);//log파일 저장
		}
		break;


		/////////////////////////각 방향마다 기능은 동일////////////////////////


	case VK_RIGHT://오른쪽방향 입력시
		if (m_board.Right() != 0)
		{
			m_board.Put_random_num2();
			Turn_count++;
			if (Save_move_flag == 1)
				m_board.printBoard(Turn_count, outFile, 2);
		}
		break;
	case VK_DOWN://아래방향 입력시
		if (m_board.Down() != 0)
		{
			m_board.Put_random_num2();
			Turn_count++;
			if (Save_move_flag == 1)
				m_board.printBoard(Turn_count, outFile, 3);
		}
		break;

	case VK_UP://위방향 입력시
		if (m_board.Up() != 0)
		{
			m_board.Put_random_num2();
			Turn_count++;
			if (Save_move_flag == 1)
				m_board.printBoard(Turn_count, outFile, 4);
		}
		break;
	}

	OnPaint();//이동후 다시 그려준다.

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

//마우스이벤트 처리 _ 눌렀을 때
void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{


	//마우스 포인터가 board 내부에 찍혔을 때만 유효
	if (point.x >= 10 && point.x <= 10 + 64 * 4
		&&
		point.y >= 10 && point.y <= 10 + 64 * 4)
	{
		org_x = point.x;
		org_y = point.y;
	}

	SetCapture();
	ReleaseCapture();


	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDragFlag_toR)
	{

	}
	else if (m_bDragFlag_toL)
	{

	}
	else
		ReleaseCapture();
	CView::OnMouseMove(nFlags, point);
}

//마우스이벤트 처리 _ 땠을 때
void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{

	//땐 좌표를 저장
	new_x = point.x;
	new_y = point.y;


	//땐 좌표와 처음 좌표가 board 내부일 때만
	if (new_x >= 10 && new_x <= 10 + 64 * 4
		&&
		new_y >= 10 && new_y <= 10 + 64 * 4
		&&
		org_x >= 10 && org_x <= 10 + 64 * 4
		&&
		org_y >= 10 && org_y <= 10 + 64 * 4
		)
	{
		if ((new_x - org_x) > 0)//드래그 앤 드롭 →
		{
			m_board.rotation_time();//시계방향으로 rotate
			Turn_count++;//turn 증가
			if (Save_rotation_flag == 1)//log 파일 save flag on일 때
			{

				m_board.printBoard(Turn_count, outFile, 5);//현재상태를 로그파일로 print
			}
			RedrawWindow();//window를 다시 그린다.
		}
		else//드래그 앤 드롭 ←
		{
			m_board.rotation_reverse_time();//반시계방향으로 rotate
			Turn_count++;//turn 증가
			if (Save_rotation_flag == 1)//log 파일 save flag on일 때
			{

				m_board.printBoard(Turn_count, outFile, 6);//현재상태를 로그파일로 print
			}
			RedrawWindow();
		}
	}

	//커서 위치 변수 초기화
	org_x = 0;
	org_y = 0;
	new_x = 0;
	new_y = 0;
	CView::OnLButtonUp(nFlags, point);
}




void CMFCApplication1View::OnClr()//출력메뉴 이벤트 : 색상을 삭제.
{
	Color_On_flag = 0;
	OnPaint();//다시 그려준다.
}


void CMFCApplication1View::OnClrNum()//출력메뉴 이벤트 :색상을 추가.
{
	Color_On_flag = 1;
	OnPaint();//다시 그려준다.
}



void CMFCApplication1View::Log_On()
{
	//log 파일 flag On
	Save_move_flag = 1;//이동
	Save_rotation_flag = 1;//로테이션



	OnPaint();//다시 그려준다.
}


void CMFCApplication1View::Log_Off()
{
	//log 파일 flag Off
	Save_move_flag = 0;//이동
	Save_rotation_flag = 0;//로테이션

	OnPaint();//다시 그려준다.

}
