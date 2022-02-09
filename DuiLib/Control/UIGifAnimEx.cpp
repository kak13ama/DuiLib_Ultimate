#include "StdAfx.h"
#ifdef USE_XIMAGE_EFFECT
#include "UIGifAnimEx.h"
#include "../../3rd/CxImage/ximage.h"
//
namespace DuiLib
{
	#define GIFANIMUIEX_EVENT_TIEM_ID	100
	IMPLEMENT_DUICONTROL(CGifAnimExUI)
	struct CGifAnimExUI::Imp
	{
		bool				m_bRealStop			;//外部停止了
		}
		void StopAnim(bool bGoFirstFrame)//bGoFirstFrame 是否跑到第一帧
		{
			if(m_bTimer)
			{
				if(bGoFirstFrame)
				{
					m_nFramePosition = 0U;
					m_pOwer->Invalidate();
				}
				m_pManager->KillTimer( m_pOwer, GIFANIMUIEX_EVENT_TIEM_ID );
				m_bTimer = false;
			}
		}
		void EventOnTimer(const WPARAM idEvent )
		{
			if ( idEvent != GIFANIMUIEX_EVENT_TIEM_ID )
				return;
			++m_nFramePosition;
			if(m_nFramePosition >= m_nFrameCount)
				m_nFramePosition = 0;
			if(!m_pOwer->IsVisible())return;
			m_pOwer->Invalidate();
		}
		void DrawFrame( HDC hDC,const RECT& rcPaint,const RECT &rcItem)
		{
			if ( NULL == hDC || NULL == m_pGifImage ) return;
			if(m_pGifImage)
			{
				if (CxImage* pImage = m_pGifImage->GetFrame(m_nFramePosition))
					pImage->Draw2(hDC,rcItem);
			}
		}
		void EventSetVisible(bool bVisible)
		{
			if(bVisible)
			{
				if(!m_bRealStop)
					StartAnim();
			}
			else
				StopAnim(true);
		}
	};
	CGifAnimExUI::CGifAnimExUI(void):m_pImp(new CGifAnimExUI::Imp(m_pManager))
	{
		this;
		m_pImp->SetOwer(this);
	}
	CGifAnimExUI::~CGifAnimExUI(void)
	{
		m_pImp->StopAnim(false);
		delete m_pImp;
		m_pImp = nullptr;
	}
	LPCTSTR CGifAnimExUI::GetClass() const
	{
		return _T("GifAnimUI");
	}
	LPVOID CGifAnimExUI::GetInterface( LPCTSTR pstrName )
	{
			if( _tcscmp(pstrName, _T("GifAnim")) == 0 ) 
				return static_cast<CGifAnimExUI*>(this);
			return CLabelUI::GetInterface(pstrName);
	}
	void CGifAnimExUI::SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue)
	{
		if( _tcscmp(pstrName, _T("auto")) == 0 ) 
			m_pImp->SetAutoStart(_tcscmp(pstrValue, _T("true")) == 0);
		else
			__super::SetAttribute(pstrName, pstrValue);
	}
	void CGifAnimExUI::Init()
	{
		__super::Init();
		m_pImp->CheckLoadImage();
	}
	void CGifAnimExUI::SetVisible(bool bVisible /*= true*/)
	{
		__super::SetVisible(bVisible);
		m_pImp->EventSetVisible(bVisible);
	}
	void CGifAnimExUI::SetInternVisible(bool bVisible/* = true*/)
	{
		__super::SetInternVisible(bVisible);
		m_pImp->EventSetVisible(bVisible);
	}

	bool CGifAnimExUI::DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl)
	{
		if( !::IntersectRect( &m_rcPaint, &rcPaint, &m_rcItem ) ) return true;
		m_pImp->DrawFrame( hDC,rcPaint,m_rcItem);

		return true;
	}
	void CGifAnimExUI::DoEvent( TEventUI& event )
	{
		this;
		WPARAM nID = event.wParam;
		if( event.Type == UIEVENT_TIMER )
			m_pImp->EventOnTimer(nID);
	}
	void CGifAnimExUI::StartAnim()
	{
		m_pImp->m_bRealStop = false;
		m_pImp->StartAnim();
	}
	void CGifAnimExUI::StopAnim()
	{
		m_pImp->m_bRealStop = true;
		m_pImp->StopAnim(true);
	}
}
#endif//USE_XIMAGE_EFFECT