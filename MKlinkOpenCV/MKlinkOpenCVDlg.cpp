
// MKlinkOpenCVDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MKlinkOpenCV.h"
#include "MKlinkOpenCVDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMKlinkOpenCVDlg 对话框



CMKlinkOpenCVDlg::CMKlinkOpenCVDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MKLINKOPENCV_DIALOG, pParent)
	, m_input_path(_T(""))
	, m_password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_OPENCV);
}

void CMKlinkOpenCVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT_PATH, m_input_path);
	DDX_Control(pDX, IDC_COMBO1, m_combo_version);
	DDX_Control(pDX, IDC_COMBO2, m_combo_vc);
	DDX_Control(pDX, IDC_COMBO3, m_combo_xnum);
	DDX_Control(pDX, IDC_COMBO4, m_combo_dr);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Control(pDX, IDC_CHECK1, m_check_go);
}

BEGIN_MESSAGE_MAP(CMKlinkOpenCVDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_PATH, &CMKlinkOpenCVDlg::OnBnClickedGetPath)
	ON_BN_CLICKED(IDC_COPY, &CMKlinkOpenCVDlg::OnBnClickedCopy)
	ON_BN_CLICKED(IDC_MKLINK, &CMKlinkOpenCVDlg::OnBnClickedMklink)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_DELETE, &CMKlinkOpenCVDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_CLEAR, &CMKlinkOpenCVDlg::OnBnClickedClear)
END_MESSAGE_MAP()


// CMKlinkOpenCVDlg 消息处理程序

BOOL CMKlinkOpenCVDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_combo_version.SetCurSel(1);
	m_combo_vc.SetCurSel(1);
	m_combo_xnum.SetCurSel(1);
	m_combo_dr.SetCurSel(1);
	m_check_go.SetCheck(TRUE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMKlinkOpenCVDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMKlinkOpenCVDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMKlinkOpenCVDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMKlinkOpenCVDlg::DeleteDir(CString path, bool cflag)
{
	std::string str = CW2A(path);
	BOOL flag = PathFileExists(path);
	if (flag == FALSE) {
		return;
	}
	/*char cmd[200];
	sprintf_s(cmd, "rd /s /q \"%s\"", str.c_str());
	doWithCMD(cmd);*/
	DeleteDirectory(path, cflag);
}

void CMKlinkOpenCVDlg::DeleteDirectory(CString sDirName, bool flag)
{
	static int cnt = 0;
	cnt++;
	CFileFind   ff;
	BOOL   bFound;
	CString sTempFileFind;
	sTempFileFind.Format(_T("%s\\*.*"), sDirName);

	bFound = ff.FindFile(sTempFileFind);

	while (bFound)
	{
		bFound = ff.FindNextFile();
		CString  sFilePath = ff.GetFilePath();

		if (ff.IsDirectory())
		{
			if (!ff.IsDots())
			{
				DeleteDirectory(sFilePath);
			}
		}
		else
		{
			if (ff.IsReadOnly())
			{
				SetFileAttributes(sFilePath, FILE_ATTRIBUTE_NORMAL);
			}
			DeleteFile(sFilePath);
		}
	}
	ff.Close();
	SetFileAttributes(sDirName, FILE_ATTRIBUTE_NORMAL);
	cnt--;
	if (cnt == 0 && flag)
		return;
	RemoveDirectory(sDirName);
}

void CMKlinkOpenCVDlg::OnBnClickedGetPath()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR           szFolderPath[MAX_PATH] = { 0 };
	CString         strFolderPath = TEXT("");

	BROWSEINFO      sInfo;
	::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T("请选择处理结果存储路径");
	sInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX | BIF_DONTGOBELOWDOMAIN;
	sInfo.lpfn = NULL;

	// 显示文件夹选择对话框  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidlBrowse != NULL)
	{
		// 取得文件夹名  
		if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath))
		{
			strFolderPath = szFolderPath;
		}
	}
	if (lpidlBrowse != NULL)
	{
		::CoTaskMemFree(lpidlBrowse);
	}
	m_input_path = strFolderPath;
	UpdateData(FALSE);
}


void CMKlinkOpenCVDlg::OnBnClickedCopy()
{
	// TODO: 在此添加控件通知处理程序代码
	std::string srcpath, dstpath;
	int rc = getSeting(srcpath, dstpath);
	if (rc != 0)
		return;
	char cmd[200];
	std::string str = CW2A(m_input_path);
	sprintf_s(cmd, "copy \"%s\" \"%s\"", srcpath.c_str(), str.c_str());
	doWithCMD(cmd);
}


void CMKlinkOpenCVDlg::OnBnClickedMklink()
{
	// TODO: 在此添加控件通知处理程序代码
	std::string srcpath, dstpath;
	int rc = getSeting(srcpath, dstpath);
	if (rc != 0)
		return;
	char cmd[200];
	sprintf_s(cmd, "mklink /H \"%s\" \"%s\"", dstpath.c_str(), srcpath.c_str());
	doWithCMD(cmd);
}

