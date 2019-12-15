// Prop1.cpp: 实现文件
//

#include "pch.h"
#include "Prop.h"
#include "Prop1.h"


// Prop1

IMPLEMENT_DYNAMIC(Prop1, CMFCPropertyPage)

Prop1::Prop1() :CMFCPropertyPage(Prop1::IDD)
, m_occupation(-1)
, m_workAddr(_T(""))
{

}

Prop1::~Prop1()
{
}


BEGIN_MESSAGE_MAP(Prop1, CMFCPropertyPage)
END_MESSAGE_MAP()



// Prop1 消息处理程序




BOOL Prop1::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);
	return CMFCPropertyPage::OnSetActive();
}


void Prop1::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_occupation);
	DDX_LBString(pDX, IDC_LIST1, m_workAddr);
}


LRESULT Prop1::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类
	UpdateData();
	if (m_occupation == -1)
	{
		MessageBox(L"请选择你的职业！");
		return -1;
	}
	if (m_workAddr == "") {
		MessageBox(L"请选择工作地点！");
		return -1;
	}
	return CMFCPropertyPage::OnWizardNext();
}


BOOL Prop1::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(L"北京");
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(L"天津");
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(L"上海");


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
