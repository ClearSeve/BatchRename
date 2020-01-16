#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CBatchRenameFileView 窗体视图

class CBatchRenameFileView : public CFormView
{
	DECLARE_DYNCREATE(CBatchRenameFileView)

public:
	CBatchRenameFileView();           // 动态创建所使用的受保护的构造函数
	virtual ~CBatchRenameFileView();

public:
	enum { IDD = IDD_FILEVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
public:


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL m_bIsInit = FALSE;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddfilebut();
	virtual void OnInitialUpdate();
	CListCtrl m_wndFileList;

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLvnGetdispinfoListfile(NMHDR *pNMHDR, LRESULT *pResult);
};




