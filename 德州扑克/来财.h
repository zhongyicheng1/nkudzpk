#pragma once
#include "afxdialogex.h"


// 来财 对话框

class 来财 : public CDialogEx
{
	DECLARE_DYNAMIC(来财)

public:
	来财(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~来财();
	CString m_strInput; // 用于存储编辑框输入的字符串

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_laicai };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog(); // 初始化对话框
	afx_msg void OnBnClickedButtonOk();
};
