// SelectFolderDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BatchRename.h"
#include "SelectFolderDialog.h"
#include "afxdialogex.h"


// CSelectFolderDialog �Ի���

IMPLEMENT_DYNAMIC(CSelectFolderDialog, CDialogEx)

CSelectFolderDialog::CSelectFolderDialog(CWnd* pParent /*=NULL*/)
: CDialogEx(CSelectFolderDialog::IDD, pParent)
{

}

CSelectFolderDialog::~CSelectFolderDialog()
{
}

void CSelectFolderDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_SELECT_FOLDER, m_wndSelectFolder);
	DDX_Control(pDX, IDC_EDITPATH, m_wndEditPath);
}


BEGIN_MESSAGE_MAP(CSelectFolderDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_FOLDER, &CSelectFolderDialog::OnBnClickedSelectFolder)
END_MESSAGE_MAP()


// CSelectFolderDialog ��Ϣ�������
int CALLBACK SHBrowseForFolderCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
// Ĭ��Ŀ¼
static CString strDef = _T("");
void CSelectFolderDialog::OnBnClickedSelectFolder()
{
	// ѡ���ļ�Ŀ¼
	TCHAR szPath[MAX_PATH] = { 0 };
	BROWSEINFO br = {};

	br.hwndOwner = this->GetSafeHwnd();
	br.lpszTitle = _T("ѡ��·��");
	br.ulFlags = BIF_STATUSTEXT | BIF_NEWDIALOGSTYLE;
	//����CALLBACK����
	br.lpfn = SHBrowseForFolderCallbackProc;
	LPITEMIDLIST lpidlBrowse = SHBrowseForFolder(&br);
	if (lpidlBrowse != NULL &&SHGetPathFromIDList(lpidlBrowse, szPath))
	{
		// ��������һ���ϴ�ѡ���Ŀ¼
		strDef = szPath;
		m_wndEditPath.SetWindowText(strDef);
		CoTaskMemFree(lpidlBrowse);

	}
}

// �ص�����
int CALLBACK SHBrowseForFolderCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch (uMsg)
	{
	case BFFM_INITIALIZED:    //��ʼ����ϢBFFM_INITIALIZED
		::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)strDef.AllocSysString());   //����Ĭ�ϴ�·�� break;
		break;
	default:
		break;
	}
	return 0;
}