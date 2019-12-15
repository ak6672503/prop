// PropSheet.cpp: 实现文件
//

#include "pch.h"
#include "Prop.h"
#include "PropSheet.h"


// PropSheet

IMPLEMENT_DYNAMIC(PropSheet, CMFCPropertySheet)

PropSheet::PropSheet()
{
	AddPage(&m_prop1);
	AddPage(&m_prop2);
	AddPage(&m_prop3);


}

PropSheet::~PropSheet()
{
}


BEGIN_MESSAGE_MAP(PropSheet, CMFCPropertySheet)
END_MESSAGE_MAP()



// PropSheet 消息处理程序


