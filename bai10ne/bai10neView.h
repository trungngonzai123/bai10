
// bai10neView.h : interface of the Cbai10neView class
//

#pragma once
#include"hinh.h"
#include"nut.h"
#include"hinhcn.h"

class Cbai10neView : public CView
{
protected: // create from serialization only
	Cbai10neView() noexcept;
	DECLARE_DYNCREATE(Cbai10neView)

// Attributes
public:
	Cbai10neDoc* GetDocument() const;

// Operations
public:
	hinh *ph[20];
	int x1, y1, x2, y2;
	nut hinh1, hinh2, hinh3;
	CString ch, keychar;
	int n;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cbai10neView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in bai10neView.cpp
inline Cbai10neDoc* Cbai10neView::GetDocument() const
   { return reinterpret_cast<Cbai10neDoc*>(m_pDocument); }
#endif

