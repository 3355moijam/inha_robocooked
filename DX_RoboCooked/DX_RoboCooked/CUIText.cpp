#include "stdafx.h"
#include "CUIText.h"


CUIText::CUIText(char* ptext)
{
	m_sText = ptext;
}


CUIText::~CUIText()
{
}

void CUIText::Update()
{

}

void CUIText::Render()
{
	RECT rc;
	SetRect(&rc, 100, 100, 301, 200);

	// >> :font manager �߰���
	LPD3DXFONT pFont = g_pFontManager->GetFont(g_pFontManager->DEFAULT);
	//<<:

	//> fontmanager �����ҋ��� setup���� ���ְ� ���⼭ �̸���
	/*m_pFont->DrawTextA(NULL,
	sText.c_str(),
	sText.length(),
	&rc,
	DT_LEFT | DT_TOP | DT_NOCLIP,
	D3DCOLOR_XRGB(255, 255, 0));*/


	pFont->DrawTextA(NULL,
		m_sText.c_str(),
		m_sText.length(),
		&rc,
		DT_LEFT | DT_TOP | DT_NOCLIP,
		D3DCOLOR_XRGB(255, 255, 0));

}
