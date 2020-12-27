#include "stdafx.h"
#include "CUIText.h"


CUIText::CUIText(string ptext, D3DXVECTOR2 vPos, int nWidth, int nHeight, eTextType type) :
	m_eType(type), m_sText(ptext)
{
	SetRect(&m_rcText, vPos.x, vPos.y, vPos.x + nWidth, vPos.y + nHeight);
}


CUIText::~CUIText()
{
}

void CUIText::Update()
{

}

void CUIText::Render()
{
	LPD3DXFONT pFont;

	switch (m_eType)
	{
	case eTextType::ClearText:
		pFont = g_pFontManager->GetFont(g_pFontManager->CLEARTIME);
		break;
	case eTextType::SelectText:
		pFont = g_pFontManager->GetFont(g_pFontManager->SELECT);
		break;
	case eTextType::UpdateText:
		pFont = g_pFontManager->GetFont(g_pFontManager->UPDATE);
		break;
	default:
		pFont = g_pFontManager->GetFont(g_pFontManager->UPDATE);
		break;
	}
	
	pFont->DrawTextA(NULL,
		m_sText.c_str(),
		m_sText.length(),
		&m_rcText,
		DT_LEFT | DT_TOP|DT_WORDBREAK|DT_CENTER|DT_VCENTER,
		D3DCOLOR_XRGB(0, 0, 0));
	
}
