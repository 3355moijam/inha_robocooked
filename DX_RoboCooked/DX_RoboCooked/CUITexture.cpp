#include "stdafx.h"
#include "CUITexture.h"


CUITexture::CUITexture( char* DisabledPath, char* ActivePath, char* HoverPath, D3DXVECTOR2 vPos)
{
	D3DXCreateSprite(g_pD3DDevice, &m_Sprite);
	m_vPosition = vPos;

	if (DisabledPath == NULL)
		return;
	m_DisabledTexture = g_pUITextureManager->GetTexture(DisabledPath);
	m_DisabledInfo = g_pUITextureManager->GetTextureInfo(DisabledPath);

	if (ActivePath == NULL)
	{
		m_ActiveTexture = nullptr;
		return;
	}
		
	m_ActiveTexture		= g_pUITextureManager->GetTexture(ActivePath);
	m_ActiveInfo		= g_pUITextureManager->GetTextureInfo(ActivePath);

	if (HoverPath == NULL)
	{
		m_HoverTexture = nullptr;
		return;
	}
		
	m_HoverTexture		= g_pUITextureManager->GetTexture(HoverPath);
	m_HoverInfo			= g_pUITextureManager->GetTextureInfo(HoverPath);
}


CUITexture::~CUITexture()
{
	SafeRelease(m_Sprite);
}

void CUITexture::Update()
{

}

void CUITexture::Render()
{
	if (m_isActive)
		RenderTexture(m_eUIState);
}

void CUITexture::RenderTexture(eUIState state)
{
	m_Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	//이미지 출력
	RECT rc;
	
	m_Sprite->SetTransform(&g_matIdentity);

	if (state == eUIState::Up)
	{
		SetRect(&rc, 0, 0, m_DisabledInfo.Width, m_DisabledInfo.Height);
		m_Sprite->Draw(m_DisabledTexture,
			&rc,
			&D3DXVECTOR3(0, 0, 0),
			&D3DXVECTOR3(m_vPosition.x, m_vPosition.y, 0),
			D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else if (state == eUIState::Down)
	{
		if (m_ActiveTexture == nullptr)
			return;
		SetRect(&rc, 0, 0, m_ActiveInfo.Width, m_ActiveInfo.Height);
		m_Sprite->Draw(m_ActiveTexture,
			&rc,
			&D3DXVECTOR3(0, 0, 0),
			&D3DXVECTOR3(m_vPosition.x, m_vPosition.y, 0),
			D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else if (state == eUIState::Hover)
	{
		if (m_HoverTexture == nullptr)
			return;
		SetRect(&rc, 0, 0, m_HoverInfo.Width, m_HoverInfo.Height);
		m_Sprite->Draw(m_HoverTexture,
			&rc,
			&D3DXVECTOR3(0, 0, 0),
			&D3DXVECTOR3(m_vPosition.x, m_vPosition.y, 0),
			D3DCOLOR_ARGB(255, 255, 255, 255));
	}

	m_Sprite->End();
}

