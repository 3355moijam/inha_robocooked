#pragma once
#include "CActor.h"

class CInteractiveActor;
class CParts;
class CBoxCollision;

class CBlueprint :
	public CActor
{
private:
	int				m_nRotAngleY;
	bool			m_isCompleted;			//�ϼ��Ǿ��°�
	string			m_sRightPartsID;		//���赵�� �����ϴ� ���� ID
	vector<ST_PNT_VERTEX>	m_vecVertex;
	LPDIRECT3DTEXTURE9		m_blueprintTexture;
	CParts*					m_onBlueprintParts;	//���赵 ���� ����
	vector<CInteractiveActor*>*		m_pVecParts;
	CBoxCollision*		m_pInteractCollision;			//������ �÷��̾�� �и��� �ʰ� ��ȣ�ۿ��� �� �ְ�
public:
	CBlueprint(string partsID, vector<CInteractiveActor*>& vecParts);
	~CBlueprint();

	void Setup();
	void Update() override;
	void Render() override;
	void OnEvent(eEvent eEvent, void* _value) override;

	void CheckOnBlueprintParts();
};

