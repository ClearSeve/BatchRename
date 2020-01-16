// OperatorView.cpp : 实现文件
//

#include "stdafx.h"
#include "BatchRename.h"
#include "OperatorView.h"


// COperatorView

IMPLEMENT_DYNCREATE(COperatorView, CFormView)

COperatorView::COperatorView()
	: CFormView(COperatorView::IDD)
{

}

COperatorView::~COperatorView()
{
}

void COperatorView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COperatorView, CFormView)
END_MESSAGE_MAP()


// COperatorView 诊断

#ifdef _DEBUG
void COperatorView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void COperatorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// COperatorView 消息处理程序
