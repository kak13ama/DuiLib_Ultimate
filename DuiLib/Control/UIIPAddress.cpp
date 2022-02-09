#include "StdAfx.h"
#pragma comment( lib, "ws2_32.lib" )

DWORD GetLocalIpAddress()   
{   
	WORD wVersionRequested = MAKEWORD(2, 2);   
	WSADATA wsaData;   
	if (WSAStartup(wVersionRequested, &wsaData) != 0)   
		return 0;   
	char local[255] = {0};   
	gethostname(local, sizeof(local));   
	hostent* ph = gethostbyname(local);   
	{
		LRESULT lRes = 0;
		BOOL bHandled = TRUE;
		if( uMsg == WM_KILLFOCUS )
		{
			bHandled = TRUE;
			return 0;
			lRes = OnKillFocus(uMsg, wParam, lParam, bHandled);
		}
		else if (uMsg == WM_KEYUP && (wParam == VK_DELETE || wParam == VK_BACK))
		{
			LRESULT lRes = ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
			m_pOwner->m_nIPUpdateFlag = IP_DELETE;
			m_pOwner->UpdateText();
			PostMessage(WM_CLOSE);
			return lRes;
		}
		else if (uMsg == WM_KEYUP && wParam == VK_ESCAPE)
		{
			LRESULT lRes = ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
			m_pOwner->m_nIPUpdateFlag = IP_KEEP;
			PostMessage(WM_CLOSE);
			return lRes;
		}
		else if( uMsg == OCM_COMMAND ) {
			if( GET_WM_COMMAND_CMD(wParam, lParam) == EN_KILLFOCUS )
			{
				lRes = OnKillFocus(uMsg, wParam, lParam, bHandled);
			}
		}
		else bHandled = FALSE;
		if( !bHandled ) return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CIPAddressWnd::OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		HWND hWndFocus = GetFocus();
		while (hWndFocus)
		{
			if (GetFocus() == m_hWnd)
			{
				bHandled = TRUE;
				return 0;
			}
			hWndFocus = GetParent(hWndFocus);
		}

		LRESULT lRes = ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
		if (m_pOwner->m_nIPUpdateFlag == IP_NONE)
		{
			::SendMessage(m_hWnd, IPM_GETADDRESS, 0, (LPARAM)&m_pOwner->m_dwIP);
			m_pOwner->m_nIPUpdateFlag = IP_UPDATE;
			m_pOwner->UpdateText();
		}
		::ShowWindow(m_hWnd, SW_HIDE);
		return lRes;
	}

	//////////////////////////////////////////////////////////////////////////
	//
	IMPLEMENT_DUICONTROL(CIPAddressUI)

		CIPAddressUI::CIPAddressUI()
	{
		m_dwIP = GetLocalIpAddress();
		m_bReadOnly = false;
		m_pWindow = NULL;
		m_nIPUpdateFlag=IP_UPDATE;
		UpdateText();
		m_nIPUpdateFlag = IP_NONE;
	}

	LPCTSTR CIPAddressUI::GetClass() const
	{
		return _T("DateTimeUI");
	}

	LPVOID CIPAddressUI::GetInterface(LPCTSTR pstrName)
	{
		if( _tcscmp(pstrName, DUI_CTR_IPADDRESS) == 0 ) return static_cast<CIPAddressUI*>(this);
		return CLabelUI::GetInterface(pstrName);
	}

	DWORD CIPAddressUI::GetIP()
	{
		return m_dwIP;
	}

	void CIPAddressUI::SetIP(DWORD dwIP)
	{
		m_dwIP = dwIP;
		UpdateText();
	}

	void CIPAddressUI::SetReadOnly(bool bReadOnly)
	{
		m_bReadOnly = bReadOnly;
		Invalidate();
	}

	bool CIPAddressUI::IsReadOnly() const
	{
		return m_bReadOnly;
	}

	void CIPAddressUI::UpdateText()
	{
		if (m_nIPUpdateFlag == IP_DELETE)
			SetText(_T(""));
		else if (m_nIPUpdateFlag == IP_UPDATE)
		{
			TCHAR szIP[MAX_PATH] = {0};
			in_addr addr;
			addr.S_un.S_addr = m_dwIP;
			_stprintf(szIP, _T("%d.%d.%d.%d"), addr.S_un.S_un_b.s_b4, addr.S_un.S_un_b.s_b3, addr.S_un.S_un_b.s_b2, addr.S_un.S_un_b.s_b1);
			SetText(szIP);
		}
	}

	void CIPAddressUI::DoEvent(TEventUI& event)
	{
		if( !IsMouseEnabled() && event.Type > UIEVENT__MOUSEBEGIN && event.Type < UIEVENT__MOUSEEND ) {
			if( m_pParent != NULL ) m_pParent->DoEvent(event);
			else CLabelUI::DoEvent(event);
			return;
		}

		if( event.Type == UIEVENT_SETCURSOR && IsEnabled() )
		{
			::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_IBEAM)));
			return;
		}
		if( event.Type == UIEVENT_WINDOWSIZE )
		{
			if( m_pWindow != NULL ) m_pManager->SetFocusNeeded(this);
		}
		if( event.Type == UIEVENT_SCROLLWHEEL )
		{
			if( m_pWindow != NULL ) return;
		}
		if( event.Type == UIEVENT_SETFOCUS && IsEnabled() ) 
		{
			if( m_pWindow ) 
			{
				return;
			}
			m_pWindow = new CIPAddressWnd();
			ASSERT(m_pWindow);
			m_pWindow->Init(this);
			m_pWindow->ShowWindow();
		}
		if( event.Type == UIEVENT_KILLFOCUS && IsEnabled() ) 
		{
			Invalidate();
		}
		if( event.Type == UIEVENT_BUTTONDOWN || event.Type == UIEVENT_DBLCLICK || event.Type == UIEVENT_RBUTTONDOWN) 
		{
			if( IsEnabled() ) {
				GetManager()->ReleaseCapture();
				if( IsFocused() && m_pWindow == NULL )
				{
					m_pWindow = new CIPAddressWnd();
					ASSERT(m_pWindow);
				}
				if( m_pWindow != NULL )
				{
					m_pWindow->Init(this);
					m_pWindow->ShowWindow();
				}
			}
			return;
		}
		if( event.Type == UIEVENT_MOUSEMOVE ) 
		{
			return;
		}
		if( event.Type == UIEVENT_BUTTONUP ) 
		{
			return;
		}
		if( event.Type == UIEVENT_CONTEXTMENU )
		{
			return;
		}
		if( event.Type == UIEVENT_MOUSEENTER )
		{
			return;
		}
		if( event.Type == UIEVENT_MOUSELEAVE )
		{
			return;
		}

		CLabelUI::DoEvent(event);
	}

	void CIPAddressUI::SetAttribute( LPCTSTR pstrName, LPCTSTR pstrValue )
	{
		CLabelUI::SetAttribute(pstrName, pstrValue);
	}
}
