#ifndef __UIVERTICALLAYOUT_H__
#define __UIVERTICALLAYOUT_H__

#pragma once

namespace DuiLib
{
	class UILIB_API CVerticalLayoutUI : public CContainerUI
	{
		DECLARE_DUICONTROL(CVerticalLayoutUI)
	public:
		CVerticalLayoutUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		UINT GetControlFlags() const;

		void SetSepHeight(int iHeight);
		int GetSepHeight() const;
		void SetSepImmMode(bool bImmediately);
		bool IsSepImmMode() const;
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void DoEvent(TEventUI& event);

		void SetPos(RECT rc, bool bNeedInvalidate = true);
		void DoPostPaint(HDC hDC, const RECT& rcPaint);
		{
			DECLARE_DUICONTROL(CVerticalLayoutUI)
		public:
			CVerticalLayoutUI();

			LPCTSTR GetClass() const;
			LPVOID GetInterface(LPCTSTR pstrName);
			UINT GetControlFlags() const;

			{
				DECLARE_DUICONTROL(CVerticalLayoutUI)
			public:
				CVerticalLayoutUI();

				LPCTSTR GetClass() const;
				LPVOID GetInterface(LPCTSTR pstrName);
				UINT GetControlFlags() const;


		RECT GetThumbRect(bool bUseNew = false) const;

	protected:
		int m_iSepHeight;
		UINT m_uButtonState;
		POINT ptLastMouse;
		RECT m_rcNewPos;
		bool m_bImmMode;
	};
}
#endif // __UIVERTICALLAYOUT_H__
