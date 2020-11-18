#pragma once
#include "CInteractiveActor.h"

class CCharacter;
class CParts :
	public CInteractiveActor
{
private:
	D3DXVECTOR3			m_vPosition;
	D3DXVECTOR3*		m_vTestPosition;

	ST_SPHERE			m_sphere;
	LPD3DXMESH			m_pMeshSphere;
	D3DMATERIAL9		m_stMtlParts;

	int					m_nPartsID;
	float				m_fRotAngle;
	float				m_fWeight;
	
public:
	CParts();
	CParts(int nPartsID);
	virtual ~CParts();

	void Setup();
	void Update() override;
	void Render() override;
	void OnEvent(EEvent eEvent, void* _value);
	void Interact(CCharacter* pCharacter) override;
	void SetPosition(D3DXVECTOR3* vPosition) { m_vTestPosition = vPosition; }
	void DownParts(D3DXVECTOR3 vDir);
};

