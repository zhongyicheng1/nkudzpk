// 来财.cpp: 实现文件
//

#include "pch.h"
#include "德州扑克.h"
#include "afxdialogex.h"
#include "来财.h"


// 来财 对话框

IMPLEMENT_DYNAMIC(来财, CDialogEx)

来财::来财(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_laicai, pParent)
{

}

来财::~来财()
{
}

void 来财::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput); // 关联编辑框
}

BOOL 来财::OnInitDialog()
{
	return 0;
}




BEGIN_MESSAGE_MAP(来财, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &来财::OnBnClickedButtonOk)
END_MESSAGE_MAP()


// 来财 消息处理程序

void 来财::OnBnClickedButtonOk()
{
	UpdateData(TRUE); 
	if (m_strInput.IsEmpty()) {
		AfxMessageBox(_T("不能输入为空,请输入来财"), MB_OK | MB_ICONERROR);
		
	}
	else if (m_strInput == "来财") {
		OnOK();
	}
	else { 
		AfxMessageBox(_T("请输入来财,请输入来财"), MB_OK | MB_ICONERROR);
	}
	// TODO: 在此添加控件通知处理程序代码
}
