#pragma once
#include "CUIButton.h"
class CUIStageSelectPopUpBoard;

class CUIStageSelect :
	public CUIButton
{
private:
	int			m_nPage;
	int			m_nMaxPage;
	json		m_jSaveData;
	CUIStageSelectPopUpBoard* board;
public:
	CUIStageSelect(D3DXVECTOR2 vPos);
	~CUIStageSelect();

public:
	void Setup() override;
	void Load();
	bool OnEvent(eEvent eEvent, void * _value);
	void SelectEvent(int i);
	void ActiveUI();

};

