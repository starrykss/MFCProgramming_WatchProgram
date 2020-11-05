#pragma once


// CAMPMDlg 대화 상자

class CAMPMDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAMPMDlg)

public:
	CAMPMDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CAMPMDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
