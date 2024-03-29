﻿
// PropView.cpp: CPropView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Prop.h"
#endif

#include "PropDoc.h"
#include "PropView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPropView

IMPLEMENT_DYNCREATE(CPropView, CView)

BEGIN_MESSAGE_MAP(CPropView, CView)
	ON_COMMAND(IDM_PROPERTYSHEET, &CPropView::OnPropertysheet)
END_MESSAGE_MAP()

// CPropView 构造/析构

CPropView::CPropView() noexcept
{
	// TODO: 在此处添加构造代码
	m_iOccupation = -1;
	m_strWorkAddr = "";
	memset(m_bLike, 0, sizeof(m_bLike));
	m_strSalary = "";

}

CPropView::~CPropView()
{
}

BOOL CPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPropView 绘图

void CPropView::OnDraw(CDC* pDC)
{
	CPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;



	CFont font;
	font.CreatePointFont(300, L"宋体");
	CFont* pOldFont;
	pOldFont = pDC->SelectObject(&font);

	CString strTemp;
	strTemp = L"你的职业：";

	switch (m_iOccupation) {
	case 0:
		strTemp += L"程序员";
		break;
	case 1:
		strTemp += L"系统工程师";
		break;
	case 2:
		strTemp += L"项目经理";
		break;
	default:
		break;
	}
	pDC->TextOutW(0, 0, strTemp);

	strTemp = L"你的工作地点：";
	strTemp += m_strWorkAddr;

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	
	pDC->TextOutW(0, tm.tmHeight, strTemp);

	strTemp = L"你的兴趣爱好：";
	if (m_bLike[0]) {
		strTemp += L"足球";
	}
	if (m_bLike[1]) {
		strTemp += L"篮球";
	}
	if (m_bLike[2]) {
		strTemp += L"排球";
	}
	if (m_bLike[3]) {
		strTemp += L"游泳";
	}
	pDC->TextOutW(0, tm.tmHeight*2, strTemp);

	strTemp = L"你的薪水：";
	strTemp += m_strSalary;
	pDC->TextOutW(0, tm.tmHeight * 3, strTemp);
	pDC->SelectObject(pOldFont);

}


// CPropView 诊断

#ifdef _DEBUG
void CPropView::AssertValid() const
{
	CView::AssertValid();
}

void CPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropDoc* CPropView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropDoc)));
	return (CPropDoc*)m_pDocument;
}
#endif //_DEBUG


// CPropView 消息处理程序


void CPropView::OnPropertysheet()
{
	PropSheet propSheet;
	propSheet.SetWizardMode();
	if (ID_WIZFINISH == propSheet.DoModal()) {
		m_iOccupation = propSheet.m_prop1.m_occupation;
		m_strWorkAddr = propSheet.m_prop1.m_workAddr;
		m_bLike[0] = propSheet.m_prop2.m_football;
		m_bLike[1] = propSheet.m_prop2.m_basketball;
		m_bLike[2] = propSheet.m_prop2.m_volleyball;
		m_bLike[3] = propSheet.m_prop2.m_swim;
		m_strSalary = propSheet.m_prop3.m_strSalary;
		Invalidate();
	}

	

}
