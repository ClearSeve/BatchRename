#pragma once

#include <vector>
using namespace std;

class CFileListData
{
public:
	CFileListData();
	~CFileListData();

public:
	struct SUFFIXIMAGE;
	struct FILEINFO;
public:

	// TODO: �ڴ�й©
	CImageList m_imageFileList;
	vector<SUFFIXIMAGE> m_vSuffixImage;



public:
	vector<FILEINFO> m_vFilePathList;

	void fileTraversal(vector<FILEINFO>& vFilePathList, CString strDir);
	HICON getFileIcon(CString extention);
	HICON getFolderIcon();
public:
	// ��m_vSuffixImage�в���ָ����׺��ͼ��
	UINT findImageFileLis(CString strSuffix);
	// ��ȡ�ļ���׺����
	CString getPathSuffix(CString fileName);



public:
	struct SUFFIXIMAGE
	{
		CString strSuffix;
		UINT    nIconId;
	};

	struct FILEINFO
	{
		CString strName;
		CString strNewName;
		CString strSize;
		CString strType;
		CString strPath;
		CString strState;
	};
};

