#pragma once
#include "CInteractiveActor.h"

class CParts;
class CBlueprint :
	public CInteractiveActor
{
private:
	//int				m_nRotAngleY;			//���赵�� Y�� ȸ��
	bool			m_isCompleted;			
	string			m_sRightPartsID;		//���赵�� �����ϴ� ���� ID
	//int				m_nRightPartsAngleY;	//���赵�� �����ϴ� ���� ȸ����
	float				m_fRightPartsAngleY;
	vector<ST_PNT_VERTEX>	m_vecVertex;
	CParts*					m_onBlueprintParts;	//���赵 ���� ����
	vector<CParts*>*		m_pVecParts;

	//D3DXMATRIXA16		m_matInteractCollision;
	ICollisionArea*		m_pInteractCollision;

	LPDIRECT3DTEXTURE9		m_blueprintTexture;
	LPDIRECT3DTEXTURE9		m_completeBlueprintTexture;
	vector<ST_PNT_VERTEX>	m_vecVertex_Multi;
public:
	CBlueprint(string partsID, vector<CParts*>& vecParts, D3DXVECTOR3 position, D3DXVECTOR3 scale, float angle, float partsAngle);
	~CBlueprint();

	void Setup();
	void Update() override;
	void Render() override;
	void OnEvent(eEvent eEvent, void* _value) override;

	void StoreOnBlueprintParts();
	void CheckBluePrintComplete();

	void AddAcceleration(const D3DXVECTOR3& vAccel) override {}
	void AddForce(const D3DXVECTOR3& vForce) override {}
	void Interact(CCharacter* pCharacter) override;
	void Setup_MultiTexture();
	void MultiTexture_Render();

	/*getter setter*/
	bool GetIsCompleted() { return m_isCompleted; }

	void SetPosition(D3DXVECTOR3 vPosition) override;
	void SetPosition(float x, float y, float z) override;
};

