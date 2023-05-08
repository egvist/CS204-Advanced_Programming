
// HW6_ReleaseVersionDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CHW6_ReleaseVersionDlg dialog
class CHW6_ReleaseVersionDlg : public CDialogEx
{
// Construction
public:
	CHW6_ReleaseVersionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_HW6_RELEASEVERSION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int RadioButtonC;
	CEdit Operand1;
	CEdit Operand2;
	CListBox ResultBox;
	CButton shiftBox;
	CComboBox shiftwayCombo;
	CEdit shiftbitBox;
	CButton ComputeButton;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedCheck1();
//	afx_msg void OnLbnSelchangeList1();
};
