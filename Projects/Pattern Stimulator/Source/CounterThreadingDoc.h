
// CounterThreadingDoc.h : interface of the CCounterThreadingDoc class
//



#pragma once




class CCounterThreadingDoc : public CDocument
{
protected: // create from serialization only
	CCounterThreadingDoc();
	DECLARE_DYNCREATE(CCounterThreadingDoc)

// Attributes
public:
	int m_iYoffset;
	int m_iXoffset;
	int m_iWidth;
	int m_iHeight;
	int m_iColumns;
	int m_iRow;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CCounterThreadingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
