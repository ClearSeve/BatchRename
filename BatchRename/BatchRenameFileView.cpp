// BatchRenameFileView.cpp : ʵ���ļ�
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
}

BEGIN_MESSAGE_MAP(CBatchRenameFileView, CFormView)
END_MESSAGE_MAP()


// CBatchRenameFileView ���

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


// CBatchRenameFileView ��Ϣ�������
