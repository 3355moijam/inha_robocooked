#include "stdafx.h"
#include "CGameScene.h"
#include "CUILoseButton.h"
#include "CUILoseBoard.h"
#include "CUIStarZero.h"
#include "CUITryAgain.h"
#include "CUIMainButton.h"
#include "CUIResetButton.h"
#include "IInteractCenter.h"


CUILoseButton::CUILoseButton(IInteractCenter* pInteractCenter):m_pInteractCenter(pInteractCenter)
{
	Setup();
	g_EventManager->Attach(eEvent::LoseMain, this);
	g_EventManager->Attach(eEvent::LoseReset, this);
}


CUILoseButton::~CUILoseButton()
{
}

void CUILoseButton::Setup()
{
	CUI* board = new CUILoseBoard();
	AddChild(board);
	m_vPosition = board->GetPosition();

	CUI* starUI = new CUIStarZero(D3DXVECTOR2(m_vPosition.x + 285, m_vPosition.y + 150));
	board->AddChild(starUI);

	CUI* tryAgainUI = new CUITryAgain(D3DXVECTOR2(m_vPosition.x + 320, m_vPosition.y + 350));
	board->AddChild(tryAgainUI);

	CUI* mainBtn = new CUIMainButton(D3DXVECTOR2(m_vPosition.x + 250, m_vPosition.y + 500), eBtnEvent::LoseMain);
	board->AddChild(mainBtn);

	CUI* ResetBtn = new CUIResetButton(D3DXVECTOR2(m_vPosition.x + 550, m_vPosition.y + 500), eBtnEvent::LoseReset);
	board->AddChild(ResetBtn);
}

bool CUILoseButton::OnEvent(eEvent eEvent, void * _value)
{
	switch (eEvent)
	{
	case eEvent::MouseClick:
		MouseClickEvent(_value);
		break;
	case eEvent::MouseHover:
		MouseHoverEvent(_value);
		break;
	case eEvent::MouseRelease:
	{
		MouseReleaseEvent(_value);
		return m_isActive;
	}
		break;
	case eEvent::LoseMain:
		break;
	case eEvent::LoseReset:
		ResetGame();
		break;
	}
	return true;
}

void CUILoseButton::ResetGame()
{
	//return;
	CGameScene* scene = new CGameScene;

	thread _t1(&CGameScene::Load, scene, "data/js", m_pInteractCenter->GetSceneID(), &CGameScene::Init);
	_t1.detach();

	CScene* pBeforeScene = g_SceneManager->SetCurrentScene(scene);
	if (pBeforeScene)
	{
		thread _t2([pBeforeScene]() { delete pBeforeScene; });
		_t2.detach();
	}
}
