
#include "stdafx.h"
#include "p.210_10.h"
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
	
	CFont font1;
	CFont font2;
	CFont font3;
	const int nHeight1 = -::MulDiv(10,GetDeviceCaps(dc, LOGPIXELSY),72);
	const int nHeight2 = -::MulDiv(12,GetDeviceCaps(dc, LOGPIXELSY),72);
	const int nHeight3 = -::MulDiv(14,GetDeviceCaps(dc, LOGPIXELSY),72);
	//CDC* pDC = dc.GetDC();  
	
	font1.CreateFont( 
		nHeight1,                  // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial") );                 // lpszFacename

	font2.CreateFont( 
		nHeight2,                  // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial") );                 // lpszFacename

	font3.CreateFont( 
		nHeight3,                  // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial") );                 // lpszFacename
	
	
	CRect rect;
	GetClientRect(&rect);

	dc.SetTextColor(RGB(255, 0, 0)); // 글자를 빨간색으로 설정
	dc.SetBkColor(RGB(255, 255, 0)); // 배경을 노란색으로 설정

	dc.SelectObject( &font1 );	//<= [a10]
	dc.DrawText(CString("DrawText 함수를 연습합니다[1]"), &rect, 0);

	dc.SelectObject( &font2 );
	dc.DrawText(CString("DrawText 함수를 연습합니다[2]"),&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	dc.SetTextAlign(TA_CENTER); // 가운데 정렬 방식으로 변경
	dc.SetTextColor(RGB(0, 0, 255)); // 글자를 파란색으로 설정
	dc.SetBkColor(RGB(0, 255, 0)); // 배경을 초록색으로 설정

	dc.SelectObject( &font3 );	//<= [a10]
	dc.TextOut(rect.right/2, 3*rect.bottom/4,
		CString("TextOut 함수를 연습합니다."));
	/*dc.SelectObject( &font3 );
	dc.DrawText(CString("DrawText 함수를 연습합니다[2]"),&rect,0);*/

	//	DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	//(70,nHeight,0,0,0,0,TRUE,0,0,0,0,0,0,);
	//font1.CreatePointFont(400, );
	
	//dc.SelectObject(&font1);
	//dc.DrawText(CString("DrawText 함수를 연습합니다[1]"),&rect,0);
	//
	//font2.CreateFont(70,30,0,0,0,TRUE,0,0,0,0,0,0,0,_T("궁서"));
	////font2.CreatePointFont(400, _T("궁서"));
	//dc.SelectObject(&font2);
	//
	//
	//dc.SetTextAlign(TA_CENTER);
	//dc.SetTextColor(RGB(0,0,255));
	//dc.SetBkColor(RGB(0,255,0));
	//font3.CreateFont(70,30,0,0,FW_BOLD,0,0,0,0,0,0,0,0,_T("바탕"));
	////font3.CreatePointFont(400, _T("바탕"));
	//dc.SelectObject(&font3);
	//dc.TextOut(rect.right/2 , 3*rect.bottom/4,CString("TextOut 함수를 연습합니다"));
}