int CMKlinkOpenCVDlg::getSeting(std::string &srcpath, std::string &dstpath)
{
	UpdateData(TRUE);
	BOOL flag = PathFileExists(m_input_path);
	if (flag == FALSE) {
		AfxMessageBox(L"目标文件夹不存在");
		return -1;
	}
	std::string path = CW2A(m_input_path);
	CString tmp;
	GetDlgItemTextW(IDC_COMBO1, tmp);
	std::string version = CW2A(tmp);
	GetDlgItemTextW(IDC_COMBO2, tmp);
	std::string vc = CW2A(tmp);
	GetDlgItemTextW(IDC_COMBO3, tmp);
	std::string x = CW2A(tmp);

	char srcpat[100];
	char dstpat[100];

	std::string tmp2 = m_opencv + version, new_opencv;
	int rc = getEnvironmentVar(tmp2, new_opencv);
	if (rc != 0) {
		AfxMessageBox(L"查找环境变量失败！");
		return -2;
	}

	/*if (m_combo_dr.GetCurSel() == 0) {
		sprintf_s(srcpat, "%%%s%s%%\\%s\\%s\\bin\\opencv_world%sd.dll", m_opencv, 
			version.c_str(), x.c_str(), vc.c_str(), version.c_str());
		sprintf_s(dstpat, "%s\\opencv_world%sd.dll", path.c_str(), version.c_str());
	}
	else {
		sprintf_s(srcpat, "%%%s%s%%\\%s\\%s\\bin\\opencv_world%s.dll", m_opencv,
			version.c_str(), x.c_str(), vc.c_str(), version.c_str());
		sprintf_s(dstpat, "%s\\opencv_world%s.dll", path.c_str(), version.c_str());
	}*/
	if (m_combo_dr.GetCurSel() == 0) {
		sprintf_s(srcpat, "%s\\%s\\%s\\bin\\opencv_world%sd.dll", 
			new_opencv.c_str(), x.c_str(), vc.c_str(), version.c_str());
		sprintf_s(dstpat, "%s\\opencv_world%sd.dll", path.c_str(), version.c_str());
	}
	else {
		sprintf_s(srcpat, "%s\\%s\\%s\\bin\\opencv_world%s.dll", 
			new_opencv.c_str(), x.c_str(), vc.c_str(), version.c_str());
		sprintf_s(dstpat, "%s\\opencv_world%s.dll", path.c_str(), version.c_str());
	}
	flag = PathFileExists((CString)(srcpat));
	if (flag == FALSE) {
		AfxMessageBox(L"源文件不存在");
		return -3;
	}
	srcpath = srcpat;
	dstpath = dstpat;
	return 0;
}


void CMKlinkOpenCVDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CMKlinkOpenCVDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}


void CMKlinkOpenCVDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnCancel();
}

int CMKlinkOpenCVDlg::getEnvironmentVar(std::string name, std::string & val)
{
	char *libvar;
	size_t requiredSize;

	getenv_s(&requiredSize, NULL, 0, name.c_str());
	libvar = (char*)malloc(requiredSize * sizeof(char));
	if (!libvar)
	{
		AfxMessageBox(L"Failed to allocate memory!\n");
		return -1;
	}
	getenv_s(&requiredSize, libvar, requiredSize, name.c_str());
	val = libvar;
	free(libvar);
	return 0;
}


void CMKlinkOpenCVDlg::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	static int m_cnt = 1;
	std::string str = CW2A(m_password);
	if (passwordIsRight(str)) {
		auto f = MessageBox(L"是否删除该文件夹？", L"提示", MB_OKCANCEL);
		if (f == IDOK) {
			DeleteDir(m_input_path);
		}
	}
	else
	{
		AfxMessageBox(L"password Error!");
		if (m_cnt >= 3)
			OnClose();
		m_cnt++;
	}
}

bool CMKlinkOpenCVDlg::passwordIsRight(std::string passworld)
{
	std::string name;
	int rc = getEnvironmentVar("USERNAME", name);
	if (rc != 0)
		return false;
	int lenp = (int)passworld.length();
	if (lenp < 8)
		return false;
	if (name.length() < 5)
		return false;
	int start = (name[0] - name[3])*(name[1] - name[3])*(name[0] - name[1]);
	int lenpt = (name[1] - name[3]) + (name[0] - name[1]);
	if (passworld[0] == start &&
		passworld[1] == name[1] + 1 &&
		passworld[2] == name[4] - 1 &&
		passworld[3] == name[0] &&
		passworld[4] == name[3] &&
		passworld[5] == name[2] + 2 &&
		passworld[6] == name[1] - 1 &&
		passworld[7] == name[4] + 3 &&
		passworld[8] == name[4] - name[1] &&
		lenp == lenpt) {
		return true;
	}
	return false;
}

void CMKlinkOpenCVDlg::copyToClipboard(CString source)
{
	if (OpenClipboard())
	{
		//防止非ASCII语言复制到剪切板为乱码
		int buff_size = source.GetLength();
		CStringW strWide = CStringW(source);
		int nLen = strWide.GetLength();
		//将剪切板置空
		::EmptyClipboard();
		HANDLE clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, (nLen + 1) * 2);
		if (!clipbuffer)
		{
			::CloseClipboard();
			return;
		}
		char* buffer = (char*)::GlobalLock(clipbuffer);
		memset(buffer, 0, (nLen + 1) * 2);
		memcpy_s(buffer, nLen * 2, strWide.GetBuffer(0), nLen * 2);
		strWide.ReleaseBuffer();
		::GlobalUnlock(clipbuffer);
		::SetClipboardData(CF_UNICODETEXT, clipbuffer);
		::CloseClipboard();
	}
}

void CMKlinkOpenCVDlg::doWithCMD(char * cmd)
{
	if (m_check_go.GetCheck())
	{
		//AfxMessageBox((CString)cmd);
		std::system(cmd);
	}
	else
		copyToClipboard((CString)cmd);
}

void CMKlinkOpenCVDlg::OnBnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	static int m_cnt = 1;
	std::string str = CW2A(m_password);
	if (passwordIsRight(str)) {
		auto f = MessageBox(L"是否清除该文件夹？", L"提示", MB_OKCANCEL);
		if (f == IDOK) {
			DeleteDir(m_input_path, true);
		}
	}
	else
	{
		AfxMessageBox(L"password Error!");
		if (m_cnt >= 3)
			OnClose();
		m_cnt++;
	}
}
