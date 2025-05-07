// CLoginDlg.cpp: 实现文件
//
#include<fstream>
#include "pch.h"
#include "德州扑克.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"
#include"德州扑克Dlg.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);  // 关联用户名编辑框
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);  // 关联密码编辑框
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序
bool CLoginDlg::ValidateUser( CString& username, CString& password)
{
	std::wifstream ifs;
	ifs.open(L"users12345", std::ios::binary);
	if (ifs.is_open()) {
		std::wstring storedUsername, storedPassword;
		while (ifs >> storedUsername >> storedPassword)
		{
			if (CString(storedUsername.c_str()) == username && CString(storedPassword.c_str()) == password)
			{
				ifs.close();
				return true;
			}

		}

		ifs.close();
		return false;
	}
	else {
		AfxMessageBox(_T("无法打开文件进行读取！"), MB_OK | MB_ICONERROR);
		return false;
	}
			
}

void CLoginDlg::RegisterUser( CString& username, CString& password)
{
	std::wofstream ifs;
	ifs.open(L"users12345",ios::app | std::ios::binary);
	if (ifs.is_open()) {
		ifs << username.GetString()<< L" " << password.GetString() << std::endl;
		ifs.close();
		AfxMessageBox(_T("注册成功！"), MB_OK | MB_ICONINFORMATION);
	}
	else {
		AfxMessageBox(_T("无法打开文件进行写入！"), MB_OK | MB_ICONERROR);
	}
	Invalidate();
}

void CLoginDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);  
	if (m_strUserName.IsEmpty() || m_strPassword.IsEmpty()) {
		MessageBox(_T("用户名或密码不能为空！"), _T("错误"), MB_OK | MB_ICONERROR);
		return;
	}
	if (ValidateUser(m_strUserName, m_strPassword)) {
		MessageBox(_T("登录成功！"), _T("提示"), MB_OK | MB_ICONINFORMATION);
		string a = CW2A(m_strUserName);
		string b = CW2A(m_strPassword);
		player* pPlayer = new player(a, b);
		players.push_back(pPlayer);
		C德州扑克Dlg* pMainDlg = (C德州扑克Dlg*)AfxGetMainWnd();
		if (pMainDlg) {
			// 更新主对话框的当前玩家指针
			pMainDlg->m_pCurrentPlayer = pPlayer;
		}

		EndDialog(IDOK); 
	}
	else {
		MessageBox(_T("用户名或密码错误！"), _T("错误"), MB_OK | MB_ICONERROR);
	}
}
	// TODO: 在此添加控件通知处理程序代码


void CLoginDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);  // 从控件获取数据

	if (m_strUserName.IsEmpty() || m_strPassword.IsEmpty()) {
		AfxMessageBox(_T("用户名或密码不能为空！"), MB_OK | MB_ICONERROR);
		return;
	}

	if (ValidateUser(m_strUserName, m_strPassword)){
		AfxMessageBox(_T("用户名已存在！"), MB_OK | MB_ICONERROR);
		return;
	}

	RegisterUser(m_strUserName, m_strPassword);
	string a = CW2A(m_strUserName);
	string b = CW2A(m_strPassword);
	player* pPlayer = new player(a,b);
	players.push_back(pPlayer);
}

	// TODO: 在此添加控件通知处理程序代码 
