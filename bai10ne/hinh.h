#pragma once
class hinh
{

public:
	CPoint point1, point2;
	virtual void ve(CClientDC *pDC);
	virtual int tronghinh(CPoint p);
	CString chu;
	hinh();
	~hinh();
};

