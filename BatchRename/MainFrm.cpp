
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "BatchRename.h"

#include "MainFrm.h"

#include "OperatorView.h"
#include "SelectFolderDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_SELECTFOLDER, &CMainFrame::OnSelectfolder)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 将焦点前移到视图窗口
	//m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{


	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{

	CRect rc;
	GetClientRect(&rc);

	//将窗口分为三列一行
	if (!m_wndSplitter.CreateStatic(this, 2, 1))
		return FALSE;

	if (m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(COperatorView), CSize(100, 100), pContext) == FALSE ||
		m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(CBatchRenameFileView), CSize(100, 100), pContext) == FALSE)
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}


	m_pWndBatchRenameFileView = (CBatchRenameFileView*)m_wndSplitter.GetPane(0, 0);


	//CSelectFolderDialog selectFolderDialog;
	//selectFolderDialog.DoModal();
	//
	return TRUE;
}


void CMainFrame::OnSelectfolder()
{
	//m_pWndBatchRenameFileView->PostMessage()
	CSelectFolderDialog selectFolderDialog;
	if (selectFolderDialog.DoModal() != IDOK)
		return;

	



}
