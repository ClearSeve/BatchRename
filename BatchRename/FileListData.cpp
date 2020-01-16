#include "stdafx.h"
#include "FileListData.h"


CFileListData::CFileListData()
{
}


CFileListData::~CFileListData()
{
}


void CFileListData::fileTraversal(vector<FILEINFO>& vFilePathList, CString strDir)
{

	CFileFind finder;
	BOOL isNotEmpty = finder.FindFile(strDir + _T("*.*"));//总文件夹，开始遍历 
	while (isNotEmpty)
	{
		isNotEmpty = finder.FindNextFile();//查找文件 
		CString filename = finder.GetFilePath();//获取文件的路径，可能是文件夹，可能是文件 
		if (!(finder.IsDirectory()))
		{
			FILEINFO info;
			info.strName = finder.GetFileName();
			info.strType = _T(".") + getPathSuffix(info.strName);
			info.strPath = filename;

			//将文件路径加入容器 
			vFilePathList.push_back(info);

		}
		else
		{
			//递归遍历用户文件夹，跳过非用户文件夹 
			if (!(finder.IsDots() || finder.IsHidden() || finder.IsSystem() || finder.IsTemporary() || finder.IsReadOnly()))
			{
				fileTraversal(vFilePathList, filename + _T("/"));

				// 将路径加入容器 
				FILEINFO info;
				info.strName = finder.GetFileName();
				info.strType = _T("文件夹");
				info.strPath = filename;
				vFilePathList.push_back(info);
			}

		}
	}
}

// 获取文件图标
HICON CFileListData::getFileIcon(CString extention)
{
	// 图标必须以.开头
	HICON icon = NULL;
	SHFILEINFO info;
	if (SHGetFileInfo(extention, FILE_ATTRIBUTE_NORMAL, &info, sizeof(info), SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
	{
		icon = info.hIcon;
	}
	return icon;
}



// 获取文件夹图标
HICON CFileListData::getFolderIcon()
{
	HICON icon = NULL;
	SHFILEINFO info;
	if (SHGetFileInfo(_T("folder"), FILE_ATTRIBUTE_DIRECTORY, &info, sizeof(info), SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
	{
		icon = info.hIcon;
	}
	return icon;
}

// 在m_vSuffixImage中查找指定后缀的图标
UINT CFileListData::findImageFileLis(CString strSuffix)
{
	UINT nImageId = 0;

	if (strSuffix.Compare(_T("文件夹")) == 0){
		return 0;
	}

	// 在队列中查找是否存在该后缀的图标
	for (UINT i = 0; i < m_vSuffixImage.size(); i++)
	{
		if (m_vSuffixImage.at(i).strSuffix.Compare(strSuffix) == 0){
			nImageId = m_vSuffixImage.at(i).nIconId;
			break;
		}
	}

	// 未找到增加
	if (nImageId == 0)
	{
		SUFFIXIMAGE SuffixImage;
		SuffixImage.nIconId = m_imageFileList.Add(getFileIcon(strSuffix));
		SuffixImage.strSuffix = strSuffix;
		m_vSuffixImage.push_back(SuffixImage);
		return SuffixImage.nIconId;
	}

	return nImageId;
}

// 获取文件后缀名称
CString CFileListData::getPathSuffix(CString fileName)
{
	int pos = fileName.Find(_T(".")); //获取. 的位置
	if (pos == -1){ //如果没有找到，直接返回该字符串
		return fileName;
	}
	else{
		return getPathSuffix(fileName.Mid(pos + 1)); //找到了的话，往深层遍历，直到最底层
	}
}