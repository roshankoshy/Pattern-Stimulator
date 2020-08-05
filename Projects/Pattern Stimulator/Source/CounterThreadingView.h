
// CounterThreadingView.h : interface of the CCounterThreadingView class
#include "CounterThreadingDoc.h"
#include "Values.h"
#pragma once


class CCounterThreadingView : public CView
{
protected: // create from serialization only
	CCounterThreadingView();
	DECLARE_DYNCREATE(CCounterThreadingView)
	CWinThread *pThread;
// Attributes
public:
	CCounterThreadingDoc* GetDocument() const;
	CArray<CPoint, CPoint> m_PointArray;
	CArray<CValues, CValues>m_Spiral;
	CArray<CValues, CValues>m_Cdamped;

// Operations
public:

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
	virtual ~CCounterThreadingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	long m_iCounter;
	long m_MatrixSize;
	long maxPoints;
	long points;
	long m_dRadius;
	long condition;
	afx_msg void OnThreadStart();
	afx_msg void OnPatternSelectpattern();
	afx_msg void OnOperationsStop();
};

#ifndef _DEBUG  // debug version in CounterThreadingView.cpp
inline CCounterThreadingDoc* CCounterThreadingView::GetDocument() const
   { return reinterpret_cast<CCounterThreadingDoc*>(m_pDocument); }
#endif

