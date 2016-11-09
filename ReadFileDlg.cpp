// ReadFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReadFile.h"
#include "ReadFileDlg.h"
//#include "NewFile_datatype_h.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadFileDlg dialog

CReadFileDlg::CReadFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReadFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReadFileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReadFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReadFileDlg)
	DDX_Control(pDX, IDC_STATIC_TEXT2, m_ctrlText2);
	DDX_Control(pDX, IDC_STATIC_TEXT, m_ctrlText);
	DDX_Control(pDX, IDC_LIST_FILE, m_lbFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReadFileDlg, CDialog)
	//{{AFX_MSG_MAP(CReadFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SELECT, OnButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_BUILD_ONE, OnButtonBuildOne)
	ON_BN_CLICKED(IDC_BUTTON_TEMP, OnButtonTemp)
	ON_BN_CLICKED(IDC_BUTTON_BUILD_ALL, OnButtonBuildAll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadFileDlg message handlers

BOOL CReadFileDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	SetWindowPos(NULL,0,0,300,150,SWP_NOMOVE);
	//MakeCodeNewFile("datatype.h");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReadFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CReadFileDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CReadFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CReadFileDlg::MakeCodeNewFile(CString strFile)
{
	CStdioFile stFile;
	BOOL flag = FALSE;
	int pos;
	CString strLeft,strRight;
	pos = strFile.Find(".");
	strLeft = strFile.Left(pos);
	strRight = strFile.Right(strFile.GetLength() - pos - 1);

	if (stFile.Open(strFile,CFile::modeRead))
	{
		NewFileHead(strLeft,strRight);
		NewFileCpp(&stFile,strLeft,strRight);
		flag = TRUE;
	}
	stFile.Close();
	return flag;
}

void CReadFileDlg::NewFileHead(CString strLeft,CString strRight)
{
	CStdioFile stFile;
	CString strFun,strH,strName,strUp;

	strName = "_" + strLeft + "_" + strRight;
	strH = "NewFile" + strName + ".h";
	strFun = "void NewFile" + strName + "();\n";
	stFile.Open(strH,CFile::modeCreate|CFile::modeReadWrite);
	strUp = strName;
	strUp.MakeUpper();
	stFile.WriteString("#ifndef _NEW" + strUp + "_H_\n");
	stFile.WriteString("#define _NEW" + strUp + "_H_\n");
	stFile.WriteString("\n");
	stFile.WriteString(strFun);
	stFile.WriteString("#endif\n");

	stFile.Close();
}

void CReadFileDlg::NewFileCpp(CStdioFile *stFile,CString strLeft,CString strRight)
{
	CStdioFile stCppFile;
	CString strLine,strTmp;
	CString strFun,strH,strCpp,strName,strOld;
	
	strName = "_" + strLeft + "_" + strRight;
	strH = "NewFile" + strName + ".h";
	strCpp = "NewFile" + strName + ".cpp";
	strFun = "void NewFile" + strName + "()";
	strOld = strLeft + "." + strRight;

	stCppFile.Open(strCpp,CFile::modeCreate|CFile::modeReadWrite);
	strLine = "#include \"StdAfx.h\"\n";
	stCppFile.WriteString(strLine);

	strLine = "#include \"" + strH + "\"\n";
	stCppFile.WriteString(strLine);
	stCppFile.WriteString("\n");//
	
	strLine = strFun + "\n";
	stCppFile.WriteString(strLine);
	stCppFile.WriteString("{\n");

	strLine = "\tCStdioFile stFile;\n";
	stCppFile.WriteString(strLine);

	strLine = "\tstFile.Open(\"" + strOld + "\",CFile::modeCreate|CFile::modeReadWrite);\n";
	stCppFile.WriteString(strLine);

	while (stFile->ReadString(strTmp))
	{
		ProcEscInString(strTmp);
		strLine = "\tstFile.WriteString(\"" + strTmp + "\\n\");\n";
		stCppFile.WriteString(strLine);
	}
	
	stCppFile.WriteString("\tstFile.Close();\n");
	stCppFile.WriteString("}");
	
	stCppFile.Close();
}

void CReadFileDlg::OnButtonSelect() 
{
	// TODO: Add your control notification handler code here
	
	char szDatFilters[] = "cpp files (*.cpp)|*.cpp|c files (*.c)|*.c|head files (*.h)|*.h|txt files (*.txt)|*.txt|";
	CStdioFile file;
	CString szLine,strTmp,strRight,strFileName;
	CStringArray strErr;
	
	CFileDialog FileOpenDlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szDatFilters, this);
	
	int nRespons = FileOpenDlg.DoModal();
	if(nRespons == IDOK)
	{
		SetWindowPos(NULL,0,0,300,420,SWP_NOMOVE);
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowPos(NULL,40,350,300,450,SWP_NOSIZE);
		GetDlgItem(IDC_BUTTON_TEMP)->SetWindowPos(NULL,160,350,300,450,SWP_NOSIZE);
		m_lbFile.ShowWindow(TRUE);
		// 选取数据文件		
		m_strFilePath = FileOpenDlg.GetPathName();
		
		int k,point;
		k = m_strFilePath.ReverseFind('\\');
		point = m_strFilePath.ReverseFind('.');
		if(k > 0)
		{
			strFileName = m_strFilePath.Left(k+1);
		}
		if (point > 0)
		{
			strRight = m_strFilePath.Right(m_strFilePath.GetLength() - point - 1);
		}
		
		m_lbFile.ResetContent();
		if (strRight == "cpp")
		{
			m_lbFile.Dir(0x0010, strFileName+"*.cpp");
		}
		else if (strRight == "txt")
		{
			m_lbFile.Dir(0x0010, strFileName+"*.txt");
		}
		else if (strRight == "h")
		{
			m_lbFile.Dir(0x0010, strFileName+"*.h");
		}
		else if (strRight == "c")
		{
			m_lbFile.Dir(0x0010, strFileName+"*.c");
		}
		
		
		int i,cnt;
		CString strFile;
		m_strArrFile.RemoveAll();
		cnt = m_lbFile.GetCount();
		for(i=0;i<cnt;i++)
		{
			m_lbFile.GetText(i,strFile);
			m_strArrFile.Add(strFile);
		}
		
	}
}

