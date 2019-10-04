#include "stdafx.h"
#include "nut.h"

void nut::ve(CClientDC *pDC)
{
	pDC->Rectangle(getA().x, getA().y, getC().x, getC().y);
	pDC->TextOutW(getA().x + 10, getA().y + 2, chu);
}
nut::nut()
{
}


nut::~nut()
{
}
