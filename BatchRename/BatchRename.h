
// BatchRename.h : BatchRename Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CBatchRenameApp:
// �йش����ʵ�֣������ BatchRename.cpp
//

class CBatchRenameApp : public CWinApp
{
public:
	CBatchRenameApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBatchRenameApp theApp;
