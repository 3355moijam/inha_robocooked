#include "stdafx.h"
#include "CPartCombinator.h"
#include "CActor.h"
#include "IInteractCenter.h"


CPartCombinator::CPartCombinator()
{
}

CPartCombinator::CPartCombinator(IInteractCenter* pInteractCenter, eCombinatorLevel eType , float fAngle, D3DXVECTOR3 vPosition)
	: m_eLevel(eType), m_eCombinatorState(ECombinatorState::E_LoadPossible), m_CombinatorTexture(nullptr),
	  m_pPartsInteractCollision(NULL)
	  , m_vOnCombinatorPosition(0, 0, 0)
	  , m_pParts(NULL), m_isCombine(false)
{
	m_pInteractCenter = pInteractCenter;
	Setup(fAngle, vPosition);
}


CPartCombinator::~CPartCombinator()
{
	
}

//void CPartCombinator::Setup(float fAngle, D3DXVECTOR3 vPosition)
//{
//	vector<ST_PNT_VERTEX> vecVertex;
//	ST_PNT_VERTEX v;
//	v.n = D3DXVECTOR3(0, 1, 0);
//
//	{
//		//front
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(0, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 1);
//		vecVertex.push_back(v);
//
//		//back
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(0, 0);
//		vecVertex.push_back(v);
//
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//
//		//left
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(0, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	v.t = D3DXVECTOR2(1, 1);
//		vecVertex.push_back(v);
//
//		//right
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(0, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(1, 1);
//		vecVertex.push_back(v);
//
//		//top
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(0, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(1, 1);
//		vecVertex.push_back(v);
//
//		//bottom
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));		v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	v.t = D3DXVECTOR2(0, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//
//		v.p = D3DXVECTOR3(-BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(0, 1);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(1, 0);
//		vecVertex.push_back(v);
//		v.p = D3DXVECTOR3(BLOCK_SIZE / (2.0f), -BLOCK_SIZE / (2.0f), BLOCK_SIZE / (2.0f));	    v.t = D3DXVECTOR2(1, 1);
//		vecVertex.push_back(v);
//	}
//
//	m_vecVertex = vecVertex;
//
//	m_CombinatorTexture = g_pTextureManager->GetTexture(("data/Texture/city_014.png"));
//
//	D3DXMatrixRotationY(&m_matR, D3DXToRadian(fAngle));
//	D3DXMatrixTranslation(&m_matT, vPosition.x, 0, vPosition.z);
//	m_vPosition = vPosition;
//	m_vOnCombinatorPosition = D3DXVECTOR3(vPosition.x, vPosition.y+1.0f, vPosition.z);
//	
//	m_pCollision = new CBoxCollision(D3DXVECTOR3(0, 0, 0),D3DXVECTOR3(1.0f, 1.0f,1.0f), &m_matWorld);
//	m_pPartsInteractCollision = new CSphereCollision(D3DXVECTOR3(0, 0, 0), 2.0f, &m_matWorld);
//
//
//}
//
//
//
//void CPartCombinator::Update()
//{
//	
//	 if (m_pCollision)
//		 m_pCollision->Update();
//
//	 if (m_pPartsInteractCollision)
//		 m_pPartsInteractCollision->Update();
//
//	 if (m_vecDischargeParts.empty())
//		 m_eCombinatorState = ECombinatorState::E_LoadPossible;
//
//	if(m_isFull && (m_eLevel == eCombinatorLevel::ONE || m_eLevel == eCombinatorLevel::TWO))
//	{
//		CombineParts();
//	}
//	
//	if (m_isCombine && m_pParts == nullptr)
//		DischargeParts();
//
//	if(m_eCombinatorState == ECombinatorState::E_LoadPossible)
//		m_pInteractCenter->CheckAroundCombinator(this);
//}
//
//void CPartCombinator::Render()
//{
//	CombinatorRender();
//
//	_DEBUG_COMMENT if (m_pCollision)
//		_DEBUG_COMMENT m_pCollision->Render();
//
//	_DEBUG_COMMENT if (m_pPartsInteractCollision)
//		_DEBUG_COMMENT m_pPartsInteractCollision->Render();
//
//}
//
//
//void CPartCombinator::Interact(CCharacter* pCharacter)
//{
//	if (m_pParts == nullptr)
//		return;
//
//	if (m_eLevel == eCombinatorLevel::ONE || m_eLevel == eCombinatorLevel::TWO)
//		return; //�ڵ��� ��ȣ�ۿ����
//
//	if (pCharacter->GetPlayerState() == EPlayerState::E_None)
//	{
//		pCharacter->SetPlayerState(EPlayerState::E_Grab);
//		pCharacter->SetParts(m_pParts);
//		m_pParts->SetGrabPosition(&pCharacter->GetGrabPartsPosition());
//		m_pParts->GetCollision()->SetActive(true);
//		m_pParts = nullptr;
//	}
//	
//}

//void CPartCombinator::PartsInteract(CParts* pParts)
//{
//	if (pParts->GetGrabPosition() != NULL)
//		return;
//
//	/*switch (m_eLevel) {
//	case ECombinatorType::E_1stAuto:
//	case ECombinatorType::E_1stManual:
//		if (m_multimapParts.size() >= 2)
//		{
//			m_eCombinatorState = ECombinatorState::E_LoadImpossible;
//			return;
//		}
//		break;
//	case ECombinatorType::E_2stAuto: 
//	case ECombinatorType::E_2stManual: 
//		if (m_multimapParts.size() >= 3)
//		{
//			m_eCombinatorState = ECombinatorState::E_LoadImpossible;
//			return;
//		}
//		break;
//	default: ;
//	}*/
//
//	 m_multimapParts.insert(std::make_pair(pParts->GetPartsID(),pParts));
//	 pParts->GetCollision()->SetActive(false);
//	 pParts->SetCombinatorPosition(m_vPosition);
//	
//	if(m_eCombinatorState == ECombinatorState::E_LoadPossible)
//		pParts->SetMoveParts(true);
//}

//void CPartCombinator::OnEvent(EEvent eEvent, void* _value)
//{
//}
//
//void CPartCombinator::CombineParts()
//{
//	/*
//	 * ����Ұ��� �����̸� ��Ÿ�� �ְ� �Ʒ��� ��������
//	 */
//
//	m_isCombine = true; //����� �����ϰ� �ϴ� bool
//
//	/*switch (m_eLevel)
//	{
//	case ECombinatorType::E_1stAuto:
//	case ECombinatorType::E_2stAuto:
//		AutoCombine();
//		break;
//	case ECombinatorType::E_1stManual:
//	case ECombinatorType::E_2stManual: 
//		ManualCombine();
//		break;
//	default: 
//		break;
//	}
//	*/
//	
//}

//void CPartCombinator::CombineManualParts()
//{
//	
//}
//
//void CPartCombinator::CombineAutoParts()
//{
//	
//}

//void CPartCombinator::AutoCombine()
//{
//	/*
//	 *���սĿ� ���缭 m_vecDischargeParts�� ���� �־��ش� . 1����
//	 *���տ� ����Ѱ��� delete ���ش� .delete�� ���Ϳ��� ������Ѵ� why? vector���ִ°͵� erase ������ϴϱ� 
//	 */
//}
//
//void CPartCombinator::ManualCombine()
//{
//
//	/*
//	 * ���ս� ���缭 ��Ƽ�ʿ� �ִ´�. ���տ� ����Ѱ��� delete ���ش� .
//	 * delete�� ���Ϳ��� ������Ѵ� why? vector���ִ°͵� erase ������ϴϱ� 
//	 */
//
//	for (auto it : m_multimapParts)
//	{
//		m_vecDischargeParts.push_back(it.second);
//	}
//	m_multimapParts.clear();
//}

//void CPartCombinator::DischargeParts() //���� ��ġ�� �����ִ� ���� ���������ִ� �Լ�
//{
//	if (m_vecDischargeParts.empty())
//	{
//		m_isCombine = false;
//		return;
//	}
//	m_pParts = *m_vecDischargeParts.begin();
//	m_pParts->SetPosition(m_vOnCombinatorPosition);
//	m_vecDischargeParts.erase(m_vecDischargeParts.begin());
//}

//void CPartCombinator::CombinatorRender()
//{
//	m_matWorld = m_matS * m_matR * m_matT;
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
//	g_pD3DDevice->SetTexture(0, m_CombinatorTexture);
//
//	D3DMATERIAL9 mtlStorage;
//	ZeroMemory(&mtlStorage, sizeof(D3DMATERIAL9));
//	mtlStorage.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
//	mtlStorage.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
//	mtlStorage.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
//
//	g_pD3DDevice->SetMaterial(&mtlStorage);
//	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0],
//		sizeof(ST_PNT_VERTEX));
//	g_pD3DDevice->SetTexture(0, 0);
//}
//
//ICollisionArea* CPartCombinator::GetInteractCollsion() const
//{
//	return m_pPartsInteractCollision;
//}
//
//D3DXVECTOR3 CPartCombinator::GetPosition() const
//{
//	return m_vPosition;
//}
//
//CParts* CPartCombinator::Make()
//{
//	return nullptr;
//}
