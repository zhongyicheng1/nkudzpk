//
// 德州扑克Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "德州扑克.h"
#include "德州扑克Dlg.h"
#include "afxdialogex.h"
#include"来财.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:


};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)


END_MESSAGE_MAP()


// C德州扑克Dlg 对话框

C德州扑克Dlg::C德州扑克Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent), allchips(0) // 初始化 allchips
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	memset(m_communityCardsImages, 0, sizeof(m_communityCardsImages)); // 初始化 m_communityCardsImages
}

void C德州扑克Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C德州扑克Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C德州扑克Dlg::OnBnClickedButton1)
	ON_COMMAND(ID_32775, &C德州扑克Dlg::On32775)
	ON_BN_CLICKED(IDC_SHOW_PLAYER_INFO, &C德州扑克Dlg::OnBnClickedShowPlayerInfo)
	ON_COMMAND(ID_32780, &C德州扑克Dlg::On发底牌)
	ON_COMMAND(ID_32786, &C德州扑克Dlg::On显示自己的底牌)
	ON_COMMAND(ID_32781, &C德州扑克Dlg::On发三张翻牌)
	ON_COMMAND(ID_32782, &C德州扑克Dlg::发一张转牌)
	ON_COMMAND(ID_32783, &C德州扑克Dlg::On发一张河牌)
	ON_COMMAND(ID_32791, &C德州扑克Dlg::On加注)
	ON_COMMAND(ID_32792, &C德州扑克Dlg::On跟注)
	ON_COMMAND(ID_32793, &C德州扑克Dlg::OnALLIN)
	ON_COMMAND(ID_32794, &C德州扑克Dlg::On过牌1)
	ON_COMMAND(ID_32795, &C德州扑克Dlg::On弃牌)
	ON_COMMAND(ID_32797, &C德州扑克Dlg::On重开)
	ON_COMMAND(ID_32798, &C德州扑克Dlg::On32798)
	ON_COMMAND(ID_32799, &C德州扑克Dlg::On偷看)
	ON_COMMAND(ID_32801, &C德州扑克Dlg::查看奖池)
	ON_COMMAND(ID_32776, &C德州扑克Dlg::On32776)
END_MESSAGE_MAP()


// C德州扑克Dlg 消息处理程序

BOOL C德州扑克Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	dlg.DoModal();
	m_showPlayerInfoButton.SubclassDlgItem(IDC_SHOW_PLAYER_INFO, this);
	m_showPlayerInfoButton.EnableWindow(FALSE);  // 初始状态为不可用
	static const UINT cardResourceIDs[] = {
	IDB_card1, IDB_card2, IDB_card3, IDB_card4,
	IDB_card5, IDB_card6, IDB_card7, IDB_card8, IDB_card9,
	IDB_card10, IDB_card11, IDB_card12, IDB_card13, IDB_card14,
	IDB_card15, IDB_card16, IDB_card17, IDB_card18, IDB_card19,
	IDB_card20, IDB_card21, IDB_card22, IDB_card23, IDB_card24,
	IDB_card25, IDB_card26, IDB_card27, IDB_card28, IDB_card29,
	IDB_card30, IDB_card31, IDB_card32, IDB_card33, IDB_card34,
	IDB_card35, IDB_card36, IDB_card37, IDB_card38, IDB_card39,
	IDB_card40, IDB_card41, IDB_card42, IDB_card43, IDB_card44,
	IDB_card45, IDB_card46, IDB_card47, IDB_card48, IDB_card49,
	IDB_card50, IDB_card51, IDB_card52,IDB_BITMAP3,IDB_BITMAP2
	};
	HBITMAP hBackground = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
	m_backgroundImage.Attach(hBackground);
	for (int i = 0; i <= 52; ++i)
	{
		HBITMAP hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(cardResourceIDs[i]), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
		if (hBitmap == nullptr)
		{
			AfxMessageBox(_T("无法加载图片！"));
			return FALSE;
		}
		m_images[i].Attach(hBitmap);
	}
	CMenu* pMenu = GetMenu();
	if (pMenu) {
		pMenu->EnableMenuItem(ID_32791, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32792, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32793, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32795, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32799, MF_BYCOMMAND | MF_GRAYED);
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C德州扑克Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C德州扑克Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else {
		CPaintDC dc(this);

		// 绘制背景图
		CRect rect;
		GetClientRect(&rect);
		m_backgroundImage.Draw(dc.GetSafeHdc(), rect);
		CRect cardRects[5] = {
		{90, 150, 180, 290}, // 第一张牌的位置
		{190, 150, 275, 290}, // 第二张牌的位置
		{285, 150, 370, 290}, // 第三张牌的位置
		{380, 150, 465, 290}, // 第四张牌的位置
		{475, 150, 560, 290}  // 第五张牌的位置
		};
		for (int i = 0; i < 5; ++i)
		{
			if (m_communityCardsImages[i] != nullptr)
			{
				m_communityCardsImages[i]->Draw(dc.GetSafeHdc(), cardRects[i]);
				
			}
		}
	}
	CDialogEx::OnPaint();
}


