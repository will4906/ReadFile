// ReadFile.h : main header file for the READFILE application
//

#if !defined(AFX_READFILE_H__C56F5496_FF14_4A74_B2D2_4AA91853C180__INCLUDED_)
#define AFX_READFILE_H__C56F5496_FF14_4A74_B2D2_4AA91853C180__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReadFileApp:
// See ReadFile.cpp for the implementation of this class
//

class CReadFileApp : public CWinApp
{
public:
	CReadFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReadFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READFILE_H__C56F5496_FF14_4A74_B2D2_4AA91853C180__INCLUDED_)
