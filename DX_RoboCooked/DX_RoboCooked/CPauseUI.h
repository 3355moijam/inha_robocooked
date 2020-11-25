#pragma once
#include "CUI.h"

class CUI;

class CPauseUI :
	public CUI
{
	enum EVENT
	{
		EN_BODY = 0 ,EN_OK,EN_CANCEL,EN_EXIT
	};
private:
	bool* m_isClick;
	
public:
	CPauseUI();
	~CPauseUI();

	

	virtual void Setup(bool* bClick);
	virtual void Update();
	virtual void Render();
	virtual void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual void ClickEvent(EVENT ev);
	virtual int ChildBtnInCheck(POINT pt);
};
