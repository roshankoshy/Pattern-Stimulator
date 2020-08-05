#pragma once


// CSelectPatternDlg dialog

class CSelectPatternDlg : public CDialog
{
	DECLARE_DYNAMIC(CSelectPatternDlg)

public:
	CSelectPatternDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectPatternDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_SELECT_PATTERN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_SelectedData;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
