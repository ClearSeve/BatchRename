#pragma once



// COperatorView ������ͼ

class COperatorView : public CFormView
{
	DECLARE_DYNCREATE(COperatorView)

protected:
	COperatorView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~COperatorView();

public:
	enum { IDD = IDD_OPERATORVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


