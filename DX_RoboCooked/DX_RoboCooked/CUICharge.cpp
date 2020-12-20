#include "stdafx.h"
#include "CUICharge.h"
#include "CUIChargeBoard.h"
#include "CUIChargeFive.h"
#include "CUIChargeFour.h"
#include "CUIChargeThree.h"
#include "CUIChargeTwo.h"
#include "CUIChargeOne.h"
#include "CUIChargeZero.h"




CUICharge::CUICharge(D3DXVECTOR3* pPos, float* pfThrowPower, float fMaxThrowPower)
	: m_pChargeFive(nullptr)
	, m_pChargeFour(nullptr)
	, m_pChargeThree(nullptr)
	, m_pChargeTwo(nullptr)
	, m_pChargeOne(nullptr)
	, m_pChargeZero(nullptr)
	, m_vChargeUIPosition(0,0,0)
{
	m_isActive = true;
	m_pPosition = pPos;
	Setup();
	
}


CUICharge::~CUICharge()
{
}

void CUICharge::Setup()
{
	m_pChargeZero = new CUIChargeZero(m_pPosition);
	m_pChargeOne = new CUIChargeOne(m_pPosition);
	m_pChargeTwo = new CUIChargeTwo(m_pPosition);
	m_pChargeThree = new CUIChargeThree(m_pPosition);
	m_pChargeFour = new CUIChargeFour(m_pPosition);
	m_pChargeFive = new CUIChargeFive(m_pPosition);

	AddChild(m_pChargeZero);
	AddChild(m_pChargeOne);
	AddChild(m_pChargeTwo);
	AddChild(m_pChargeThree);
	AddChild(m_pChargeFour);
	AddChild(m_pChargeFive);




	
	//InvertActive();
}

void CUICharge::UpdateCharging(float fThrowPower , float fMaxThrowPower)
{
	SetChildActive(false);

	float temp = fMaxThrowPower / 5.0f;

	if (temp * 1 > fThrowPower)
	{
		m_pChargeZero->SetActive(true);
	}
	else if (temp * 2 > fThrowPower)
	{
		m_pChargeOne->SetActive(true);
	}
	else if (temp * 3 > fThrowPower)
	{
		m_pChargeTwo->SetActive(true);
	}
	else if (temp * 4 > fThrowPower)
	{
		m_pChargeThree->SetActive(true);
	}
	else if (temp * 5 > fThrowPower)
	{
		m_pChargeFour->SetActive(true);
	}
	else if(temp * 6 > fThrowPower)
	{
		m_pChargeFive->SetActive(true);
	}
	
}
