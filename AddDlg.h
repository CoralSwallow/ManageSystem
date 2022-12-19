#pragma once
#include "afxdialogex.h"


// AddDlg 对话框

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString user;
	CString time;
	CString money;
	CString IO;
	CString use;
	afx_msg void OnBnClickedButtonSubmit();
	afx_msg void OnCbnSelchangeCombo1();
};
