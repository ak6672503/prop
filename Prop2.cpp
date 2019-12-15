// Prop2.cpp: 实现文件
//

#include "pch.h"
#include "Prop.h"
#include "Prop2.h"


// Prop2

IMPLEMENT_DYNAMIC(Prop2, CMFCPropertyPage)

Prop2::Prop2() :CMFCPropertyPage(Prop2::IDD)
, m_football(FALSE)
, m_basketball(FALSE)
, m_volleyball(FALSE)
, m_swim(FALSE)
{

}

Prop2::~Prop2()
{
}


BEGIN_MESSAGE_MAP(Prop2, CMFCPropertyPage)
END_MESSAGE_MAP()



// Prop2 消息处理程序




BOOL Prop2::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);

	return CMFCPropertyPage::OnSetActive();
}


void Prop2::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_football);
	DDX_Check(pDX, IDC_CHECK2, m_basketball);
	DDX_Check(pDX, IDC_CHECK3, m_volleyball);
	DDX_Check(pDX, IDC_CHECK4, m_swim);
}


LRESULT Prop2::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类

	UpdateData();
	if(m_football||m_basketball||m_volleyball||m_swim)
		return CMFCPropertyPage::OnWizardNext();

	else {
		MessageBox(L"请选择兴趣爱好！");
		return -1;

	}

}
