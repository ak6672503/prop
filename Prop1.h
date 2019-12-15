#pragma once


// Prop1
class Prop1 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(Prop1)

public:
	Prop1();
	virtual ~Prop1();
	enum {IDD=IDD_PROP1};

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual void DoDataExchange(CDataExchange* pDX);
	int m_occupation;
	virtual LRESULT OnWizardNext();
	virtual BOOL OnInitDialog();
	CString m_workAddr;
	
};


