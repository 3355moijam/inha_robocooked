﻿#include "stdafx.h"
#include "CSphereCollision.h"

#include "CBoxCollision.h"

//static LPD3DXMESH pMesh = nullptr;
CSphereCollision::CSphereCollision(D3DXVECTOR3 vOriginPos, float fRadius, D3DXMATRIXA16* pmatWorld): fRadius(fRadius),
	m_pMesh(nullptr)
{
	m_eType = eColideType::Sphere;
	m_vOriginCenterPos = vOriginPos;
	m_vCenterPos = vOriginPos;
	m_pmatWorldTM = pmatWorld;

	_RELEASE_COMMENT return ;

	D3DXCreateSphere(g_pD3DDevice, fRadius, 20, 20, &m_pMesh, nullptr);
}

CSphereCollision::~CSphereCollision()
{
}

void CSphereCollision::Render()
{
	_RELEASE_COMMENT return;

	if(m_pMesh)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, m_pmatWorldTM);
		g_pD3DDevice->SetTexture(0, NULL);
		D3DMATERIAL9 stMtl{};
		float a = m_isCollide ? 0 : 1;
		stMtl.Ambient = D3DXCOLOR(1, a, a, 1.0f);
		stMtl.Diffuse = D3DXCOLOR(1, a, a, 1.0f);
		stMtl.Specular = D3DXCOLOR(1, a, a, 1.0f);
		g_pD3DDevice->SetMaterial(&stMtl);
		m_pMesh->DrawSubset(0);
		g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		m_isCollide = false;
	}
	
}

void CSphereCollision::Update()
{
	D3DXVec3TransformCoord(&m_vCenterPos, &m_vOriginCenterPos, m_pmatWorldTM);
	
}

bool CSphereCollision::CollideToBox(CBoxCollision* pTargetCollider, D3DXVECTOR3* pNormal)
{
	bool b = pTargetCollider->CollideToSphere(this, pNormal);
	if(pNormal)
		*pNormal *= -1;
	return b;
}

bool CSphereCollision::CollideToSphere(CSphereCollision* pTargetCollider, D3DXVECTOR3* pNormal)
{
	D3DXVECTOR3 vDist = m_vCenterPos - pTargetCollider->GetCenter();
	
	if (D3DXVec3LengthSq(&vDist) > (fRadius + pTargetCollider->fRadius) * (fRadius + pTargetCollider->fRadius))
		return false;
	if (pNormal)
		*pNormal = *D3DXVec3Normalize(&vDist, &vDist);
	m_isCollide = true;
	pTargetCollider->SetIsCollide(true);
	return true;
}
