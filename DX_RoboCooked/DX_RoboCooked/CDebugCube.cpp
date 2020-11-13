#include "stdafx.h"
#include "CDebugCube.h"

#include "CBoxCollision.h"


CDebugCube::CDebugCube() :
	m_fSpeed(0.1f)
{
	m_vPosition = m_cube.vCenter;
	D3DXMatrixIdentity(&m_matWorld);
	
	m_stInputKey.moveFowardKey = VK_UP;
	m_stInputKey.moveLeftKey = VK_LEFT;
	m_stInputKey.moveBackKey = VK_BACK;
	m_stInputKey.moveRightKey = VK_RIGHT;
	m_stInputKey.interactableKey1 = VK_OEM_COMMA;
	m_stInputKey.interactableKey2 = VK_OEM_PERIOD;
	m_stInputKey.interactableKey3 = VK_OEM_2;
	
	g_EventManager->Attach(EEvent::E_KeyPress, this);
	g_EventManager->Attach(EEvent::E_KeyRelease, this);
	g_EventManager->Attach(EEvent::E_Player2KeyChange, this);

	m_pCollision = new CBoxCollision(m_vPosition, D3DXVECTOR3(1, 1, 1), &m_matWorld);
}


CDebugCube::~CDebugCube()
{
	SafeDelete(m_pCollision);
}

void CDebugCube::Setup()
{
	D3DXCreateBox(g_pD3DDevice, 0.8f, 0.8f, 0.8f, &m_pMeshCube, NULL);

	ZeroMemory(&m_stMtlCube, sizeof(D3DMATERIAL9));
	m_stMtlCube.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtlCube.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtlCube.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
}

void CDebugCube::Update()
{
	if (m_pCollision)
		m_pCollision->Update();
}

void CDebugCube::Render()
{
	m_matWorld = m_matS * m_matR * m_matT;
	
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetMaterial(&m_stMtlCube);
	m_pMeshCube->DrawSubset(0);

	_DEBUG_COMMENT if (m_pCollision)
		_DEBUG_COMMENT m_pCollision->Render();
}

void CDebugCube::OnEvent(EEvent eEvent, void* _value)
{
	switch (eEvent)
	{
	case EEvent::E_KeyPress:
		PressKey(_value);
		break;
	case EEvent::E_KeyRelease:
		ReleaseKey(_value);
	case EEvent::E_Player2KeyChange:
		SetKeyChange(_value);
		break;
	}
}

void CDebugCube::PressKey(void* _value)
{
	ST_KeyInputEvent *data = static_cast<ST_KeyInputEvent*>(_value);
	
	if (data->wKey == m_stInputKey.moveFowardKey)	//이벤트 추가해야함
	{
		Move(D3DXVECTOR3(0, 0, 1) * m_fSpeed);
	}
	if (data->wKey == m_stInputKey.moveLeftKey)
	{
		Move((D3DXVECTOR3(-1, 0, 0) * m_fSpeed));
	}
	if (data->wKey == m_stInputKey.moveBackKey)
	{
		Move(D3DXVECTOR3(0, 0, -1) * m_fSpeed);
	}
	if (data->wKey == m_stInputKey.moveRightKey)
	{
		Move(D3DXVECTOR3(1, 0, 0) * m_fSpeed);
	}
	if (data->wKey == m_stInputKey.interactableKey1)
	{
		
	}
	if (data->wKey == m_stInputKey.interactableKey2)
	{
		
	}
	if (data->wKey == m_stInputKey.interactableKey3)
	{
		
	}
}

void CDebugCube::ReleaseKey(void* _value)
{
}

void CDebugCube::Move(D3DXVECTOR3 _vecMove)
{
	D3DXVECTOR3 vPosition = m_vPosition;
	vPosition += _vecMove;
	m_vPosition = vPosition;
	D3DXMatrixTranslation(&m_matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
}

void CDebugCube::SetKeyChange(void* _value)
{
	memcpy(&m_stInputKey, &_value, sizeof(ST_PLAYER_INPUTKEY));
}
