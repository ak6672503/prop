// Prop3.cpp: 实现文件
//

#include "pch.h"
#include "Prop.h"
#include "Prop3.h"


// Prop3

IMPLEMENT_DYNAMIC(Prop3, CMFCPropertyPage)

Prop3::Prop3() :CMFCPropertyPage(Prop3::IDD)
{

}

Prop3::~Prop3()
{
}


BEGIN_MESSAGE_MAP(Prop3, CMFCPropertyPage)
END_MESSAGE_MAP()



// Prop3 消息处理程序




BOOL Prop3::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);

	return CMFCPropertyPage::OnSetActive();
}


void Prop3::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CMFCPropertyPage::DoDataExchange(pDX);
}


BOOL Prop3::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(L"3000");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(L"3000-5000");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(L"5000-8000");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(L"8000-9000");

	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL Prop3::OnWizardFinish()
{
	// TODO: 在此添加专用代码和/或调用基类
	int index;
	index = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetLBText(index, m_strSalary);
	return CMFCPropertyPage::OnWizardFinish();
}
