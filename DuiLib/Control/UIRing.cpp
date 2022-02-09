#include "StdAfx.h"
#include "UIRing.h"

namespace DuiLib
{
	IMPLEMENT_DUICONTROL(CRingUI)

	CRingUI::CRingUI() : m_fCurAngle(0.0f), m_pBkimage(NULL)
	{
	}

	CRingUI::~CRingUI()
	{
		if(m_pManager) m_pManager->KillTimer(this, RING_TIMERID);
	{
		m_pBkimage = CRenderEngine::GdiplusLoadImage(GetBkImage());
		if ( NULL == m_pBkimage ) return;
		if(m_pManager) m_pManager->SetTimer(this, RING_TIMERID, 100);
	}

	void CRingUI::DeleteImage()
	{
		if ( m_pBkimage != NULL )
		{
			delete m_pBkimage;
			m_pBkimage = NULL;
		}
	}
}
