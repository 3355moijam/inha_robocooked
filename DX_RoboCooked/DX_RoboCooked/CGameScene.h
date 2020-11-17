#pragma once
#include "CActor.h"
#include "CScene.h"

class CField;
class CInteractiveActor;
class CParts;
class CCharacter;

/* ������ */
class CDebugPlayer1;
class CDebugPlayer2;

class CGameScene :
	public CScene,CEventListener
{
private:
	CField*						m_pField;
	vector<CActor*>				m_vecStaticActor;
	vector<CInteractiveActor*>	m_vecObject;
	vector<CInteractiveActor*>	m_vecParts;
	vector<CCharacter*>			m_vecCharacters;

	/* ������ */
	CDebugPlayer1*				m_pDebugSphere;
	CDebugPlayer2*				m_pDebugCube;
	CParts*						m_pDebugParts;
public:
	CGameScene();
	~CGameScene();

public:
	virtual void Init();
	virtual void Render();
	virtual void Update();
	void OnEvent(EEvent eEvent, void* _value) override;
	void CGameScene::GetInteractObject(CCharacter* pCharacter);
};

