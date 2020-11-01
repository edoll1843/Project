
// MFCApplication1View.h : CMFCApplication1View 클래스의 인터페이스
//

#pragma once


class CMFCApplication1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

	// 특성입니다.
public:
	CMFCApplication1Doc* GetDocument() const;

	// 작업입니다.
public:

	// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 구현입니다.
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();//큐브그림 출력
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);//kyboard 입력 처리



	//마우스 입력 이벤트
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	//메뉴 리소스 이벤트
	afx_msg void OnClr();//출력메뉴-색상 On
	afx_msg void OnClrNum();//출력메뉴-색생 Off
	afx_msg void Log_On();//기록메뉴- 기록 on
	afx_msg void Log_Off();//기록메뉴- 기록 Off



	bool Color_On_flag;//0: color off , 1: color on

	bool Save_rotation_flag;//1이면 회전 기록
	bool Save_move_flag;//1이면 회전기록

	int Turn_count;//턴의 횟수

	bool m_bDragFlag_toR;//오른쪽으로 드래그 시작여부 (true: ok, false: no)
	bool m_bDragFlag_toL;//왼쪽으로 시작여부 (true: ok, false: no)
	int org_x, org_y;//드래그 시 처음 좌표
	int new_x, new_y;//드래그 시 마지막 좌표

	CFile outFile;//log 파일을 처리하기 위한 CFile

};

#ifndef _DEBUG  // MFCApplication1View.cpp의 디버그 버전
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
{
	return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument);
}
#endif

