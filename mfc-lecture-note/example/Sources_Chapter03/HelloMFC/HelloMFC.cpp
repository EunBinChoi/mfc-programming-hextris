#include <afxwin.h>
#include <locale.h>

// 응용 프로그램 클래스를 선언한다.
class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// 메인 윈도우 클래스를 선언한다.
class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

// 응용 프로그램 객체를 선언한다.
CHelloApp theApp;

// 응용 프로그램 클래스를 정의한다.
BOOL CHelloApp::InitInstance()
{
	_tsetlocale(LC_ALL, _T("")); // TRACE() 매크로에서 유니코드 한글 출력에 필요!
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	return TRUE;
}

// 메인 윈도우 클래스를 정의한다.
CMainFrame::CMainFrame()
{
	Create(NULL, _T("HelloMFC"));
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	TCHAR *msg = _T("Hello, MFC");
	dc.TextOut(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
#if 0
	AfxMessageBox(_T("마우스 클릭!"));
#endif
#if 1
	TRACE(_T("응용 프로그램 객체 주소: %p = %p\n"), AfxGetApp(), &theApp);
	//TRACE(_T("메인 윈도우 객체 주소: %p = %p\n"), AfxGetMainWnd(), theApp.m_pMainWnd);
	TRACE(_T("메인 윈도우 객체 주소: %p = %p\n"), AfxGetMainWnd(), this);
	TRACE(_T("응용 프로그램 이름: %s\n"), AfxGetAppName());
#endif
#if 0
	// 인스턴스 핸들값은 실행 파일이 로드된 가상 메모리 주소다.
	TRACE("인스턴스 핸들: %p\n", AfxGetInstanceHandle());
#endif
}

// 메시지맵을 선언한다.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
