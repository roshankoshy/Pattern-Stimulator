// SelectPatternDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CounterThreading.h"
#include "SelectPatternDlg.h"
#include "afxdialogex.h"


// CSelectPatternDlg dialog

IMPLEMENT_DYNAMIC(CSelectPatternDlg, CDialog)

CSelectPatternDlg::CSelectPatternDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1_SELECT_PATTERN, pParent)
	, m_SelectedData(_T(""))
{

}

CSelectPatternDlg::~CSelectPatternDlg()
{
}

void CSelectPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_OPTIONS, m_SelectedData);
}


BEGIN_MESSAGE_MAP(CSelectPatternDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CSelectPatternDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSelectPatternDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSelectPatternDlg message handlers


void CSelectPatternDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CDialog::OnOK();
}


void CSelectPatternDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
