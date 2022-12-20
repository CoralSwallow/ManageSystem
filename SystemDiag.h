#pragma once
#include "afxdialogex.h"

struct DATA
{
	int subitem;
	CListCtrl* plist;
};
// SystemDiag 对话框

class SystemDiag : public CDialogEx
{
	DECLARE_DYNAMIC(SystemDiag)

public:
	SystemDiag(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SystemDiag();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	// 这是显示班级财务信息的列表
	CListCtrl MyList;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	int sort_column;  // 表示需要排序的列
	static bool method;  //类内申明
	static int CALLBACK listCompare(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
	afx_msg void OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton8();
};
