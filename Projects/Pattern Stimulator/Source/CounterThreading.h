
// CounterThreading.h : main header file for the CounterThreading application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCounterThreadingApp:
// See CounterThreading.cpp for the implementation of this class
//

class CCounterThreadingApp : public CWinApp
{
public:
	CCounterThreadingApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCounterThreadingApp theApp;
