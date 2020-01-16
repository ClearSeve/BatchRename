
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// ������ǰ�Ƶ���ͼ����
	//m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{


	// ����ִ��Ĭ�ϴ���
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{

	CRect rc;
	GetClientRect(&rc);

	//�����ڷ�Ϊ����һ��
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
