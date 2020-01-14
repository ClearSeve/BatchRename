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

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_wndAddFile;
	afx_msg void OnBnClickedAddfilebut();
	CTreeCtrl m_wndFileTree;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);



};


