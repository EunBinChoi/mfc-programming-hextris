
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "InputCharacter.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
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
	CPaintDC dc(this);
	
	// 화면 출력용 폰트를 선택한다.
	CFont font;
	font.CreatePointFont(150, _T("궁서"));
	dc.SelectObject(&font);

	// 현재까지 입력된 글자들을 화면에 출력한다.
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT|DT_SINGLELINE);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT|DT_SINGLELINE|DT_CALCRECT);	//<= [a10]

	CPoint pt;	//<= [a10]
	if ( m_str.GetSize() > 0 )
	{
		pt = rect.BottomRight();
		pt.y -= 15;
	}
	else
	{
		pt = CPoint( 1, 1 );
	}
	SetCaretPos( pt );
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// Backspace 입력 시 맨 마지막 글자를 삭제한다.
	if(nChar == _T('\b')){
		if(m_str.GetSize() > 0)
			m_str.RemoveAt(m_str.GetSize()-1);
	}
	// 그 밖의 경우에는 동적 배열에 글자를 추가한다.
	else{
		m_str.Add(nChar);
	}

	// 화면을 갱신한다.
	Invalidate();
}


void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);

	CreateSolidCaret(1, 15);
	ShowCaret();	

	Invalidate();
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	HideCaret();
	::DestroyCaret();
}
