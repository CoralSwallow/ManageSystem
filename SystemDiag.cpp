// SystemDiag.cpp: 实现文件
//

#include "pch.h"
#include "ManageSystem.h"
#include "afxdialogex.h"
#include "SystemDiag.h"
#include "AddDlg.h"


// SystemDiag 对话框

IMPLEMENT_DYNAMIC(SystemDiag, CDialogEx)

SystemDiag::SystemDiag(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

SystemDiag::~SystemDiag()
{
}

void SystemDiag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, MyList);
}


BEGIN_MESSAGE_MAP(SystemDiag, CDialogEx)
	ON_WM_CLOSE()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &SystemDiag::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &SystemDiag::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &SystemDiag::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &SystemDiag::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &SystemDiag::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &SystemDiag::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &SystemDiag::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &SystemDiag::OnBnClickedButton7)
	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &SystemDiag::OnColumnclickList1)
END_MESSAGE_MAP()


// SystemDiag 消息处理程序


void SystemDiag::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog* pdlg = (CDialog*)AfxGetMainWnd();
	pdlg->DestroyWindow();
	CDialogEx::OnClose();
}


BOOL SystemDiag::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// TODO:  在此添加额外的初始化
	MyList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	MyList.InsertColumn(0, _T("使用人员"), 0, 140);
	MyList.InsertColumn(1, _T("使用时间"), 0, 140);
	MyList.InsertColumn(2, _T("使用金额"), 0, 140);
	MyList.InsertColumn(3, _T("收支情况"), 0, 140);
	MyList.InsertColumn(4, _T("用途"), 0, 140);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void SystemDiag::OnPaint()
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

void SystemDiag::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void SystemDiag::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < MyList.GetItemCount(); i++)
	{
		MyList.SetCheck(i,TRUE);
	}
}


void SystemDiag::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < MyList.GetItemCount(); i++)
	{
		MyList.SetCheck(i, !MyList.GetCheck(i));
	}
}


void SystemDiag::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	AddDlg dlg;
	dlg.DoModal();
	int nCount = MyList.GetItemCount();
	MyList.InsertItem(nCount, dlg.user);
	MyList.SetItemText(nCount, 1, dlg.time);
	MyList.SetItemText(nCount, 2, dlg.money);
	MyList.SetItemText(nCount, 3, dlg.IO);
	MyList.SetItemText(nCount, 4, dlg.use);
}


void SystemDiag::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < MyList.GetItemCount(); i++)
	{
		BOOL state = MyList.GetCheck(i);
		if (state)
		{
			MyList.DeleteItem(i);
			i--;
		}
	}
}


void SystemDiag::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < MyList.GetItemCount(); i++)
	{
		BOOL state = MyList.GetCheck(i);
		if (state)
		{
			AddDlg dlg;
			dlg.DoModal();

			MyList.SetItemText(i, 0, dlg.user);
			MyList.SetItemText(i, 1, dlg.time);
			MyList.SetItemText(i, 2, dlg.money);
			MyList.SetItemText(i, 3, dlg.IO);
			MyList.SetItemText(i, 4, dlg.use);
		}
	}
}


void SystemDiag::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fDlg(FALSE,".csv","Information",OFN_OVERWRITEPROMPT,"Excel文件(*.csv)|*.csv|所有文件(*.*)|(*.*)||",NULL);

	if (fDlg.DoModal() == IDOK)
	{
		CString Path = fDlg.GetPathName();
		//创建文件对象
		CStdioFile file(Path,CFile::modeWrite|CFile::modeCreate);

		//写入操作
		CString cs;
		for (int i = 0; i < MyList.GetItemCount(); i++)
		{
			cs = MyList.GetItemText(i, 0) + ",";
			cs += MyList.GetItemText(i, 1) + ",";
			cs += MyList.GetItemText(i, 2) + ",";
			cs += MyList.GetItemText(i, 3) + ",";
			cs += MyList.GetItemText(i, 4) + "\n";

			file.WriteString(cs);
		}
		file.Close(); 

	}

}


void SystemDiag::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fDlg(TRUE, ".csv", "Information", OFN_OVERWRITEPROMPT, "Excel文件(*.csv)|*.csv|所有文件(*.*)|(*.*)||", NULL);

	if (fDlg.DoModal() == IDOK)
	{
		CString Path = fDlg.GetPathName();
		//创建文件对象
		CStdioFile file(Path, CFile::modeRead);

		//读取操作
		CString cs;
		int index = 0;
		while (file.ReadString(cs))
		{
			int m, n, l, r, x, y, u, v;
			m = cs.Find(",");
			l = m + 1;
			r = cs.Find(",", l) - l;
			x = r + l + 1;
			y = cs.Find(",", x) - x;
			u = y + x + 1;
			v = cs.Find(",", u) - u;
			n = cs.GetLength() - cs.Find(",", u + v) - 1;
			MyList.InsertItem(index, cs.Left(m));
			MyList.SetItemText(index, 1, cs.Mid(l, r));
			MyList.SetItemText(index, 2, cs.Mid(x, y));
			MyList.SetItemText(index, 3, cs.Mid(u, v));
			MyList.SetItemText(index, 4, cs.Right(n));
			index++;
		}
	}
}

bool SystemDiag::method = false;  // 类外定义
int CALLBACK SystemDiag::listCompare(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	DATA* pListCtrl = (DATA*)lParamSort;
	int col = pListCtrl->subitem; //点击的列项传递给col，用来判断点击了第几列

	//CString header[]={"姓名","年龄","编号"};  //假设现在的列头是这几项

	//得到该列的前2项
	CString strItem1 = (pListCtrl->plist)->GetItemText(lParam1, col);
	CString strItem2 = (pListCtrl->plist)->GetItemText(lParam2, col);

	if (col == 0)  // CString
	{
		int tmp = strItem1.CompareNoCase(strItem2); //如果两个对象完全一致则返回0，如果小于lpsz，则返回-1。
		if (method) // true--升序
		{
			if (tmp <= 0)
				return -1;
			else
				return 1;
		}
		else
		{
			if (tmp >= 0)
				return -1;
			else
				return 1;
		}
	}
	else if (col == 1 || col == 2)  // int 
	{
		__int64 n1 = _atoi64(strItem1);
		__int64 n2 = _atoi64(strItem2);
		if (method)//
		{
			if (n1 <= n2)
				return -1;
			else
				return 1;
		}
		else
		{
			if (n1 >= n2)
				return -1;
			else
				return 1;
		}
	}
	return -1;  // -1表示第一项在第二项前面，0表示两项相等
}

void SystemDiag::OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	sort_column = pNMLV->iSubItem;//点击的列

	int count = MyList.GetItemCount();
	for (int i = 0; i < count; i++)
		MyList.SetItemData(i, i);

	DATA data;
	data.subitem = sort_column;
	data.plist = &MyList;

	method = !method;
	//m_ListCtrl.SortItems(listCompare,(LPARAM)&m_ListCtrl);  
	MyList.SortItems(listCompare, (LPARAM)&data);
	*pResult = 0;
}
