#include "StdAfx.h"
#include "UIAnimation.h"
#include <vector>
#include <algorithm>

namespace DuiLib {
	struct CUIAnimation::Imp
	{
	{
		if(m_pControl == NULL) return;

		if(nAnimationID  != 0)
		{
			CAnimationData* pData = GetAnimationDataByID(nAnimationID);
			if( NULL != pData )
			{
				m_pControl->GetManager()->KillTimer( m_pControl, nAnimationID );
		}

		if(nFrame >= 0 && nFrame <= pData->m_nTotalFrame)
		{
			pData->m_nCurFrame = nFrame;
			return TRUE;
		}
		else
		{
			ASSERT(FALSE);
		}
		return FALSE;
	}

	void CUIAnimation::OnAnimationElapse(int nAnimationID)
	{
		if(m_pControl == NULL) return;

		CAnimationData* pData = GetAnimationDataByID(nAnimationID);
		if( NULL == pData ) return;

		int nCurFrame = pData->m_nCurFrame;
		if(nCurFrame == 0)
		{
			OnAnimationStart(nAnimationID, pData->m_bFirstLoop);
			pData->m_bFirstLoop = FALSE;
		}

		OnAnimationStep(pData->m_nTotalFrame, nCurFrame, nAnimationID);

		if(nCurFrame >= pData->m_nTotalFrame)
		{
			OnAnimationStop(nAnimationID);
			if(pData->m_bLoop)
			{
				pData->m_nCurFrame = 0;
			}
			else
			{
				m_pControl->GetManager()->KillTimer( m_pControl, nAnimationID );
				m_pImp->m_arAnimations.erase(std::remove(m_pImp->m_arAnimations.begin(), m_pImp->m_arAnimations.end(), pData), m_pImp->m_arAnimations.end());
				delete pData;
				pData = NULL;
			}
		}

		if( NULL != pData )
		{
			++(pData->m_nCurFrame);
		}
	}

	CAnimationData* CUIAnimation::GetAnimationDataByID(int nAnimationID)
	{
		CAnimationData* pRet = NULL;
		int nCount = m_pImp->m_arAnimations.size();
		for(int i=0; i<nCount; ++i)
		{
			if(m_pImp->m_arAnimations[i]->m_nAnimationID == nAnimationID)
			{
				pRet = m_pImp->m_arAnimations[i];
				break;
			}
		}

		return pRet;
	}

} // namespace DuiLib