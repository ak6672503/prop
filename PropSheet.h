#pragma once

#include "Prop1.h"
#include "Prop2.h"
#include "Prop3.h"

// PropSheet





class PropSheet : public CMFCPropertySheet
{
	DECLARE_DYNAMIC(PropSheet)

public:
	PropSheet();
	virtual ~PropSheet();
	Prop1 m_prop1;
	Prop2 m_prop2;
	Prop3 m_prop3;
protected:
	DECLARE_MESSAGE_MAP()

	

};


