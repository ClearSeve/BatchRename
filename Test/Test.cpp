// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Test.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;


void fileTraversal(vector<CString>& vFilePathList, CString strDir)
{

	CFileFind finder;
	BOOL isNotEmpty = finder.FindFile(strDir + _T("*.*"));//���ļ��У���ʼ���� 
	while (isNotEmpty)
	{
		isNotEmpty = finder.FindNextFile();//�����ļ� 
		CString filename = finder.GetFilePath();//��ȡ�ļ���·�����������ļ��У��������ļ� 
		if (!(finder.IsDirectory()))
		{
			//���ļ�·���������� 
			vFilePathList.push_back(filename);
		}
		else
		{
			//�ݹ�����û��ļ��У��������û��ļ��� 
			if (!(finder.IsDots() || finder.IsHidden() || finder.IsSystem() || finder.IsTemporary() || finder.IsReadOnly()))
			{
				fileTraversal(vFilePathList, filename + _T("/"));
				//��·���������� 
				vFilePathList.push_back(filename);
			}

		}
	}
}


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����:  MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			
			Find(_T("C:\\Users\\ClearSeve\\Desktop\\AIUIChatDemo\\*.*"));

		}
	}
	else
	{
		// TODO:  ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����:  GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
