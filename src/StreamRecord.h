// StreamRecord.h : StreamRecord Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������




// CNSPlayerApp:
// �йش����ʵ�֣������ StreamRecord.cpp
//

class CNSPlayerApp : public CWinApp
{
public:
	CNSPlayerApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CNSPlayerApp theApp;
