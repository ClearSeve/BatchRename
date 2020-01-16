#pragma once
#include "afxwin.h"


// CSelectFolderDialog 对话框

class CSelectFolderDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectFolderDialog)

public:
	CSelectFolderDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectFolderDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_SELECT_FOLDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_wndSelectFolder;
	afx_msg void OnBnClickedSelectFolder();
	CEdit m_wndEditPath;
};
