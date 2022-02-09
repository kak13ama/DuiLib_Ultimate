#ifndef __UITILELAYOUT_H__
#define __UITILELAYOUT_H__

#pragma once

namespace DuiLib
{
	class UILIB_API CTileLayoutUI : public CContainerUI
	{
		DECLARE_DUICONTROL(CTileLayoutUI)
	public:
		CTileLayoutUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void SetPos(RECT rc, bool bNeedInvalidate = true);

		SIZE GetItemSize() const;
		void SetItemSize(SIZE szItem);
		i{
		DECLARE_DUICONTROL(CTileLayoutUI)
	public:
		CTileLayoutUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void SetPos(RECT rc, bool bNeedInvalidate = true);

		{
			DECLARE_DUICONTROL(CTileLayoutUI)
		public:
			CTileLayoutUI();

			LPCTSTR GetClass() const;
			LPVOID GetInterface(LPCTSTR pstrName);

			void SetPos(RECT rc, bool bNeedInvalidate = true);

			nt GetColumns() const;
		void SetColumns(int nCols);

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	protected:
		SIZE m_szItem;
		int m_nColumns;
	};
}
#endif // __UITILELAYOUT_H__
