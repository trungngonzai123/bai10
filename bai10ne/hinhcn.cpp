#include "stdafx.h"
#include "hinhcn.h"

hinhcn::hinhcn(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	x1 = p1.x;
	y1 = p1.y;
	x2 = p2.x;
	y2 = p2.y;
}
hinhcn::hinhcn(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1; y1 = my1; x2 = mx2; y2 = my2;
}
void hinhcn::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1; y1 = my1; x2 = mx2; y2 = my2;
}
CPoint hinhcn::getA()
{
	return CPoint(x1, y1);
}
CPoint hinhcn::getC()
{
	return CPoint(x2, y2);
}
hinhcn::hinhcn()
{
}
void hinhcn::ve(CClientDC *pDC)
{
	pDC->Rectangle(x1, y1, x2, y2);
}
int hinhcn::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x > x1 &&p.y > y1 &&p.x < x2&&p.y < y2)
		kq = 1;
	return kq;
}



hinhcn::~hinhcn()
{
}
