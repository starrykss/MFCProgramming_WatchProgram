
// MFCPractice5_WatchDlg.h: 헤더 파일
//

#pragma once


// CMFCPractice5WatchDlg 대화 상자
class CMFCPractice5WatchDlg : public CDialog
{
// 생성입니다.
public:
	CMFCPractice5WatchDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPRACTICE5_WATCH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strYear;
	CString m_strMonth;
	CString m_strDay;
	CString m_strHour;
	CString m_strMinute;
	CString m_strSecond;
	CString m_strPMAM;
	bool m_bRadioClockType;
	afx_msg void OnRadio12h();
	afx_msg void OnRadio24h();
	bool m_bCheckYear;
	bool m_bCheckHour;
	afx_msg void OnClickedCheckYear();
	afx_msg void OnClickedCheckHour();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedButtonInformation();
};
