// AddDlg.cpp: 实现文件
//

#include "pch.h"
#include "ManageSystem.h"
#include "afxdialogex.h"
#include "AddDlg.h"


// AddDlg 对话框

IMPLEMENT_DYNAMIC(AddDlg, CDialogEx)

AddDlg::AddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

AddDlg::~AddDlg()
{
}

void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Submit, &AddDlg::OnBnClickedButtonSubmit)
END_MESSAGE_MAP()


// AddDlg 消息处理程序


void AddDlg::OnBnClickedButtonSubmit()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_User, user);
	GetDlgItemText(IDC_EDIT_Time, time);
	GetDlgItemText(IDC_EDIT_Money, money);
	GetDlgItemText(IDC_EDIT_IO, IO);
	GetDlgItemText(IDC_EDIT_Use, use);
	EndDialog(0);
}


void AddDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}
