#pragma once
#include "CInteractiveActor.h"
#include "IPartGenerator.h"

class IPartGenerator;


enum class eCombinatorLevel
{
	ONE,
	TWO
};

enum class ECombinatorState
{
	E_LoadPossible,
	E_LoadImpossible
};

class CPartCombinator :
	public CInteractiveActor ,public IPartGenerator 
{
protected:
	eCombinatorLevel				m_eLevel;
	ECombinatorState				m_eCombinatorState;
	vector<ST_PNT_VERTEX>			m_vecVertex;
	LPDIRECT3DTEXTURE9				m_CombinatorTexture;
	std::multimap<string, CParts*>	m_multimapParts;
	std::vector<CParts*>			m_vecDischargeParts;
	ICollisionArea*					m_pPartsInteractCollision;
	D3DXVECTOR3						m_vOnCombinatorPosition;
	CParts*							m_pParts;
	bool							m_isFull;
	bool							m_isCombine;
	


	
public:
	CPartCombinator();
	CPartCombinator(IInteractCenter* pInteractCenter, eCombinatorLevel eType, float fAngle, D3DXVECTOR3 vPosition);
	virtual ~CPartCombinator();

public:
	void Update() override;
	void Render() override;
	
	virtual void Interact(CCharacter* pCharacter) override;
	virtual void PartsInteract(CParts* pParts);
	virtual void OnEvent(EEvent eEvent, void* _value) override;
	virtual void CombineParts();
	virtual void CombineManualParts();
	virtual void CombineAutoParts();
	void AutoCombine() {};
	void ManualCombine() {};
	virtual void DischargeParts();
	virtual void CombinatorRender() = 0;
	virtual ICollisionArea* GetInteractCollsion() const;
	virtual D3DXVECTOR3 GetPosition() const;

private:
	CParts* Make() override;
	virtual void Setup(float fAngle, D3DXVECTOR3 vPosition);

	
};

