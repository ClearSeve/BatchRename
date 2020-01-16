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
	DDX_Control(pDX, IDC_LISTFILE, m_wndFileList);
}

BEGIN_MESSAGE_MAP(CBatchRenameFileView, CFormView)
	ON_WM_SIZE()
	ON_NOTIFY(LVN_GETDISPINFO, IDC_LISTFILE, &CBatchRenameFileView::OnLvnGetdispinfoListfile)
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



void CBatchRenameFileView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	if (TRUE == m_bIsInit)
		return;

	m_bIsInit = TRUE;

	//m_imageFileList.Create(16, 16, ILC_COLOR32, 10, 1);
	//m_imageFileList.Add(getFolderIcon());


	m_wndFileList.InsertColumn(0, _T("文件名"), LVCFMT_LEFT, 200);
	m_wndFileList.InsertColumn(1, _T("替换后"), LVCFMT_LEFT, 100);
	m_wndFileList.InsertColumn(2, _T("大小"), LVCFMT_LEFT, 100);
	m_wndFileList.InsertColumn(3, _T("类型"), LVCFMT_LEFT, 100);
	m_wndFileList.InsertColumn(4, _T("路径"), LVCFMT_LEFT, 500);
	m_wndFileList.InsertColumn(5, _T("状态"), LVCFMT_LEFT, 50);

	//m_wndFileList.SetImageList(&m_imageFileList, LVSIL_SMALL);

	m_wndFileList.SetExtendedStyle(m_wndFileList.GetExtendedStyle() | LVS_EX_SUBITEMIMAGES);


	//fileTraversal(m_vFilePathList, _T("C:\\Users\\ClearSeve\\Desktop\\AIUIChatDemo\\"));
	//for (UINT i = 0; i < m_vFilePathList.size(); ++i)
	//{
	//	UINT nImageId = findImageFileLis(m_vFilePathList.at(i).strType);
	//	UINT nItem = m_wndFileList.InsertItem(0, m_vFilePathList.at(i).strName, nImageId);
	//	//
	//	//m_wndFileList.SetItemText(nItem, 3, vFilePathList.at(i).strType);
	//	//m_wndFileList.SetItemText(nItem, 4, vFilePathList.at(i).strPath);
	//}

	// 设置数量
	//m_wndFileList.SetItemCount(m_vFilePathList.size());


}


void CBatchRenameFileView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	if (m_bIsInit)
	{
		m_wndFileList.SetWindowPos(NULL, 0, 0, cx + 1, cy + 1, SWP_NOMOVE);

	}
}



void CBatchRenameFileView::OnLvnGetdispinfoListfile(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	LV_DISPINFO* pDispInfo1 = (LV_DISPINFO*)pNMHDR;
	LV_ITEM* pItem = &(pDispInfo1)->item;
	int iItemIndex = pItem->iItem;
	if (pDispInfo1->item.mask & LVIF_TEXT)
	{
		//switch (pItem->iSubItem)
		//{
		//case 0://第0列
		//	lstrcpy(pItem->pszText, m_vFilePathList.at(pItem->iItem).strName);
		//	//m_wndFileList.SetItemText(nItem, 3, );
		//	pItem->iImage = 0;
		//	break;
		//case 1: //第一列
		//	
		//	break;
		//case 3:
		//	lstrcpy(pItem->pszText, m_vFilePathList.at(pItem->iItem).strType);
		//	break;
		//case 4:
		//	lstrcpy(pItem->pszText, m_vFilePathList.at(pItem->iItem).strPath);
		//	break;
		//}
	}
	
	// 错误
	//if (pDispInfo1->item.mask & LVIF_IMAGE)
	//{
	//	pItem->iImage = 0;
	//}


	*pResult = 0;
}
