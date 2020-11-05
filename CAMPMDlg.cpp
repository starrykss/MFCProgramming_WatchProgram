// CAMPMDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCPractice5_Watch.h"
#include "CAMPMDlg.h"
#include "afxdialogex.h"


// CAMPMDlg 대화 상자

IMPLEMENT_DYNAMIC(CAMPMDlg, CDialogEx)

CAMPMDlg::CAMPMDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CAMPMDlg::~CAMPMDlg()
{
}

void CAMPMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAMPMDlg, CDialogEx)
END_MESSAGE_MAP()


// CAMPMDlg 메시지 처리기
