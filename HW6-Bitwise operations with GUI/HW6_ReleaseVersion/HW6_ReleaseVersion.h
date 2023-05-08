
// HW6_ReleaseVersion.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CHW6_ReleaseVersionApp:
// See HW6_ReleaseVersion.cpp for the implementation of this class
//

class CHW6_ReleaseVersionApp : public CWinApp
{
public:
	CHW6_ReleaseVersionApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CHW6_ReleaseVersionApp theApp;