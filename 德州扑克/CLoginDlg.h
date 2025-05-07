#pragma once
#include "afxdialogex.h"
#include<string>
#include"pch.h"
#include "resource.h"
#include"玩家.h"
// CLoginDlg 对话框

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 用户名
	CString m_strUserName;
	CString m_strPassword;
	afx_msg bool ValidateUser( CString& username,  CString& password);
	afx_msg void RegisterUser( CString& username,  CString& password);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	std::vector<player*>players;
};
