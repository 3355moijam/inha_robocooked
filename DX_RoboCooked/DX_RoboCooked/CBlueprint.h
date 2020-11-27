#pragma once
#include "CActor.h"

class CParts;
class CBlueprint :
	public CActor
{
private:
	int				m_nRotAngleY;			//���赵�� Y�� ȸ��
	bool			m_isCompleted;			//�ϼ��Ǿ��°�
	string			m_sRightPartsID;		//���赵�� �����ϴ� ���� ID
	vector<ST_PNT_VERTEX>	m_vecVertex;
	LPDIRECT3DTEXTURE9		m_BlueprintTexture;
	CParts*					m_myParts;		//���� ���¸� �ο��ϱ� ����
public:
	CBlueprint(string partsID);
	~CBlueprint();

	void Setup();
	void Update() override;
	void Render() override;
	void OnEvent(eEvent eEvent, void* _value) override;
};

