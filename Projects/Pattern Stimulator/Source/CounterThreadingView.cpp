
// CounterThreadingView.cpp : implementation of the CCounterThreadingView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CounterThreading.h"
#endif

#include "CounterThreadingDoc.h"
#include "CounterThreadingView.h"
#include "TestThread.h"
#include "SelectPatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCounterThreadingView

IMPLEMENT_DYNCREATE(CCounterThreadingView, CView)

BEGIN_MESSAGE_MAP(CCounterThreadingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_THREAD_START, &CCounterThreadingView::OnThreadStart)
	ON_COMMAND(ID_PATTERN_SELECTPATTERN, &CCounterThreadingView::OnPatternSelectpattern)
	ON_COMMAND(ID_OPERATIONS_STOP, &CCounterThreadingView::OnOperationsStop)
END_MESSAGE_MAP()

// CCounterThreadingView construction/destruction

CCounterThreadingView::CCounterThreadingView()
	
{
	
	m_iCounter = 0;
}

CCounterThreadingView::~CCounterThreadingView()
{
}

BOOL CCounterThreadingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCounterThreadingView drawing

void CCounterThreadingView::OnDraw(CDC* pDC)
{
	CCounterThreadingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (condition == 1)
	{
		for (int i = 0; i < m_PointArray.GetSize() - 2; i++)
		{
			pDC->MoveTo(m_PointArray[i].x, m_PointArray[i].y);
			pDC->LineTo(m_PointArray[i + 1].x, m_PointArray[i + 1].y);
		}
	}


	else if (condition == 2)
	{

		pDC->MoveTo(400, 300);
		for (int i = 0; i <= (m_Spiral.GetSize() - 2); i++)
		{

			pDC->LineTo(m_Spiral[i].m_dX, m_Spiral[i].m_dY);
		}

	}


	else if (condition == 3)

	{
		pDC->MoveTo(10, 30);
		pDC->LineTo(10, 800);
		pDC->MoveTo(10, 200);
		pDC->LineTo(800, 200);
		

		pDC->MoveTo(10, 200);

		for (int i = 0; i <= m_Cdamped.GetSize() - 1; i++)
		{
			pDC->LineTo(m_Cdamped[i].m_dX1, m_Cdamped[i].m_dY1);

		}
	}
}


// CCounterThreadingView printing

BOOL CCounterThreadingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCounterThreadingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCounterThreadingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCounterThreadingView diagnostics

#ifdef _DEBUG
void CCounterThreadingView::AssertValid() const
{
	CView::AssertValid();
}

void CCounterThreadingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCounterThreadingDoc* CCounterThreadingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCounterThreadingDoc)));
	return (CCounterThreadingDoc*)m_pDocument;
}
#endif //_DEBUG


// CCounterThreadingView message handlers


void CCounterThreadingView::OnThreadStart()
{
	pThread = AfxBeginThread(CTestThread::RunThreadFunction, this);
}

void CCounterThreadingView::OnOperationsStop()
{
	pThread->SuspendThread();

}


void CCounterThreadingView::OnPatternSelectpattern()
{
	// TODO: Add your command handler code here
	CSelectPatternDlg select;
	if (select.DoModal() == IDOK)
	{
		if (select.m_SelectedData == ("Random Walk"))
		{
			condition = 1;
		}
		else if (select.m_SelectedData == ("Damped Harmonic Oscillator"))
		{
			condition = 3;
		}
		else if (select.m_SelectedData == ("Spiral Motion "))
		{
			condition = 2;
		}

	} UpdateData();
}


