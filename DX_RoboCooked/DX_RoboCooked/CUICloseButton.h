#pragma once
#include "CUIButton.h"
class CUICloseButton :
	public CUIButton
{
public:
	CUICloseButton(D3DXVECTOR2 vPos);
	~CUICloseButton();

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;

};

