#pragma once
#include "afxwin.h"


// CSelectFolderDialog �Ի���

class CSelectFolderDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectFolderDialog)

public:
	CSelectFolderDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectFolderDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_SELECT_FOLDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CButton m_wndSelectFolder;
	afx_msg void OnBnClickedSelectFolder();
	CEdit m_wndEditPath;
};
