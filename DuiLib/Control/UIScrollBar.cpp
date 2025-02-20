#include "StdAfx.h"
#include "UIScrollBar.h"

namespace DuiLib
{
	IMPLEMENT_DUICONTROL(CScrollBarUI)

	CScrollBarUI::CScrollBarUI() : m_bHorizontal(false), m_nRange(0), m_nScrollPos(0), m_nLineSize(8), 
		m_pOwner(NULL), m_nLastScrollPos(0), m_nLastScrollOffset(0), m_nScrollRepeatDelay(0), m_uButton1State(0), \
		m_uButton2State(0), m_uThumbState(0), m_bShowButton1(true), m_bShowButton2(true)
	{
		m_cxyFixed.cx = DEFAULT_SCROLLBAR_SIZE;
		m_ptLastMouse.x = m_ptLastMouse.y = 0;
		::ZeroMemory(&m_rcThumb, sizeof(m_rcThumb));
			}
		}
		else {
			if( m_cxyFixed.cx == 0 ) {
				m_cxyFixed.cx = DEFAULT_SCROLLBAR_SIZE;
				m_cxyFixed.cy = 0;
			}
		}

		if( m_pOwner != NULL ) m_pOwner->NeedUpdate(); else NeedParentUpdate();
	}

	int CScrollBarUI::GetScrollRange() const
	{
		return m_nRange;
	}

	void CScrollBarUI::SetScrollRange(int nRange)
	{
		if( m_nRange == nRange ) return;

		m_nRange = nRange;
		if( m_nRange < 0 ) m_nRange = 0;
		if( m_nScrollPos > m_nRange ) m_nScrollPos = m_nRange;
		SetPos(m_rcItem);
	}

	int CScrollBarUI::GetScrollPos() const
	{
		return m_nScrollPos;
	}

	void CScrollBarUI::SetScrollPos(int nPos)
	{
		if( m_nScrollPos == nPos ) return;

		m_nScrollPos = nPos;
		if( m_nScrollPos < 0 ) m_nScrollPos = 0;
		if( m_nScrollPos > m_nRange ) m_nScrollPos = m_nRange;
		SetPos(m_rcItem);
	}

	int CScrollBarUI::GetLineSize() const
	{
		return m_nLineSize;
	}

	void CScrollBarUI::SetLineSize(int nSize)
	{
		m_nLineSize = nSize;
	}

	bool CScrollBarUI::GetShowButton1()
	{
		return m_bShowButton1;
	}

	void CScrollBarUI::SetShowButton1(bool bShow)
	{
		m_bShowButton1 = bShow;
		SetPos(m_rcItem);
	}

	LPCTSTR CScrollBarUI::GetButton1NormalImage()
	{
		return m_sButton1NormalImage;
	}

	void CScrollBarUI::SetButton1NormalImage(LPCTSTR pStrImage)
	{
		m_sButton1NormalImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetButton1HotImage()
	{
		return m_sButton1HotImage;
	}

	void CScrollBarUI::SetButton1HotImage(LPCTSTR pStrImage)
	{
		m_sButton1HotImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetButton1PushedImage()
	{
		return m_sButton1PushedImage;
	}

	void CScrollBarUI::SetButton1PushedImage(LPCTSTR pStrImage)
	{
		m_sButton1PushedImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetButton1DisabledImage()
	{
		return m_sButton1DisabledImage;
	}

	void CScrollBarUI::SetButton1DisabledImage(LPCTSTR pStrImage)
	{
		m_sButton1DisabledImage = pStrImage;
		Invalidate();
	}

	bool CScrollBarUI::GetShowButton2()
	{
		return m_bShowButton2;
	}

	void CScrollBarUI::SetShowButton2(bool bShow)
	{
		m_bShowButton2 = bShow;
		SetPos(m_rcItem);
	}

	LPCTSTR CScrollBarUI::GetButton2NormalImage()
	{
		return m_sButton2NormalImage;
	}

	void CScrollBarUI::SetButton2NormalImage(LPCTSTR pStrImage)
	{
		m_sButton2NormalImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetButton2HotImage()
	{
		return m_sButton2HotImage;
	}

	void CScrollBarUI::SetButton2HotImage(LPCTSTR pStrImage)
	{
		m_sButton2HotImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetButton2PushedImage()
	{
		return m_sButton2PushedImage;
	}

	void CScrollBarUI::SetButton2PushedImage(LPCTSTR pStrImage)
	{
		m_sButton2PushedImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetButton2DisabledImage()
	{
		return m_sButton2DisabledImage;
	}

	void CScrollBarUI::SetButton2DisabledImage(LPCTSTR pStrImage)
	{
		m_sButton2DisabledImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetThumbNormalImage()
	{
		return m_sThumbNormalImage;
	}

	void CScrollBarUI::SetThumbNormalImage(LPCTSTR pStrImage)
	{
		m_sThumbNormalImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetThumbHotImage()
	{
		return m_sThumbHotImage;
	}

	void CScrollBarUI::SetThumbHotImage(LPCTSTR pStrImage)
	{
		m_sThumbHotImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetThumbPushedImage()
	{
		return m_sThumbPushedImage;
	}

	void CScrollBarUI::SetThumbPushedImage(LPCTSTR pStrImage)
	{
		m_sThumbPushedImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetThumbDisabledImage()
	{
		return m_sThumbDisabledImage;
	}

	void CScrollBarUI::SetThumbDisabledImage(LPCTSTR pStrImage)
	{
		m_sThumbDisabledImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetRailNormalImage()
	{
		return m_sRailNormalImage;
	}

	void CScrollBarUI::SetRailNormalImage(LPCTSTR pStrImage)
	{
		m_sRailNormalImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetRailHotImage()
	{
		return m_sRailHotImage;
	}

	void CScrollBarUI::SetRailHotImage(LPCTSTR pStrImage)
	{
		m_sRailHotImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetRailPushedImage()
	{
		return m_sRailPushedImage;
	}

	void CScrollBarUI::SetRailPushedImage(LPCTSTR pStrImage)
	{
		m_sRailPushedImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetRailDisabledImage()
	{
		return m_sRailDisabledImage;
	}

	void CScrollBarUI::SetRailDisabledImage(LPCTSTR pStrImage)
	{
		m_sRailDisabledImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetBkNormalImage()
	{
		return m_sBkNormalImage;
	}

	void CScrollBarUI::SetBkNormalImage(LPCTSTR pStrImage)
	{
		m_sBkNormalImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetBkHotImage()
	{
		return m_sBkHotImage;
	}

	void CScrollBarUI::SetBkHotImage(LPCTSTR pStrImage)
	{
		m_sBkHotImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetBkPushedImage()
	{
		return m_sBkPushedImage;
	}

	void CScrollBarUI::SetBkPushedImage(LPCTSTR pStrImage)
	{
		m_sBkPushedImage = pStrImage;
		Invalidate();
	}

	LPCTSTR CScrollBarUI::GetBkDisabledImage()
	{
		return m_sBkDisabledImage;
	}

	void CScrollBarUI::SetBkDisabledImage(LPCTSTR pStrImage)
	{
		m_sBkDisabledImage = pStrImage;
		Invalidate();
	}

	void CScrollBarUI::SetPos(RECT rc, bool bNeedInvalidate)
	{
		CControlUI::SetPos(rc, bNeedInvalidate);
		SIZE cxyFixed = m_cxyFixed;
		if (m_pManager != NULL) {
			GetManager()->GetDPIObj()->Scale(&cxyFixed);
		}
		rc = m_rcItem;
		if( m_bHorizontal ) {
			int cx = rc.right - rc.left;
			if( m_bShowButton1 ) cx -= cxyFixed.cy;
			if( m_bShowButton2 ) cx -= cxyFixed.cy;
			if( cx > cxyFixed.cy ) {
				m_rcButton1.left = rc.left;
				m_rcButton1.top = rc.top;
				if( m_bShowButton1 ) {
					m_rcButton1.right = rc.left + cxyFixed.cy;
					m_rcButton1.bottom = rc.top + cxyFixed.cy;
				}
				else {
					m_rcButton1.right = m_rcButton1.left;
					m_rcButton1.bottom = m_rcButton1.top;
				}

				m_rcButton2.top = rc.top;
				m_rcButton2.right = rc.right;
				if( m_bShowButton2 ) {
					m_rcButton2.left = rc.right - cxyFixed.cy;
					m_rcButton2.bottom = rc.top + cxyFixed.cy;
				}
				else {
					m_rcButton2.left = m_rcButton2.right;
					m_rcButton2.bottom = m_rcButton2.top;
				}

				m_rcThumb.top = rc.top;
				m_rcThumb.bottom = rc.top + cxyFixed.cy;
				if( m_nRange > 0 ) {
					int cxThumb = cx * (rc.right - rc.left) / (m_nRange + rc.right - rc.left);
					if( cxThumb < cxyFixed.cy ) cxThumb = cxyFixed.cy;

					m_rcThumb.left = m_nScrollPos * (cx - cxThumb) / m_nRange + m_rcButton1.right;
					m_rcThumb.right = m_rcThumb.left + cxThumb;
					if( m_rcThumb.right > m_rcButton2.left ) {
						m_rcThumb.left = m_rcButton2.left - cxThumb;
						m_rcThumb.right = m_rcButton2.left;
					}
				}
				else {
					m_rcThumb.left = m_rcButton1.right;
					m_rcThumb.right = m_rcButton2.left;
				}
			}
			else {
				int cxButton = (rc.right - rc.left) / 2;
				if( cxButton > cxyFixed.cy ) cxButton = cxyFixed.cy;
				m_rcButton1.left = rc.left;
				m_rcButton1.top = rc.top;
				if( m_bShowButton1 ) {
					m_rcButton1.right = rc.left + cxButton;
					m_rcButton1.bottom = rc.top + cxyFixed.cy;
				}
				else {
					m_rcButton1.right = m_rcButton1.left;
					m_rcButton1.bottom = m_rcButton1.top;
				}

				m_rcButton2.top = rc.top;
				m_rcButton2.right = rc.right;
				if( m_bShowButton2 ) {
					m_rcButton2.left = rc.right - cxButton;
					m_rcButton2.bottom = rc.top + cxyFixed.cy;
				}
				else {
					m_rcButton2.left = m_rcButton2.right;
					m_rcButton2.bottom = m_rcButton2.top;
				}

				::ZeroMemory(&m_rcThumb, sizeof(m_rcThumb));
			}
		}
		else {
			int cy = rc.bottom - rc.top;
			if( m_bShowButton1 ) cy -= cxyFixed.cx;
			if( m_bShowButton2 ) cy -= cxyFixed.cx;
			if( cy > cxyFixed.cx ) {
				m_rcButton1.left = rc.left;
				m_rcButton1.top = rc.top;
				if( m_bShowButton1 ) {
					m_rcButton1.right = rc.left + cxyFixed.cx;
					m_rcButton1.bottom = rc.top + cxyFixed.cx;
				}
				else {
					m_rcButton1.right = m_rcButton1.left;
					m_rcButton1.bottom = m_rcButton1.top;
				}

				m_rcButton2.left = rc.left;
				m_rcButton2.bottom = rc.bottom;
				if( m_bShowButton2 ) {
					m_rcButton2.top = rc.bottom - cxyFixed.cx;
					m_rcButton2.right = rc.left + cxyFixed.cx;
				}
				else {
					m_rcButton2.top = m_rcButton2.bottom;
					m_rcButton2.right = m_rcButton2.left;
				}

				m_rcThumb.left = rc.left;
				m_rcThumb.right = rc.left + cxyFixed.cx;
				if( m_nRange > 0 ) {
					int cyThumb = cy * (rc.bottom - rc.top) / (m_nRange + rc.bottom - rc.top);
					if( cyThumb < cxyFixed.cx ) cyThumb = cxyFixed.cx;

					m_rcThumb.top = (m_nScrollPos * 1.0f / m_nRange) * (cy - cyThumb) + m_rcButton1.bottom;
					m_rcThumb.bottom = m_rcThumb.top + cyThumb;
					if( m_rcThumb.bottom > m_rcButton2.top ) {
						m_rcThumb.top = m_rcButton2.top - cyThumb;
						m_rcThumb.bottom = m_rcButton2.top;
					}
				}
				else {
					m_rcThumb.top = m_rcButton1.bottom;
					m_rcThumb.bottom = m_rcButton2.top;
				}
			}
			else {
				int cyButton = (rc.bottom - rc.top) / 2;
				if( cyButton > cxyFixed.cx ) cyButton = cxyFixed.cx;
				m_rcButton1.left = rc.left;
				m_rcButton1.top = rc.top;
				if( m_bShowButton1 ) {
					m_rcButton1.right = rc.left + cxyFixed.cx;
					m_rcButton1.bottom = rc.top + cyButton;
				}
				else {
					m_rcButton1.right = m_rcButton1.left;
					m_rcButton1.bottom = m_rcButton1.top;
				}

				m_rcButton2.left = rc.left;
				m_rcButton2.bottom = rc.bottom;
				if( m_bShowButton2 ) {
					m_rcButton2.top = rc.bottom - cyButton;
					m_rcButton2.right = rc.left + cxyFixed.cx;
				}
				else {
					m_rcButton2.top = m_rcButton2.bottom;
					m_rcButton2.right = m_rcButton2.left;
				}

				::ZeroMemory(&m_rcThumb, sizeof(m_rcThumb));
			}
		}
	}

	void CScrollBarUI::DoEvent(TEventUI& event)
	{
		if( !IsMouseEnabled() && event.Type > UIEVENT__MOUSEBEGIN && event.Type < UIEVENT__MOUSEEND ) {
			if( m_pOwner != NULL ) m_pOwner->DoEvent(event);
			else CControlUI::DoEvent(event);
			return;
		}

		if( event.Type == UIEVENT_SETFOCUS ) 
		{
			return;
		}
		if( event.Type == UIEVENT_KILLFOCUS ) 
		{
			return;
		}
		if( event.Type == UIEVENT_BUTTONDOWN || event.Type == UIEVENT_DBLCLICK )
		{
			if( !IsEnabled() ) return;

			m_nLastScrollOffset = 0;
			m_nScrollRepeatDelay = 0;

			if( ::PtInRect(&m_rcButton1, event.ptMouse) ) {
				m_uButton1State |= UISTATE_PUSHED;
				if( !m_bHorizontal ) {
					if( m_pOwner != NULL ) m_pOwner->LineUp(); 
					else SetScrollPos(m_nScrollPos - m_nLineSize);
				}
				else {
					if( m_pOwner != NULL ) m_pOwner->LineLeft(); 
					else SetScrollPos(m_nScrollPos - m_nLineSize);
				}
			}
			else if( ::PtInRect(&m_rcButton2, event.ptMouse) ) {
				m_uButton2State |= UISTATE_PUSHED;
				if( !m_bHorizontal ) {
					if( m_pOwner != NULL ) m_pOwner->LineDown(); 
					else SetScrollPos(m_nScrollPos + m_nLineSize);
				}
				else {
					if( m_pOwner != NULL ) m_pOwner->LineRight(); 
					else SetScrollPos(m_nScrollPos + m_nLineSize);
				}
			}
			else if( ::PtInRect(&m_rcThumb, event.ptMouse) ) {
				m_uThumbState |= UISTATE_CAPTURED | UISTATE_PUSHED;
				m_ptLastMouse = event.ptMouse;
				m_nLastScrollPos = m_nScrollPos;
				
				m_pManager->SetTimer(this, DEFAULT_TIMERID, 50U);
			}
			else {
				if( !m_bHorizontal ) {
					if( event.ptMouse.y < m_rcThumb.top ) {
						if( m_pOwner != NULL ) m_pOwner->PageUp(); 
						else SetScrollPos(m_nScrollPos + m_rcItem.top - m_rcItem.bottom);
					}
					else if ( event.ptMouse.y > m_rcThumb.bottom ){
						if( m_pOwner != NULL ) m_pOwner->PageDown(); 
						else SetScrollPos(m_nScrollPos - m_rcItem.top + m_rcItem.bottom);                    
					}
				}
				else {
					if( event.ptMouse.x < m_rcThumb.left ) {
						if( m_pOwner != NULL ) m_pOwner->PageLeft(); 
						else SetScrollPos(m_nScrollPos + m_rcItem.left - m_rcItem.right);
					}
					else if ( event.ptMouse.x > m_rcThumb.right ){
						if( m_pOwner != NULL ) m_pOwner->PageRight(); 
						else SetScrollPos(m_nScrollPos - m_rcItem.left + m_rcItem.right);                    
					}
				}
			}
			if( m_pManager != NULL) m_pManager->SendNotify(this, DUI_MSGTYPE_SCROLL);
			return;
		}
		if( event.Type == UIEVENT_BUTTONUP )
		{
			m_nScrollRepeatDelay = 0;
			m_nLastScrollOffset = 0;
			m_pManager->KillTimer(this, DEFAULT_TIMERID);

			if( (m_uThumbState & UISTATE_CAPTURED) != 0 ) {
				m_uThumbState &= ~( UISTATE_CAPTURED | UISTATE_PUSHED );
				Invalidate();
			}
			else if( (m_uButton1State & UISTATE_PUSHED) != 0 ) {
				m_uButton1State &= ~UISTATE_PUSHED;
				Invalidate();
			}
			else if( (m_uButton2State & UISTATE_PUSHED) != 0 ) {
				m_uButton2State &= ~UISTATE_PUSHED;
				Invalidate();
			}
			return;
		}
		if( event.Type == UIEVENT_MOUSEMOVE )
		{
			if( (m_uThumbState & UISTATE_CAPTURED) != 0 ) {
				if( !m_bHorizontal ) {
					__int64 fMouseRange = (event.ptMouse.y - m_ptLastMouse.y) * m_nRange;
					int nBtnSize = 0;
					if(GetShowButton1()) nBtnSize += m_cxyFixed.cx;
					if(GetShowButton2()) nBtnSize += m_cxyFixed.cx;
					int vRange = m_rcItem.bottom - m_rcItem.top - (m_rcThumb.bottom - m_rcThumb.top) - nBtnSize;
					if (vRange != 0){
						m_nLastScrollOffset = fMouseRange / abs(vRange);
					}
				}
				else {
					__int64 fMouseRange = (event.ptMouse.x - m_ptLastMouse.x) * m_nRange;
					int nBtnSize = 0;
					if(GetShowButton1()) nBtnSize += m_cxyFixed.cy;
					if(GetShowButton2()) nBtnSize += m_cxyFixed.cy;
					int hRange = m_rcItem.right - m_rcItem.left - m_rcThumb.right + m_rcThumb.left - nBtnSize;
					if (hRange != 0) m_nLastScrollOffset = fMouseRange / abs(hRange);
				}
			}
			else {
				if( (m_uThumbState & UISTATE_HOT) != 0 ) {
					if( !::PtInRect(&m_rcThumb, event.ptMouse) ) {
						m_uThumbState &= ~UISTATE_HOT;
						Invalidate();
					}
				}
				else {
					if( !IsEnabled() ) return;
					if( ::PtInRect(&m_rcThumb, event.ptMouse) ) {
						m_uThumbState |= UISTATE_HOT;
						Invalidate();
					}
				}
			}
			return;
		}
		if( event.Type == UIEVENT_CONTEXTMENU )
		{
			return;
		}
		if( event.Type == UIEVENT_TIMER && event.wParam == DEFAULT_TIMERID )
		{
			++m_nScrollRepeatDelay;
			if( (m_uThumbState & UISTATE_CAPTURED) != 0 ) {
				if( !m_bHorizontal ) {
					if( m_pOwner != NULL ) m_pOwner->SetScrollPos(CDuiSize(m_pOwner->GetScrollPos().cx, \
						m_nLastScrollPos + m_nLastScrollOffset)); 
					else SetScrollPos(m_nLastScrollPos + m_nLastScrollOffset);
				}
				else {
					if( m_pOwner != NULL ) m_pOwner->SetScrollPos(CDuiSize(m_nLastScrollPos + m_nLastScrollOffset, \
						m_pOwner->GetScrollPos().cy)); 
					else SetScrollPos(m_nLastScrollPos + m_nLastScrollOffset);
				}
				Invalidate();
			}
			else if( (m_uButton1State & UISTATE_PUSHED) != 0 ) {
				if( m_nScrollRepeatDelay <= 5 ) return;
				if( !m_bHorizontal ) {
					if( m_pOwner != NULL ) m_pOwner->LineUp(); 
					else SetScrollPos(m_nScrollPos - m_nLineSize);
				}
				else {
					if( m_pOwner != NULL ) m_pOwner->LineLeft(); 
					else SetScrollPos(m_nScrollPos - m_nLineSize);
				}
			}
			else if( (m_uButton2State & UISTATE_PUSHED) != 0 ) {
				if( m_nScrollRepeatDelay <= 5 ) return;
				if( !m_bHorizontal ) {
					if( m_pOwner != NULL ) m_pOwner->LineDown(); 
					else SetScrollPos(m_nScrollPos + m_nLineSize);
				}
				else {
					if( m_pOwner != NULL ) m_pOwner->LineRight(); 
					else SetScrollPos(m_nScrollPos + m_nLineSize);
				}
			}
			else {
				if( m_nScrollRepeatDelay <= 5 ) return;
				POINT pt = { 0 };
				::GetCursorPos(&pt);
				::ScreenToClient(m_pManager->GetPaintWindow(), &pt);
				if( !m_bHorizontal ) {
					if( pt.y < m_rcThumb.top ) {
						if( m_pOwner != NULL ) m_pOwner->PageUp(); 
						else SetScrollPos(m_nScrollPos + m_rcItem.top - m_rcItem.bottom);
					}
					else if ( pt.y > m_rcThumb.bottom ){
						if( m_pOwner != NULL ) m_pOwner->PageDown(); 
						else SetScrollPos(m_nScrollPos - m_rcItem.top + m_rcItem.bottom);                    
					}
				}
				else {
					if( pt.x < m_rcThumb.left ) {
						if( m_pOwner != NULL ) m_pOwner->PageLeft(); 
						else SetScrollPos(m_nScrollPos + m_rcItem.left - m_rcItem.right);
					}
					else if ( pt.x > m_rcThumb.right ){
						if( m_pOwner != NULL ) m_pOwner->PageRight(); 
						else SetScrollPos(m_nScrollPos - m_rcItem.left + m_rcItem.right);                    
					}
				}
			}
			if( m_pManager != NULL ) m_pManager->SendNotify(this, DUI_MSGTYPE_SCROLL);
			return;
		}
		if( event.Type == UIEVENT_MOUSEENTER )
		{
			if( IsEnabled() ) {
				m_uButton1State |= UISTATE_HOT;
				m_uButton2State |= UISTATE_HOT;
				if( ::PtInRect(&m_rcThumb, event.ptMouse) ) m_uThumbState |= UISTATE_HOT;
				Invalidate();
			}
			return;
		}
		if( event.Type == UIEVENT_MOUSELEAVE )
		{
			if( IsEnabled() ) {
				m_uButton1State &= ~UISTATE_HOT;
				m_uButton2State &= ~UISTATE_HOT;
				m_uThumbState &= ~UISTATE_HOT;
				Invalidate();
			}
			return;
		}

		if( m_pOwner != NULL ) m_pOwner->DoEvent(event); else CControlUI::DoEvent(event);
	}

	void CScrollBarUI::SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue)
	{
		if( _tcsicmp(pstrName, _T("button1normalimage")) == 0 ) SetButton1NormalImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("button1hotimage")) == 0 ) SetButton1HotImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("button1pushedimage")) == 0 ) SetButton1PushedImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("button1disabledimage")) == 0 ) SetButton1DisabledImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("button2normalimage")) == 0 ) SetButton2NormalImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("button2hotimage")) == 0 ) SetButton2HotImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("button2pushedimage")) == 0 ) SetButton2PushedImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("button2disabledimage")) == 0 ) SetButton2DisabledImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("thumbnormalimage")) == 0 ) SetThumbNormalImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("thumbhotimage")) == 0 ) SetThumbHotImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("thumbpushedimage")) == 0 ) SetThumbPushedImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("thumbdisabledimage")) == 0 ) SetThumbDisabledImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("railnormalimage")) == 0 ) SetRailNormalImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("railhotimage")) == 0 ) SetRailHotImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("railpushedimage")) == 0 ) SetRailPushedImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("raildisabledimage")) == 0 ) SetRailDisabledImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("bknormalimage")) == 0 ) SetBkNormalImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("bkhotimage")) == 0 ) SetBkHotImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("bkpushedimage")) == 0 ) SetBkPushedImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("bkdisabledimage")) == 0 ) SetBkDisabledImage(pstrValue);
		else if( _tcsicmp(pstrName, _T("hor")) == 0 ) SetHorizontal(_tcsicmp(pstrValue, _T("true")) == 0);
		else if( _tcsicmp(pstrName, _T("linesize")) == 0 ) SetLineSize(_ttoi(pstrValue));
		else if( _tcsicmp(pstrName, _T("range")) == 0 ) SetScrollRange(_ttoi(pstrValue));
		else if( _tcsicmp(pstrName, _T("value")) == 0 ) SetScrollPos(_ttoi(pstrValue));
		else if( _tcsicmp(pstrName, _T("showbutton1")) == 0 ) SetShowButton1(_tcsicmp(pstrValue, _T("true")) == 0);
		else if( _tcsicmp(pstrName, _T("showbutton2")) == 0 ) SetShowButton2(_tcsicmp(pstrValue, _T("true")) == 0);
		else CControlUI::SetAttribute(pstrName, pstrValue);
	}

	bool CScrollBarUI::DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl)
	{
		PaintBkColor(hDC);
		PaintBkImage(hDC);
		PaintBk(hDC);
		PaintButton1(hDC);
		PaintButton2(hDC);
		PaintThumb(hDC);
		PaintRail(hDC);
		PaintBorder(hDC);
		return true;
	}

	void CScrollBarUI::PaintBk(HDC hDC)
	{
		if( !IsEnabled() ) m_uThumbState |= UISTATE_DISABLED;
		else m_uThumbState &= ~ UISTATE_DISABLED;

		if( (m_uThumbState & UISTATE_DISABLED) != 0 ) {
			if( !m_sBkDisabledImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sBkDisabledImage) ) {}
				else return;
			}
		}
		else if( (m_uThumbState & UISTATE_PUSHED) != 0 ) {
			if( !m_sBkPushedImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sBkPushedImage) ) {}
				else return;
			}
		}
		else if( (m_uThumbState & UISTATE_HOT) != 0 ) {
			if( !m_sBkHotImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sBkHotImage) ) {}
				else return;
			}
		}

		if( !m_sBkNormalImage.IsEmpty() ) {
			if( !DrawImage(hDC, (LPCTSTR)m_sBkNormalImage) ) {}
			else return;
		}
	}

	void CScrollBarUI::PaintButton1(HDC hDC)
	{
		if( !m_bShowButton1 ) return;

		if( !IsEnabled() ) m_uButton1State |= UISTATE_DISABLED;
		else m_uButton1State &= ~ UISTATE_DISABLED;

		int d1 = MulDiv(m_rcButton1.left - m_rcItem.left, 100, GetManager()->GetDPIObj()->GetScale());
		int d2 = MulDiv(m_rcButton1.top - m_rcItem.top, 100, GetManager()->GetDPIObj()->GetScale());
		int d3 = MulDiv(m_rcButton1.right - m_rcItem.left, 100, GetManager()->GetDPIObj()->GetScale());
		int d4 = MulDiv(m_rcButton1.bottom - m_rcItem.top, 100, GetManager()->GetDPIObj()->GetScale());
		m_sImageModify.Empty();
		m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1, d2, d3, d4);

		if( (m_uButton1State & UISTATE_DISABLED) != 0 ) {
			if( !m_sButton1DisabledImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sButton1DisabledImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}
		else if( (m_uButton1State & UISTATE_PUSHED) != 0 ) {
			if( !m_sButton1PushedImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sButton1PushedImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}
		else if( (m_uButton1State & UISTATE_HOT) != 0 ) {
			if( !m_sButton1HotImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sButton1HotImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}

		if( !m_sButton1NormalImage.IsEmpty() ) {
			if( !DrawImage(hDC, (LPCTSTR)m_sButton1NormalImage, (LPCTSTR)m_sImageModify) ) {}
			else return;
		}

		DWORD dwBorderColor = 0xFF85E4FF;
		int nBorderSize = 2;
		CRenderEngine::DrawRect(hDC, m_rcButton1, nBorderSize, dwBorderColor);
	}

	void CScrollBarUI::PaintButton2(HDC hDC)
	{
		if( !m_bShowButton2 ) return;

		if( !IsEnabled() ) m_uButton2State |= UISTATE_DISABLED;
		else m_uButton2State &= ~ UISTATE_DISABLED;
		int d1 = MulDiv(m_rcButton2.left - m_rcItem.left, 100, GetManager()->GetDPIObj()->GetScale());
		int d2 = MulDiv(m_rcButton2.top - m_rcItem.top, 100, GetManager()->GetDPIObj()->GetScale());
		int d3 = MulDiv(m_rcButton2.right - m_rcItem.left, 100, GetManager()->GetDPIObj()->GetScale());
		int d4 = MulDiv(m_rcButton2.bottom - m_rcItem.top, 100, GetManager()->GetDPIObj()->GetScale());
		m_sImageModify.Empty();
		m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"),d1 ,d2 ,d3 ,d4 );

		if( (m_uButton2State & UISTATE_DISABLED) != 0 ) {
			if( !m_sButton2DisabledImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sButton2DisabledImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}
		else if( (m_uButton2State & UISTATE_PUSHED) != 0 ) {
			if( !m_sButton2PushedImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sButton2PushedImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}
		else if( (m_uButton2State & UISTATE_HOT) != 0 ) {
			if( !m_sButton2HotImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sButton2HotImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}

		if( !m_sButton2NormalImage.IsEmpty() ) {
			if( !DrawImage(hDC, (LPCTSTR)m_sButton2NormalImage, (LPCTSTR)m_sImageModify) ) {}
			else return;
		}

		DWORD dwBorderColor = 0xFF85E4FF;
		int nBorderSize = 2;
		CRenderEngine::DrawRect(hDC, m_rcButton2, nBorderSize, dwBorderColor);
	}

	void CScrollBarUI::PaintThumb(HDC hDC)
	{
		if( m_rcThumb.left == 0 && m_rcThumb.top == 0 && m_rcThumb.right == 0 && m_rcThumb.bottom == 0 ) return;
		if( !IsEnabled() ) m_uThumbState |= UISTATE_DISABLED;
		else m_uThumbState &= ~ UISTATE_DISABLED;
		int d1 = MulDiv(m_rcThumb.left - m_rcItem.left, 100, GetManager()->GetDPIObj()->GetScale());
		int d2 = MulDiv(m_rcThumb.top - m_rcItem.top, 100, GetManager()->GetDPIObj()->GetScale());
		int d3 = MulDiv(m_rcThumb.right - m_rcItem.left, 100, GetManager()->GetDPIObj()->GetScale());
		int d4 = MulDiv(m_rcThumb.bottom - m_rcItem.top, 100, GetManager()->GetDPIObj()->GetScale());
		m_sImageModify.Empty();
		m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1, d2, d3, d4);

		if( (m_uThumbState & UISTATE_DISABLED) != 0 ) {
			if( !m_sThumbDisabledImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sThumbDisabledImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}
		else if( (m_uThumbState & UISTATE_PUSHED) != 0 ) {
			if( !m_sThumbPushedImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sThumbPushedImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}
		else if( (m_uThumbState & UISTATE_HOT) != 0 ) {
			if( !m_sThumbHotImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sThumbHotImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}

		if( !m_sThumbNormalImage.IsEmpty() ) {
			if( !DrawImage(hDC, (LPCTSTR)m_sThumbNormalImage, (LPCTSTR)m_sImageModify) ) {}
			else return;
		}

		DWORD dwBorderColor = 0xFF85E4FF;
		int nBorderSize = 2;
		CRenderEngine::DrawRect(hDC, m_rcThumb, nBorderSize, dwBorderColor);
	}

	void CScrollBarUI::PaintRail(HDC hDC)
	{
		if( m_rcThumb.left == 0 && m_rcThumb.top == 0 && m_rcThumb.right == 0 && m_rcThumb.bottom == 0 ) return;
		if( !IsEnabled() ) m_uThumbState |= UISTATE_DISABLED;
		else m_uThumbState &= ~ UISTATE_DISABLED;

		m_sImageModify.Empty();
		if( !m_bHorizontal ) {
			int d1 = MulDiv(m_rcThumb.left - m_rcItem.left, 100, GetManager()->GetDPIObj()->GetScale());
			int d2 = MulDiv((m_rcThumb.top + m_rcThumb.bottom) / 2 - m_rcItem.top - m_cxyFixed.cx / 2, 100, GetManager()->GetDPIObj()->GetScale());
			int d3 = MulDiv(m_rcThumb.right - m_rcItem.left, 100, GetManager()->GetDPIObj()->GetScale());
			int d4 = MulDiv((m_rcThumb.top + m_rcThumb.bottom) / 2 - m_rcItem.top + m_cxyFixed.cx - m_cxyFixed.cx / 2, 100, GetManager()->GetDPIObj()->GetScale());
			m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1, d2, d3,d4);
		}
		else {
			int d1 = MulDiv((m_rcThumb.left + m_rcThumb.right) / 2 - m_rcItem.left - m_cxyFixed.cy / 2, 100, GetManager()->GetDPIObj()->GetScale());
			int d2 = MulDiv(m_rcThumb.top - m_rcItem.top, 100, GetManager()->GetDPIObj()->GetScale());
			int d3 = MulDiv((m_rcThumb.left + m_rcThumb.right) / 2 - m_rcItem.left + m_cxyFixed.cy - m_cxyFixed.cy / 2, 100, GetManager()->GetDPIObj()->GetScale());
			int d4 = MulDiv(m_rcThumb.bottom - m_rcItem.top, 100, GetManager()->GetDPIObj()->GetScale());
			m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1,d2, d3, d4);
		}

		if( (m_uThumbState & UISTATE_DISABLED) != 0 ) {
			if( !m_sRailDisabledImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sRailDisabledImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}
		else if( (m_uThumbState & UISTATE_PUSHED) != 0 ) {
			if( !m_sRailPushedImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sRailPushedImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}
		else if( (m_uThumbState & UISTATE_HOT) != 0 ) {
			if( !m_sRailHotImage.IsEmpty() ) {
				if( !DrawImage(hDC, (LPCTSTR)m_sRailHotImage, (LPCTSTR)m_sImageModify) ) {}
				else return;
			}
		}

		if( !m_sRailNormalImage.IsEmpty() ) {
			if( !DrawImage(hDC, (LPCTSTR)m_sRailNormalImage, (LPCTSTR)m_sImageModify) ) {}
			else return;
		}
	}
}
