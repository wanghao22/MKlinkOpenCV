
// MKlinkOpenCVDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <iostream>

// CMKlinkOpenCVDlg �Ի���
class CMKlinkOpenCVDlg : public CDialogEx
{
// ����
public:
	CMKlinkOpenCVDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MKLINKOPENCV_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	const char* m_opencv = "OpenCV_";
	void DeleteDirectory(CString sDirName, bool flag = false);
	void DeleteDir(CString path, bool flag = false);
public:
	CString m_input_path;
	afx_msg void OnBnClickedGetPath();
	afx_msg void OnBnClickedCopy();
	afx_msg void OnBnClickedMklink();
	CComboBox m_combo_version;
	CComboBox m_combo_vc;
	CComboBox m_combo_xnum;
	CComboBox m_combo_dr;
	int getSeting(std::string &srcpath, std::string &dstpath);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClose();
	int getEnvironmentVar(std::string name, std::string &val);
	CString m_password;
	afx_msg void OnBnClickedDelete();
	bool passwordIsRight(std::string passworld);
	void copyToClipboard(CString source);
	CButton m_check_go;
	void doWithCMD(char* cmd);
	afx_msg void OnBnClickedClear();
};
