
// MFCPractice5_WatchDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCPractice5_Watch.h"
#include "MFCPractice5_WatchDlg.h"
#include "afxdialogex.h"
#include "CAMPMDlg.h" // 헤더 추가

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCPractice5WatchDlg 대화 상자



CMFCPractice5WatchDlg::CMFCPractice5WatchDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MFCPRACTICE5_WATCH_DIALOG, pParent)
	, m_strYear(_T(""))
	, m_strMonth(_T(""))
	, m_strDay(_T(""))
	, m_strHour(_T(""))
	, m_strMinute(_T(""))
	, m_strSecond(_T(""))
	, m_strPMAM(_T(""))
	, m_bCheckYear(false)
	, m_bCheckHour(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCPractice5WatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_strYear);
	DDX_Text(pDX, IDC_EDIT_MONTH, m_strMonth);
	DDX_Text(pDX, IDC_EDIT_DAY, m_strDay);
	DDX_Text(pDX, IDC_EDIT_HOUR, m_strHour);
	DDX_Text(pDX, IDC_EDIT_MINUTE, m_strMinute);
	DDX_Text(pDX, IDC_EDIT_SECOND, m_strSecond);
	DDX_Text(pDX, IDC_EDIT_PMAM, m_strPMAM);
}

BEGIN_MESSAGE_MAP(CMFCPractice5WatchDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO_12H, &CMFCPractice5WatchDlg::OnRadio12h)
	ON_COMMAND(IDC_RADIO_24H, &CMFCPractice5WatchDlg::OnRadio24h)
	ON_BN_CLICKED(IDC_CHECK_YEAR, &CMFCPractice5WatchDlg::OnClickedCheckYear)
	ON_BN_CLICKED(IDC_CHECK_HOUR, &CMFCPractice5WatchDlg::OnClickedCheckHour)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_INFORMATION, &CMFCPractice5WatchDlg::OnClickedButtonInformation)
END_MESSAGE_MAP()


// CMFCPractice5WatchDlg 메시지 처리기

BOOL CMFCPractice5WatchDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	// 라디오 버튼, 체크박스 초기화
	((CButton*)GetDlgItem(IDC_RADIO_12H))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_CHECK_HOUR))->SetCheck(TRUE);

	// 년, 월, 일 에디트 컨트롤 초기화
	GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_HIDE);

	// 년, 월, 일 스태틱 텍스트 초기화
	GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_MONTH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DAY)->ShowWindow(SW_HIDE);

	// 멤버변수 초기화
	m_bRadioClockType = true;
	m_bCheckYear = false;
	m_bCheckHour = true;

	// 타이머 설정
	SetTimer(0, 1000, NULL);   // 0번 타이머를 1000ms 간격으로 실행

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCPractice5WatchDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCPractice5WatchDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCPractice5WatchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCPractice5WatchDlg::OnRadio12h()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bRadioClockType = true;
}


void CMFCPractice5WatchDlg::OnRadio24h()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bRadioClockType = false;
}


void CMFCPractice5WatchDlg::OnClickedCheckYear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bCheckYear == false)
	{
		GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MONTH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_DAY)->ShowWindow(SW_SHOW);
	
		m_bCheckYear = true;
	}
	else
	{
		GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_MONTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DAY)->ShowWindow(SW_HIDE);

		m_bCheckYear = false;
	}
}


void CMFCPractice5WatchDlg::OnClickedCheckHour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bCheckHour == false)
	{
		GetDlgItem(IDC_EDIT_HOUR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MINUTE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_SECOND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_PMAM)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_HOUR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MINUTE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SECOND)->ShowWindow(SW_SHOW);

		m_bCheckHour = true;
	}
	else
	{
		GetDlgItem(IDC_EDIT_HOUR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_MINUTE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_SECOND)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_PMAM)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_HOUR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_MINUTE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SECOND)->ShowWindow(SW_HIDE);

		m_bCheckHour = false;
	}
}

void CMFCPractice5WatchDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int hour;
	CTime timer;
	timer = CTime::GetCurrentTime();

	m_strYear.Format(_T("%d"), timer.GetYear());
	m_strMonth.Format(_T("%d"), timer.GetMonth());
	m_strDay.Format(_T("%d"), timer.GetDay());

	hour = timer.GetHour();
	if (m_bRadioClockType)
	{
		if (hour >= 12)
		{
			m_strPMAM = _T("PM");
			if (hour >= 13)
				hour -= 12;
		}
		else
		{
			m_strPMAM = _T("AM");
		}
	}
	else
	{
		m_strPMAM.Empty();
	}

	m_strHour.Format(_T("%d"), hour);
	m_strMinute.Format(_T("%d"), timer.GetMinute());
	m_strSecond.Format(_T("%d"), timer.GetSecond());

	UpdateData(FALSE);

	CDialog::OnTimer(nIDEvent);
}


void CMFCPractice5WatchDlg::OnClickedButtonInformation()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CAMPMDlg dlg;
	dlg.DoModal();
}
