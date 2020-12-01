#pragma once
#include "CActor.h"

class CInteractiveActor;
class CParts;
class CBlueprint :
	public CActor
{
private:
	int				m_nRotAngleY;			//���赵�� Y�� ȸ��
	bool			m_isCompleted;			//�ϼ��Ǿ��°�
	string			m_sRightPartsID;		//���赵�� �����ϴ� ���� ID
	vector<ST_PNT_VERTEX>	m_vecVertex;
	LPDIRECT3DTEXTURE9		m_blueprintTexture;
	CParts*					m_onBlueprintParts;	//���赵 ���� ����
	vector<CInteractiveActor*>*		m_pVecParts;
public:
	CBlueprint(string partsID, vector<CInteractiveActor*>& vecParts);
	~CBlueprint();

	void Setup();
	void Update() override;
	void Render() override;
	void OnEvent(eEvent eEvent, void* _value) override;

	void AddAcceleration(const D3DXVECTOR3& vAccel) override {}
	void AddForce(const D3DXVECTOR3& vForce) override {}
};

