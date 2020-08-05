// TestThread.cpp : implementation file
//

#include "stdafx.h"
#include "CounterThreading.h"
#include "TestThread.h"
#include "CounterThreadingView.h"
#include"CounterThreadingDoc.h"
#include "Values.h"

// CTestThread

IMPLEMENT_DYNCREATE(CTestThread, CWinThread)

CTestThread::CTestThread()
{
}

CTestThread::~CTestThread()
{
}

BOOL CTestThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CTestThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CTestThread, CWinThread)
END_MESSAGE_MAP()


// CTestThread message handlers


UINT CTestThread::RunThreadFunction(LPVOID param)
{
	CCounterThreadingView *pCounterThreadingView = (CCounterThreadingView *)param;
	int local = pCounterThreadingView->condition;

	CPoint Point;
	CValues cdamp;

		if (local == 1)   //Random Walk
		{
			while (1)
			{
				Point.x = rand() / 100 + 150;
				Point.y = rand() / 100 + 150;
				pCounterThreadingView->m_PointArray.Add(Point);
				pCounterThreadingView->Invalidate();
				Sleep(100);
			}

		}

		else if (local == 2)   //Spiral
		{
			CValues values;

			while (values.m_dTheta <= 500)
			{
				values.m_dTheta += values.m_dDelta;
				values.m_dRadius = values.m_dTheta;
				values.m_dX = (values.m_dRadius* cos(values.m_dRadius / 10 * 3.14)) + values.m_dX;
				values.m_dY = (values.m_dRadius* sin(values.m_dRadius / 10 * 3.14)) + values.m_dY;
				pCounterThreadingView->m_Spiral.Add(values);
				pCounterThreadingView->Invalidate();
				Sleep(100);
			}

		}

		else if(local == 3)    //Damped harmonic Oscillation
		{
			while (1)
			{
				int t = 0;
				t = cdamp.m_dAmplitude;
				for (int i = 1; i < cdamp.m_dAmplitude; i++)
				{
					cdamp.m_dX1 += cdamp.m_dPeriod / t;
					t--;
					cdamp.m_dY1 -= 1;
					pCounterThreadingView->m_Cdamped.Add(cdamp);
				}
				t = 1;
				for (int j = cdamp.m_dAmplitude; j > 0; j--)
				{
					cdamp.m_dX1 += cdamp.m_dPeriod / t;
					t++;
					cdamp.m_dY1 += 1;
					pCounterThreadingView->m_Cdamped.Add(cdamp);
				}
				t = cdamp.m_dAmplitude;
				for (int i = 1; i < cdamp.m_dAmplitude; i++)
				{
					cdamp.m_dX1 += cdamp.m_dPeriod / t;
					t--;
					cdamp.m_dY1 += 1;
					pCounterThreadingView->m_Cdamped.Add(cdamp);
				}
				t = 1;
				for (int j = cdamp.m_dAmplitude; j > 0; j--)
				{
					cdamp.m_dX1 += cdamp.m_dPeriod / t;
					t++;
					cdamp.m_dY1 -= 1;
					pCounterThreadingView->m_Cdamped.Add(cdamp);
				}
				pCounterThreadingView->m_Cdamped.Add(cdamp);
				cdamp.m_dAmplitude -= 9;
				pCounterThreadingView->Invalidate();
				Sleep(500);
			}

		}
		return 0;
	}
	