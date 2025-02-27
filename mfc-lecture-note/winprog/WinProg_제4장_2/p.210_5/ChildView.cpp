
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p.210_5.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	CMetaFileDC dc;
	dc.CreateEnhanced(NULL,NULL,NULL,NULL);
	dc.Rectangle(0,0,10,10);
	dc.Ellipse(1,1,9,9);
	m_hmf = dc.CloseEnhanced();
}

CChildView::~CChildView()
{
	::DeleteEnhMetaFile(m_hmf);
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	POSITION pos = list.GetHeadPosition();
	while(pos){
		CPoint point = list.GetNext(pos);
		CRect rect(point.x-20,point.y-20,point.x+20,point.y+20);
		dc.PlayMetaFile(m_hmf,&rect);
		
	}
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CRect rect(point.x-20,point.y-20,point.x+20,point.y+20);
	
	//dc.Rectangle(rect);
	dc.PlayMetaFile(m_hmf,&rect);
	list.AddTail(point);
	Invalidate(FALSE);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CRect rect(point.x-20,point.y-20,point.x+20,point.y+20);
	
//dc.Rectangle(rect);
	dc.PlayMetaFile(m_hmf,&rect);
	list.AddTail(point);
	Invalidate(FALSE);
}
