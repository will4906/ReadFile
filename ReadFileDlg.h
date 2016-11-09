// ReadFileDlg.h : header file
//

#if !defined(AFX_READFILEDLG_H__97FF37E6_D50C_44E7_824E_2AAC0BC80426__INCLUDED_)
#define AFX_READFILEDLG_H__97FF37E6_D50C_44E7_824E_2AAC0BC80426__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StringCheck.h"

#pragma comment (lib,"DataProcess")
/////////////////////////////////////////////////////////////////////////////
// CReadFileDlg dialog

class CReadFileDlg : public CDialog
{
// Construction
public:
	void ProcEscInString(CString &strTmp);
	CString m_strFilePath;
	CString	m_strFileName;
	CStringArray  m_strArrFile;
	int SplitPoint(CString strFile);
	void NewFileCpp(CStdioFile *stFile,CString strLeft,CString strRight);
	void NewFileHead(CString strLeft,CString strRight);
	BOOL MakeCodeNewFile(CString strFile);
	CReadFileDlg(CWnd* pParent = NULL);	// standard constructor
	CStringCheck m_StringCheck;
// Dialog Data
	//{{AFX_DATA(CReadFileDlg)
	enum { IDD = IDD_READFILE_DIALOG };
	CStatic	m_ctrlText2;
	CStatic	m_ctrlText;
	CListBox	m_lbFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReadFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSelect();
	afx_msg void OnButtonBuildOne();
	afx_msg void OnButtonTemp();
	afx_msg void OnButtonBuildAll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READFILEDLG_H__97FF37E6_D50C_44E7_824E_2AAC0BC80426__INCLUDED_)
