#include "stdafx.h"
#include "CUITexture.h"


CUITexture::CUITexture(char* ActivePath, char* DisabledPath, char* HoverPath)
{
	m_ActiveTexture		= g_pUITextureManager->GetTexture(ActivePath);
	m_ActiveInfo		= g_pUITextureManager->GetTextureInfo(ActivePath);

	m_DisabledTexture	= g_pUITextureManager->GetTexture(DisabledPath);
	m_DisabledInfo		= g_pUITextureManager->GetTextureInfo(DisabledPath);

	m_HoverTexture		= g_pUITextureManager->GetTexture(HoverPath);
	m_HoverInfo			= g_pUITextureManager->GetTextureInfo(HoverPath);

	D3DXCreateSprite(g_pD3DDevice, &m_Sprite);
}


CUITexture::~CUITexture()
{
	SafeRelease(m_Sprite);
}

void CUITexture::Update()
{
	if (m_pParentWorldTM)
		m_matWorld *= *m_pParentWorldTM;
}

void CUITexture::Render()
{
	m_Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	//�̹��� ���
	RECT rc;

	////>>: UI�� ȸ�������� ��ų���־�
	//D3DXMATRIXA16 matS, matR, mat;
	////���� ��ġ  matTranslation;

	//mat = m_matWorldTM;

	m_Sprite->SetTransform(&m_matWorld);


	SetRect(&rc, 0, 0, m_ActiveInfo.Width, m_ActiveInfo.Height);
	m_Sprite->Draw(m_ActiveTexture,
		&rc,
		&D3DXVECTOR3(0, 0, 0),
		&D3DXVECTOR3(0, 0, 0),
		D3DCOLOR_ARGB(150, 255, 255, 255)); // A�� ���ĺ�����




	m_Sprite->End();
}

