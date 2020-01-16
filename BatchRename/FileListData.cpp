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
	BOOL isNotEmpty = finder.FindFile(strDir + _T("*.*"));//���ļ��У���ʼ���� 
	while (isNotEmpty)
	{
		isNotEmpty = finder.FindNextFile();//�����ļ� 
		CString filename = finder.GetFilePath();//��ȡ�ļ���·�����������ļ��У��������ļ� 
		if (!(finder.IsDirectory()))
		{
			FILEINFO info;
			info.strName = finder.GetFileName();
			info.strType = _T(".") + getPathSuffix(info.strName);
			info.strPath = filename;

			//���ļ�·���������� 
			vFilePathList.push_back(info);

		}
		else
		{
			//�ݹ�����û��ļ��У��������û��ļ��� 
			if (!(finder.IsDots() || finder.IsHidden() || finder.IsSystem() || finder.IsTemporary() || finder.IsReadOnly()))
			{
				fileTraversal(vFilePathList, filename + _T("/"));

				// ��·���������� 
				FILEINFO info;
				info.strName = finder.GetFileName();
				info.strType = _T("�ļ���");
				info.strPath = filename;
				vFilePathList.push_back(info);
			}

		}
	}
}

// ��ȡ�ļ�ͼ��
HICON CFileListData::getFileIcon(CString extention)
{
	// ͼ�������.��ͷ
	HICON icon = NULL;
	SHFILEINFO info;
	if (SHGetFileInfo(extention, FILE_ATTRIBUTE_NORMAL, &info, sizeof(info), SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
	{
		icon = info.hIcon;
	}
	return icon;
}



// ��ȡ�ļ���ͼ��
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

// ��m_vSuffixImage�в���ָ����׺��ͼ��
UINT CFileListData::findImageFileLis(CString strSuffix)
{
	UINT nImageId = 0;

	if (strSuffix.Compare(_T("�ļ���")) == 0){
		return 0;
	}

	// �ڶ����в����Ƿ���ڸú�׺��ͼ��
	for (UINT i = 0; i < m_vSuffixImage.size(); i++)
	{
		if (m_vSuffixImage.at(i).strSuffix.Compare(strSuffix) == 0){
			nImageId = m_vSuffixImage.at(i).nIconId;
			break;
		}
	}

	// δ�ҵ�����
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

// ��ȡ�ļ���׺����
CString CFileListData::getPathSuffix(CString fileName)
{
	int pos = fileName.Find(_T(".")); //��ȡ. ��λ��
	if (pos == -1){ //���û���ҵ���ֱ�ӷ��ظ��ַ���
		return fileName;
	}
	else{
		return getPathSuffix(fileName.Mid(pos + 1)); //�ҵ��˵Ļ�������������ֱ����ײ�
	}
}