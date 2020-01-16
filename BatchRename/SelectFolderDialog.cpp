// SelectFolderDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "BatchRename.h"
#include "SelectFolderDialog.h"
#include "afxdialogex.h"


// CSelectFolderDialog 对话框

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


// CSelectFolderDialog 消息处理程序
int CALLBACK SHBrowseForFolderCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
// 默认目录
static CString strDef = _T("");
void CSelectFolderDialog::OnBnClickedSelectFolder()
{
	// 选择文件目录
	TCHAR szPath[MAX_PATH] = { 0 };
	BROWSEINFO br = {};

	br.hwndOwner = this->GetSafeHwnd();
	br.lpszTitle = _T("选择路径");
	br.ulFlags = BIF_STATUSTEXT | BIF_NEWDIALOGSTYLE;
	//设置CALLBACK函数
	br.lpfn = SHBrowseForFolderCallbackProc;
	LPITEMIDLIST lpidlBrowse = SHBrowseForFolder(&br);
	if (lpidlBrowse != NULL &&SHGetPathFromIDList(lpidlBrowse, szPath))
	{
		// 重新设置一下上次选择的目录
		strDef = szPath;
		m_wndEditPath.SetWindowText(strDef);
		CoTaskMemFree(lpidlBrowse);

	}
}

// 回调函数
int CALLBACK SHBrowseForFolderCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch (uMsg)
	{
	case BFFM_INITIALIZED:    //初始化消息BFFM_INITIALIZED
		::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)strDef.AllocSysString());   //传递默认打开路径 break;
		break;
	default:
		break;
	}
	return 0;
}