void CReadFileDlg::OnButtonBuildOne() 
{
	// TODO: Add your control notification handler code here
	SetWindowPos(NULL,0,0,300,500,SWP_NOMOVE);
	CStringArray strArr;
	int k;
	CTime time;  
	CString strTime,strBack,m_strReport;
	time=CTime::GetCurrentTime();//获得当前时间  
	strTime=time.Format("%Y-%m-%d %H:%M:%S");//将时间转化为字符串  
	m_strReport = _T("处理时间：") + strTime + _T("\r\n");
	
	//UpdateData(TRUE);
	k = m_lbFile.GetCurSel();
	if(k<0)
		return;
	m_lbFile.GetText(k,m_strFileName);
	if (k >= 0)
	{
		MakeCodeNewFile(m_strFileName);
		m_ctrlText.SetWindowText(m_strReport);
		m_ctrlText2.SetWindowText("文件处理成功!");
	} 
	else
	{
		m_ctrlText.SetWindowText(m_strReport);
		m_ctrlText2.SetWindowText("文件处理失败!");
	}
	
}

void CReadFileDlg::OnButtonTemp() 
{
	// TODO: Add your control notification handler code here
	SetWindowPos(NULL,0,0,300,420,SWP_NOMOVE);
	GetDlgItem(IDC_BUTTON_SELECT)->SetWindowPos(NULL,40,350,300,450,SWP_NOSIZE);
	GetDlgItem(IDC_BUTTON_TEMP)->SetWindowPos(NULL,160,350,300,450,SWP_NOSIZE);
	m_lbFile.ShowWindow(TRUE);
}

void CReadFileDlg::OnButtonBuildAll() 
{
	// TODO: Add your control notification handler code here
	SetWindowPos(NULL,0,0,300,500,SWP_NOMOVE);
	GetDlgItem(IDC_BUTTON_SELECT)->SetWindowPos(NULL,40,350,300,450,SWP_NOSIZE);
	GetDlgItem(IDC_BUTTON_TEMP)->SetWindowPos(NULL,160,350,300,450,SWP_NOSIZE);
	//m_lbFile.ShowWindow(TRUE);

	int cnt,i;
	CTime time;  
	CString strTime,strBack,m_strReport,strErr = "";
	CStringArray strArr;
	BOOL bName;
	time=CTime::GetCurrentTime();//获得当前时间  
	strTime=time.Format("%Y-%m-%d %H:%M:%S");//将时间转化为字符串  
	m_strReport = _T("处理时间：") + strTime + _T("\r\n");
	
	cnt = m_lbFile.GetCount();
	for(i=0;i<cnt;i++)
	{
		m_lbFile.SetCurSel(i);
		m_lbFile.GetText(i,m_strFileName);
		strArr.RemoveAll();
		bName = m_StringCheck.CheckVarName(m_strFileName);
		if (bName == TRUE)
		{
			MakeCodeNewFile(m_strFileName);
		}
		else
		{
			strErr += m_strFileName + "不符合命名规范";
		}
	}
	if (cnt >= 0 && bName == TRUE)
	{
		m_ctrlText.SetWindowText(m_strReport);
		m_ctrlText2.SetWindowText("文件处理成功!");
	} 
	else
	{
		m_ctrlText.SetWindowText(m_strReport);
		m_ctrlText2.SetWindowText("文件处理失败!" + strErr);
	}
}

void CReadFileDlg::ProcEscInString(CString &strTmp)
{
	strTmp.Replace("\\","\\\\");
	strTmp.Replace("\"","\\\"");
}
