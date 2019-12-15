#pragma once


// Prop3

class Prop3 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(Prop3)

public:
	Prop3();
	virtual ~Prop3();
	enum { IDD = IDD_PROP3 };
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	CString m_strSalary;
	virtual BOOL OnWizardFinish();
	
};


