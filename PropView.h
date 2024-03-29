﻿
// PropView.h: CPropView 类的接口
//

#pragma once
#include "Resource.h"
#include"PropSheet.h"
class CPropView : public CView
{

private:
	CString m_strSalary;
	BOOL m_bLike[4];
	int m_iOccupation;
	CString m_strWorkAddr;
protected: // 仅从序列化创建
	CPropView() noexcept;
	DECLARE_DYNCREATE(CPropView)

// 特性
public:
	CPropDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CPropView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPropertysheet();
};

#ifndef _DEBUG  // PropView.cpp 中的调试版本
inline CPropDoc* CPropView::GetDocument() const
   { return reinterpret_cast<CPropDoc*>(m_pDocument); }
#endif

