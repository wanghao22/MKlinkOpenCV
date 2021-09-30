
// MKlinkOpenCVDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <iostream>

// CMKlinkOpenCVDlg 对话框
class CMKlinkOpenCVDlg : public CDialogEx
{
// 构造
public:
	CMKlinkOpenCVDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MKLINKOPENCV_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