//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C德州扑克Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void C德州扑克Dlg::OnBnClickedButton1()
{

	// TODO: 在此添加控件通知处理程序代码
}

void C德州扑克Dlg::On32775()//菜单的开始
{
	HBITMAP hBackground = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
	if (hBackground == nullptr)
	{
		AfxMessageBox(_T("无法加载背景图！"));
		return;
	}
	m_backgroundImage.Destroy(); // 确保销毁旧的背景图
	m_backgroundImage.Attach(hBackground);
	Invalidate();
	//确保按钮显示在图片之上
	m_showPlayerInfoButton.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	// 启用按钮
	m_showPlayerInfoButton.EnableWindow(TRUE);
}
bool C德州扑克Dlg::simulateGame(const std::vector<card>& playerHand, const std::vector<card>& communityCards)
{
	poker2.cards.clear();//清空牌组;
	for (int suit = 0; suit < 4; suit++) {
		for (int rank = 2; rank <= 14; rank++) {
			poker2.cards.push_back({ suit, rank });
		}
	}
	std::vector<card> opponentHand;
	std::vector<card>myHand;
	std::vector<card>  communityCards12;
	for (auto it = poker2.cards.begin(); it != poker2.cards.end();) {
		if (!(std::find(playerHand.begin(), playerHand.end(), *it) == playerHand.end() &&
			std::find(communityCards.begin(), communityCards.end(), *it) == communityCards.end())) {
			it = poker2.cards.erase(it);
		}
		else {
			++it;
		}
	}
	for (int i = 0; i < communityCards.size(); i++) {
		communityCards12.push_back(communityCards[i]);
	}
	if ((int)communityCards.size() < 5) {
		poker2.Fisher_Yates(poker2.cards);
		poker2.deliverCards(5 - communityCards.size(), communityCards12);
	}
	poker2.deliverCards(2, opponentHand);
	myHand.push_back(playerHand[0]);
	myHand.push_back(playerHand[1]);
	for (int i = 0; i < 5; i++) {
		myHand.push_back(communityCards12[i]);
		opponentHand.push_back(communityCards12[i]);
	}
	bool d = compairhandtype(myHand, opponentHand);

	return d;
}
double C德州扑克Dlg::monteCarloSimulation(const std::vector<card>& playerHand, const std::vector<card>& communityCards)
{
	int winCount = 0;
	for (int i = 0; i < 10000; ++i) {
		if (simulateGame(playerHand, communityCards)) {
			++winCount;
		}
	}
	return static_cast<double>(winCount) / 10000;
}
// TODO: 在此添加命令处理程序代码





int C德州扑克Dlg::GetCardIndex(const card& c)
{
	if (c.rank == 14) {
		return c.suit * 13 + 1;
	}
	else {
		return c.suit * 13 + c.rank;
	}
}


void C德州扑克Dlg::again()
{
	poker1.cards.clear();//清空牌组;
	for (int suit = 0; suit < 4; suit++) {
		for (int rank = 2; rank <= 14; rank++) {
			poker1.cards.push_back({ suit, rank });
		}
	}
	poker1.Fisher_Yates(poker1.cards);
	communityCards.clear();
	player1Cards.clear();
	player2Cards.clear();
	for (int i = 0; i < 5; ++i) {
		m_communityCardsImages[i] = nullptr; // 假设你有一个数组来显示公共牌
	}
	Invalidate(); // 刷新界面
	allchips = 0;
	m_pCurrentPlayer->isAllIn = false;
	m_pCurrentPlayer->isFolded = false;
	playercomputer.isAllIn = false;
	playercomputer.isFolded = false;
	turn2 = false; 
	CMenu* pMenu = GetMenu();
	pMenu->EnableMenuItem(ID_32780, MF_BYCOMMAND | MF_ENABLED);
	pMenu->EnableMenuItem(ID_32781, MF_BYCOMMAND | MF_ENABLED);
	pMenu->EnableMenuItem(ID_32782, MF_BYCOMMAND | MF_ENABLED);
	pMenu->EnableMenuItem(ID_32783, MF_BYCOMMAND | MF_ENABLED);
	if (playercomputer.chips < 0) {
		AfxMessageBox(_T("恭喜你已经成功击败电脑"), MB_OK );
	}
}

