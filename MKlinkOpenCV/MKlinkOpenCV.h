
// MKlinkOpenCV.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMKlinkOpenCVApp: 
// �йش����ʵ�֣������ MKlinkOpenCV.cpp
//

class CMKlinkOpenCVApp : public CWinApp
{
public:
	CMKlinkOpenCVApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMKlinkOpenCVApp theApp;