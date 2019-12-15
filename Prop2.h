#pragma once


// Prop2

class Prop2 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(Prop2)

public:
	Prop2();
	virtual ~Prop2();
	enum { IDD = IDD_PROP2 };
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual LRESULT OnWizardNext();
	BOOL m_football;
	BOOL m_basketball;
	BOOL m_volleyball;
	BOOL m_swim;
	
};