CString C德州扑克Dlg::printCards(std::vector<card>& cards)
{

	CString result;
	for (const auto& c : cards) {
		CString suit;
		switch (c.suit) {
		case 0: suit = _T("\u2660"); break; // 黑桃
		case 1: suit = _T("\u2665"); break; // 红心
		case 2: suit = _T("\u2663"); break; // 梅花
		case 3: suit = _T("\u2666"); break; // 方块
		}

		CString rank;
		switch (c.rank) {
		case 14: rank = _T("A"); break;
		case 11: rank = _T("J"); break;
		case 12: rank = _T("Q"); break;
		case 13: rank = _T("K"); break;
		default: rank.Format(_T("%d"), c.rank); break;
		}

		result += rank + suit + _T(" ");
	}
	return result;
}

void C德州扑克Dlg::OnBnClickedShowPlayerInfo()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pCurrentPlayer) {
		// 显示玩家信息
		CString strMessage;
		strMessage.Format(_T("Player Name: %s\nChips: %d"),
			m_pCurrentPlayer->playerName.c_str(), m_pCurrentPlayer->chips);
		MessageBox(strMessage, _T("Player Info"), MB_OK | MB_ICONINFORMATION);
	}
	else {
		MessageBox(_T("No player is logged in."), _T("Error"), MB_OK | MB_ICONERROR);
	}
}


void C德州扑克Dlg::On发底牌()
{
	poker1.cards.clear();//清空牌组;
	for (int suit = 0; suit < 4; suit++) {
		for (int rank = 2; rank <= 14; rank++) {
			poker1.cards.push_back({ suit, rank });
		}
	}
	poker1.Fisher_Yates(poker1.cards);
	poker1.deliverCards(2, player1Cards);
	poker1.deliverCards(2, player2Cards);


	// TODO: 在此添加命令处理程序代码
	m_pCurrentPlayer->backbet();
	playercomputer.backbet();
	allchips = m_pCurrentPlayer->currentBet + playercomputer.currentBet;
	CMenu* pMenu = GetMenu();
	pMenu->EnableMenuItem(ID_32780, MF_BYCOMMAND | MF_GRAYED);
	pMenu->EnableMenuItem(ID_32799, MF_BYCOMMAND | MF_ENABLED);
}

void C德州扑克Dlg::On显示自己的底牌()
{
	CString a = printCards(player2Cards);
	MessageBox((a), MB_OK);
	// TODO: 在此添加命令处理程序代码
}

void C德州扑克Dlg::On发三张翻牌()
{
	poker1.deliverCards(3, communityCards);
	for (int i = 0; i < 3; ++i) {
		card c = communityCards[i];
		int a = GetCardIndex(c);
		m_communityCardsImages[i] = &m_images[a];
		Invalidate();
	}

	double e = monteCarloSimulation(player1Cards, communityCards);
	if (e > 0.7) {
		if (playercomputer.chips > m_pCurrentPlayer->currentBet * 2) {
			playercomputer.raise(m_pCurrentPlayer->currentBet);
			MessageBox(_T("电脑选择加注"), _T("提示"), MB_OK);
		}
		else {
			playercomputer.AllIn();
			MessageBox(_T("电脑选择Showhand"), _T("提示"), MB_OK);
		}
	}
	else if (e > 0.5) {
		if (playercomputer.chips > m_pCurrentPlayer->currentBet) {
			playercomputer.call(m_pCurrentPlayer->currentBet);
			MessageBox(_T("电脑选择跟注"), _T("提示"), MB_OK);
		}
		else {
			playercomputer.check();
			MessageBox(_T("电脑选择过牌"), _T("提示"), MB_OK);
		}
	}
	else if (e > 0.3) {
		playercomputer.check();
		MessageBox(_T("电脑选择过牌"), _T("提示"), MB_OK);
	}
	else {
		playercomputer.fold();
		MessageBox(_T("电脑选择弃牌"), MB_OK);
	}
	allchips += playercomputer.currentBet;
	if (playercomputer.isFolded == true) {
		MessageBox(_T("玩家胜利"), MB_OK);
		m_pCurrentPlayer->chips += allchips;
		again();
		return;
	}
	CMenu* pMenu = GetMenu();
	if (pMenu) {
		pMenu->EnableMenuItem(ID_32791, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32792, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32793, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32795, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32780, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32781, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32782, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32783, MF_BYCOMMAND | MF_GRAYED);
		
		// TODO: 在此添加命令处理程序代码
	}
}

