// BatchRenameFileView.cpp : 实现文件
//

#include "stdafx.h"
#include "BatchRename.h"
#include "BatchRenameFileView.h"


// CBatchRenameFileView

IMPLEMENT_DYNCREATE(CBatchRenameFileView, CFormView)

CBatchRenameFileView::CBatchRenameFileView()
: CFormView(CBatchRenameFileView::IDD)
{

}

CBatchRenameFileView::~CBatchRenameFileView()
{
}

void CBatchRenameFileView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADDFILEBUT, m_wndAddFile);
	DDX_Control(pDX, IDC_TREEFILE, m_wndFileTree);
}

BEGIN_MESSAGE_MAP(CBatchRenameFileView, CFormView)
	ON_BN_CLICKED(IDC_ADDFILEBUT, &CBatchRenameFileView::OnBnClickedAddfilebut)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CBatchRenameFileView 诊断

#ifdef _DEBUG
void CBatchRenameFileView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBatchRenameFileView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBatchRenameFileView 消息处理程序


// 增加文件按钮事件
void CBatchRenameFileView::OnBnClickedAddfilebut()
{
	TCHAR szFolderPath[MAX_PATH] = { 0 };
	CString strFolderPath;

	BROWSEINFO sInfo;
	::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T("请选择处理结果存储路径");
	sInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX | BIF_DONTGOBELOWDOMAIN;
	sInfo.lpfn = NULL;

	// 显示文件夹选择对话框  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidlBrowse != NULL)
	{
		// 取得文件夹名  
		if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath))
		{
			strFolderPath = szFolderPath;
		}
	}
	if (lpidlBrowse != NULL)
	{
		::CoTaskMemFree(lpidlBrowse);
	}

}



int CBatchRenameFileView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;




	return 0;
}


void CBatchRenameFileView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();


	HTREEITEM hRoot;
	hRoot = m_wndFileTree.InsertItem(_T("111111"));
}


void CBatchRenameFileView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	

}
