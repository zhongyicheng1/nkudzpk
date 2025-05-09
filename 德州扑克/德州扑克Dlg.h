#include"CLoginDlg.h"
// 德州扑克Dlg.h: 头文件
//
#include"玩家.h"
#include"牌类.h"
#include"card.h"
#include"运行.h"


#pragma once


// C德州扑克Dlg 对话框
class C德州扑克Dlg : public CDialogEx
{
// 构造
public:
	C德州扑克Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	CBitmap m_BackgroundBitmap;


public:
	player* m_pCurrentPlayer = nullptr;  // 当前登录的玩家
	CButton m_showPlayerInfoButton;       // 玩家信息按钮
	afx_msg void On32775();
	CLoginDlg dlg;
	bool simulateGame(const std::vector<card>& playerHand,const std::vector<card>& communityCards);
	double monteCarloSimulation(const std::vector<card>& playerHand, const std::vector<card>& communityCards);
	Cpoker poker1;
	Cpoker poker2;
	std::vector<card> player1Cards;
	std::vector<card> player2Cards;
	std::vector<card> communityCards;
	CImage m_images[54]; // 存储所有牌的图片
	CImage* m_communityCardsImages[5]; // 存储公共牌的图片指针
	int GetCardIndex(const card& c);
	CImage m_backgroundImage; // 背景图
	player playercomputer;
	int allchips;
	void again();
	bool turn1 = false;
	bool turn2 = false;
	CString printCards(std::vector<card>& cards);
	afx_msg void OnBnClickedShowPlayerInfo();
	afx_msg void On发底牌();
	afx_msg void On显示自己的底牌();
	afx_msg void On发三张翻牌();
	afx_msg void 发一张转牌();
	afx_msg void On发一张河牌();
	afx_msg void On加注();
	afx_msg void On跟注();
	afx_msg void OnALLIN();
	afx_msg void On过牌1();
	afx_msg void On弃牌();
	afx_msg void On重开();
	
	afx_msg void On32798();
	afx_msg void On偷看();
	afx_msg void 查看奖池();
};
