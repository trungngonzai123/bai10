
// bai10neView.cpp : implementation of the Cbai10neView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "bai10ne.h"
#endif

#include "bai10neDoc.h"
#include "bai10neView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbai10neView

IMPLEMENT_DYNCREATE(Cbai10neView, CView)

BEGIN_MESSAGE_MAP(Cbai10neView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cbai10neView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cbai10neView construction/destruction

Cbai10neView::Cbai10neView() noexcept
{
	// TODO: add construction code here
	n = 0;
	hinh1.thietlap(50, 50, 100, 100);
	hinh1.chu = CString(" ");
	hinh2.thietlap(120, 40, 180, 60);
	hinh2.chu = CString(" Xuat");
	hinh3.thietlap(120, 90, 180, 110);
	hinh3.chu = CString("Reset");


}

Cbai10neView::~Cbai10neView()
{
}

BOOL Cbai10neView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cbai10neView drawing

void Cbai10neView::OnDraw(CDC* /*pDC*/)
{
	Cbai10neDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pDC(this);
	hinh1.ve(&pDC);
	hinh2.ve(&pDC);
	hinh3.ve(&pDC);


	// TODO: add draw code for native data here
}


// Cbai10neView printing


void Cbai10neView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cbai10neView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cbai10neView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cbai10neView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

//void Cbai10neView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

void Cbai10neView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cbai10neView diagnostics

#ifdef _DEBUG
void Cbai10neView::AssertValid() const
{
	CView::AssertValid();
}

void Cbai10neView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cbai10neDoc* Cbai10neView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cbai10neDoc)));
	return (Cbai10neDoc*)m_pDocument;
}
#endif //_DEBUG


// Cbai10neView message handlers


void Cbai10neView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	int keyso;
	// TODO: Add your message handler code here and/or call default
	keyso = nChar;
	CClientDC pDC(this);
	keychar = (char)keyso;
	pDC.Rectangle(50, 50, 100, 100);
	pDC.TextOutW(70, 70, keychar);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Cbai10neView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//hinh2.thietlap(120, 40, 180, 60);
	CClientDC pDC(this);
	if (point.x > 120 && point.y > 40 && point.x < 180 && point.y < 60)
	{
		//hinh4.thietlap(300, 200, 500, 400);
		pDC.Rectangle(300, 200, 500, 400);
		pDC.TextOutW(400, 300, keychar);
	}
	//hinh3.thietlap(120, 90, 180, 110);
	else 
		if (point.x > 120 && point.y > 90 && point.x < 180 && point.y < 110)
	{
			pDC.Rectangle(300, 200, 500, 400);
			pDC.Rectangle(50, 50, 100, 100);
	}
	CView::OnLButtonDown(nFlags, point);
}
