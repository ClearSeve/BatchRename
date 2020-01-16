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

	// TODO: 内存泄漏
	CImageList m_imageFileList;
	vector<SUFFIXIMAGE> m_vSuffixImage;



public:
	vector<FILEINFO> m_vFilePathList;

	void fileTraversal(vector<FILEINFO>& vFilePathList, CString strDir);
	HICON getFileIcon(CString extention);
	HICON getFolderIcon();
public:
	// 在m_vSuffixImage中查找指定后缀的图标
	UINT findImageFileLis(CString strSuffix);
	// 获取文件后缀名称
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

