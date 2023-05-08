
// HW6_ReleaseVersionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HW6_ReleaseVersion.h"
#include "HW6_ReleaseVersionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHW6_ReleaseVersionDlg dialog



CHW6_ReleaseVersionDlg::CHW6_ReleaseVersionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHW6_ReleaseVersionDlg::IDD, pParent)
	, RadioButtonC(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHW6_ReleaseVersionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, RadioButtonC);
	DDX_Control(pDX, IDC_EDIT1, Operand1);
	DDX_Control(pDX, IDC_EDIT2, Operand2);
	DDX_Control(pDX, IDC_LIST1, ResultBox);
	DDX_Control(pDX, IDC_CHECK1, shiftBox);
	DDX_Control(pDX, IDC_COMBO1, shiftwayCombo);
	DDX_Control(pDX, IDC_EDIT3, shiftbitBox);
	DDX_Control(pDX, IDC_BUTTON2, ComputeButton);
}

BEGIN_MESSAGE_MAP(CHW6_ReleaseVersionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CHW6_ReleaseVersionDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CHW6_ReleaseVersionDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CHW6_ReleaseVersionDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CHW6_ReleaseVersionDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_CHECK1, &CHW6_ReleaseVersionDlg::OnBnClickedCheck1)
//	ON_LBN_SELCHANGE(IDC_LIST1, &CHW6_ReleaseVersionDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CHW6_ReleaseVersionDlg message handlers

BOOL CHW6_ReleaseVersionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	shiftwayCombo.SetCurSel(0);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHW6_ReleaseVersionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHW6_ReleaseVersionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHW6_ReleaseVersionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int maxSize = 0;
void CHW6_ReleaseVersionDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString op1, op2, res, resf, dummystring, bit;
	unsigned int op1i, op2i, bit1i;

	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());
	CSize cz;


	Operand1.GetWindowTextW(op1);
	Operand2.GetWindowTextW(op2);

	if (op1.GetLength() == 0 || op2.GetLength() == 0)
	{
		resf = _T("At least one operand was not entered");
		ResultBox.AddString(resf);
		cz = pDC->GetTextExtent(resf);
		if (cz.cx > maxSize)
		{
			maxSize = cz.cx;
		}
	}
	
	else
	{
		op1i = _ttof(op1);
		op2i = _ttof(op2);


		if (shiftBox.GetCheck() == 1)
		{
			
			int selectedIdx = shiftwayCombo.GetCurSel();
			shiftwayCombo.GetLBText(selectedIdx, dummystring);
			shiftbitBox.GetWindowTextW(bit);
			if (bit.GetLength() == 0)
			{
				resf = _T("Specify how many bits you want to shift");
				ResultBox.AddString(resf);
				cz = pDC->GetTextExtent(resf);
				if (cz.cx > maxSize)
				{
					maxSize = cz.cx;
				}
			}
			else 
			{
				bit1i = _ttof(bit);

				if(dummystring == _T("Left"))
				{
					op1.Format(_T("%i"), op1i<<bit1i);
					op2.Format(_T("%i"), op2i<<bit1i);
				}
				else if (dummystring == _T("Right"))
				{
					op1.Format(_T("%i"), op1i>>bit1i);
					op2.Format(_T("%i"), op2i>>bit1i);
		
				}
				op1i = _ttof(op1);
				op2i = _ttof(op2);


				if (RadioButtonC == 0)
				{
					res.Format(_T("%i"), op1i&op2i);
					resf = op1 + _T(" AND ") + op2 + _T(" = ") + res; 
		
		

				}

				else if (RadioButtonC == 1)
				{
					res.Format(_T("%i"), (op1i|op2i));
					resf = op1 + _T(" OR ") + op2 + _T(" = ") + res; 
		
				}

				else if (RadioButtonC == 2)
				{
					res.Format(_T("%i"), (op1i^op2i));
					resf = op1 + _T(" XOR ") + op2 + _T(" = ") + res; 
		
				}
				else
				{
				}
				ResultBox.AddString(resf);
				cz = pDC->GetTextExtent(resf);
				if (cz.cx > maxSize)
				{
					maxSize = cz.cx;
				}
			}

	
		}
		else
		{
			op1i = _ttof(op1);
			op2i = _ttof(op2);


			if (RadioButtonC == 0)
			{
				res.Format(_T("%i"), op1i&op2i);
				resf = op1 + _T(" AND ") + op2 + _T(" = ") + res; 
		
		

			}

			else if (RadioButtonC == 1)
			{
				res.Format(_T("%i"), (op1i|op2i));
				resf = op1 + _T(" OR ") + op2 + _T(" = ") + res; 
		
			}

			else if (RadioButtonC == 2)
			{
				res.Format(_T("%i"), (op1i^op2i));
				resf = op1 + _T(" XOR ") + op2 + _T(" = ") + res; 
		
			}
			else
			{
			}
			ResultBox.AddString(resf);
			cz = pDC->GetTextExtent(resf);
			if (cz.cx > maxSize)
			{
				maxSize = cz.cx;
			}
		}

	}

	ResultBox.SetHorizontalExtent(maxSize);
}


void CHW6_ReleaseVersionDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	RadioButtonC = 0;
}


void CHW6_ReleaseVersionDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	RadioButtonC = 1;
}


void CHW6_ReleaseVersionDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	RadioButtonC = 2;
}


void CHW6_ReleaseVersionDlg::OnBnClickedCheck1()
{
	if (shiftBox.GetCheck())
	{
		shiftbitBox.EnableWindow(TRUE);
		shiftwayCombo.EnableWindow(TRUE);
		
	}
	else 
	{
		shiftbitBox.EnableWindow(FALSE);
		shiftwayCombo.EnableWindow(FALSE);
	
	}
}


//void CHW6_ReleaseVersionDlg::OnLbnSelchangeList1()
//{
//	// TODO: Add your control notification handler code here
//}