void C德州扑克Dlg::发一张转牌()
{
	
	if (m_pCurrentPlayer->isAllIn == true) {
		double e = monteCarloSimulation(player1Cards, communityCards);
		if (e >= 0.6) {
			MessageBox(_T("电脑选择跟注"), _T("提示"), MB_OK);
			playercomputer.call(m_pCurrentPlayer->currentBet);
			poker1.deliverCards(1, communityCards);
			card c = communityCards[3];
			int a = GetCardIndex(c);
			m_communityCardsImages[3] = &m_images[a];
			poker1.deliverCards(1, communityCards);
			card d = communityCards[4];
			int e = GetCardIndex(d);
			m_communityCardsImages[4] = &m_images[e];
			Invalidate();
			std::vector<card>playerhand;
			std::vector<card>playerhand1;
			playerhand1.push_back(player2Cards[0]);
			playerhand1.push_back(player2Cards[1]);
			for (int i = 0; i < 5; i++) {
				playerhand1.push_back(communityCards[i]);
			}
			playerhand.push_back(player1Cards[0]);
			playerhand.push_back(player1Cards[1]);
			CString h= printCards(player1Cards);
			MessageBox(_T("电脑底牌为"), (h), MB_OK);
			for (int i = 0; i < 5; i++) {
				playerhand.push_back(communityCards[i]);
			}
			if (evaluate1(playerhand, playerhand1) == 0) {
				MessageBox(_T("电脑胜利"), _T("提示"), MB_OK);
				playercomputer.chips += allchips;
				turn1 = FALSE;
				again();
			}
			else if (evaluate1(playerhand, playerhand1) == 1) {
				MessageBox(_T("玩家胜利"), _T("提示"), MB_OK);
				m_pCurrentPlayer->chips += allchips;
				turn1 = FALSE;
				again();
			}
			else if (evaluate1(playerhand, playerhand1) == 2) {
				MessageBox(_T("平局"), _T("提示"), MB_OK);
				m_pCurrentPlayer->chips += allchips / 2;
				playercomputer.chips += allchips / 2;
				turn1 = FALSE;
				again();
			}
			return;
		}
		else {
			MessageBox(_T("电脑选择弃牌"), _T("提示"), MB_OK);
			playercomputer.fold();
			MessageBox(_T("玩家胜利"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			again();
			return;
		
		}
	}

	poker1.deliverCards(1, communityCards);
	card c = communityCards[3];
	int a = GetCardIndex(c);
	m_communityCardsImages[3] = &m_images[a];
	Invalidate();
	double e = monteCarloSimulation(player1Cards, communityCards);
	if (turn2 == true) {
		if (e > 0.7) {
			if (playercomputer.chips > m_pCurrentPlayer->currentBet * 2) {
				playercomputer.raise(m_pCurrentPlayer->currentBet);
				MessageBox(_T("电脑选择加注"), _T("提示"), MB_OK);
			}
			else {
				playercomputer.AllIn();
				MessageBox(_T("电脑选择Showhand"), _T("提示"), MB_OK);
			}
		}
		else if (e > 0.4) {
			if (playercomputer.chips > m_pCurrentPlayer->currentBet) {
				playercomputer.call(m_pCurrentPlayer->currentBet);
				MessageBox(_T("电脑选择跟注"), _T("提示"), MB_OK);
			}
			else {
				playercomputer.fold();
				MessageBox(_T("电脑选择弃牌"), _T("提示"), MB_OK);
			}
		}
		else {
			playercomputer.fold();
			MessageBox(_T("电脑选择弃牌"), MB_OK);
		}
		allchips += playercomputer.currentBet;
		if (playercomputer.isFolded == true) {
			MessageBox(_T("玩家胜利"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			again();
			return;
		}
	}
	else {
		if (e > 0.7) {
			if (playercomputer.chips > m_pCurrentPlayer->currentBet * 2) {
				playercomputer.raise(m_pCurrentPlayer->currentBet);
				MessageBox(_T("电脑选择加注"), _T("提示"), MB_OK);
			}
			else {
				playercomputer.AllIn();
				MessageBox(_T("电脑选择Showhand"), _T("提示"), MB_OK);
			}
		}
		else if (e > 0.5) {
			if (playercomputer.chips > m_pCurrentPlayer->currentBet) {
				playercomputer.call(m_pCurrentPlayer->currentBet);
				MessageBox(_T("电脑选择跟注"), _T("提示"), MB_OK);
			}
			else {
				playercomputer.check();
				MessageBox(_T("电脑选择过牌"), _T("提示"), MB_OK);
			}
		}
		else if (e > 0.25) {
			playercomputer.check();
			MessageBox(_T("电脑选择过牌"), _T("提示"), MB_OK);
		}
		else {
			playercomputer.fold();
			MessageBox(_T("电脑选择弃牌"), MB_OK);
		}
		allchips += playercomputer.currentBet;
		if (playercomputer.isFolded == true) {
			MessageBox(_T("玩家胜利"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			again();
		}
	}
		CMenu* pMenu = GetMenu();
		if (pMenu) {
			pMenu->EnableMenuItem(ID_32791, MF_BYCOMMAND | MF_ENABLED);
			pMenu->EnableMenuItem(ID_32792, MF_BYCOMMAND | MF_ENABLED);
			pMenu->EnableMenuItem(ID_32793, MF_BYCOMMAND | MF_ENABLED);
			pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_ENABLED);
			pMenu->EnableMenuItem(ID_32795, MF_BYCOMMAND | MF_ENABLED);
			pMenu->EnableMenuItem(ID_32780, MF_BYCOMMAND | MF_GRAYED);
			pMenu->EnableMenuItem(ID_32781, MF_BYCOMMAND | MF_GRAYED);
			pMenu->EnableMenuItem(ID_32782, MF_BYCOMMAND | MF_GRAYED);
			pMenu->EnableMenuItem(ID_32783, MF_BYCOMMAND | MF_GRAYED);

			// TODO: 在此添加命令处理程序代码
		}
	
	// TODO: 在此添加命令处理程序代码
}


void C德州扑克Dlg::On发一张河牌()
{
	
	if (m_pCurrentPlayer->isAllIn == true) {
		double e = monteCarloSimulation(player1Cards, communityCards);
		if (e >= 0.6) {
			MessageBox(_T("电脑选择跟注"), _T("提示"), MB_OK);
			playercomputer.call(m_pCurrentPlayer->currentBet);
			poker1.deliverCards(1, communityCards);
			card c = communityCards[3];
			int a = GetCardIndex(c);
			m_communityCardsImages[3] = &m_images[a];
			poker1.deliverCards(1, communityCards);
			card d = communityCards[4];
			int e = GetCardIndex(d);
			m_communityCardsImages[4] = &m_images[e];
			Invalidate();
			std::vector<card>playerhand;
			std::vector<card>playerhand1;
			playerhand1.push_back(player2Cards[0]);
			playerhand1.push_back(player2Cards[1]);
			for (int i = 0; i < 5; i++) {
				playerhand1.push_back(communityCards[i]);
			}
			playerhand.push_back(player1Cards[0]);
			playerhand.push_back(player1Cards[1]);
			CString h = printCards(player1Cards);
			MessageBox(_T("电脑底牌为"), (h), MB_OK);
			for (int i = 0; i < 5; i++) {
				playerhand.push_back(communityCards[i]);
			}
			if (evaluate1(playerhand, playerhand1) == 0) {
				MessageBox(_T("电脑胜利"), _T("提示"), MB_OK);
				playercomputer.chips += allchips;
				turn1 = FALSE;
				again();
			}
			else if (evaluate1(playerhand, playerhand1) == 1) {
				MessageBox(_T("玩家胜利"), _T("提示"), MB_OK);
				m_pCurrentPlayer->chips += allchips;
				turn1 = FALSE;
				again();
			}
			else if (evaluate1(playerhand, playerhand1) == 2) {
				MessageBox(_T("平局"), _T("提示"), MB_OK);
				m_pCurrentPlayer->chips += allchips / 2;
				playercomputer.chips += allchips / 2;
				turn1 = FALSE;
				again();
			}
			return;
		}
		else {
			MessageBox(_T("电脑选择弃牌"), _T("提示"), MB_OK);
			playercomputer.fold();
			MessageBox(_T("玩家胜利"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			again();
			return;

		}
	}
	poker1.deliverCards(1, communityCards);
	card c = communityCards[4];
	int a = GetCardIndex(c);
	m_communityCardsImages[4] = &m_images[a];
	Invalidate();
	double e = monteCarloSimulation(player1Cards, communityCards);
	if (turn2 == true) {
		if (e > 0.7) {
			if (playercomputer.chips > m_pCurrentPlayer->currentBet * 2) {
				playercomputer.raise(m_pCurrentPlayer->currentBet);
				MessageBox(_T("电脑选择加注"), _T("提示"), MB_OK);
			}
			else {
				playercomputer.AllIn();
				MessageBox(_T("电脑选择Showhand"), _T("提示"), MB_OK);
			}
		}
		else if (e > 0.4) {
			if (playercomputer.chips > m_pCurrentPlayer->currentBet) {
				playercomputer.call(m_pCurrentPlayer->currentBet);
				MessageBox(_T("电脑选择跟注"), _T("提示"), MB_OK);
			}
			else {
				playercomputer.fold();
				MessageBox(_T("电脑选择弃牌"), _T("提示"), MB_OK);
			}
		}
		else {
			playercomputer.fold();
			MessageBox(_T("电脑选择弃牌"), MB_OK);
		}
		allchips += playercomputer.currentBet;
		if (playercomputer.isFolded == true) {
			MessageBox(_T("玩家胜利"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			again();
			return;
		}
	}
	else {
		if (e > 0.7) {
			if (playercomputer.chips > m_pCurrentPlayer->currentBet * 2) {
				playercomputer.raise(m_pCurrentPlayer->currentBet);
				MessageBox(_T("电脑选择加注"), _T("提示"), MB_OK);
			}
			else {
				playercomputer.AllIn();
				MessageBox(_T("电脑选择Showhand"), _T("提示"), MB_OK);
			}
		}
		else if (e > 0.5) {
			if (playercomputer.chips > m_pCurrentPlayer->currentBet) {
				playercomputer.call(m_pCurrentPlayer->currentBet);
				MessageBox(_T("电脑选择跟注"), _T("提示"), MB_OK);
			}
			else {
				playercomputer.check();
				MessageBox(_T("电脑选择过牌"), _T("提示"), MB_OK);
			}
		}
		else if (e > 0.3) {
			playercomputer.check();
			MessageBox(_T("电脑选择过牌"), _T("提示"), MB_OK);
		}
		else {
			playercomputer.fold();
			MessageBox(_T("电脑选择弃牌"), MB_OK);
		}
		allchips += playercomputer.currentBet;
		if (playercomputer.isFolded == true) {
			MessageBox(_T("玩家胜利"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			again();
			return;
		}
	}
	turn1 = true;
	CMenu* pMenu = GetMenu();
	if (pMenu) {
		pMenu->EnableMenuItem(ID_32791, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32792, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32793, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32795, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32780, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32781, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32782, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32783, MF_BYCOMMAND | MF_GRAYED);
		// TODO: 在此添加命令处理程序代码
		// TODO: 在此添加命令处理程序代码
	}
}

void C德州扑克Dlg::On加注()
{
	if (playercomputer.isAllIn) {
		MessageBox(_T("对方已选择 All-In，您只能选择跟注或弃牌"), _T("提示"), MB_OK);
		return;
	}
	if (playercomputer.currentBet * 2 < m_pCurrentPlayer->chips) {
		m_pCurrentPlayer->raise(playercomputer.currentBet);
		MessageBox(_T("玩家选择加注"), _T("提示"), MB_OK);
		allchips += m_pCurrentPlayer->currentBet;
		turn2 = true;
	}
	else {
		MessageBox(_T("钱都不够，ALL IN吧"), _T("提示"), MB_OK);
		return;
	}
	CMenu* pMenu = GetMenu();
	if (pMenu) { 
		
		pMenu->EnableMenuItem(ID_32781, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32782, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32783, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32795, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32791, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32792, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32793, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_GRAYED);

		// TODO: 在此添加命令处理程序代码
	}
	if (turn1 == true) {
		std::vector<card>playerhand;
		std::vector<card>playerhand1;
		playerhand1.push_back(player2Cards[0]);
		playerhand1.push_back(player2Cards[1]);
		for (int i = 0; i < 5; i++) {
			playerhand1.push_back(communityCards[i]);
		}
		playerhand.push_back(player1Cards[0]);
		playerhand.push_back(player1Cards[1]); 
		CString a = printCards(player1Cards);
		MessageBox(_T("电脑底牌为"), (a), MB_OK);
		for (int i = 0; i < 5; i++) {
			playerhand.push_back(communityCards[i]);
		}
		if (evaluate1(playerhand, playerhand1) == 0) {
			MessageBox(_T("电脑胜利"), _T("提示"), MB_OK);
			playercomputer.chips += allchips;
			turn1 = FALSE;
			again();
		}
		else if(evaluate1(playerhand, playerhand1) == 1) {
			MessageBox(_T("玩家胜利"), _T("提示"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			turn1 = FALSE;
			again();
		}
		else if (evaluate1(playerhand, playerhand1) == 2) {
			MessageBox(_T("平局"), _T("提示"), MB_OK);
			m_pCurrentPlayer->chips += allchips/2;
			playercomputer.chips += allchips / 2;
			turn1 = FALSE;
			again();
		}
	}
	// TODO: 在此添加命令处理程序代码
}

void C德州扑克Dlg::On跟注()
{
	if (playercomputer.currentBet < m_pCurrentPlayer->chips) {
		m_pCurrentPlayer->call(playercomputer.currentBet);
		MessageBox(_T("玩家选择跟注"), _T("提示"), MB_OK);

		allchips += m_pCurrentPlayer->currentBet;
		turn2 = true;//turn2使对方不能过牌
	}
	else {
		MessageBox(_T("钱都不够操作失败，过牌或者all_in吧"), _T("提示"), MB_OK);
		return;
	}
	CMenu* pMenu = GetMenu();
	if (pMenu) {
		
		pMenu->EnableMenuItem(ID_32781, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32782, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32783, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32795, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32791, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32792, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32793, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_GRAYED);

		// TODO: 在此添加命令处理程序代码
	}
	if (turn1 == true) {
		std::vector<card>playerhand;
		std::vector<card>playerhand1;
		playerhand1.push_back(player2Cards[0]);
		playerhand1.push_back(player2Cards[1]);
		for (int i = 0; i < 5; i++) {
			playerhand1.push_back(communityCards[i]);
		}
		playerhand.push_back(player1Cards[0]);
		playerhand.push_back(player1Cards[1]);
		CString a = printCards(player1Cards);
		MessageBox(_T("电脑底牌为"), (a), MB_OK);
		for (int i = 0; i < 5; i++) {
			playerhand.push_back(communityCards[i]);
		}
		if (evaluate1(playerhand, playerhand1) == 0) {
			MessageBox(_T("电脑胜利"), _T("提示"), MB_OK);
			playercomputer.chips += allchips;
			turn1 = FALSE;
			again();
		}
		else if (evaluate1(playerhand, playerhand1) == 1) {
			MessageBox(_T("玩家胜利"), _T("提示"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			turn1 = FALSE;
			again();
		}
		else if (evaluate1(playerhand, playerhand1) == 2) {
			MessageBox(_T("平局"), _T("提示"), MB_OK);
			m_pCurrentPlayer->chips += allchips / 2;
			playercomputer.chips += allchips / 2;
			turn1 = FALSE;
			again();
		}
	}

	return;
	// TODO: 在此添加命令处理程序代码
}



void C德州扑克Dlg::OnALLIN()
{
	if (playercomputer.isAllIn) {
		if (m_pCurrentPlayer->chips > playercomputer.currentBet) {
			MessageBox(_T("对方已选择 All-In，您只能选择跟注或弃牌"), _T("提示"), MB_OK);
			return;
		}
		else {
			MessageBox(_T("玩家也选择showhand"), _T("提示"), MB_OK);
			m_pCurrentPlayer->AllIn();
			playercomputer.currentBet = m_pCurrentPlayer->currentBet;
			allchips = allchips + m_pCurrentPlayer->currentBet * 2 - playercomputer.currentBet;
			playercomputer.chips = playercomputer.currentBet - m_pCurrentPlayer->currentBet;
			
		}
	}
	m_pCurrentPlayer->AllIn();
	MessageBox(_T("玩家选择showhand"), _T("提示"), MB_OK);
	allchips += m_pCurrentPlayer->currentBet;
	CMenu* pMenu = GetMenu();
	if (pMenu) {
		pMenu->EnableMenuItem(ID_32780, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32781, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32782, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32783, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32795, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32791, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32792, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32793, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_GRAYED);

		// TODO: 在此添加命令处理程序代码
	}
	if (turn1 == true) {
		std::vector<card>playerhand;
		std::vector<card>playerhand1;
		playerhand1.push_back(player2Cards[0]);
		playerhand1.push_back(player2Cards[1]);
		for (int i = 0; i < 5; i++) {
			playerhand1.push_back(communityCards[i]);
		}
		playerhand.push_back(player1Cards[0]);
		playerhand.push_back(player1Cards[1]);
		CString a = printCards(player1Cards);
		MessageBox(_T("电脑底牌为"), (a), MB_OK);
		for (int i = 0; i < 5; i++) {
			playerhand.push_back(communityCards[i]);
		}
		if (evaluate1(playerhand, playerhand1) == 0) {
			MessageBox(_T("电脑胜利"), _T("提示"), MB_OK);
			playercomputer.chips += allchips;
			turn1 = FALSE;
			again();
		}
		else if (evaluate1(playerhand, playerhand1) == 1) {
			MessageBox(_T("玩家胜利"), _T("提示"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			turn1 = FALSE;
			again();
		}
		else if (evaluate1(playerhand, playerhand1) == 2) {
			MessageBox(_T("平局"), _T("提示"), MB_OK);
			m_pCurrentPlayer->chips += allchips / 2;
			playercomputer.chips += allchips / 2;
			turn1 = FALSE;
			again();
		}
	}
	// TODO: 在此添加命令处理程序代码
}


void C德州扑克Dlg::On过牌1()
{
	if (playercomputer.isAllIn) {

		MessageBox(_T("对方已选择 All-In，您只能选择跟注或弃牌"), _T("提示"), MB_OK);
		return;

	}
	m_pCurrentPlayer->check();
	CMenu* pMenu = GetMenu();
	if (pMenu) {
		
		pMenu->EnableMenuItem(ID_32781, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32782, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32783, MF_BYCOMMAND | MF_ENABLED);
		pMenu->EnableMenuItem(ID_32795, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32791, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32792, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32793, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_GRAYED);

		// TODO: 在此添加命令处理程序代码
	}
	if (turn1 == true) {
		std::vector<card>playerhand;
		std::vector<card>playerhand1;
		playerhand1.push_back(player2Cards[0]);
		playerhand1.push_back(player2Cards[1]);
		for (int i = 0; i < 5; i++) {
			playerhand1.push_back(communityCards[i]);
		}
		playerhand.push_back(player1Cards[0]);
		playerhand.push_back(player1Cards[1]);
		CString a = printCards(player1Cards);
		MessageBox(_T("电脑底牌为"), (a), MB_OK);
		for (int i = 0; i < 5; i++) {
			playerhand.push_back(communityCards[i]);
		}
		if (evaluate1(playerhand, playerhand1) == 0) {
			MessageBox(_T("电脑胜利"), _T("提示"), MB_OK);
			playercomputer.chips += allchips;
			turn1 = FALSE;
			again();
		}
		else if (evaluate1(playerhand, playerhand1) == 1) {
			MessageBox(_T("玩家胜利"), _T("提示"), MB_OK);
			m_pCurrentPlayer->chips += allchips;
			turn1 = FALSE;
			again();
		}
		else if (evaluate1(playerhand, playerhand1) == 2) {
			MessageBox(_T("平局"), _T("提示"), MB_OK);
			m_pCurrentPlayer->chips += allchips / 2;
			playercomputer.chips += allchips / 2;
			turn1 = FALSE;
			again();
		}
	}
	// TODO: 在此添加命令处理程序代码
}

void C德州扑克Dlg::On弃牌()
{
	m_pCurrentPlayer->fold();
	CString a = printCards(player1Cards);
	MessageBox(_T("电脑底牌为"), (a), MB_OK);
	if (m_pCurrentPlayer->isFolded) {
		MessageBox(_T("电脑获胜"), _T("提示"), MB_OK);
	}
	playercomputer.chips += allchips;
	again();
	// TODO: 在此添加命令处理程序代码
}

void C德州扑克Dlg::On重开()
{
	playercomputer.chips+= allchips;
	again();
}

void C德州扑克Dlg::On32798()
{

	来财 dlg;
	dlg.DoModal();
	if (dlg.DoModal() == IDOK) {
		m_pCurrentPlayer->chips += 500;
	}
	// TODO: 在此添加命令处理程序代码
}

void C德州扑克Dlg::On偷看()
{
	CString a = printCards(player1Cards);
	MessageBox((a), MB_OK);
	// TODO: 在此添加命令处理程序代码
}

void C德州扑克Dlg::查看奖池()
{

	CString strValue;
	strValue.Format(_T("%d"),allchips); // 将 int 转换为 CString
	MessageBox(strValue);

	// TODO: 在此添加命令处理程序代码
}

void C德州扑克Dlg::On32776()
{
	PostQuitMessage(0);
	// TODO: 在此添加命令处理程序代码
}
